#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <ctime>
#include "math_functions.h"



int main() {
    std::vector<float> function = {2, 0};
    std::vector<float> result = calculateImpactIntercept(function);
    for(int i = 0; i < 2; i++){
        std::cout << result[i] << " ";
    }

    return 0;
}
