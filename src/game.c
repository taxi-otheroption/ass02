#include "cprocessing.h"
#include "utils.h"

float a_x;
float a_y;
float ta_tx;
float ta_rx;
float ta_lx;
float ta_ty;
float ta_ry;
float ta_ly;
float ax_speed;
float ay_speed;


float b_x;
float b_y;
float tb_tx;
float tb_rx;
float tb_lx;
float tb_ty;
float tb_ry;
float tb_ly;
float bx_speed;

float ta_dir;
float tb_dir;

BOOL a_pressed;
BOOL b_pressed;

void Game_Init(void)
{	
	a_x = 100.0f;
	a_y = 100.0f;
	ta_tx = 100.0f;
	ta_rx = 123.0f;
	ta_lx = 77.0f;
	ta_ty = 77.0f;
	ta_ry = 110.0f;
	ta_ly = 110.0f;
	ax_speed = 3.0f;
	bx_speed = 3.0f;


	b_x = 500.0f;
	b_y = 100.0f;
	tb_tx = 500.0f;
	tb_rx = 523.0f;
	tb_lx = 477.0f;
	tb_ty = 77.0f;
	tb_ry = 110.0f;
	tb_ly = 110.0f;

	ta_dir = 90;
	tb_dir = 270;

	a_pressed = FALSE;
	b_pressed = FALSE;
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
		if (IsWithinBoundary(b_x, b_y, a_x, a_y) == 1)
		{
			bx_speed *= -1.0f;
			tb_dir += 180.0f;
		}
		if (b_x < 25 || b_x > 1575)
		{
			bx_speed *= -1.0f;
			tb_dir += 180.0f;
		}
		b_x += bx_speed;
		tb_tx += bx_speed;
		tb_rx += bx_speed;
		tb_lx += bx_speed;
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
		if (IsWithinBoundary(a_x, a_y, b_x, b_y) == 1)
		{
			ax_speed *= -1.0f;
			ta_dir += 180.0f;
		}
		if (a_x < 25 || a_x > 1575)
		{
			ax_speed *= -1.0f;
			ta_dir += 180.0f;
		}
		a_x += ax_speed;
		ta_tx += ax_speed;
		ta_rx += ax_speed;
		ta_lx += ax_speed;

	}
		





}

void Game_Exit(void)
{

}