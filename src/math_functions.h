#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <iostream>
#include <vector>
#include<cmath>

extern float DISTANCE_COVERED_PER_CYCLE;
extern float TIME_CYCLE;
extern int X_LIMIT;
extern int Y_LIMIT;

//std::vector<float> getLinearFunction(std::vector<float> points);
std::vector<float> flipLinearFunction(std::vector<float> linearFunction);
float getEuclideanDistance(std::vector<float> positions);
float calculateDistanceToImpact(std::vector<float> ballPosition, std::vector<float> linearFunction);
float calculateTimeOfImpact(std::vector<float> ballPosition, std::vector<float> linearFunction);
std::vector<float> calculateImpactIntercept(std::vector<float> linearFunction);
std::vector<float> getImpactPoint(const std::vector<float> *linearFunction);
std::vector<float> getLinearFunction(std::vector<std::vector<float>> three_points);


#endif // MATH_FUNCTIONS_H
