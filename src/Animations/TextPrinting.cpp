#include<iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

const string alphabets = " !\"£$%^&*()<>?{}:@~,./;'#[]\\++-_=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12345678900\n";

void ClearScreen(){
    #ifdef _WIN32 // Check if compiling on Windows
        // Windows command to clear the screen
        system("cls");
    #else
        // Unix/Linux command to clear the screen
        system("clear");
    #endif
}



void iterater(const string& message){
    string result = "";
    for(int i = 0; i < message.length(); i++){
        for(int j = 0; j < alphabets.length(); j++){
            if(message[i]) result += alphabets[j];
            if (alphabets[j] != message[i]) result.erase(result.length() - 1,1);
            else{
                ClearScreen();
                cout << result;
                std::chrono::milliseconds timespan(50);
                std::this_thread::sleep_for(timespan);
                break;
            }
        }
    }
}


int main(){
    system("cls");
    string intro = "Hi! My name is Syed Muhammad Taha. This is me Experimenting with system() function commands in c++.\nBye.....";
    iterater(intro); cout << endl;
}