//---------------------------------------------------------
// file:	utils.h
// author:	Muhammad Ibnu Khalis Bin Muhammad Farid
// email:	[m.binmuhammadfarid@digipen.edu]
//
// brief:	header file where functions are declared
//		
//
// Copyright © 2026 DigiPen, All rights reserved.
//---------------------------------------------------------

#pragma once

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y);
int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y);
int IsWithinBoundary(float ai_x, float ai_y, float player_x, float player_y);