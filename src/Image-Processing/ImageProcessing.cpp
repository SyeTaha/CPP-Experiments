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

class ShapeMaker{
    std::string filename;
public:
    ShapeMaker(const std::string& name) : filename(name){}

    void Animate(std::vector<std::vector<int>> vec, int delay){
        int numOfCol = 0;
        while(numOfCol <= vec[0].size()){
            for(size_t row = 0; row < vec.size(); row++){
                for(int col = 0; col < numOfCol; col++){
                    std::cout << vec[row][col] << " ";
                }
                std::cout << std::endl;
                
            }   
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            system("cls");
            numOfCol++;
        }
    }

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

    bool isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }


    void DrawPrimeNumbers() {
        int count = 0;
        std::ofstream image(filename, std::ios::trunc);
        if (!image.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }
        
        image << "P3\n";
        image << Width << " " << Height << "\n";
        image << "255\n";
        
        for (int y = 0; y < Height; ++y) {
            for (int x = 0; x < Width; ++x) {
                if (isPrime(y * Width + x)) {
                    image << "0 150 150\n";
                    count++;
                } else {
                    image << "0 0 0\n";
                }
            }
        }
        
        std::cout << "Total Primes: " << count << std::endl;
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
                    else image << "0 150 150" << std::endl;
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
            }
        }
        image.close();
    }

   void Test(int a, int b, int r){
        filename += ".ppm";

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

    std::string filename = "image.ppm";

    ShapeMaker m1(filename);

    m1.DrawPrimeNumbers();
    //m1.render(0, 1000);


    return 0;
}
