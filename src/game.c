#include "cprocessing.h"
#include "utils.h"

float test = 100.0f;
BOOL pressed = FALSE;

void Game_Init(void)
{
	

}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Graphics_DrawCircle(test, 100.0, 50.0f);
	if (IsCircleClicked(100.0f, 100.0f, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		pressed = TRUE;
	}
	if (pressed == TRUE)

	{
		if (CP_Input_KeyDown(KEY_D))
		{
			test += 10.0;
		}
		
	}
	
	// draw a circle at the mouse position
	
}

void Game_Exit(void)
{

}