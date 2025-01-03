// These are special "ZEROPAGE" variables. They are faster to access, but there is very limited space for them.
// (255 bytes, many of which are used by the engine)
// Convert your most heavily used variables using the ZEROPAGE_DEF method. 
// (Usage: ZEROPAGE_DEF(type, variableName) ; eg ZEROPAGE_DEF(int, myInt))
// Note: Be sure to also update `globals.h` with these variables, so you can use them everywhere.
#include "source/c/library/bank_helpers.h"

ZEROPAGE_DEF(unsigned char, i);
ZEROPAGE_DEF(unsigned char, j);

ZEROPAGE_DEF(unsigned char, playerHealth);
ZEROPAGE_DEF(unsigned char, playerScoreCount);
ZEROPAGE_DEF(unsigned char, playerKeyCount);
ZEROPAGE_DEF(unsigned char, playerBombCount);
ZEROPAGE_DEF(unsigned char, playerMaxHealth);
ZEROPAGE_DEF(unsigned char, playerSelectedItem);
ZEROPAGE_DEF(unsigned char, playerHasSword);
ZEROPAGE_DEF(unsigned char, playerHasBomb);
ZEROPAGE_DEF(unsigned char, playerHasMagic);
ZEROPAGE_DEF(unsigned char, gameState);
ZEROPAGE_DEF(unsigned char, currentWorldId);

ZEROPAGE_DEF(unsigned char, charoffset);
ZEROPAGE_ARRAY_DEF(unsigned char, screenBuffer, 0x40);

ZEROPAGE_DEF(unsigned char, everyOtherCycle);

ZEROPAGE_DEF(unsigned char, controllerState);
ZEROPAGE_DEF(unsigned char, lastControllerState);

ZEROPAGE_DEF(unsigned char, tempChar1);
ZEROPAGE_DEF(unsigned char, tempChar2);
ZEROPAGE_DEF(unsigned char, tempChar3);
ZEROPAGE_DEF(unsigned char, tempChar4);
ZEROPAGE_DEF(unsigned char, tempChar5);
ZEROPAGE_DEF(unsigned char, tempChar6);
ZEROPAGE_DEF(unsigned char, tempChar7);
ZEROPAGE_DEF(unsigned char, tempChar8);
ZEROPAGE_DEF(unsigned char, tempChar9);
ZEROPAGE_DEF(unsigned char, tempChara);

ZEROPAGE_DEF(int, tempInt1);
ZEROPAGE_DEF(int, tempInt2);
ZEROPAGE_DEF(int, tempInt3);
ZEROPAGE_DEF(int, tempInt4);
ZEROPAGE_DEF(int, tempInt5);
ZEROPAGE_DEF(int, tempInt6);

// This can be used to convert a byte value to a bit id - just get the 
const unsigned int bitToByte[8] = {
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80
};
