#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main(){
    double a;
    scanf("%lf", &a);
    printf("%.6lf\n", a*a*M_PI);
    printf("%.6lf\n", a*a*2);
    return 0;
}
