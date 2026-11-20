// Host test tool: astral_cli <mach-o file> [max instructions] [device model]
#include "core.h"
#include <cstdio>
#include <cstdlib>
int main(int argc, char** argv) {
  if (argc < 2) { fprintf(stderr, "usage: %s <mach-o> [max_insns] [device]\n", argv[0]); return 1; }
  astral::Core core;
  if (argc > 3) core.device_model = argv[3];
  if (argc > 4) core.ram_limit_mb = (uint32_t)atoi(argv[4]);
  uint64_t n = argc > 2 ? strtoull(argv[2], nullptr, 10) : 50000000ull;
  std::string r = core.run_report(argv[1], n);
  fputs(r.c_str(), stdout);
  return 0;
}
