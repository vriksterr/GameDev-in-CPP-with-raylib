#include"raylib.h"

int main(){
    
    InitWindow(800,800,"Vrikster");

    SetTargetFPS(60);
    int circle_x = 300;
    int circle_y = 300;
    while (!WindowShouldClose())    // or  WindowShouldClose() == false , this function will close a window when an esc key or windows is closed 
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Game logic begins
        
        DrawCircle(circle_x,circle_y,40,BLUE);
        
        if(IsKeyDown(KEY_D)){
            circle_x = circle_x + 2;
        }
        if(IsKeyDown(KEY_A)){
            circle_x = circle_x - 2;
        }
        if(IsKeyDown(KEY_S)){
            circle_y = circle_y + 2;
        }
        if(IsKeyDown(KEY_W)){
            circle_y = circle_y - 2;
        }

        // if(circle_x >= 800 || circle_y >= 800){
        //     return 0;
        // }
        //Game logic ends
        EndDrawing();
    }
    
}