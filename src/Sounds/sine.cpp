#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
#include<random> 


const int SampleRate = 44100;
const int bitDepth = 16;
const int duration = 4;



class Oscilator{
    float frequency, amplitude, angle = 0.0f, offset = 0.0f;

public:
    Oscilator(float freq, float amp) : frequency(freq), amplitude(amp) {

        offset = (2.0f * M_PI * frequency) / SampleRate;
        srand(time(0));
    }

    float process(){
        //Asin(2pif/sr)
        float sample = amplitude * sin(angle);
        angle += offset;    
        return sample;
    }
    

};


void WriteToFile(std::ofstream& file, int value, int size){
    file.write(reinterpret_cast<const char*>(&value), size);
}

std::string SetPrecision(const float& number, const int& precision) {
    std::ostringstream temp;
    temp << std::fixed << std::setprecision(precision) << number;
    return temp.str();

}

int main(){
    const float amp = 0.1f;

    const int freq = 440;

    std::string filename = "Sine_" + std::to_string(freq) + "Hz_" + SetPrecision(amp, 1) + "Amp.wav";



    Oscilator sineWave(freq, amp);
    std::ofstream AudioFile;
    AudioFile.open(filename, std::ios::binary);

    //Header
    AudioFile << "RIFF";
    AudioFile << "----";
    AudioFile << "WAVE";

    //Format Chunk
    AudioFile << "fmt ";
    WriteToFile(AudioFile, 16, 4); //Size
    WriteToFile(AudioFile, 1, 2); //Compression Code
    WriteToFile(AudioFile, 1, 2); // Number of Channels
    WriteToFile(AudioFile, SampleRate, 4); //Sample Rate
    WriteToFile(AudioFile, SampleRate * bitDepth/8, 4); //Bite Rate
    WriteToFile(AudioFile, bitDepth/8, 2); //Block Align
    WriteToFile(AudioFile, bitDepth, 2); //Bit Depth


    //Data Chunk
    AudioFile << "data";
    AudioFile << "----";

    int prePos = AudioFile.tellp();

    auto maxAmp = pow(2, bitDepth - 1) - 1;
    for(size_t i = 0; i < SampleRate * duration; i++){
        auto sample = sineWave.process();
        int AdjustedSample = static_cast<int> (sample * maxAmp);

        WriteToFile(AudioFile, AdjustedSample, 2);

    }

    int postPos = AudioFile.tellp();
    AudioFile.seekp(prePos - 4);
    WriteToFile(AudioFile, postPos - prePos, 4);

    AudioFile.seekp(4, std::ios::beg);
    WriteToFile(AudioFile, postPos - 8, 4);
    

    AudioFile.close();







    return 0;
}