#include "stdio.h"
#include <math.h>

struct Point {
    double x;
    double y;
};

double distance(struct Point point1, struct Point point2) {
    return sqrt((point1.x - point2.x) * (point1.x - point2.x)
                + (point1.y - point2.y) * (point1.y - point2.y));
}

double area(struct Point point1, struct Point point2, struct Point point3) {
    return fabs(point1.x * point2.y - point2.x * point1.y + point2.x * point3.y
                     - point3.x * point2.y + point3.x * point1.y - point1.x * point3.y) / 2;
}

int main() {
    struct Point a, b, c;
    a.x = 2.5;
    a.y = 6;
    b.x = 1;
    b.y = 2.2;
    c.x = 10;
    c.y = 6;
    printf("Distance: %f\n", distance(a, b));
    printf("Area: %f\n", area(a, b, c));
    return 0;
}
