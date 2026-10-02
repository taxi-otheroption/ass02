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
float ay_speed;


float b_x;
float b_y;
float tb_tx;
float tb_rx;
float tb_lx;
float tb_ty;
float tb_ry;
float tb_ly;

float ta_dir;
float tb_dir;

BOOL a_pressed;
BOOL b_pressed;
BOOL t;


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

	a_pressed = TRUE;
	b_pressed = FALSE;
	t = FALSE;
}


void Game_Update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 255));
	
	if (IsCircleClicked(a_x, a_y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		a_pressed = TRUE;
		b_pressed = FALSE;
	}
	if (a_pressed == TRUE)
	{		

		CP_Settings_Fill(CP_Color_Create(0, 0, 204, 255));
		CP_Graphics_DrawCircle(b_x, b_y, 50.0f);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Graphics_DrawTriangleAdvanced(
			tb_tx, tb_ty, tb_rx, tb_ry, tb_lx, tb_ly, tb_dir
		);
		CP_Settings_Fill(CP_Color_Create(255, 102, 255, 255));
		CP_Graphics_DrawCircle(a_x, a_y, 50.0f);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Graphics_DrawTriangleAdvanced(
			ta_tx, ta_ty, ta_rx, ta_ry, ta_lx, ta_ly, ta_dir
		);
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
		if (t == FALSE)
		{
			if (IsWithinBoundary(b_x, b_y, a_x, a_y) == 1)
			{
				if (a_x < b_x)
				{
					tb_dir = 90;
				}
				else if (a_x > b_x)
				{
					tb_dir = 270;
				}
			}
		}
		if (b_x <= 25 && t == FALSE)
		{
			if (IsWithinBoundary(b_x, b_y, a_x, a_y) == 1)
			{
				if (a_y > b_y)
				{
					tb_dir = 0;
					t = TRUE;
				}
				else
				{
					tb_dir = 180;
					t = TRUE;
				}
			}
			else
			{
				tb_dir = 90;
			}
		}
		if (b_x >= 1575 && t == FALSE)
		{
			if (IsWithinBoundary(b_x, b_y, a_x, a_y) == 1)
			{
				if (a_y > b_y)
				{
					tb_dir = 0;
					t = TRUE;
				}
				else
				{
					tb_dir = 180;
					t = TRUE;
				}
			}
			else
			{
				tb_dir = 270;
			}
		}
		if (tb_dir == 0 && b_y <= 25)
		{

			if (b_x <= 25)
			{
				tb_dir = 90;
			}
			else if (b_x >= 1575)
			{
				tb_dir = 270;
			}
			else
			{
				tb_dir = 270;
			}

			t = FALSE;
		}
		else if (tb_dir == 180 && b_y >= 875)
		{
			if (b_x <= 25)
			{
				tb_dir = 90;
			}
			else if (b_x >= 1575)
			{
				tb_dir = 270;
			}
			else
			{
				tb_dir = 90;
			}

			t = FALSE;
		}
		if (tb_dir == 90 && b_x < 1575)
		{
			b_x += 3.0f;
			tb_tx += 3.0f;
			tb_rx += 3.0f;
			tb_lx += 3.0f;
		}
		else if (tb_dir == 270 && b_x > 25)
		{
			b_x -= 3.0f;
			tb_tx -= 3.0f;
			tb_rx -= 3.0f;
			tb_lx -= 3.0f;
		}
		else if (tb_dir == 0 && b_y > 25)
		{
			b_y -= 3.0f;
			tb_ty -= 3.0f;
			tb_ry -= 3.0f;
			tb_ly -= 3.0f;
		}
		else if (tb_dir == 180 && b_y < 875)
		{
			b_y += 3.0f;
			tb_ty += 3.0f;
			tb_ry += 3.0f;
			tb_ly += 3.0f;
		}
	}
	if (IsCircleClicked(b_x, b_y, 50.0f, CP_Input_GetMouseX(), CP_Input_GetMouseY()) == 1)
	{
		b_pressed = TRUE;
		a_pressed = FALSE;
	}
	if (b_pressed == TRUE)
	{
		CP_Settings_Fill(CP_Color_Create(255, 102, 255, 255));
		CP_Graphics_DrawCircle(a_x, a_y, 50.0f);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Graphics_DrawTriangleAdvanced(
			ta_tx, ta_ty, ta_rx, ta_ry, ta_lx, ta_ly, ta_dir
		);
		CP_Settings_Fill(CP_Color_Create(0, 0, 204, 255));
		CP_Graphics_DrawCircle(b_x, b_y, 50.0f);

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
		CP_Graphics_DrawTriangleAdvanced(
			tb_tx, tb_ty, tb_rx, tb_ry, tb_lx, tb_ly, tb_dir
		);
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
		if (t == FALSE)
		{
			if (IsWithinBoundary(a_x, a_y, b_x, b_y) == 1)
			{
				if (b_x < a_x)
				{
					ta_dir = 90;
				}
				else if (b_x > a_x)
				{
					ta_dir = 270;
				}
			}
		}
		if (a_x <= 25 && t == FALSE)
		{
			if (IsWithinBoundary(a_x, a_y, b_x, b_y) == 1)
			{
				if (b_y > a_y)
				{
					ta_dir = 0;
					t = TRUE;
				}
				else
				{
					ta_dir = 180;
					t = TRUE;
				}
			}
			else
			{
				ta_dir = 90;
			}
		}
		if (a_x >= 1575 && t == FALSE)
		{
			if (IsWithinBoundary(a_x, a_y, b_x, b_y) == 1)
			{
				if (b_y > a_y)
				{
					ta_dir = 0;
					t = TRUE;
				}
				else
				{
					ta_dir = 180;
					t = TRUE;
				}
			}
			else
			{
				ta_dir = 270;
			}
		}
		if (ta_dir == 0 && a_y <= 25)
		{

			if (a_x <= 25)
			{
				ta_dir = 90;
			}
			else if (a_x >= 1575)
			{
				ta_dir = 270;
			}
			else
			{
				ta_dir = 270;
			}

			t = FALSE;
		}
		else if (ta_dir == 180 && a_y >= 875)
		{
			if (a_x <= 25)
			{
				ta_dir = 90;
			}
			else if (a_x >= 1575)
			{
				ta_dir = 270;
			}
			else
			{
				ta_dir = 90;
			}

			t = FALSE;
		}
		if (ta_dir == 90 && a_x < 1575)
		{
			a_x += 3.0f;
			ta_tx += 3.0f;
			ta_rx += 3.0f;
			ta_lx += 3.0f;
		}
		else if (ta_dir == 270 && a_x > 25)
		{
			a_x -= 3.0f;
			ta_tx -= 3.0f;
			ta_rx -= 3.0f;
			ta_lx -= 3.0f;
		}
		else if (ta_dir == 0 && a_y > 25)
		{
			a_y -= 3.0f;
			ta_ty -= 3.0f;
			ta_ry -= 3.0f;
			ta_ly -= 3.0f;
		}
		else if (ta_dir == 180 && a_y < 875)
		{
			a_y += 3.0f;
			ta_ty += 3.0f;
			ta_ry += 3.0f;
			ta_ly += 3.0f;
		}
	}
}

void Game_Exit(void)
{

}