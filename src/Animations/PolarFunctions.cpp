#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include<string>
#include<filesystem>

const std::string RED = "150 0 0";
const std::string BLACK = "0 0 0";

const int height = 1920;
const int width = 1080;


// r = b tan (a * theta)
class TanTheta {
    double a, b; // Change to double for higher precision

public:
    TanTheta(double _a = 1.0, double _b = 1.0) : a(_a), b(_b) {}

    void Draw() {
        const std::string outputDir = "Rendered/";

        const double aMax = 100;
        const int maxFrame = 20 * aMax;
        const int frameStart = 1;

        //Arithematic Progression
        const double CommonDifference = (aMax - a) / (maxFrame - 1);

        std::cout << "Rendering " << maxFrame << " frames with 'a' differing by " << CommonDifference << std::endl;

        // Check if the directory exists, if not, create it
        if (!std::filesystem::exists(outputDir))
            std::filesystem::create_directory(outputDir);

        for (int frameNumber = frameStart ; frameNumber <= maxFrame; ++frameNumber) {

            std::string frame = outputDir + std::to_string(frameNumber) + ".ppm";
            std::ofstream image(frame, std::ios::trunc);
            if (image.is_open()) {

                // Initialise
                image << "P3\n" << width << " " << height << "\n255\n";

                // Taking each Pixel to be a Point in the X, Y coordinate plane  
                for (int y = 0; y < height; y++) {
                    for (int x = 0; x < width; x++) {
                        // Get Center Points
                        double Ox = x - width / 2.0, Oy = y - height / 2.0; // Change to double
                        // Check if a Point Lies on r = b(tan(a*θ))
                        if (isValidPoint(Ox, Oy)) {
                            image << RED << " ";
                        } else {
                            image << BLACK << " ";
                        }
                    }   
                }
                image << std::endl; // New line for next row of pixels

                std::cout << "\rRendered " << frameNumber << " frames with a = " << a << std::flush;
            } else {
                std::cerr << "Error: Unable to open file " << frame << std::endl;
            }
            image.close();


            a += CommonDifference;
        }
    }
    
    
    bool isValidPoint(double x, double y) {
        double r_squared = y * y + x * x;
        double r = sqrt(r_squared); // Using double precision
        double theta;

        if (x == 0) {
            // Special case when x is zero
            if (y >= 0)
                theta = M_PI / 2.0; // Angle is pi/2 radians
            else
                theta = 3.0 * M_PI / 2.0; // Angle is 3*pi/2 radians
        } else {
            // Calculate theta in radians
            theta = atan2(y, x);
        }

        // Check if the point lies exactly on the rose curve
        double rose_condition = b * b * pow(tan(a * theta), 2);
        return std::abs(r_squared - rose_condition) < 10000; // Adjust epsilon for tolerance
    }


};



int main() {
    TanTheta t(1, 500.0);
    t.Draw();

    std::cout << std::endl;

    system("bash ./convertTopng.sh");
    
    return 0;
}



