#include<iostream>
#include<chrono>
#include<thread>
#include <climits>

void moveX(int steps, std::string item){
    for(int j= 0; j<steps;j++){
        std::cout << " ";
    }
    std::cout << item << std::endl;
}

void moveY(int steps, std::string item){
    for(int j= 0; j<steps;j++){
        std::cout << std::endl;
    }
    std::cout << item << std::endl;

}

void moveXY(int x, int y, std::string item){
    for(int j= 0; j<y;j++){
        std::cout << std::endl;
    }
    for(int j= 0; j<x;j++){
        std::cout << " ";
    }
    std::cout << item << std::endl;
}


void ClearScreen(){
    #ifdef _WIN32 // Check if compiling on Windows
        // Windows command to clear the screen
        system("cls");
    #else
        // Unix/Linux command to clear the screen
        system("clear");
    #endif
}

int main(){
    int x = 0;
    int y = 0;
    system("cls");
    int dirX =1;
    int dirY =1;

    while(x != INT_MAX){
        moveXY(x,y,"Hello World");
        ClearScreen();
        std::chrono::milliseconds timespan(50);
        std::this_thread::sleep_for(timespan);

        if(x == 15){
            dirX = -1;
        } 
        if(y == 20){
            dirY=-1;
        }
        if(x == 0){
            dirX=1;
        }
        if(y == 0){
            dirY=1;
        }

        x += dirX;
        y += dirY;
        
    }





    return 0;
}