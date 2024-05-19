
# APEX DMA
It's a DMA cheat framework for apex legends in VM.\
Based on Memprocfs and Memflow.\
There's a simple example showing how to get key state and\
the health of LocalPlayer in this project.

## Tested Features

- Keyboard (windows version > 22000)
- CR3(DTB) Fix
- Basic Memory Functions:
> - Scatter Read (Tested)
> - Get Base Module Address / Size (Tested)
> - Scatter Write
> - Sig Scanning
> - Dumping MemMap


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

- Add other features when I have free time
- Windows with version <22000 will not be supported ( keyboard )\
  because the Registry is not working well


## Credits

- DMA Library: https://github.com/Metick/DMALibrary
- LeechCore Plugin: https://github.com/ufrisk/LeechCore-plugins
- Memflow [Connector]: https://github.com/memflow/memflow-qemu 
- Memprocfs: https://github.com/ufrisk/MemProcFS


## Screenshot

![Screenshot](https://github.com/atombottle/apex_dma/blob/main/screenshots/pic.jpg)
