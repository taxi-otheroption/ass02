#include "cprocessing.h"
#include "utils.h"

float a_x = 100.0f;
float a_y = 100.0f;

float b_x = 500.0f;
float b_y = 100.0f;

BOOL a_pressed = FALSE;
BOOL b_pressed = FALSE;

void Game_Init(void)
{
	

}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Graphics_DrawCircle(a_x, a_y, 50.0f);
	CP_Graphics_DrawCircle(b_x, b_y, 50.0f);
	if (IsCircleClicked(a_x, a_y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		a_pressed = TRUE;
		b_pressed = FALSE;
	}
	if (a_pressed == TRUE)

	{
		
		if (CP_Input_KeyDown(KEY_W))
		{
			a_y -= 2.0;
		}
		if (CP_Input_KeyDown(KEY_A))
		{
			a_x -= 2.0;
		}
		if (CP_Input_KeyDown(KEY_S))
		{
			a_y += 2.0;
		}
		if (CP_Input_KeyDown(KEY_D))
		{
			a_x += 2.0;
		}	
		b_x += 2.0f;
	}
	if (IsCircleClicked(b_x, b_y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		b_pressed = TRUE;
		a_pressed = FALSE;
	}
	if (b_pressed == TRUE)
	{
		if (CP_Input_KeyDown(KEY_W))
		{
			b_y -= 2.0;
		}
		if (CP_Input_KeyDown(KEY_A))
		{
			b_x -= 2.0;
		}
		if (CP_Input_KeyDown(KEY_S))
		{
			b_y += 2.0;
		}
		if (CP_Input_KeyDown(KEY_D))
		{
			b_x += 2.0;
		}

		a_x += 2.0f;

	}
	
	// draw a circle at the mouse position
	
}

void Game_Exit(void)
{

}