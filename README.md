# mgs
Emulator for the Megify Game System, a fictional retro game system by [F0x1fy](https://github.com/F0x1fy) and [Mego](https://github.com/MegaLoler), hence the name Megify.

# Cloning
MGS uses [ayumi](https://github.com/true-grue/ayumi) and [Z80](https://github.com/redcode/Z80) as submodules.
Please be sure to run `git clone --recursive https://github.com/Megify/mgs` to clone.
When updating, please use `git submodule update --init --recursive`.

# Building

Do this to build and optionally install `mgs` on your system:

```bash
mkdir build
cd build
../configure # or, use the configure_debug script
             # instead to build with debug flags
make         # will produce mgs binary in build/
make install # optional
```
