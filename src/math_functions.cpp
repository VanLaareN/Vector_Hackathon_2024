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
int X_LIMIT = 10;
int Y_LIMIT = 10;

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



std::vector<float> calculateImpactIntercept(std::vector<float> linearFunction){
    float x_intercept1 = linearFunction[1]/linearFunction[0] * (-1);
    std::vector<float> point1 = {x_intercept1, 0};

    float x_intercept2 = (Y_LIMIT - linearFunction[1])/linearFunction[0];
    std::vector<float> point2 = {x_intercept2, (float) Y_LIMIT};

    std::vector<float> points = {x_intercept1, x_intercept2, 0, (float) Y_LIMIT};
    float ankathete = abs(abs(x_intercept2)-abs(x_intercept1));
    float a = getEuclideanDistance(points);
    
    double theta = acos(ankathete/a);

    

    float gamma = M_PI-2.0f*theta;
    
    float c = 2.0f*a*sin(gamma/2);

    

    float leftOver = X_LIMIT % (int) c;

    float y_intercept = leftOver/tan(gamma/2.0f);

    std::vector<float> vec = {(float) X_LIMIT, y_intercept};
    return vec;

}