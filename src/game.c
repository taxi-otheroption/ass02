#include "cprocessing.h"
#include "utils.h"

float a_x = 100.0f;
float a_y = 100.0f;
float ta_tx = 100.0f;
float ta_rx = 123.0f;
float ta_lx = 77.0f;
float ta_ty = 77.0f;
float ta_ry = 110.0f;
float ta_ly = 110.0f;


float b_x = 500.0f;
float b_y = 100.0f;
float tb_tx = 500.0f;
float tb_rx = 523.0f;
float tb_lx = 477.0f;
float tb_ty = 77.0f;
float tb_ry = 110.0f;
float tb_ly = 110.0f;

float ta_dir = 90;
float tb_dir = 270;

BOOL a_pressed = FALSE;
BOOL b_pressed = FALSE;

void Game_Init(void)
{	

}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	CP_Settings_Fill(CP_Color_Create(255, 102, 255, 255));
	CP_Graphics_DrawCircle(a_x, a_y, 50.0f);
	CP_Settings_Fill(CP_Color_Create(0, 0, 204, 255));
	CP_Graphics_DrawCircle(b_x, b_y, 50.0f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawTriangleAdvanced(ta_tx, ta_ty, ta_rx, ta_ry, ta_lx, ta_ly, ta_dir);
	CP_Graphics_DrawTriangleAdvanced(tb_tx, tb_ty, tb_rx, tb_ry, tb_lx, tb_ly, tb_dir);
	if (IsCircleClicked(a_x, a_y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		a_pressed = TRUE;
		b_pressed = FALSE;
	}
	if (a_pressed == TRUE)

	{
		
		if (CP_Input_KeyDown(KEY_W))
		{
			a_y -= 3.0f;
			ta_ty -= 3.0f;
			ta_ry -= 3.0f;
			ta_ly -= 3.0f;
			ta_dir = 0.0f;
			
		}
		if (CP_Input_KeyDown(KEY_A))
		{
			a_x -= 3.0f;
			ta_tx -= 3.0f;
			ta_rx -= 3.0f;
			ta_lx -= 3.0f;
			ta_dir = 270.0f;
		}
		if (CP_Input_KeyDown(KEY_S))
		{
			a_y += 3.0f;
			ta_ty += 3.0f;
			ta_ry += 3.0f;
			ta_ly += 3.0f;
			ta_dir = 180.0f;
		}
		if (CP_Input_KeyDown(KEY_D))
		{
			a_x += 3.0f;
			ta_tx += 3.0f;
			ta_rx += 3.0f;
			ta_lx += 3.0f;
			ta_dir = 90.0f;
		}	
		b_x += 3.0f;
		tb_tx += 3.0f;
		tb_rx += 3.0f;
		tb_lx += 3.0f;
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
			b_y -= 3.0f;
			tb_ty -= 3.0f;
			tb_ry -= 3.0f;
			tb_ly -= 3.0f;
			tb_dir = 0.0f;
		}
		if (CP_Input_KeyDown(KEY_A))
		{
			b_x -= 3.0f;
			tb_tx -= 3.0f;
			tb_rx -= 3.0f;
			tb_lx -= 3.0f;
			tb_dir = 270.0f;

		}
		if (CP_Input_KeyDown(KEY_S))
		{
			b_y += 3.0f;
			tb_ty += 3.0f;
			tb_ry += 3.0f;
			tb_ly += 3.0f;
			tb_dir = 180.0f;
		}
		if (CP_Input_KeyDown(KEY_D))
		{
			b_x += 3.0f;
			tb_tx += 3.0f;
			tb_rx += 3.0f;
			tb_lx += 3.0f;
			tb_dir = 90.0f;
		}

		a_x += 3.0f;
		ta_tx += 3.0f;
		ta_rx += 3.0f;
		ta_lx += 3.0f;

	}
	
	// draw a circle at the mouse position
	
}

void Game_Exit(void)
{

}