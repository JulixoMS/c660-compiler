#ifndef __MCODE
#define __MCODE

// 00,01,02,03,04,05,06,07,08,09,0A,0B,0C,0D,0E,0F
// XO,YO,AO,XI,YI,AI,VO,VI,PC,PJ,JH,JL,MI,NI,L1,L0

// When XO and XI are called, do Z->PC (ZP)
// When YO and YI are called, do PC->Z (PZ)

// ?O: Output to bus
// ?I: Save from bus
// J?: Save ? byte from bus
// PC: Increment PC
// PJ: Set PC to J
// L1: Alu byte 1
// L0: Alu byte 0
// NU: Nothing

// M: ALU input A
// N: ALU input B
// V: Instruction argument / Data port

// Z0C0 = Less / Not equal
// Z0C1 = Greater / Not equal
// Z1C0 = Equal
// Z1C1 = Not equal(exactly n2=256-n1)

#define XO (0x0001<<0x0)
#define YO (0x0001<<0x1)
#define AO (0x0001<<0x2)
#define XI (0x0001<<0x3)
#define YI (0x0001<<0x4)
#define AI (0x0001<<0x5)
#define VO (0x0001<<0x6)
#define VI (0x0001<<0x7)
#define PC (0x0001<<0x8)
#define PJ (0x0001<<0x9)
#define JH (0x0001<<0xA)
#define JL (0x0001<<0xB)
#define MI (0x0001<<0xC)
#define NI (0x0001<<0xD)
#define L1 (0x0001<<0xE)
#define L0 (0x0001<<0xF)
#define ZP (XO|XI)
#define PZ (YO|YI)

#define NU (0x0000<<0x0)

const char ilen[] = {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2,
  1,
  1,
  1,
  2
};

const char *istr[] = {
  "NOP",
  "NOP",
  "NOP",
  "NOP",
  "SJH X",
  "SJH Y",
  "SJH A",
  "SJH ####",
  "SJL X",
  "SJL Y",
  "SJL A",
  "SJL ####",
  "HLT",
  "HLT",
  "HLT",
  "HLT",
  "JMP",
  "JMP",
  "JMP",
  "JMP",
  "BLS",
  "BGR",
  "BEQ",
  "BNE",
  "CPA X",
  "CPA Y",
  "CPA ####",
  "CPX Y",
  "CPX ####",
  "CPY ####",
  "NOP",
  "NOP",
  "LDX A",
  "LDY A",
  "LDJ A",
  "LDY X",
  "LDA X",
  "LDJ X",
  "LDX Y",
  "LDA Y",
  "LDJ Y",
  "LDX ####",
  "LDY ####",
  "LDA ####",
  "NOP",
  "LDX J",
  "LDY J",
  "LDA J",
  "ADD X",
  "ADD Y",
  "ADD A",
  "ADD ####",
  "SUB X",
  "SUB Y",
  "SUB A",
  "SUB ####",
  "SHR X",
  "SHR Y",
  "SHR A",
  "SHR ####",
  "NND X",
  "NND Y",
  "NND A",
  "NND ####"
};

const short mcodeZ0C0[] = {
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJH
  YO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJL
  YO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // HLT
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // JMP
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BLS
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BGR
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BEQ
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BNE
  MI|AO|L0,NI|XO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|AO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  PC      ,MI|AO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|XO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|XO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|YO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPY
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(again)
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  AO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,AO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  XO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  XO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,XO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  YO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  YO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,YO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  PC      ,VO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  PC      ,VO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PC      ,VO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(another time)
  PZ      ,PJ      ,VO|XI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDX
  PZ      ,PJ      ,VO|YI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,VO|AI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDA
  L0|MI|AO,NI|XO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|YO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|AO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  PC      ,L0|MI|AO,NI|VO   ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,L1|NI|XO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|YO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|AO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  PC      ,L0|MI|AO,L1|NI|VO,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|XO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|YO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|AO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|XO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|YO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|AO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1      ,L1|L0|AI,NU      ,PC        // NND
};

