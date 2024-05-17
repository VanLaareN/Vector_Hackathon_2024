#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <ctime>
#include "math_functions.h"



int main() {
    std::vector<std::vector<float>> three_points = {{1,2,3}, {1,2,5}};
    std::vector<float> linearFunction = getLinearFunction(three_points);

    if(linearFunction[0] == 0 && linearFunction[1] == 0){
        std::cout << "NOT A LINE";
    }
    else{
        std::cout << "IT IS A LINE!!!!!";
    }

    return 0;
}
