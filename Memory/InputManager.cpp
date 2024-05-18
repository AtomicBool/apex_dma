#include "pch.h"
#include "InputManager.h"
#include "Memory.h"

bool c_keys::InitKeyboard()
{
	win_logon_pid = mem.GetPidFromName("winlogon.exe");

	auto pids = mem.GetPidListFromName("csrss.exe");
	for (size_t i = 0; i < pids.size(); i++)
	{
		auto pid = pids[i];
		uintptr_t tmp = VMMDLL_ProcessGetModuleBaseU(mem.vHandle, pid, const_cast<LPSTR>("win32ksgd.sys"));
		uintptr_t g_session_global_slots = tmp + 0x3110;
		uintptr_t user_session_state = mem.Read<uintptr_t>(mem.Read<uintptr_t>(mem.Read<uintptr_t>(g_session_global_slots, pid), pid), pid);
		gafAsyncKeyStateExport = user_session_state + 0x3690;
		if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
			break;
	}
	if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
		return true;
	return false;
}

void c_keys::UpdateKeys()
{
	uint8_t previous_key_state_bitmap[64] = {0};
	memcpy(previous_key_state_bitmap, state_bitmap, 64);

	VMMDLL_MemReadEx(mem.vHandle, this->win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY, gafAsyncKeyStateExport, reinterpret_cast<PBYTE>(&state_bitmap), 64, NULL, VMMDLL_FLAG_NOCACHE);
	for (int vk = 0; vk < 256; ++vk)
		if ((state_bitmap[(vk * 2 / 8)] & 1 << vk % 4 * 2) && !(previous_key_state_bitmap[(vk * 2 / 8)] & 1 << vk % 4 * 2))
			previous_state_bitmap[vk / 8] |= 1 << vk % 8;
}

bool c_keys::IsKeyDown(uint32_t virtual_key_code)
{
	if (gafAsyncKeyStateExport < 0x7FFFFFFFFFFF)
		return false;
	if (std::chrono::system_clock::now() - start > std::chrono::milliseconds(1))
	{
		UpdateKeys();
		start = std::chrono::system_clock::now();
	}
	return state_bitmap[(virtual_key_code * 2 / 8)] & 1 << virtual_key_code % 4 * 2;
}
