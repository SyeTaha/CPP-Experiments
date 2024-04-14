#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<random>
#include<chrono>
#include<thread>

const int Height = 1920;
const int Width = 1080;

class Animator{

public:


    void DrawTanPatt(int a, int b, int r){
        int frameNumber = 1920;
        std::ofstream image;
        int maxFrame = Height;

        while(frameNumber <= maxFrame){       
            int numOfLines = 0;
            std::string frame =  "Rendered/" + std::to_string(frameNumber) + ".ppm";
            image.open(frame, std::ios::trunc);
            if(image.is_open()){
                image << "P3" << std::endl;
                image << Width << " " << Height << std::endl;
                image << "255" << std::endl;   
                for(int y = 0; y < frameNumber; y++){
                    for(int x = 0; x < Width; x++){
                        int Ox = x - a, Oy = y - b;
                        if(tan(pow(Ox, 2) + pow(Oy, 2)) <= tan(pow(r, 2))) 
                            image << "0 0 0" << std::endl;
                        else 
                            image << "0 40 40" << std::endl;
                    }
                }
                for(int y = frameNumber; y < Height; y++){
                    for(int x = 0; x < Width; x++){
                        image << "0 0 0" << std::endl;
                    }
                }
            }
            std::cout << "Rendered " << frameNumber << " frames\n";
            image.close();
            frameNumber++;
        }
    }


};




int main(){


    Animator m1;

    m1.DrawTanPatt(Width/2, Height/2, 0);
    //m1.render(0, 1000);


    return 0;
}
