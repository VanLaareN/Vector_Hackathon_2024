#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <ctime>
#include "math_functions.h"



int main() {
    std::vector<float> function = {-1, 1};
    std::vector<float> result = getImpactPoint(function);
    for(int i = 0; i < 2; i++){
        std::cout << result[i] << " ";
    }

    return 0;
}
