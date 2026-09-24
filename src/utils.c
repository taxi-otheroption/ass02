#include <math.h>
#include "cprocessing.h"
#include "game.h"


int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
    float left = area_center_x - area_width / 2.0f;
    float right = area_center_x + area_width / 2.0f;
    float top = area_center_y - area_height / 2.0f;
    float bottom = area_center_y + area_height / 2.0f;
    if ((click_x >= left && click_x <= right) && (click_y >= top && click_y <= bottom))
    {
        if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
        {
            return 1;
        }
    }
    return 0;
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
    float radius = diameter / 2.0f;
    float left = circle_center_x - radius;
    float right = circle_center_x + radius;
    float top = circle_center_y - radius;
    float bottom = circle_center_y + radius;

    if ((click_x >= left && click_x <= right) && (click_y >= top && click_y <= bottom))
    {
        if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
        {
            return 1;
        }

    }
    return 0;
}
