# Pokémon XD: Gale of Darkness – TeamOrre Decompilation Project

This repository is the home of the **Pokémon XD** decompilation effort under **TeamOrre**.

## Supported Versions

Work in progress:

- `GXXE01`: Rev 0 (USA)
- `NXXJ01`: Rev 0 (JP Demo Disc)

## Status

`GXXE01`: Porting symbols and preparing splits.

`NXXJ01`: Symbols and splits mostly prepared.

## Project Goals

- Reconstruct the game's code in C/C++.
- Produce a **matching** retail binary.
- Remain legally clean – **no ROMs, ISOs, or copyrighted assets**.

## Repository Organization

- `src/` – Decompiled C/C++ sources  
- `include/` – Reconstructed headers  
- `config/` – Project configs, splits, and symbols  
- `tools/` – Helper scripts and utilities
- `docs/` – Documentation and notes

## Legal Notices

This project does **not** contain game assets or proprietary data.  
It is a reverse engineering effort for educational and archival purposes.

## Dependencies

Windows
--------

On Windows, it's **highly recommended** to use native tooling. WSL or msys2 are **not** required.  
When running under WSL, [objdiff](#diffing) is unable to get filesystem notifications for automatic rebuilds.

- Install [Python](https://www.python.org/downloads/) and add it to `%PATH%`.
  - Also available from the [Windows Store](https://apps.microsoft.com/store/detail/python-311/9NRWMJP3717K).
- Download [ninja](https://github.com/ninja-build/ninja/releases) and add it to `%PATH%`.
  - Quick install via pip: `pip install ninja`

macOS
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages):

  ```sh
  brew install ninja
  ```

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

Linux
------

- Install [ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages).

[wibo](https://github.com/decompals/wibo), a minimal 32-bit Windows binary wrapper, will be automatically downloaded and used.

## Building

- Clone the repository:

  ```sh
  git clone https://github.com/TeamOrre/xd-decomp.git
  ```

- Copy your game's disc image to `orig/GXXE01`.
  - Supported formats: ISO (GCM), RVZ, WIA, WBFS, CISO, NFS, GCZ, TGC
  - After the initial build, the disc image can be deleted to save space.

- Configure:

  ```sh
  python configure.py
  ```

  To use a version other than `GXXE01` (USA), specify it with `--version`.

- Build:

  ```sh
  ninja
  ```

## Diffing

Once the initial build succeeds, an `objdiff.json` should exist in the project root.

Download the latest release from [encounter/objdiff](https://github.com/encounter/objdiff). Under project settings, set `Project directory`. The configuration should be loaded automatically.

Select an object from the left sidebar to begin diffing. Changes to the project will rebuild automatically: changes to source files, headers, `configure.py`, `splits.txt` or `symbols.txt`.
