#include "../include/raylib.h"
#include "song.h"
#include "draw.h"
#include "chart.h"
#include "input.h"


int main(void)
{

    // All sorts of varibles to keep time, based off of Rythm Doctor
    const int screenWidth = 800;
    const int screenHeight = 450;
    // 
    music_info songdata 
    {
    100,
    60/songdata.bpm, 
    30/songdata.bpm,
    0
    };

    float lastbeat = 0.0f;
    float lasthalfbeat = 0.0f;
    float timeplayed = 0.0f;
    int counter = 0;
    int curbeat = 0;
    bool pause = false;
    bool coachturn = true;
    int bar = 0;
    // This is used for the visual counter
    int bar_multiplied = 0;
    int score = 0;
    int countcounter = 0;
    Vector2 timekeep = {220, 330};



    //Name of the game
    InitWindow(screenWidth, screenHeight, "Boxin' Beat");
    InitAudioDevice();
    //Chooses our song
    Music song = LoadMusicStream("./music/GenorationBox.wav");
    PlayMusicStream(song);

    SetTargetFPS(60);               // Set our game to run at 60


    while (!WindowShouldClose())
    {

        if (!coachturn)
        {
          // Makes it so you can't cheat notes as easily
            score = keyinput(songchart, curbeat, score);
        }
        // Keeps the music playing
        UpdateMusicStream(song);
        // How long the song has been playing
        timeplayed = GetMusicTimePlayed(song);


        BeginDrawing();
        // Tells the player who's turn it is
        ClearBackground(BLACK);
        DrawFPS(0, 0);
        drawstage();
        if (GetMusicTimePlayed(song) > lastbeat + songdata.beat)
        {
            // These effects play every beat
            circlebeat();
            lastbeat += songdata.beat;
        }
        if (GetMusicTimePlayed(song) > lasthalfbeat + songdata.halfbeat)
        {
            // Add beat effects here 2x speed
            if ((counter + 1) % 16 == 0)
            {
                if (coachturn == true)
                {
                    coachturn = false;
                }
                else
                {
                    coachturn = true;
                    bar += 1;
                }
            }
            if (coachturn == false)
            {
                curbeat += 1;
            }
            counter += 1;
            lasthalfbeat += songdata.halfbeat;
            if (countcounter > 14)
            {
                timekeep.x = 220;
                countcounter = 0;
            }
            else
            {
                if (songchart[curbeat - 1] == 1)
                {
                    timekeep.x += (12*3)/2;
                }
                /*


                else if (songchart[curbeat - 1] == 1) {
                timekeep.x += (12*3)/2;
                }
                */
                else
                {
                    timekeep.x += 12*3;
                }
                countcounter += 1;
            }
        }
        bar_multiplied = bar * 16;


        drawstagetext(curbeat, score, bar_multiplied, timekeep, songchart);
        // This one doesn't work when out of main for some reason
        DrawText(TextFormat("Coach Turn: %i", coachturn), 220, 370, 20, GREEN);

        EndDrawing();

        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(song);
            else ResumeMusicStream(song);

        }
        if (!pause)
        {


        }

        if (counter > sizeof(songchart))
        {
            WindowShouldClose();
        }

        //input();

        //----------------------------------------------------------------------------------
    }
    UnloadMusicStream(song);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
