#include "cprocessing.h"
#include "game.h"
#include "utils.h"

CP_Font myFont;
float textSize;

void Main_Menu_Init(void)
{
    myFont = CP_Font_Load("Assets/Exo2-Regular.ttf");
    textSize = 80.0f;
    CP_Settings_TextSize(textSize);
    
}

void Main_Menu_Update(void)
{
    CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
    CP_Settings_Fill(CP_Color_Create(255, 153, 153, 255));
    CP_Graphics_DrawRect(800.0f, 250.0f, 300.0f, 200.0f);
    CP_Graphics_DrawRect(800.0f, 650.0f, 300.0f, 200.0f);
    CP_Settings_Fill(CP_Color_Create(1, 2, 3, 255));
    CP_Font_Set(myFont);
    CP_Font_DrawText("Play", 730, 270);
    CP_Font_Set(myFont);
    CP_Font_DrawText("Exit", 740, 670);
    if (IsAreaClicked(800.0f, 250.0f, 300.0f, 200.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
    {
        CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Exit);
    }  
    if (IsAreaClicked(800.0f, 650.0f, 300.0f, 200.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()))
    {
        CP_Engine_Terminate();
    }
    if (CP_Input_KeyDown(KEY_Q))
    {
        CP_Engine_Terminate();
    }
}

void Main_Menu_Exit(void)
{

}