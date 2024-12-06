# Senfina, Means "infinite" in Esperanto

![senfina](/imgstore/Senfina.png)

Senfina is a fork of the unfinished Gamecube emulator Pureikyubu.

Pureikyubu has not published a new release since 2023 and appears to have stagnated. So we decided to maintain development on it with a fork called Senfina.

Senfina is unlikely to surpass Dolphin, in fact it is being created for experimental purposes, not as a goal to create a better emulator than Dolphin.

If you want a truly superior gaming experience, go with Dolphin.

## Build

### Windows version

Build using Visual Studio 2022. To build, open `scripts/pureikyubu.sln` and click Build.

### Generic Linux (Ubuntu) version

The Linux build does not yet have support for graphics and sound. All emulation output can be seen only through debug messages.

```
# Choose a suitable folder to store a clone of the repository, cd there and then
git clone https://github.com/emu-russia/pureikyubu.git 
cd pureikyubu
git submodule init
git submodule update
cd build
cmake ..
make
./pureikyubu pong.dol
```

Requirements: CMake, pthread, OpenGL, GLEW, imgui, SDL2. If cmake says that some components cannot be built, you should look for solutions on the Internet (`apt get install xxx`) as usual.

## Gallery

|![wip](/imgstore/wip.png)|![wip](/imgstore/wip.png)|![wip](/imgstore/wip.png)|
|---|---|---|

## Credits

We would like to say Thanks to people, who helped us to make Dolwin/pureikyubu:
- Costis: gcdev.com and some valuable information
- Titanik: made GC development possible
- tmbinc: details of GC bootrom and first working GX demos
- DesktopMan: nice GC demos
- groepaz: YAGCD and many other
- FiRES and ector for Dolphin-emulator, nice chats and information
- Masken: some ideas from WhineCube
- monk: some ideas from gcube
- Alex Raider: basic Windows Console code
- segher: Bootrom descrambler
- Duddie: For DSP reversing and docs

And also to people, we have forgot or who wanted to stay anonymous :)

Many thanks to our Beta-testers, for bug and compatibility reports.
Dolwin Beta-team: Chrono, darkreign, Jeil, Knuckles, MasterPhW and Posty.

Thanks to Martin for web-hosting on Emulation64.com

Dolwin 0.10 Team:
- hotquik (http://www.hotsoft.com.ve/about/), responsible for memory cards emulation, Bootrom fonts and UI.
- org (ogamespec), responsible for the rest

## Contacts

Mail: kurikyo0709@gmail.com
