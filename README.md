# Snake-Game
A classic Snake game built in C++ using SFML 3.0.2.
 
---
 
## Requirements
 
- Windows 64-bit
- [SFML 3.0.2 (GCC 14.2.0 MinGW 64-bit)](https://www.sfml-dev.org/download/)
- [WinLibs GCC 14.2.0](https://winlibs.com/) — must match the SFML build exactly
- [VS Code](https://code.visualstudio.com/) with the C/C++ extension
 
---
 
## Setup
 
### 1. Clone the repository
 
```bash
git clone https://github.com/YOUR_USERNAME/Snake-Game.git
cd Snake-Game
```
 
### 2. Download SFML
 
Download **SFML 3.0.2 — GCC 14.2.0 MinGW 64-bit** from https://www.sfml-dev.org/download/
 
Extract it somewhere on your machine, for example:
```
C:/SFML-3.0.2/
```
 
### 3. Download the matching GCC compiler
 
Download **WinLibs GCC 14.2.0 (UCRT, POSIX, SEH)** from https://winlibs.com/
 
Extract it somewhere, for example:
```
C:/mingw64/
```
 
> ⚠️ The GCC version must be **14.2.0** to match the SFML build. Using a different version will cause a crash on launch.
 
### 4. Copy required DLLs into the project folder
 
You need two sets of DLLs in the same folder as `game.exe`:
 
**From your SFML folder** (`SFML-3.0.2/bin/` or root):
```
sfml-graphics-d-3.dll
sfml-window-d-3.dll
sfml-system-d-3.dll
sfml-audio-d-3.dll
sfml-network-d-3.dll
```
 
**From your WinLibs GCC folder** (`mingw64/bin/`):
```
libstdc++-6.dll
libgcc_s_seh-1.dll
libwinpthread-1.dll
```
 
### 5. Update `tasks.json`
 
Open `.vscode/tasks.json` and update the following paths to match your machine:
 
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "C:/path/to/mingw64/bin/g++",
      "args": [
        "-IC:/path/to/SFML-3.0.2/include",
        "-LC:/path/to/SFML-3.0.2/lib",
        "src/main.cpp",
        "-lsfml-graphics-d",
        "-lsfml-window-d",
        "-lsfml-system-d",
        "-o",
        "game.exe"
      ]
    }
  ]
}
```
 
Replace `C:/path/to/mingw64` and `C:/path/to/SFML-3.0.2` with the actual paths on your machine.
 
---
 
## Building
 
In VS Code, press `Ctrl+Shift+B` or go to **Terminal > Run Build Task**.
 
This will compile `src/main.cpp` and produce `game.exe` in the project root.
 
---
 
## Running
 
```powershell
./game.exe
```
 
Or simply press **F5** in VS Code if a launch configuration is set up.
 
---
 
## Controls
 
| Key | Action |
|-----|--------|
| ↑ | Move Up |
| ↓ | Move Down |
| ← | Move Left |
| → | Move Right |
| Esc | Quit |
 
---
 
## Project Structure
 
```
Snake-Game/
├── src/
│   └── main.cpp        # Game source code
├── .vscode/
│   ├── tasks.json      # Build configuration
│   └── c_cpp_properties.json  # IntelliSense configuration
├── .gitignore
└── README.md
```
 
---
 
## Why so many DLLs?
 
C++ doesn't have a package manager like `npm`. Instead, libraries like SFML are linked manually and their `.dll` files must be distributed alongside the executable. The MinGW runtime DLLs (`libstdc++`, etc.) are the C++ standard library — the equivalent of the Node.js runtime.
 
---
 
## License
 
MIT