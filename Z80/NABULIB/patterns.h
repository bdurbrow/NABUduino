#ifndef PATTERNS_H
#define PATTERNS_H

// Uncomment only one of the fonts that you wish to use
// If you with to use your own font, specify the font as a const uint8_t[768] before the #include "tms9918.h" in your code
// --------------------------------------------------------------------------------------------------------------------------
//#define FONT_AMIGA
//#define FONT_SET1
#define FONT_STANDARD


#ifdef FONT_AMIGA
const uint8_t  ASCII[768] = {
   0, 0, 0, 0, 0, 0, 0, 0,
   24, 60, 60, 24, 24, 0, 24, 0,
   108, 108, 0, 0, 0, 0, 0, 0,
   108, 108, 254, 108, 254, 108, 108, 0,
   24, 62, 96, 60, 6, 124, 24, 0,
   0, 198, 204, 24, 48, 102, 198, 0,
   56, 108, 104, 118, 220, 204, 118, 0,
   24, 24, 48, 0, 0, 0, 0, 0,
   12, 24, 48, 48, 48, 24, 12, 0,
   48, 24, 12, 12, 12, 24, 48, 0,
   0, 102, 60, 255, 60, 102, 0, 0,
   0, 24, 24, 126, 24, 24, 0, 0,
   0, 0, 0, 0, 0, 24, 24, 48,
   0, 0, 0, 126, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 24, 24, 0,
   3, 6, 12, 24, 48, 96, 192, 0,
   60, 102, 110, 126, 118, 102, 60, 0,
   24, 56, 24, 24, 24, 24, 126, 0,
   60, 102, 6, 28, 48, 102, 126, 0,
   60, 102, 6, 28, 6, 102, 60, 0,
   28, 60, 108, 204, 254, 12, 30, 0,
   126, 96, 124, 6, 6, 102, 60, 0,
   28, 48, 96, 124, 102, 102, 60, 0,
   126, 102, 6, 12, 24, 24, 24, 0,
   60, 102, 102, 60, 102, 102, 60, 0,
   60, 102, 102, 62, 6, 12, 56, 0,
   0, 24, 24, 0, 0, 24, 24, 0,
   0, 24, 24, 0, 0, 24, 24, 48,
   12, 24, 48, 96, 48, 24, 12, 0,
   0, 0, 126, 0, 0, 126, 0, 0,
   48, 24, 12, 6, 12, 24, 48, 0,
   60, 102, 6, 12, 24, 0, 24, 0,
   124, 198, 222, 222, 222, 192, 120, 0,
   24, 60, 60, 102, 126, 195, 195, 0,
   252, 102, 102, 124, 102, 102, 252, 0,
   60, 102, 192, 192, 192, 102, 60, 0,
   248, 108, 102, 102, 102, 108, 248, 0,
   254, 102, 96, 120, 96, 102, 254, 0,
   254, 102, 96, 120, 96, 96, 240, 0,
   60, 102, 192, 206, 198, 102, 62, 0,
   102, 102, 102, 126, 102, 102, 102, 0,
   126, 24, 24, 24, 24, 24, 126, 0,
   14, 6, 6, 6, 102, 102, 60, 0,
   230, 102, 108, 120, 108, 102, 230, 0,
   240, 96, 96, 96, 98, 102, 254, 0,
   130, 198, 238, 254, 214, 198, 198, 0,
   198, 230, 246, 222, 206, 198, 198, 0,
   56, 108, 198, 198, 198, 108, 56, 0,
   252, 102, 102, 124, 96, 96, 240, 0,
   56, 108, 198, 198, 198, 108, 60, 6,
   252, 102, 102, 124, 108, 102, 227, 0,
   60, 102, 112, 56, 14, 102, 60, 0,
   126, 90, 24, 24, 24, 24, 60, 0,
   102, 102, 102, 102, 102, 102, 62, 0,
   195, 195, 102, 102, 60, 60, 24, 0,
   198, 198, 198, 214, 254, 238, 198, 0,
   195, 102, 60, 24, 60, 102, 195, 0,
   195, 195, 102, 60, 24, 24, 60, 0,
   254, 198, 140, 24, 50, 102, 254, 0,
   60, 48, 48, 48, 48, 48, 60, 0,
   192, 96, 48, 24, 12, 6, 3, 0,
   60, 12, 12, 12, 12, 12, 60, 0,
   16, 56, 108, 198, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 254,
   24, 24, 12, 0, 0, 0, 0, 0,
   0, 0, 60, 6, 30, 102, 59, 0,
   224, 96, 108, 118, 102, 102, 60, 0,
   0, 0, 60, 102, 96, 102, 60, 0,
   14, 6, 54, 110, 102, 102, 59, 0,
   0, 0, 60, 102, 126, 96, 60, 0,
   28, 54, 48, 120, 48, 48, 120, 0,
   0, 0, 59, 102, 102, 60, 198, 124,
   224, 96, 108, 118, 102, 102, 230, 0,
   24, 0, 56, 24, 24, 24, 60, 0,
   6, 0, 6, 6, 6, 6, 102, 60,
   224, 96, 102, 108, 120, 108, 230, 0,
   56, 24, 24, 24, 24, 24, 60, 0,
   0, 0, 102, 119, 107, 99, 99, 0,
   0, 0, 124, 102, 102, 102, 102, 0,
   0, 0, 60, 102, 102, 102, 60, 0,
   0, 0, 220, 102, 102, 124, 96, 240,
   0, 0, 61, 102, 102, 62, 6, 7,
   0, 0, 236, 118, 102, 96, 240, 0,
   0, 0, 62, 96, 60, 6, 124, 0,
   16, 48, 124, 48, 48, 52, 24, 0,
   0, 0, 204, 204, 204, 204, 118, 0,
   0, 0, 204, 204, 204, 120, 48, 0,
   0, 0, 198, 214, 214, 108, 108, 0,
   0, 0, 99, 54, 28, 54, 99, 0,
   0, 0, 102, 102, 102, 60, 24, 112,
   0, 0, 126, 76, 24, 50, 126, 0,
   14, 24, 24, 112, 24, 24, 14, 0,
   24, 24, 24, 24, 24, 24, 24, 0,
   112, 24, 24, 14, 24, 24, 112, 0,
   114, 156, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
};
#endif

