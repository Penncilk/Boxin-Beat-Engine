#include "../include/raylib.h"
#include "song.h"
#include "main.h"
//#include "chart.h"
#include <string>
#define circlesize 50


// This makes the circle and line in the project
void drawstage() {
    DrawLine(circlesize*2, 0, circlesize*2, 450, LIGHTGRAY);
    DrawCircleLines(circlesize*3, 300, 50, LIGHTGRAY);
}

// This makes all of the text in the project, like 
// Turns, Song, Visual Counter, etc
void drawstagetext(int beat, int score, int hmbar, Vector2 timekeep, int songchart[20*16]) {
  DrawText("Genoration - Jude & Codi", 420, 370, 20, YELLOW);
        if (beat != 0) {
        DrawText(TextFormat("Score: %i", score), 220, 390, 20, WHITE);
        }
        DrawText(TextFormat("%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i%i", songchart[(hmbar)],songchart[(1+hmbar)], songchart[(2+hmbar)], songchart[(3+hmbar)],songchart[(4+hmbar)], songchart[(5+hmbar)],songchart[(6+hmbar)],songchart[(7+hmbar)],songchart[(8+hmbar)],
                            songchart[(9+hmbar)],songchart[(10+hmbar)],songchart[(11+hmbar)],songchart[(12+hmbar)],songchart[(13+hmbar)],songchart[(14+hmbar)],songchart[(15+hmbar)]), 220, 275, 60, WHITE);
        DrawRectangleV(timekeep, {5*3, 10*3}, WHITE);
}


// This makes the circle get thicker to the beat
void circlebeat() {
    DrawCircleLines(circlesize*3, 300, 49, LIGHTGRAY);
    DrawCircleLines(circlesize*3, 300, 48, LIGHTGRAY);
}

void goodhit() {
    DrawCircle(circlesize*3, 300, 50, GREEN);
}

void badhit() {
    DrawCircle(circlesize*3, 300, 50, RED);
}
