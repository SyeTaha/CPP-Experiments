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

    void AnimateTanPattern(int a, int b, int r) {
        const std::string outputDir = "Rendered/";
        const int maxFrame = Height;
        
        for (int frameNumber = 1; frameNumber <= maxFrame; ++frameNumber) {
            std::string frame = outputDir + std::to_string(frameNumber) + ".ppm";
            std::ofstream image(frame, std::ios::trunc);
            
            if (image.is_open()) {
                image << "P3\n";
                image << Width << " " << Height << "\n";
                image << "255\n";
                
                for (int y = 0; y < Height; ++y) {
                    if (y <= frameNumber) {
                        for (int x = 0; x < Width; ++x) {
                            int Ox = x - a, Oy = y - b;
                            if (tan(pow(Ox, 2) + pow(Oy, 2)) <= tan(pow(r, 2)))
                                image << "0 0 0\n";
                            else
                                image << "0 150 150\n";
                        }
                    } else {
                        // Fill the remaining lines with black
                        for (int x = 0; x < Width; ++x) {
                            image << "0 0 0\n";
                        }
                    }
                }
                
                std::cout << "\rRendered " << frameNumber << " frames" << std::flush;
            } else {
                std::cerr << "Error: Unable to open file " << frame << std::endl;
            }
            
            image.close();
        }
    }

    void AnimatePrimeNumbers() {
        const std::string outputDir = "Rendered/";
        const int maxFrame = Height;
        
        for (int frameNumber = 1; frameNumber <= maxFrame; ++frameNumber) {
            std::string frame = outputDir + std::to_string(frameNumber) + ".ppm";
            std::ofstream image(frame, std::ios::trunc);
            
            if (image.is_open()) {
                image << "P3\n";
                image << Width << " " << Height << "\n";
                image << "255\n";
                
                for (int y = 0; y < Height; ++y) {
                    if (y <= frameNumber) {
                        for (int x = 0; x < Width; ++x) {
                            if (isPrime(y * Width + x))
                                image << "0 150 150\n";
                            else
                                image << "0 0 0\n";
                        }
                    } else {
                        // Fill the remaining lines with black
                        for (int x = 0; x < Width; ++x) {
                            image << "0 0 0\n";
                        }
                    }
                }
                
                std::cout << "\rRendered " << frameNumber << " frames" << std::flush;
            } else {
                std::cerr << "Error: Unable to open file " << frame << std::endl;
            }
            
            image.close();
        }
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



};






int main(){


    Animator m1;

    m1.AnimatePrimeNumbers();
    //m1.render(0, 1000);


    return 0;
}


