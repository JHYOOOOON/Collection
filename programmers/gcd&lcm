#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

vector<int> solution(int n, int m) {
    int a=gcd(n,m);
    int b=lcm(n,m);
    vector<int> answer={a,b};
    return answer;
}
