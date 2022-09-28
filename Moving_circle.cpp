#include"raylib.h"

int main(){
    
    int Window_Width = 800, Window_Height = 800;
    InitWindow(Window_Width,Window_Height,"Circle Moving Game by.Vrikster");

    SetTargetFPS(60);
    int circle_x_position = 300;
    int circle_y_position = 600;
    int circle_radius = 40;
    int circle_increment = 5;

    //in game x and y axis starting point is the top left corner
    int rectangle_x_position = 600;
    int rectangle_y_position = 0;
    int rectangle_width = 50;
    int rectangle_height = 300;

    
    //Circle Boundries
    int circle_top_edge = circle_y_position - circle_radius;
    int circle_bottom_edge = circle_y_position + circle_radius;
    int circle_left_edge = circle_x_position - circle_radius;
    int circle_right_edge = circle_x_position + circle_radius;

    //Rectangle Boundries
    int rectangle_top_edge = rectangle_y_position;
    int rectangle_bottom_edge = rectangle_y_position + rectangle_height;
    int rectangle_left_edge = rectangle_x_position;
    int rectangle_right_edge = rectangle_x_position + rectangle_width;


    int direction = 4;

    bool collision_with_axe = (rectangle_bottom_edge>=circle_top_edge)&&
                              (rectangle_top_edge<=circle_bottom_edge)&&
                              (rectangle_right_edge>=circle_left_edge)&&
                              (rectangle_left_edge<=circle_right_edge);

    // once the while loops starts the program keeps looping within while loop until the game is closed

    while (!WindowShouldClose())    // or  WindowShouldClose() == false , this function will close a window when an esc key or windows is closed 
    {
        BeginDrawing();
        ClearBackground(WHITE);

        
        if(collision_with_axe){
            DrawText("Game Over!", 300, 400, 60, RED);
        }
        else{
            //Game logic begins
            DrawCircle(circle_x_position,circle_y_position,circle_radius,BLUE);
            DrawRectangle(rectangle_x_position, rectangle_y_position, rectangle_width, rectangle_height, RED);         //DrwawRectangle(distance_x,distance_y,width,height,color)
            

        //updating cicle boundaries
        circle_top_edge = circle_y_position - circle_radius;
        circle_bottom_edge = circle_y_position + circle_radius;
        circle_left_edge = circle_x_position - circle_radius;
        circle_right_edge = circle_x_position + circle_radius;
        //updating rectangle boundaries
     rectangle_top_edge = rectangle_y_position;
     rectangle_bottom_edge = rectangle_y_position + rectangle_height;
     rectangle_left_edge = rectangle_x_position;
     rectangle_right_edge = rectangle_x_position + rectangle_width;
        //updating collision_with_axe boundaries
        collision_with_axe = (rectangle_bottom_edge>=circle_top_edge)&&
                              (rectangle_top_edge<=circle_bottom_edge)&&
                              (rectangle_right_edge>=circle_left_edge)&&
                              (rectangle_left_edge<=circle_right_edge);




            
            
            //move the rectangle
            rectangle_y_position += direction;
            //rectangle edges
            int rectangle_edge_top = rectangle_y_position;
            int rectangle_edge_bottom = rectangle_y_position + rectangle_height;
            // int rectangle_edge_left = rectangle_x;
            // int rectangle_edge_right = rectangle_y + rectangle_width;
            
            if( rectangle_edge_bottom >= Window_Height || rectangle_edge_top <= 0){   // This function basically changes the +ve to -ve and -ve to +ve after eveytime it reaches the 800 or 0, so direction becomes (-4) and after it reaches top it becomes (+4) and this is how the box keeps moving
                direction = -direction;
            }

            //controlling the circle position
            if(IsKeyDown(KEY_D) && circle_x_position+circle_radius <= 800){
                circle_x_position += circle_increment;
            }
            if(IsKeyDown(KEY_A) && circle_x_position-circle_radius >= 0){
                circle_x_position -= circle_increment;
            }
            if(IsKeyDown(KEY_S) && circle_y_position+circle_radius <= 800){
                circle_y_position += circle_increment;
            }
            if(IsKeyDown(KEY_W) && circle_y_position-circle_radius >= 0){
                circle_y_position -= circle_increment;
            }

            //Game logic ends
        }

        EndDrawing();
    }
}