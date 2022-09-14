#include"raylib.h"

int main(){
    
    int Window_Width = 800, Window_Height = 800;
    InitWindow(Window_Width,Window_Height,"Circle Moving Game by.Vrikster");

    SetTargetFPS(60);
    int circle_x = 300;
    int circle_y = 300;
    int circle_radius = 40;
    int circle_increment = 5;

    //in game x and y axis starting point is the top left corner
    int rectangle_x = 600;
    int rectangle_y = 0;
    int rectangle_width = 50;
    int rectangle_height = 300;
    
    
    

    int direction = 4;


    // once the while loops starts the program keeps looping within while loop until the game is closed

    while (!WindowShouldClose())    // or  WindowShouldClose() == false , this function will close a window when an esc key or windows is closed 
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //Game logic begins
        
        DrawCircle(circle_x,circle_y,circle_radius,BLUE);
        DrawRectangle(rectangle_x, rectangle_y, rectangle_width, rectangle_height, RED);         //DrwawRectangle(distance_x,distance_y,width,height,color)
        
        
        //move the rectangle
        rectangle_y += direction;
        //rectangle edges
        int rectangle_edge_top = rectangle_y;
        int rectangle_edge_bottom = rectangle_y + rectangle_height;
        // int rectangle_edge_left = rectangle_x;
        // int rectangle_edge_right = rectangle_y + rectangle_width;
        
        if( rectangle_edge_bottom >= Window_Height || rectangle_edge_top <= 0){   // This function basically changes the +ve to -ve and -ve to +ve after eveytime it reaches the 800 or 0, so direction becomes (-4) and after it reaches top it becomes (+4) and this is how the box keeps moving
            direction = -direction;
        }

        //controlling the circle
        if(IsKeyDown(KEY_D) && circle_x+circle_radius <= 800){
            circle_x += circle_increment;
        }
        if(IsKeyDown(KEY_A) && circle_x-circle_radius >= 0){
            circle_x -= circle_increment;
        }
        if(IsKeyDown(KEY_S) && circle_y+circle_radius <= 800){
            circle_y += circle_increment;
        }
        if(IsKeyDown(KEY_W) && circle_y-circle_radius >= 0){
            circle_y -= circle_increment;
        }

        //Game logic ends
        EndDrawing();
    }
}