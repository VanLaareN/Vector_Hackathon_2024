#include<vector>
#include<iostream>
#include "helper.h"
#include "math_functions.h"

void getStraightLine(std::vector<float> x_values, std::vector<float> y_values){

    // Initialize the three_points vector with two empty vectors for x and y coordinates
    std::vector<std::vector<float>> three_points(2, std::vector<float>(3, 0.0f));

    int counter = 0;
    std::vector<float> straightLine;
    
    while(counter <= x_values.size() - 3) {
        for (int i = counter; i < counter + 3; i++) {
            three_points[0][i - counter] = x_values[i];
            three_points[1][i - counter] = y_values[i];
        }

        std::vector<float> linearFunction = getLinearFunction(three_points);
        if (linearFunction[0] == 0 && linearFunction[1] == 0) {
            straightLine = linearFunction;
        } else {
            std::cout << "Points (" << counter << ", " << counter+1 << ", " << counter+2 << ") lie on a straight line.\n";
            break;
        }
        counter++;
    }
}