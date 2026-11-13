# AstralHLE v0.2.0

One app (APK) for Android 7.0 and newer. Modern look with liquid glass, imported IPA games, Settings,
and the first part of the emulation core (C++, written from scratch).

## What is in this version
- Lock screen (glass clock, swipe up to unlock), home screen (empty until you add an IPA), glass dock:
  Add IPA, Settings, Recent app.
- Settings: Quality (original, 2x-5x), Display mode, FPS counter + corner, Trace GL errors, Lock screen,
  Graphics (Auto / OpenGL ES / Vulkan), Cheat Engine, Network access, Local Game Center sign-in,
  analog sticks for tilt, Device model, Language, Time & date. Copyright line at the bottom.
- Floating glass button inside a game: drag it anywhere, tap it, choose "Close app".
- Emulation core (app/src/main/cpp): Mach-O loader, ARMv6 interpreter (ARM + Thumb-1 + VFP),
  import binding, libc / pthread / math / time functions (HLE).

## Honest status of the core
Games do NOT run yet. Tapping a game starts the core, which loads the real game code, runs it, and shows a
report. Both test games (Resident Evil: Degeneration, R.Thunder 2) execute real code and then reach the first
Objective-C call: [NSAutoreleasePool alloc]. Next step: Objective-C runtime + Foundation, then UIKit and
OpenGL ES.  See core-tests/sample-output.txt.

## Build the APK
### Option A: GitHub (works from a phone browser)
1. Create a free GitHub repository and upload everything in this folder (keep the .github folder).
2. Open the Actions tab, pick "Build AstralHLE APK", press Run workflow.
3. When it is green, open the run and download the artifact "AstralHLE-apk".

### Option B: Android Studio on a computer
Open this folder, wait for Gradle sync (needs internet, installs NDK + CMake), then Build > Build APK(s).

## Test the core on a computer
cd core-tests && sh run_host_tests.sh /path/to/extracted/Mach-O
(Unzip the IPA, the game binary is Payload/<name>.app/<executable>.)
