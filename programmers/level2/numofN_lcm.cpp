#include <string>
#include <vector>

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

int solution(vector<int> arr) {
    int answer = lcm(arr[0],arr[1]);
    if(arr.size()==1){return arr[0];}
    if(arr.size()==2){return answer;}
    for(int i=2;i<arr.size();i++){
        answer=lcm(answer,arr[i]);
    }
    return answer;
}
