#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

void drawCircle(int radius) {
    // Define the center of the circle
    int centerX = radius;
    int centerY = radius;

    // Iterate over each row
        system("cls");
    for (int y = 0; y <= radius * 2; ++y) {
        // Iterate over each column
        for (int x = 0; x <= radius * 2; ++x) {
            // Calculate distance from the center of the circle to the current point
            double distance = std::pow(x - centerX, 2) + std::pow(y - centerY, 2);
            
            // If the distance is close to the radius, print '*'
            if (distance >= radius * radius) {
                std::cout << "*";
            } else {
                // Otherwise, print a space
                std::cout << " ";
            }
        }
        // Move to the next line (y-direction)
        std::cout << std::endl;

        // Introduce a time pause to slow down the animation
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Clear the console screen for next frame
    }
}

int main() {
    int radius = 20;
    drawCircle(radius);
    return 0;
}
