#include "source/c/menus/credits.h"
#include "graphics/palettes/palettes.config.h"
#include "source/c/configuration/system_constants.h"
#include "source/c/globals.h"
#include "source/c/neslib.h"
#include "source/c/configuration/game_states.h"
#include "source/c/menus/text_helpers.h"
#include "source/c/configuration/game_info.h"

CODE_BANK(PRG_BANK_CREDITS_MENU);

void draw_win_screen(void) {
    set_vram_update(NULL);
    ppu_off();
    clear_screen();
    // We reuse the title palette here, though we have the option of making our own if needed.
    pal_bg(titlePalette);
    pal_spr(titlePalette);
    scroll(0, 0);

    set_chr_bank_0(CHR_BANK_MENU);
    set_chr_bank_1(CHR_BANK_MENU);

    // Add whatever you want here; NTADR_A just picks a position on the screen for you. Your options are 0, 0 to 32, 30
    put_str(NTADR_A(7, 2), "- Congratulations -");

    put_str(NTADR_A(6, 8), "You've recovered the");
    put_str(NTADR_A(8, 9), "Ember Artifact");
    put_str(NTADR_A(6, 10), "and sealed away the");
    put_str(NTADR_A(8, 11), "last nightfaller!");
    put_str(NTADR_A(6, 12), "The land of riven");
    put_str(NTADR_A(8, 13), "has been saved...");
    put_str(NTADR_A(7, 15), "- until next time -");

    // Hide all existing sprites
    oam_clear();
    ppu_on_all();

}

void draw_credits_screen(void) {
    set_vram_update(NULL);
    ppu_off();
    clear_screen();
    // We reuse the title palette here, though we have the option of making our own if needed.
    pal_bg(titlePalette);
    pal_spr(titlePalette);
    scroll(0, 0);

    set_chr_bank_0(CHR_BANK_MENU);
    set_chr_bank_1(CHR_BANK_MENU);

    // Add whatever you want here; NTADR_A just picks a position on the screen for you. Your options are 0, 0 to 32, 30
    put_str(NTADR_A(10, 2), "- Credits -");

    put_str(NTADR_A(2, 6), "Programming & Artwork");
    put_str(NTADR_A(4, 8), "Liz M.");

    put_str(NTADR_A(2, 11), "Music");
    put_str(NTADR_A(4, 13), "Alex P.");

    put_str(NTADR_A(5, 21), "Thank you for playing!");

    put_str(NTADR_A(6, 25), "Created in");
    put_str(NTADR_A(17, 25), currentYear);
    put_str(NTADR_A(22, 25), "by");

    put_str(NTADR_A(11, 27), gameAuthor);


    // Hide all existing sprites
    oam_clear();
    ppu_on_all();
}
