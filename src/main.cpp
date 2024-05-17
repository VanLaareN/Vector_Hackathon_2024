#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include "math_functions.h"
#include "helper.h"

void generatePoints(std::vector<float>& x_values, std::vector<float>& y_values) {
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate 100 random points
    for (int i = 0; i < 100; ++i) {
        float x = static_cast<float>(std::rand()) / RAND_MAX * 100;  // Random x in range [0, 100]
        float y = static_cast<float>(std::rand()) / RAND_MAX * 100;  // Random y in range [0, 100]
        x_values.push_back(x);
        y_values.push_back(y);
    }

    // Select a random index to start the line sequence (ensure there is room for two more points)
    int startIndex = std::rand() % 98;  // Choose startIndex from 0 to 97 to ensure two following points

    // Set these three consecutive points to be on the line y = 2x + 1
    for (int i = 0; i < 3; ++i) {
        x_values[startIndex + i] = static_cast<float>(std::rand()) / RAND_MAX * 100;
        y_values[startIndex + i] = 2.0f * x_values[startIndex + i] + 1.0f;
    }
}


int main() {
    std::vector<float> x_values;
    std::vector<float> y_values;
    generatePoints(x_values, y_values);
    getStraightLine(x_values, y_values);

    return 0;
}