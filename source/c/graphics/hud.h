// Some defines for the elements in the HUD
#define PRG_BANK_HUD 2

#define HUD_POSITION_START 0x0300
#define HUD_HEART_START 0x0321
#define HUD_SCORE_START 0x0361
#define HUD_KEY_START 0x0381
#define HUD_INVENTORY_START 0x035a
#define HUD_ATTRS_START 0x03f0

#define HUD_TILE_HEART 0xd4
#define HUD_TILE_HEART_EMPTY 0xd5
#define HUD_TILE_SCORE 0xd6
#define HUD_TILE_KEY 0xd7
#define HUD_TILE_SWORD 0xd8
#define HUD_TILE_BOMB 0xda
#define HUD_TILE_MAGIC 0xdb
#define HUD_TILE_ITEM_SEL 0xe6
#define HUD_TILE_ITEM_SER 0xe7
#define HUD_TILE_ITEM_UNL 0xe8
#define HUD_TILE_ITEM_UNR 0xe9
#define HUD_TILE_NUMBER 0xf6
#define HUD_TILE_BLANK 0xf2
#define HUD_TILE_BORDER_BL 0xf4
#define HUD_TILE_BORDER_BR 0xf5
#define HUD_TILE_BORDER_HORIZONTAL 0xe5
#define HUD_TILE_BORDER_VERTICAL 0xe4

#define HUD_SPRITE_ZERO_TILE_ID 0xfb

// Draw the HUD
void draw_hud(void);

// Update the number of hearts, coins, etc in the hud.
void update_hud(void);
