#include"raylib.h"

int main(){
    
    InitWindow(800,800,"Vrikster");

    SetTargetFPS(60);
    int circle_x = 300;
    int circle_y = 300;

    int rectangle_x = 600;
    int rectangle_y = 800;

    int driection = 4;

    while (!WindowShouldClose())    // or  WindowShouldClose() == false , this function will close a window when an esc key or windows is closed 
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Game logic begins
        
        DrawCircle(circle_x,circle_y,40,BLUE);
        DrawRectangle(rectangle_x, rectangle_y, 50, 50, RED);         //DrwawRectangle(distance_x,distance_y,width,height,color)
        
        
        //move the rectangle
        rectangle_y += driection;
        if(rectangle_y > 800 || rectangle_y < 0){   // This function basically changes the +ve to -ve and -ve to +ve after eveytime it reaches the 800 or 0, so direction becomes (-4) and after it reaches top it becomes (+4) and this is how the box keeps moving
            driection = -driection;
        }

        //controlling the circle
        if(IsKeyDown(KEY_D) && circle_x <= 800){
            circle_x += 10;
        }
        if(IsKeyDown(KEY_A) && circle_x >= 0){
            circle_x -= 10;
        }
        if(IsKeyDown(KEY_S) && circle_y <= 800){
            circle_y += 10;
        }
        if(IsKeyDown(KEY_W) && circle_y >= 0){
            circle_y -= 10;
        }

        // if(circle_x >= 800 || circle_y >= 800){
        //     return 0;
        // }
        //Game logic ends
        EndDrawing();
    }
    
}