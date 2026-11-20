# AstralHLE

An Android app that is being built to run old iPhone OS games (iPhone OS 1 to iOS 4) on Android 7.0 and newer.

## Status
Early development (v0.2.1). The launcher, the settings and the first part of the emulation core work.
Games do not run yet: the core loads a game's real code and runs it up to its first Objective-C call.

## What works so far
- Lock screen, home screen and glass look, with smooth open and close animations
- Add IPA, Recent app, game icons and names read from the IPA
- Settings: quality, display mode, FPS counter and corner, graphics backend, device model, language,
  RAM limit, time and date
- Games open in portrait or landscape, as the game asks
- Floating button to close a game
- Emulation core in C++: Mach-O loader, ARMv6 interpreter (ARM, Thumb, VFP), C library functions

## Notes
Not affiliated with Apple. Use only games you own.
Inspired by the open-source touchHLE project.

(c) 7.0Transformers Editz
