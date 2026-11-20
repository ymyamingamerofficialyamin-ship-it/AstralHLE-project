#include "cpu.h"
#include <cstdio>
using namespace astral;
int main(){
  Memory m; Cpu c; c.mem=&m;
  // ARM: r0 = sum 1..10
  uint32_t prog[]={0xE3A00000,0xE3A0100A,0xE0800001,0xE2511001,0x1AFFFFFC,0xE12FFF1E};
  m.write_bytes(0x1000,prog,sizeof prog);
  c.r[15]=0x1000; c.r[14]=RET_SENTINEL;
  Stop s=c.run(1000); printf("ARM: stop=%d r0=%u (expect 55)\n",(int)s,c.r[0]);
  // Thumb: same loop
  uint16_t t[]={0x2000,0x210A,0x1840,0x3901,0xD1FC,0x4770};
  m.write_bytes(0x2000,t,sizeof t);
  Cpu d; d.mem=&m; d.thumb=true; d.r[15]=0x2000; d.r[14]=RET_SENTINEL;
  s=d.run(1000); printf("Thumb: stop=%d r0=%u (expect 55)\n",(int)s,d.r[0]);
  // ARM: ldm/stm, mul, shifts, flags: r0=(5*7)<<2 >>1 via mov with shifts; push/pop r4,r5
  uint32_t p2[]={0xE3A04005,0xE3A05007,0xE92D0030,0xE3A04000,0xE3A05000,0xE8BD0030,0xE0000594,0xE1A00100,0xE1A000C0,0xE12FFF1E};
  // mov r4,#5; mov r5,#7; stmfd sp!,{r4,r5}; mov r4,#0; mov r5,#0; ldmfd sp!,{r4,r5}; mul r0,r4,r5; mov r0,r0,lsl#2; mov r0,r0,asr#1; bx lr
  Cpu e; e.mem=&m; m.map(0x100000,0x1000); e.r[13]=0x100800; m.write_bytes(0x3000,p2,sizeof p2);
  e.r[15]=0x3000; e.r[14]=RET_SENTINEL; s=e.run(1000); printf("ARM2: stop=%d r0=%u (expect 70)\n",(int)s,e.r[0]);
  return 0;
}
