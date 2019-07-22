#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    double N=sqrt(n);
    if(N-(long)N==0){return pow(N+1,2);}
    else{return -1;}
}
