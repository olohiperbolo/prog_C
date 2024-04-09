#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Point;
void change(Point * p){
    p -> x++;
    p -> y++;
}
typedef struct{
    Point A;
    Point B;
    Point C;
    Point D;
} Rectangle;
double sideLength(Point p1, Point p2){
    return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));
}
double Obwod(Rectangle rect){
    double sideAB = sideLength(rect.A, rect.B);
    double sideBC = sideLength(rect.B, rect.C);
    double sideCD = sideLength(rect.C, rect.D);
    double sideDA = sideLength(rect.D, rect.A);
    return sideAB + sideBC + sideCD + sideDA;
}
int main() {
    Point p1 = {3 ,5};
    change(&p1);

    printf("x: %i\n", p1.x);
    printf("y: %i\n", p1.y);

    Rectangle r1 = {{-5,2},{-5,-4},{3,-4},{3,2}};

    printf("Obwod protokata = %.2f", Obwod(r1));

    return 0;
}
