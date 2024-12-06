# main

This component is used to control host emulation (GameCube).

You can assume that the "Loaded" state is equivalent to the fact that the GameCube is on (powered),
and the "Running" state is equivalent to the main Gekko clock is running.

The architecture of the emulator is designed in such a way that the running Gekko thread is the main driving force of the emulator.
All other emulation threads are based on the Gekko emulated timer (Time Base Register).

Thus, if the Gekko thread is in a suspended state, all other hardware modules are also "sleeping".

> [!NOTE]  
> In a real system, the clock frequency is generated by a special chip that supplies 162 MHz simultaneously to the input of both Gekko and Flipper. Gekko has a PLL that multiplies the frequency by 3 (up to 486 MHz). In the emulator we simplify this interaction and consider that Gekko is a CLK master.

## Loader

The part of the main module used to "load files" for emulation purposes.

Supported file formats:
- DOL
- ELF
- GCM/ISO: unencrypted GameCube disk images
- The special file name `Bootrom` is used to start the IPL from the beginning (reset vector, 0xfff00100); The Bootrom image must be set in the emulator settings.

## Threads

Instead of calling `Thread` class directly from utils.cpp, `EMUCreateThread` / `EMUJoinThread` calls are used for threads. They are in essence wrappers and are needed to keep statistics of active threads of the emulator.

## HWConfig

To avoid using configuration from the HW component, all Flipper hardware emulation settings are aggregated
into the HWConfig structure.