const short mcodeZ0C1[] = {
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJH
  YO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJL
  YO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // HLT
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // JMP
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BLS
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BGR
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BEQ
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BNE
  MI|AO|L0,NI|XO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|AO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  PC      ,MI|AO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|XO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|XO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|YO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPY
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(again)
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  AO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,AO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  XO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  XO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,XO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  YO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  YO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,YO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  PC      ,VO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  PC      ,VO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PC      ,VO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(another time)
  PZ      ,PJ      ,VO|XI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDX
  PZ      ,PJ      ,VO|YI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,VO|AI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDA
  L0|MI|AO,NI|XO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|YO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|AO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  PC      ,L0|MI|AO,NI|VO   ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,L1|NI|XO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|YO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|AO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  PC      ,L0|MI|AO,L1|NI|VO,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|XO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|YO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|AO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|XO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|YO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|AO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1      ,L1|L0|AI,NU      ,PC        // NND
};

const short mcodeZ1C0[] = {
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJH
  YO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJL
  YO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // HLT
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // JMP
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BLS
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BGR
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BEQ
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BNE
  MI|AO|L0,NI|XO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|AO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  PC      ,MI|AO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|XO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|XO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|YO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPY
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(again)
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  AO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,AO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  XO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  XO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,XO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  YO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  YO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,YO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  PC      ,VO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  PC      ,VO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PC      ,VO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(another time)
  PZ      ,PJ      ,VO|XI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDX
  PZ      ,PJ      ,VO|YI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,VO|AI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDA
  L0|MI|AO,NI|XO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|YO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|AO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  PC      ,L0|MI|AO,NI|VO   ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,L1|NI|XO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|YO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|AO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  PC      ,L0|MI|AO,L1|NI|VO,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|XO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|YO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|AO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|XO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|YO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|AO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1      ,L1|L0|AI,NU      ,PC        // NND
};

const short mcodeZ1C1[] = {
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJH
  YO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JH   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  XO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // SJL
  YO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  PC      ,VO|JL   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // HLT
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // JMP
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BLS
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BGR
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // BEQ
  PJ      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // BNE
  MI|AO|L0,NI|XO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|AO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  PC      ,MI|AO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPA
  MI|XO|L0,NI|YO|L1,NU      ,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|XO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPX
  PC      ,MI|YO|L0,NI|VO|L1,NU      ,NU      ,NU      ,NU      ,NU      , // CPY
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(again)
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      ,
  AO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  AO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,AO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  XO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  XO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,XO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  YO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  YO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  PZ      ,PJ      ,YO|VI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDJ
  PC      ,VO|XI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDX
  PC      ,VO|YI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDY
  PC      ,VO|AI   ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // LDA
  NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,NU      ,PC      , // NOP(another time)
  PZ      ,PJ      ,VO|XI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDX
  PZ      ,PJ      ,VO|YI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDY
  PZ      ,PJ      ,VO|AI   ,ZP      ,NU      ,NU      ,NU      ,PC      , // LDA
  L0|MI|AO,NI|XO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|YO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,NI|AO   ,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // ADD
  PC      ,L0|MI|AO,NI|VO   ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // ADD
  L0|MI|AO,L1|NI|XO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|YO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|AO,L1|L0|AI,NU      ,NU      ,NU      ,NU      ,PC      , // SUB
  PC      ,L0|MI|AO,L1|NI|VO,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SUB
  L0|MI|AO,L1|NI|XO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|YO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|AO,L1      ,L1|L0|AI,NU      ,NU      ,NU      ,PC      , // SHR
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // SHR
  L0|MI|AO,L1|NI|XO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|YO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  L0|MI|AO,L1|NI|AO,L1      ,L1      ,L1|L0|AI,NU      ,NU      ,PC      , // NND
  PC      ,L0|MI|AO,L1|NI|VO,L1      ,L1      ,L1|L0|AI,NU      ,PC        // NND
};

#endif