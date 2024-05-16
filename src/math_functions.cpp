#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <ctime>
#include "math_functions.h"

/* 
outputs {m,c} value of linear function
*/
float DISTANCE_COVERED_PER_CYCLE = 3;
float TIME_CYCLE = 0.0001;
int X_LIMIT = 255;
int Y_LIMIT = 149;

std::vector<float> getLinearFunction(std::vector<float> points) {
    float x1 = points[0];
    float x2 = points[1];
    float y1 = points[2];
    float y2 = points[3];

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

float calculateDistanceToImpact(std::vector<float> ballPosition, std::vector<float> linearFunction){
    float y_position = linearFunction[0]* X_LIMIT + linearFunction[1];
    std::vector<float> positions = {ballPosition[0], (float) X_LIMIT, ballPosition[1], y_position};
    float distance = getEuclideanDistance(positions);
    return distance;
}

float calculateTimeOfImpact(std::vector<float> ballPosition, std::vector<float> linearFunction){
    float distance = calculateDistanceToImpact(ballPosition, linearFunction);
    float timeToImpact = distance/DISTANCE_COVERED_PER_CYCLE*TIME_CYCLE;

    return timeToImpact;
}