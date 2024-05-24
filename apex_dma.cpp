#include "Memory/Memory.h"
#include "offset.h"

uint64_t apex_base;

int main(){
    if (!mem.Init("r5apex.exe", true, true))
    {
	std::cout << "[!] Failed to open Process of APEX!" << std::endl;
    }
    apex_base = mem.get_base_address();

    c_keys keyboard;
    bool init_keyboard = keyboard.InitKeyboard();
    if (!init_keyboard)
    {
        std::cout << "[!] Failed to initialize keyboard!" << std::endl;
    }

    while(apex_base){
        if(!keyboard.IsKeyDown(0x10)){
            uint64_t LocalPlayer = mem.Read<uint64_t>(apex_base + OFFSET_LOCAL_ENT);
            int health = mem.Read<int>(LocalPlayer + OFFSET_HEALTH);
            printf("[LocalPlayer Health] %d\n", health);
        }else printf("[Shift pressed]\n");
        if(keyboard.IsKeyDown(0x05)){
            uint64_t LocalPlayer = mem.Read<uint64_t>(apex_base + OFFSET_LOCAL_ENT);
            mem.Write<int>(apex_base + OFFSET_IN_DUCK + 0x8, 7);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
