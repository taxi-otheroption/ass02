#include <math.h>
#include "cprocessing.h"
#include "game.h"

//int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
//{
//    if ((CP_Input_GetMouseX() > 650.0f && CP_Input_GetMouseX() < 950.0f) && (CP_Input_GetMouseY() > 150.0f && CP_Input_GetMouseY() < 350.0f))
//    {
//        if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
//        {
//            CP_Graphics_DrawLine(click_x, click_y, CP_Input_GetMousePreviousX(), CP_Input_GetMousePreviousY());
//            CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Update);
//            CP_System_SetWindowSize(1600, 900);
//            CP_Engine_Run(0);
//        }
//
//    }
//}

void IsAreaClicked(float xl, float xh, float yl, float yh, float click_x, float click_y)
{
	    if ((click_x > xl && click_x < xh) && (click_y > yl && click_y < yh))
        {
            if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
            {
                //CP_Graphics_DrawLine(click_x, click_y, CP_Input_GetMousePreviousX(), CP_Input_GetMousePreviousY());
                CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Update);
                CP_System_SetWindowSize(1600, 900);
                CP_Engine_Run(0);
            }

        }

}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
}

