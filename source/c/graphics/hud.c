#include "source/c/neslib.h"
#include "source/c/graphics/hud.h"
#include "source/c/globals.h"

CODE_BANK(PRG_BANK_HUD);

void draw_hud(void)
{
    // Draw the background and frame
    vram_adr(NAMETABLE_A + HUD_POSITION_START);
    for (i = 0; i != 160; ++i) { vram_put(HUD_TILE_BLANK); }
    vram_put(HUD_TILE_BORDER_BL);
    for (i = 0; i != 30; ++i) { vram_put(HUD_TILE_BORDER_HORIZONTAL); }
    vram_put(HUD_TILE_BORDER_BR);

    // I don't know what this is, I think it's the key counter
    vram_adr(NAMETABLE_A + HUD_ATTRS_START);
    for (i = 0; i != 16; ++i) { vram_put(0xff); }

    // Add additional STATIC HUD assets below this point
    // Inventory frames
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START);
    vram_put(HUD_TILE_ITEM_UNL);
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START+4);
    vram_put(HUD_TILE_ITEM_UNR);
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START+32);
    vram_put(HUD_TILE_ITEM_UNL);
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START+4+32);
    vram_put(HUD_TILE_ITEM_UNR);
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START+64);
    vram_put(HUD_TILE_ITEM_UNL);
    vram_adr(NAMETABLE_A + HUD_INVENTORY_START+4+64);
    vram_put(HUD_TILE_ITEM_UNR);
}

void update_hud(void)
{
    // Make sure we don't update vram while editing the screenBuffer array, or we could get visual glitches.
    set_vram_update(NULL);
    // This sets up screenBuffer to print x hearts, then x more empty hearts. 
    // You give it the address, tell it the direction to write, then follow up with
    // Ids, ending with NT_UPD_EOF
    // We use i for the index on screen buffer, so we don't have to shift things around
    // as we add values. 
    i = 0;

    // Hearts
    screenBuffer[i++] = MSB(NAMETABLE_A + HUD_HEART_START) | NT_UPD_HORZ;
    screenBuffer[i++] = LSB(NAMETABLE_A + HUD_HEART_START);
    // Length of tiles to update
    screenBuffer[i++] = playerMaxHealth;
    // Add one heart for every health the player has
    for (j = 0; j != playerHealth; ++j) { screenBuffer[i++] = HUD_TILE_HEART; }
    // Using the same variable, add empty hearts up to max health
    for (; j != playerMaxHealth; ++j) { screenBuffer[i++] = HUD_TILE_HEART_EMPTY; }

    // Score
    screenBuffer[i++] = MSB(NAMETABLE_A + HUD_SCORE_START) | NT_UPD_HORZ;
    screenBuffer[i++] = LSB(NAMETABLE_A + HUD_SCORE_START);
    screenBuffer[i++] = 2;
    screenBuffer[i++] = HUD_TILE_SCORE;
    screenBuffer[i++] = HUD_TILE_NUMBER + playerScoreCount;

    // Keys
    // Next, draw the key count, using the key tile, and our key count variable
    screenBuffer[i++] = MSB(NAMETABLE_A + HUD_KEY_START) | NT_UPD_HORZ;
    screenBuffer[i++] = LSB(NAMETABLE_A + HUD_KEY_START);
    screenBuffer[i++] = 2;
    screenBuffer[i++] = HUD_TILE_KEY;
    screenBuffer[i++] = HUD_TILE_NUMBER + playerKeyCount;

    // Selected items
    // Item SWORD
    /*charoffset = 0;
    for (j = 0; j != 6; j++)
    {
        screenBuffer[i++] = MSB(NAMETABLE_A + HUD_INVENTORY_START + charoffset) | NT_UPD_HORZ;
        screenBuffer[i++] = LSB(NAMETABLE_A + HUD_INVENTORY_START + charoffset);
        screenBuffer[i++] = 1;
        if (j == 0 || j == 2 || j == 4)
        {
            screenBuffer[i++] = HUD_TILE_ITEM_UNL;
            charoffset += 4;
        }
        else ()
        {
            screenBuffer[i++] = HUD_TILE_ITEM_UNR;
            charoffset += 4+32;
        }
    }*/



    screenBuffer[i++] = NT_UPD_EOF;
    set_vram_update(screenBuffer);
}
