#include "Memory/Memory.h"

int main(){
    if (!mem.Init("r5apex.exe", true, false))
	{
		std::cout << "Failed to initilize DMA" << std::endl;
	}

    c_keys keyboard;
    bool init_keyboard = keyboard.InitKeyboard();
    if (!init_keyboard)
    {
        std::cout << "Failed to initialize keyboard hotkeys through kernel." << std::endl;
    }

    while(true){
	if(keyboard.IsKeyDown(0x10)) printf("pressed shift\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