#ifdef FONT_SET1
const uint8_t  ASCII[768] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /*Blank*/
  0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00, /*!*/
  0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00, /*"*/
  0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00, /*#*/
  0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,0x00, /*$*/
  0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00, /*%*/
  0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00, /*&*/
  0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00, /*'*/
  0x20,0x40,0x80,0x80,0x80,0x40,0x20,0x00, /*(*/
  0x20,0x10,0x08,0x08,0x08,0x10,0x20,0x00, /*)*/
  0x20,0xA8,0x70,0x20,0x70,0xA8,0x20,0x00, /***/
  0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00, /*+*/
  0x00,0x00,0x00,0x00,0x20,0x20,0x40,0x00, /*,*/
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00, /*-*/
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00, /*.*/
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00, /*/*/
  0x70,0x88,0x98,0xA8,0xC8,0x88,0x70,0x00, /*0*/
  0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00, /*1*/
  0x70,0x88,0x08,0x30,0x40,0x80,0xF8,0x00, /*2*/
  0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00, /*3*/
  0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00, /*4*/
  0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00, /*5*/
  0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00, /*6*/
  0xF8,0x08,0x10,0x20,0x40,0x40,0x40,0x00, /*7*/
  0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00, /*8*/
  0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00, /*9*/
  0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00, /*:*/
  0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00, /*;*/
  0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x00, /*<*/
  0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00, /*=*/
  0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, /*>*/
  0x70,0x88,0x10,0x20,0x20,0x00,0x20,0x00, /*?*/

  0x70,0x88,0xA8,0xB8,0xB0,0x80,0x78,0x00, /*@*/
  0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00, /*A*/
  0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00, /*B*/
  0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00, /*C*/
  0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00, /*D*/
  0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00, /*E*/
  0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00, /*F*/
  0x78,0x80,0x80,0x80,0x98,0x88,0x78,0x00, /*G*/
  0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00, /*H*/
  0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00, /*I*/
  0x08,0x08,0x08,0x08,0x08,0x88,0x70,0x00, /*J*/
  0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00, /*K*/
  0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00, /*L*/
  0x88,0xD8,0xA8,0xA8,0x88,0x88,0x88,0x00, /*M*/
  0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00, /*N*/
  0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00, /*O*/
  0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00, /*P*/
  0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00, /*Q*/
  0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00, /*R*/
  0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00, /*S*/
  0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x00, /*T*/
  0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00, /*U*/
  0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00, /*V*/
  0x88,0x88,0x88,0xA8,0xA8,0xD8,0x88,0x00, /*W*/
  0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00, /*X*/
  0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00, /*Y*/
  0xF8,0x08,0x10,0x20,0x40,0x80,0xF8,0x00, /*Z*/
  0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00, /*[*/
  0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00, /*\*/
  0xF0,0x10,0x10,0x10,0x10,0x10,0xF0,0x00, /*]*/
  0x00,0x00,0x20,0x50,0x88,0x00,0x00,0x00, /*^*/
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8, /*_*/
  0x40,0x20,0x10,0x00,0x00,0x00,0x00,0x00, /*`*/
  0x00,0x00,0x60,0x10,0x70,0x90,0x68,0x00, /*a*/
  0x80,0x80,0xB0,0xC8,0x88,0xC8,0xB0,0x00, /*b*/
  0x00,0x00,0x70,0x88,0x80,0x88,0x70,0x00, /*c*/
  0x08,0x08,0x78,0x88,0x88,0x88,0x78,0x00, /*d*/
  0x00,0x00,0x70,0x88,0xF8,0x80,0x78,0x00, /*e*/
  0x30,0x48,0x40,0xF0,0x40,0x40,0x40,0x00, /*f*/
  0x00,0x00,0x68,0x98,0x98,0x68,0x08,0xF0, /*g*/
  0x80,0x80,0xB0,0xC8,0x88,0x88,0x88,0x00, /*h*/
  0x20,0x00,0x60,0x20,0x20,0x20,0x70,0x00, /*i*/
  0x08,0x00,0x18,0x08,0x08,0x08,0x48,0x30, /*j*/
  0x80,0x80,0x88,0x90,0xA0,0xD0,0x88,0x00, /*k*/
  0x30,0x10,0x10,0x10,0x10,0x10,0x38,0x00, /*l*/
  0x00,0x00,0x50,0xF8,0xA8,0xA8,0xA8,0x00, /*m*/
  0x00,0x00,0xB0,0xC8,0x88,0x88,0x88,0x00, /*n*/
  0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00, /*o*/
  0x00,0x00,0xB0,0xC8,0xC8,0xB0,0x80,0x80, /*p*/
  0x00,0x00,0x68,0x98,0x98,0x68,0x08,0x08, /*q*/
  0x00,0x00,0xB0,0xC8,0x80,0x80,0x80,0x00, /*r*/
  0x00,0x00,0x70,0x80,0x70,0x08,0xF0,0x00, /*s*/
  0x40,0x40,0xF0,0x40,0x40,0x48,0x30,0x00, /*t*/
  0x00,0x00,0x88,0x88,0x88,0x98,0x68,0x00, /*u*/
  0x00,0x00,0x88,0x88,0x88,0x50,0x20,0x00, /*v*/
  0x00,0x00,0x88,0xA8,0xA8,0xA8,0x50,0x00, /*w*/
  0x00,0x00,0x88,0x50,0x20,0x50,0x88,0x00, /*x*/
  0x00,0x00,0x88,0x88,0x98,0x68,0x08,0x70, /*y*/
  0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00, /*z*/
  0x38,0x40,0x20,0xC0,0x20,0x40,0x38,0x00, /*{*/
  0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, /*>*/
  0xE0,0x10,0x20,0x18,0x20,0x10,0xE0,0x00, /*}*/
  0x40,0xA8,0x10,0x00,0x00,0x00,0x00,0x00, /*~*/
  0xA8,0x50,0xA8,0x50,0xA8,0x50,0xA8,0x00,
};
#endif


