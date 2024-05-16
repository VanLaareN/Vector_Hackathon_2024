#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <ctime>
#include "math_functions.h"



int main() {
    std::vector<float> positions = {10,20,30,40};
    std::vector<float> linearFunction = getLinearFunction(positions);
    std::vector<float> ballPosition = {10,30};

    float time = calculateTimeOfImpact(ballPosition, linearFunction);

    std::cout << time;

    return 0;
}
