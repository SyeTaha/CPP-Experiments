#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<cmath>
#include<ctime>
#include<random>

const int Height = 1080;
const int Width = 1920;

class ShapeMaker{
    std::string filename;
public:
    ShapeMaker(const std::string& name) : filename(name){}

    void drawCircle(int a, int b, int r){
        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;
            for(int y = 0; y < Height; y++){
                for(int x = 0; x < Width; x++){
                    if(pow(x - a, 2) + pow(y - b, 2) <= pow(r, 2)) image << "255 0 0" << std::endl;
                    else image << "0 23 0" << std::endl;
                }
            }
        }
        image.close();
    }

    void DrawTanPatt(int a, int b, int r){

        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;   
            for(int y = 0; y < Height; y++){
                for(int x = 0; x < Width; x++){
                    int Ox = x - a, Oy = y - b;
                    if(tan(pow(Ox, 2) + pow(Oy, 2)) <= tan(pow(r, 2))){
                        image << "0 0 0" << std::endl;
                    }
                    else{
                        image << "0 150 150" << std::endl;
                    }
                }
            }
        }
        image.close();
    }

    void DrawSineWave(int a, int b){
        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;   
            for(int y = 0; y < Height; y++){
                for(int x = 0; x < Width; x++){
                    int Ox = x - a, Oy = y - b;
                    if(sin(Ox) >= Oy){
                        image << "0 0 0" << std::endl;
                    }
                    else{
                        image << "0 150 150" << std::endl;
                    }
                }
            }
        }
        image.close();



    }

   void DrawTANXY(int a, int b, int r){

        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;   
            for(int y = 0; y < Height; y++){
               
                for(int x = 0; x < Width; x++){
                    int Ox = x - a, Oy = y - b;
                    if(tan(x*y) <= r){
                        image << "0 0 0" << std::endl;
                    }
                    else{
                        image << "0 150 150" << std::endl;
                    }
                }
                std::cout << "\rScanned " << y + 1 << " files" << std::flush;
            }
        }
        image.close();
    }

   void Test(int a, int b, int r){

        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;   
            for(int y = 0; y < Height; y++){
               
                for(int x = 0; x < Width; x++){
                    int Ox = x - a, Oy = y - b;
                    if( tan(tan(tan(tan(Ox*Oy)))) <= r){
                        image << "0 0 0" << std::endl;
                    }
                    else{
                        image << "0 150 150" << std::endl;
                    }
                }
                std::cout << "\rHeight: " << y + 1 << std::flush;
            }
        }
        image.close();
    }



    void convertToPNG(std::string newFile){
        std::string command = "convert " + filename + " " + newFile;
        system(command.c_str());

    }
};




int main(){

    std::string filename = "Tests";

    ShapeMaker m1(filename + ".ppm");
    m1.Test(Width/2, Height/2, 100);
    //m1.convertToPNG(filename + ".png");

    return 0;
}
