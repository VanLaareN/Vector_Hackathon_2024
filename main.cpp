#include <iostream>
#include <vector>
#include<cmath>

/* 
outputs {m,c} value of linear function
*/
std::vector<float> getLinearFunction(float x1, float x2, float y1, float y2) {
    float m = 0;
    float c = 0;

    m = std::abs((y1-y2)/(x1-x2));
    c = y1 - x1*m;

    return std::vector<float> {m, c};
}

std::vector<float> flipLinearFunction(std::vector<float> linearFunction){
    float flippedM = 0;
    float flippedC = 0;

    flippedM = linearFunction[0] * (-1);
    flippedC = linearFunction[1] * (-1);

    return std::vector<float> {flippedM, flippedC};
}

/*
calculate euclidean disttance between 2 points in space
(if distance covered by ball in one cycle ont given)
*/
float getEuclideanDistance(std::vector<float> positions){
    float euclideanDistance = sqrt(pow(abs(positions[0]-positions[1]), 2) + pow(abs(positions[2]-positions[3]), 2));
    return euclideanDistance;
}

int main() {
    std::vector<float> positions = {10,20,30,40};
    float distance_covered_per_cycle = getEuclideanDistance(positions);
    float time_cycle = 0.0001;

    //asd


    return 0;
}
