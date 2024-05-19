CXX=g++
CXXFLAGS=-I./includes/ -I./Memory/ -L./libs -l:vmm.so -l:leechcore.so -l:leechcore_device_microvmi.so -Wno-multichar
LIBS=-lm -Wl,--no-as-needed -ldl -lpthread

OUTDIR=./build
OBJDIR=$(OUTDIR)/obj

$(shell mkdir -p $(OBJDIR))
$(shell cp libs/leechcore.so /usr/lib/)
$(shell cp libs/vmm.so /usr/lib/)
$(shell cp libs/leechcore_device_microvmi.so /usr/lib/)
$(shell cp libs/libmemflow_qemu.x86_64.so $(OUTDIR)/)

%.o: %.cpp
	$(CXX) -c -o $(OBJDIR)/$@ $< $(CXXFLAGS)

Memory.o: ./Memory/Memory.cpp
	$(CXX) -c -o $(OBJDIR)/Memory.o ./Memory/Memory.cpp $(CXXFLAGS)

InputManager.o: ./Memory/InputManager.cpp
	$(CXX) -c -o $(OBJDIR)/InputManager.o ./Memory/InputManager.cpp $(CXXFLAGS)

apex_dma: apex_dma.o Memory.o InputManager.o
	$(CXX) -o $(OUTDIR)/$@ $(OBJDIR)/apex_dma.o $(OBJDIR)/Memory.o $(OBJDIR)/InputManager.o $(CXXFLAGS) $(LIBS)

.PHONY: all
all: apex_dma

.DEFAULT_GOAL := all

clean:
	rm -rf $(OUTDIR)
	rm -rf /usr/lib/vmm.so
	rm -rf /usr/lib/leechcore.so
	rm -rf /usr/lib/leechcore_device_microvmi.so
