#include<iostream>
#include<vector>
#include<thread>
#include<chrono>

template<typename type>
void print(std::vector<type> vec){
    for(size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
        if((i+1) % 3 == 0){
            std::cout << std::endl;
        }
        
    }
}

void print(std::vector<std::vector<char>>& vec){
    for(size_t i = 0; i < vec.size(); i++){
        for(size_t j = 0; j < vec[0].size(); j++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void printTranspose(std::vector<int> vec) {
    size_t numRows = vec.size() / 3;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < numRows; ++j) {
            std::cout << vec[j * 3 + i] << " ";
        }
        std::cout << std::endl;
    }
}



//Print Col one by one
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
            print(*it);
            it++;
        }
       
    }
}


int main(){

    std::vector<int> myVec1 = { 1, 2, 3,
                               4, 5, 6, 
                               7, 8, 9};

    std::vector<std::vector<int>> myVec2 = { { 1, 2, 3},
                                             { 4, 5, 6},
                                             { 7, 8, 9}};

    std::vector<std::vector<char>> myVec3 = { { '1',  '2',  '3'},
                                              { ' ',  ' ',  ' '},
                                              { '7',  '8',  '9'}};



    Animate(myVec2, 100);
    //print(myVec3);
    //filter(myVec3);
    //std::cout << myVec3.size() << " " << myVec3[0].size();
    //print(myVec3);
    //printTranspose(myVec1);
    return 0;
}

/*
  0 1 2
0 1 2 3
1 4 5 6
2 7 8 9


*/