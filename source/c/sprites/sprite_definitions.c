#include "source/c/sprites/sprite_definitions.h"

// NOTE: All of this data is in the primary bank.

// Put all newly-designed sprites here. 8 Bytes per sprite, defined mostly from constants
// in sprite_definitions.h. The 8 bytes are: 
// 1st byte: Sprite type 
// 2nd byte: Tile id for first tile, using 8x8 grid. See the guide for more detail on this.
// 3rd byte: Split; contains sprite size and palette. Combine the constants
//           using the logical OR operator (represented by the bar character: |) 
// 4th byte: Animation type
// 5th byte: How the sprite moves.
// 6th-8th byte: Miscellaneous; you can use this for whatever extra data you need. For enemies, byte 5
//           is used as the damage they deal. Health powerups use byte 5 to store how much to restore. 
//           Byte 6 is used for movement speed on enemies and npcs.
//           Byte 7 is used for health on enemy sprites in our `add_sword` branch.
// NOTE: This array cannot contain more than 64 sprites, or other logic will break.

// ORDER
// Collectables
// Level Elements
// Pawns
// Attacks
const unsigned char spriteDefinitions[] = {
    SPRITE_TYPE_HEALTH, 0x08, SPRITE_SIZE_8PX_8PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 1, 0x00, 0x00,
    SPRITE_TYPE_KEY, 0x09, SPRITE_SIZE_8PX_8PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_COIN, 0x18, SPRITE_SIZE_8PX_8PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 5, 0x00, 0x00,
    SPRITE_TYPE_ENDGAME, 0x28, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_SWORD, 0x48, SPRITE_SIZE_8PX_8PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_BOMB_ITEM, 0x58, SPRITE_SIZE_8PX_8PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_DOOR, 0x0a, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_DOOR_OPEN, 0x0c, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_DOOR_LOCKED, 0x2a, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_DOOR_BOSS, 0x2c, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x00, 0x00, 0x00,
    SPRITE_TYPE_NPC, 0x00, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_0, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 0x01, 14, 0x00,
    SPRITE_TYPE_REGULAR_ENEMY, 0x40, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_1, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 1, 14, 1,
    SPRITE_TYPE_INVULNERABLE_ENEMY, 0x40, SPRITE_SIZE_16PX_16PX | SPRITE_PALETTE_1, SPRITE_ANIMATION_NONE, SPRITE_MOVEMENT_NONE, 1, 14, 1
};
