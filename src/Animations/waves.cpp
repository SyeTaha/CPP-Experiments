#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <vector>


void clearScreen(){
    #ifdef _WIN32 // Check if compiling on Windows
        // Windows command to clear the screen
        system("cls");
    #else
        // Unix/Linux command to clear the screen
        system("clear");
    #endif
}

void PrintWave(std::vector<std::vector<char>> wave, int delay){
    for(size_t col = 0; col < wave.size(); col++){
        for(size_t row = 0; row < wave[col].size(); row++) {
            std::cout << wave[col][row];
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
        std::cout << std::endl;
    }
}

void Animate(std::vector<std::vector<char>> vec, int delay){
    int numOfCol = 0;
    while(numOfCol <= vec[0].size()){
        clearScreen();
        for(size_t row = 0; row < vec.size(); row++){
            for(int col = 0; col < numOfCol; col++){
                std::cout << vec[row][col];
            }
            std::cout << std::endl;   
        }   
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        numOfCol++;
    }
}

bool containsOnlySpaces(std::vector<char> vec){
    for(const char& c : vec){ 
        if(c != ' ') return false;
    }
    return true;

}


void filter(std::vector<std::vector<char>>& vec) {
    for (auto it = vec.begin(); it != vec.end(); /* no increment here */) {
        if (containsOnlySpaces(*it)) {
            it = vec.erase(it);
        }
        else{

            it++;
        }
       
    }
}
                    

void PrintWave(std::vector<char> wave, int delay){
    for(char c : wave){
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

std::vector<std::vector<char>> transpose(std::vector<std::vector<char>> ogWave){

    std::vector<std::vector<char>> transposed(ogWave[0].size(), std::vector<char>(ogWave.size()));

    std::cout << "Starting...\n";
    for (size_t i = 0; i < ogWave.size(); ++i) {
        for (size_t j = 0; j < ogWave[i].size(); ++j) {
            transposed[j][i] = ogWave[i][j];
        }
    }
    return transposed;

}


// Function to draw a sine wave graph
void drawSineWave(double amplitude, double frequency, int duration) {
    clearScreen();
    // Define constants for the graph
    const int numLines = 20; // Number of lines on the y-axis
    const double pi = 3.14159;

    char SineChar = '*';
    char CosChar = '.';


    std::vector<std::vector<char>> Wave;
    //std::vector<char> Wave;

    
    // Calculate time period of one oscillation
    double period = 1.0 / frequency; //Time Period = 1/frequency


    
    // Iterate over time
    for (int t = 0; t < duration; ++t) {
        std::vector<char> row;
        // Calculate the current time in the range [0, 2pi)
        double time = 2 * pi * t / duration;

        // Calculate the value of sine function at the current time
        double valueS = amplitude * std::sin(time * frequency);
        double valueC = amplitude * std::cos(time * frequency);


        // Normalize the value to fit within the screen
        int yS = static_cast<int>((valueS + amplitude) / (2 * amplitude) * numLines);
        int yC = static_cast<int>((valueC + amplitude) / (2 * amplitude) * numLines);
        //std::cout << time << " " << yC << " " << yS << std::endl;

        // Print the graph for each line
        for (int line = numLines; line >= 0; --line) {
            if (line <= yS && line >= yC) {
                // Print '*' at the position of the sine wave
                row.push_back(SineChar);
                //Wave.push_back(SineChar);
            } 
            else if (line >= yS && line <= yC) {
                // Print '*' at the position of the sine wave
                row.push_back(CosChar);
                //Wave.push_back(CosChar);
            }
            else if (line == numLines / 2) {
                // Print '-' at the x-axis
                row.push_back('-');
                //Wave.push_back('|');
                //std::cout << "|";
            } else {
                // Print space for other positions
                row.push_back(' ');
                //std::cout << " ";
            }
        }
        //std::cout << std::endl;
        
        Wave.push_back(row);
        // Introduce a delay to slow down the animation
        
    }

    //Animate(Wave, 100);
    std::vector<std::vector<char>> transposedWave = transpose(Wave);
    filter(transposedWave);
    Animate(transposedWave, 1000);

    //PrintWave(transposedWave, 0);

}



int main() {
    system("cls");

    double amplitude = 1.0; // Amplitude of the sine wave
    double frequency = 2; // Frequency of the sine wave
    int duration = 40; // Duration of the animation (in seconds)
    
    drawSineWave(amplitude, frequency, duration);
    
    return 0;
}
