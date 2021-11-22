#include "../include/raylib.h"
#include "draw.h"

int keyinput(int chart[20*16], int beat, int score)
{
    if ((IsKeyPressed(KEY_X)))
    {
        if (chart[beat-1] == 1)
        {
            score += 1;
            goodhit();

        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_Z))
    {
        if (chart[beat-1] == 2)
        {
            goodhit();
            score += 1;
        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_RIGHT))
    {
        if (chart[beat-1] == 3)
        {
            score += 1;
            goodhit();
        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_LEFT))
    {
        if (chart[beat-1] == 4)
        {
            score += 1;
            goodhit();
        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_X) | IsKeyPressed(KEY_UP))
    {
        if (chart[beat-1] == 5)
        {
            score += 1;
            goodhit();
        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_Z) | IsKeyPressed(KEY_UP))
    {
        if (chart[beat-1] == 6)
        {
            score += 1;
            goodhit();
        }
        else
        {
            badhit();
        }
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        if (chart[beat-1] == 7)
        {
            score += 1;
            goodhit();
        }
        else
        {
            badhit();
        }
    }
    return score;
}