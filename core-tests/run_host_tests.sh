#!/bin/sh
# Builds the emulation core on a normal computer and runs the checks.
# Usage: sh run_host_tests.sh [path-to-extracted-Mach-O ...]
set -e
SRC=../app/src/main/cpp
g++ -std=c++17 -O2 -Wall -Wextra -Wno-unused-parameter -I$SRC $SRC/cpu.cpp cpu_test.cpp -o /tmp/astral_cpu_test
/tmp/astral_cpu_test
g++ -std=c++17 -O2 -Wall -Wextra -Wno-unused-parameter -I$SRC $SRC/cpu.cpp $SRC/macho.cpp $SRC/core.cpp $SRC/hle.cpp cli_main.cpp -o /tmp/astral_cli
for f in "$@"; do echo "== $f"; /tmp/astral_cli "$f" 50000000; done
