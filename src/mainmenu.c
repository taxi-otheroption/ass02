#include "cprocessing.h"
#include "mainmenu.h"

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
    // set the background color to gray
    CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));
    // Rectangle colour = red
    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
    // Draw rectangle
    CP_Graphics_DrawRect(800.0f, 250.0f, 300.0f, 200.0f);
    CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
    // Draw rectangle
    CP_Graphics_DrawRect(800.0f, 650.0f, 300.0f, 200.0f);
    CP_Settings_Fill(CP_Color_Create(1, 2, 3, 255));
    CP_Font_Set(myFont);
    CP_Font_DrawText("Play", 730, 270);
    CP_Font_Set(myFont);
    CP_Font_DrawText("Exit", 740, 670);
    if (CP_Input_KeyDown(KEY_Q))
    {
        CP_Engine_Terminate();
    }
}
   


void Main_Menu_Exit(void)
{

}