#ifdef FONT_STANDARD
const uint8_t  ASCII[768] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, /*Blank*/
  0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x00, /*!*/
  0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00, /*"*/
  0x50,0x50,0xF8,0x50,0xF8,0x50,0x50,0x00, /*#*/
  0x20,0x78,0xA0,0x70,0x28,0xF0,0x20,0x00, /*$*/
  0xC0,0xC8,0x10,0x20,0x40,0x98,0x18,0x00, /*%*/
  0x40,0xA0,0xA0,0x40,0xA8,0x90,0x68,0x00, /*&*/
  0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00, /*'*/
  0x20,0x40,0x80,0x80,0x80,0x40,0x20,0x00, /*(*/
  0x20,0x10,0x08,0x08,0x08,0x10,0x20,0x00, /*)*/
  0x20,0xA8,0x70,0x20,0x70,0xA8,0x20,0x00, /***/
  0x00,0x20,0x20,0xF8,0x20,0x20,0x00,0x00, /*+*/
  0x00,0x00,0x00,0x00,0x20,0x20,0x40,0x00, /*,*/
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00, /*-*/
  0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00, /*.*/
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00, /*/*/
  0x70,0x88,0x98,0xA8,0xC8,0x88,0x70,0x00, /*0*/
  0x20,0x60,0x20,0x20,0x20,0x20,0x70,0x00, /*1*/
  0x70,0x88,0x08,0x30,0x40,0x80,0xF8,0x00, /*2*/
  0xF8,0x08,0x10,0x30,0x08,0x88,0x70,0x00, /*3*/
  0x10,0x30,0x50,0x90,0xF8,0x10,0x10,0x00, /*4*/
  0xF8,0x80,0xF0,0x08,0x08,0x88,0x70,0x00, /*5*/
  0x38,0x40,0x80,0xF0,0x88,0x88,0x70,0x00, /*6*/
  0xF8,0x08,0x10,0x20,0x40,0x40,0x40,0x00, /*7*/
  0x70,0x88,0x88,0x70,0x88,0x88,0x70,0x00, /*8*/
  0x70,0x88,0x88,0x78,0x08,0x10,0xE0,0x00, /*9*/
  0x00,0x00,0x20,0x00,0x20,0x00,0x00,0x00, /*:*/
  0x00,0x00,0x20,0x00,0x20,0x20,0x40,0x00, /*;*/
  0x10,0x20,0x40,0x80,0x40,0x20,0x10,0x00, /*<*/
  0x00,0x00,0xF8,0x00,0xF8,0x00,0x00,0x00, /*=*/
  0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, /*>*/
  0x70,0x88,0x10,0x20,0x20,0x00,0x20,0x00, /*?*/

  0x70,0x88,0xA8,0xB8,0xB0,0x80,0x78,0x00, /*@*/
  0x20,0x50,0x88,0x88,0xF8,0x88,0x88,0x00, /*A*/
  0xF0,0x88,0x88,0xF0,0x88,0x88,0xF0,0x00, /*B*/
  0x70,0x88,0x80,0x80,0x80,0x88,0x70,0x00, /*C*/
  0xF0,0x88,0x88,0x88,0x88,0x88,0xF0,0x00, /*D*/
  0xF8,0x80,0x80,0xF0,0x80,0x80,0xF8,0x00, /*E*/
  0xF8,0x80,0x80,0xF0,0x80,0x80,0x80,0x00, /*F*/
  0x78,0x80,0x80,0x80,0x98,0x88,0x78,0x00, /*G*/
  0x88,0x88,0x88,0xF8,0x88,0x88,0x88,0x00, /*H*/
  0x70,0x20,0x20,0x20,0x20,0x20,0x70,0x00, /*I*/
  0x08,0x08,0x08,0x08,0x08,0x88,0x70,0x00, /*J*/
  0x88,0x90,0xA0,0xC0,0xA0,0x90,0x88,0x00, /*K*/
  0x80,0x80,0x80,0x80,0x80,0x80,0xF8,0x00, /*L*/
  0x88,0xD8,0xA8,0xA8,0x88,0x88,0x88,0x00, /*M*/
  0x88,0x88,0xC8,0xA8,0x98,0x88,0x88,0x00, /*N*/
  0x70,0x88,0x88,0x88,0x88,0x88,0x70,0x00, /*O*/
  0xF0,0x88,0x88,0xF0,0x80,0x80,0x80,0x00, /*P*/
  0x70,0x88,0x88,0x88,0xA8,0x90,0x68,0x00, /*Q*/
  0xF0,0x88,0x88,0xF0,0xA0,0x90,0x88,0x00, /*R*/
  0x70,0x88,0x80,0x70,0x08,0x88,0x70,0x00, /*S*/
  0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x00, /*T*/
  0x88,0x88,0x88,0x88,0x88,0x88,0x70,0x00, /*U*/
  0x88,0x88,0x88,0x88,0x88,0x50,0x20,0x00, /*V*/
  0x88,0x88,0x88,0xA8,0xA8,0xD8,0x88,0x00, /*W*/
  0x88,0x88,0x50,0x20,0x50,0x88,0x88,0x00, /*X*/
  0x88,0x88,0x50,0x20,0x20,0x20,0x20,0x00, /*Y*/
  0xF8,0x08,0x10,0x20,0x40,0x80,0xF8,0x00, /*Z*/
  0x78,0x40,0x40,0x40,0x40,0x40,0x78,0x00, /*[*/
  0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00, /*\*/
  0xF0,0x10,0x10,0x10,0x10,0x10,0xF0,0x00, /*]*/
  0x00,0x00,0x20,0x50,0x88,0x00,0x00,0x00, /*^*/
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8, /*_*/
  0x40,0x20,0x10,0x00,0x00,0x00,0x00,0x00, /*`*/
  0x00,0x00,0x70,0x88,0xF8,0x88,0x88,0x00, /*a*/
  0x00,0x00,0xF0,0x48,0x70,0x48,0xF0,0x00, /*b*/
  0x00,0x00,0x78,0x80,0x80,0x80,0x78,0x00, /*c*/
  0x00,0x00,0xF0,0x48,0x48,0x48,0xF0,0x00, /*d*/
  0x00,0x00,0xF0,0x80,0xE0,0x80,0xF0,0x00, /*e*/
  0x00,0x00,0xF0,0x80,0xE0,0x80,0x80,0x00, /*f*/
  0x00,0x00,0x78,0x80,0xB8,0x88,0x70,0x00, /*g*/
  0x00,0x00,0x88,0x88,0xF8,0x88,0x88,0x00, /*h*/
  0x00,0x00,0x70,0x20,0x20,0x20,0xF8,0x00, /*i*/
  0x00,0x00,0x70,0x20,0x20,0xA0,0xE0,0x00, /*j*/
  0x00,0x00,0x90,0xA0,0xC0,0xA0,0x90,0x00, /*k*/
  0x00,0x00,0x80,0x80,0x80,0x80,0xF8,0x00, /*l*/
  0x00,0x00,0x88,0xD8,0xA8,0x88,0x88,0x00, /*m*/
  0x00,0x00,0x88,0xC8,0xA8,0x98,0x88,0x00, /*n*/
  0x00,0x00,0x70,0x88,0x88,0x88,0x70,0x00, /*o*/
  0x00,0x00,0xF0,0x88,0xF0,0x80,0x80,0x00, /*p*/
  0x00,0x00,0xF8,0x88,0xA8,0x90,0xE8,0x00, /*q*/
  0x00,0x00,0xF8,0x88,0xF8,0xA0,0x90,0x00, /*r*/
  0x00,0x00,0x78,0x80,0x70,0x08,0xF0,0x00, /*s*/
  0x00,0x00,0xF8,0x20,0x20,0x20,0x20,0x00, /*t*/
  0x00,0x00,0x88,0x88,0x88,0x88,0x70,0x00, /*u*/
  0x00,0x00,0x88,0x88,0x90,0xA0,0x40,0x00, /*v*/
  0x00,0x00,0x88,0x88,0xA8,0xD8,0x88,0x00, /*w*/
  0x00,0x00,0x88,0x70,0x20,0x70,0x88,0x00, /*x*/
  0x00,0x00,0x88,0x50,0x20,0x20,0x20,0x00, /*y*/
  0x00,0x00,0xF8,0x10,0x20,0x40,0xF8,0x00, /*z*/
  0x38,0x40,0x20,0xC0,0x20,0x40,0x38,0x00, /*{*/
  0x40,0x20,0x10,0x08,0x10,0x20,0x40,0x00, /*>*/
  0xE0,0x10,0x20,0x18,0x20,0x10,0xE0,0x00, /*}*/
  0x40,0xA8,0x10,0x00,0x00,0x00,0x00,0x00, /*~*/
  0xA8,0x50,0xA8,0x50,0xA8,0x50,0xA8,0x00,
};
#endif

#endif

