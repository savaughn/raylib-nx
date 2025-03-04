/*******************************************************************************************
*
*   raylib [core] example - Gamepad input
*
*   NOTE: This example requires a Gamepad connected to the system
*         raylib is configured to work with the following gamepads:
*                - Xbox 360 Controller (Xbox 360, Xbox One)
*                - PLAYSTATION(R)3 Controller
*         Check raylib.h for buttons configuration
*
*   Example originally created with raylib 1.1, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <switch.h>

// NOTE: Gamepad name ID depends on drivers and OS
#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
    #define XBOX360_NAME_ID     "Xbox 360 Controller"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    romfsInit();
    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Set MSAA 4X hint before windows creation

    InitWindow(screenWidth, screenHeight, "raylib [core] example - gamepad input");

    Texture2D texPs3Pad = LoadTexture("romfs:/resources/ps3.png");
    Texture2D texXboxPad = LoadTexture("romfs:/resources/xbox.png");
    Texture2D texNinProPad = LoadTexture("romfs:/resources/switch_pro.png");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // ...
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (IsGamepadAvailable(0))
            {
                DrawText(TextFormat("GP1: %s", GetGamepadName(0)), 10, 10, 10, BLACK);
                if (TextIsEqual(GetGamepadName(0), XBOX360_NAME_ID) || TextIsEqual(GetGamepadName(0), XBOX360_LEGACY_NAME_ID))
                {
                    DrawTexture(texXboxPad, 0, 0, DARKGRAY);

                    // Draw buttons: xbox home
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(394, 89, 19, RED);

                    // Draw buttons: basic
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawCircle(436, 150, 9, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawCircle(352, 150, 9, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(501, 151, 15, BLUE);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(536, 187, 15, LIME);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(572, 151, 15, MAROON);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(536, 115, 15, GOLD);

                    // Draw buttons: d-pad
                    DrawRectangle(317, 202, 19, 71, BLACK);
                    DrawRectangle(293, 228, 69, 19, BLACK);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(317, 202, 19, 26, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(317, 202 + 45, 19, 26, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(292, 228, 25, 19, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(292 + 44, 228, 26, 19, RED);

                    // Draw buttons: left-right back
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(259, 61, 20, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(536, 61, 20, RED);

                    // Draw axis: left joystick
                    DrawCircle(259, 152, 39, BLACK);
                    DrawCircle(259, 152, 34, LIGHTGRAY);
                    DrawCircle(259 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X)*20),
                            152 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y)*20), 25, BLACK);

                    // Draw axis: right joystick
                    DrawCircle(450, 240, 60, BLACK);
                    DrawCircle(450, 240, 33, LIGHTGRAY);
                    DrawCircle(450 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*20),
                            240 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*20), 25, BLACK);

                    // Draw axis: left-right triggers
                    DrawRectangle(170, 30, 15, 70, GRAY);
                    DrawRectangle(604, 30, 15, 70, GRAY);
                    DrawRectangle(170, 30, 15, (int)(((1 + GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER))/2)*70), RED);
                    DrawRectangle(604, 30, 15, (int)(((1 + GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER))/2)*70), RED);

                    //DrawText(TextFormat("Xbox axis LT: %02.02f", GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER)), 10, 40, 10, BLACK);
                    //DrawText(TextFormat("Xbox axis RT: %02.02f", GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER)), 10, 60, 10, BLACK);
                }
                else if (TextIsEqual(GetGamepadName(0), PS3_NAME_ID))
                {
                    DrawTexture(texPs3Pad, 0, 0, DARKGRAY);

                    // Draw buttons: ps
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(396, 222, 13, RED);

                    // Draw buttons: basic
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawRectangle(328, 170, 32, 13, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawTriangle((Vector2){ 436, 168 }, (Vector2){ 436, 185 }, (Vector2){ 464, 177 }, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(557, 144, 13, LIME);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(586, 173, 13, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(557, 203, 13, VIOLET);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(527, 173, 13, PINK);

                    // Draw buttons: d-pad
                    DrawRectangle(225, 132, 24, 84, BLACK);
                    DrawRectangle(195, 161, 84, 25, BLACK);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(225, 132, 24, 29, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(225, 132 + 54, 24, 30, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(195, 161, 30, 25, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(195 + 54, 161, 30, 25, RED);

                    // Draw buttons: left-right back buttons
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(239, 82, 20, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(557, 82, 20, RED);

                    // Draw axis: left joystick
                    DrawCircle(319, 255, 35, BLACK);
                    DrawCircle(319, 255, 31, LIGHTGRAY);
                    DrawCircle(319 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) * 20),
                            255 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) * 20), 25, BLACK);

                    // Draw axis: right joystick
                    DrawCircle(475, 255, 35, BLACK);
                    DrawCircle(475, 255, 31, LIGHTGRAY);
                    DrawCircle(475 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X) * 20),
                            255 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) * 20), 25, BLACK);

                    // Draw axis: left-right triggers
                    DrawRectangle(169, 48, 15, 70, GRAY);
                    DrawRectangle(611, 48, 15, 70, GRAY);
                    DrawRectangle(169, 48, 15, (int)(((1 - GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER)) / 2) * 70), RED);
                    DrawRectangle(611, 48, 15, (int)(((1 - GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER)) / 2) * 70), RED);
                }
                else if (TextIsEqual(GetGamepadName(0), "Nintendo Switch Pro Controller"))
                {
                    DrawTexture(texNinProPad, screenWidth/2 - 400, screenHeight/2 - 352, DARKGRAY);

                    // Draw buttons: basic
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT)) DrawCircle(screenWidth/2 + 92, 192, 15, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_LEFT)) DrawCircle(screenWidth/2 - 99, 192, 15, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) DrawCircle(screenWidth/2 + 143, 252, 25, GREEN);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) DrawCircle(screenWidth/2 + 205, 308, 25, YELLOW);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) DrawCircle(screenWidth/2 + 267, 252, 25, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP)) DrawCircle(screenWidth/2 + 205, 196, 25, BLUE);

                    // Draw buttons: d-pad
                    // DrawRectangle(317, 202, 19, 71, BLACK);
                    // DrawRectangle(293, 228, 69, 19, BLACK);
                    DrawRectangle(499, 305, 40, 115, GRAY);
                    DrawRectangle(460, 346, 115, 40, GRAY);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) DrawRectangle(499, 305, 40, 30, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) DrawRectangle(499, 396, 40, 30, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) DrawRectangle(459, 346, 25, 40, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) DrawRectangle(550, 346, 26, 40, RED);

                    // Draw buttons: left-right back
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) DrawCircle(259 + 230, 61, 20, RED);
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) DrawCircle(536 + 230, 61, 20, RED);

                    // Draw axis: left joystick
                    DrawCircle(421, 251, 70, BLACK);
                    DrawCircle(421, 251, 65, LIGHTGRAY);
                    DrawCircle(421 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X)*20),
                            251 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y)*-20), 35, BLACK);

                    // Draw axis: right joystick
                    DrawCircle(screenWidth/2 + 103, 360, 70, BLACK);
                    DrawCircle(screenWidth/2 + 103, 360, 65, LIGHTGRAY);
                    DrawCircle(screenWidth/2 + 103 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*20),
                            360 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*-20), 35, BLACK);

                    // joystick down press
                    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB)) DrawCircle(421 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X)*20),
                        251 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y)*-20), 35, RED);
                    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_THUMB)) DrawCircle(screenWidth/2 + 103 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*20),
                            360 + (int)(GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*-20), 35, RED);

                    // Draw axis: left-right triggers
                    DrawRectangle(170 + 230, 30, 15, 70, GRAY);
                    DrawRectangle(604 + 230, 30, 15, 70, GRAY);
                    DrawRectangle(170 + 230, 30, 15, (int)(((1 + GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER))/2)*70), RED);
                    DrawRectangle(604 + 230, 30, 15, (int)(((1 + GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER))/2)*70), RED);

                    //DrawText(TextFormat("Xbox axis LT: %02.02f", GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER)), 10, 40, 10, BLACK);
                    //DrawText(TextFormat("Xbox axis RT: %02.02f", GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER)), 10, 60, 10, BLACK);
                }
                else
                {
                    DrawText("- GENERIC GAMEPAD -", 280, 180, 20, GRAY);

                    // TODO: Draw generic gamepad
                }

                DrawText(TextFormat("DETECTED AXIS [%i]:", GetGamepadAxisCount(0)), 10, 50, 10, MAROON);

                for (int i = 0; i < GetGamepadAxisCount(0); i++)
                {
                    DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);
                }

                if (GetGamepadButtonPressed() != -1) DrawText(TextFormat("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RED);
                else DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY);
            }
            else
            {
                DrawText("GP1: NOT DETECTED", 10, 10, 10, GRAY);

                DrawTexture(texXboxPad, 0, 0, LIGHTGRAY);
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texPs3Pad);
    UnloadTexture(texXboxPad);
    UnloadTexture(texNinProPad);

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    romfsExit();
    return 0;
}
