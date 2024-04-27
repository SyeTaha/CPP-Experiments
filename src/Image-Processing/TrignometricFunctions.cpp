#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<functional>

const int Height = 1920;
const int Width = 1080;

class Sine{
    double a;
    double b;
public:
    Sine(double a_, double b_) : a(a_), b(b_) {}

    bool operator()(double x, double y, int tolerance) {
        double angle = x / b;
        double value = a * sin(angle); // Using double precision
        return std::abs(y - value) < tolerance; // Adjust epsilon for tolerance
    }
};

class Tangent{
    double a;
    double b;
public:
    Tangent(double a_, double b_) : a(a_), b(b_) {}

    bool operator()(double x, double y, int tolerance) {
        double angle = x / b;
        double value = a * tan(angle); // Using double precision
        return std::abs(y - value) < tolerance; // Adjust epsilon for tolerance
    }
};

class Cosine{
    double a;
    double b;
public:
    Cosine(double a_, double b_) : a(a_), b(b_) {}

    bool operator()(double x, double y, int tolerance) {
        double angle = x / b;
        double value = a * cos(angle); // Using double precision
        return std::abs(y - value) < tolerance; // Adjust epsilon for tolerance
    }
};


class Draw{
public:
    template<typename Functor>
    void operator()(std::string filename, int tolerance, Functor& isValidPoint){
        int cX = Width /2;
        int cY = Height/2;
        std::ofstream image;
        image.open(filename, std::ios::trunc);
        if(image.is_open()){
            image << "P3" << std::endl;
            image << Width << " " << Height << std::endl;
            image << "255" << std::endl;   
            for(int y = 0; y < Height; y++){
                for(int x = 0; x < Width; x++){
                    int Ox = x - cX, Oy = y - cY;
                    if(isValidPoint(Ox, Oy, tolerance)){
                        image << "0 150 150" << std::endl;
                    }
                    else{
                        image << "0 0 0" << std::endl;
                    }
                }
            }
        }
        image.close();
    }

};




int main(){

    int a = 100;
    int b = 70;
    int tolerance = 10;
    


    Tangent tangent(a, b);
    Sine sine(a, b);
    Cosine cosine(a, b);

    std::function<bool(double, double, int)> functors[3] = {tangent, sine, cosine};

    int count = 1;
    for(const auto& functor : functors){
        std::string filename = "Rendered/image";
        filename += std::to_string(count);
        filename += ".ppm";
        Draw()(filename, tolerance, functor);
        count++;
    }

    //sine.Draw(10);

    //m1.render(0, 1000);


    return 0;
}

