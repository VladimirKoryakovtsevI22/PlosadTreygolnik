// structure.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

struct Point
{
    int x;
    int y;
};

float calculateDistance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool isTriangle(Point p1, Point p2, Point p3)
{
    float a = calculateDistance(p1, p2);
    float b = calculateDistance(p2, p3);
    float c = calculateDistance(p3, p1);

    return a + b > c && a + c > b && c + b > a;
}

int main()
{
    const int n = 3;
    Point coord[n] = { {5, 6}, {2, 4}, {8, 3} };

    if (isTriangle(coord[0], coord[1], coord[2]))
    {
        float a = calculateDistance(coord[0], coord[1]);
        float b = calculateDistance(coord[1], coord[2]);
        float c = calculateDistance(coord[2], coord[0]);

        float P = (a + b + c) / 2;
        float S = sqrt(P * (P - a) * (P - b) * (P - c));

        printf("S triangle = %3.f\n", S);
    }
    else
    {
        printf("It is not a triangle.\n");
    }

    return 0;
}
