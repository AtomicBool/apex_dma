
# APEX DMA
It's a DMA cheat for apex legends in VM.\
Based on Memprocfs and Memflow.

## Features

- Keyboard (windows version > 22000)
- CR3(DTB) Fix (Seems working)
- Memory R/W (Seems working)


## Use

```bash
  git clone https://github.com/atombottle/apex_dma.git
  sudo make
  cd build
  sudo ./apex_dma
```

```bash
  sudo make clean
```


## TODO

- Test Memory R/W and CR3 Fix with a simple demo
- A guest with UDP communication
- ESP
- Aimbot
- Other Stuff
- Windows with version <22000 will not be supported ( keyboard )


## Credits

- DMA Library: https://github.com/Metick/DMALibrary
- LeechCore Plugin: https://github.com/ufrisk/LeechCore-plugins
- Memflow [Connector]: https://github.com/memflow/memflow-qemu 
- Memprocfs: https://github.com/ufrisk/MemProcFS


## Screenshot

![Screenshot](https://github.com/atombottle/apex_dma/blob/main/screenshots/pic.jpg)
