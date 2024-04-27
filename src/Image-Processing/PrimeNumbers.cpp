#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>



const int Height = 1920;
const int Width = 1080;

class PrimeNumbers{
    std::string filename;
public:
    PrimeNumbers(const std::string& name) : filename(name){}

    bool isPrime(int number) {
        if (number <= 1) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;
        for (int i = 3; i * i <= number; i += 2 ) {
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

};

int main(){

    std::string filename = "image.ppm";
    PrimeNumbers m1(filename);
    m1.DrawPrimeNumbers();

    return 0;
}
