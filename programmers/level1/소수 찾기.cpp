#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>v;

    v.push_back(0);
    v.push_back(0);
    for(int i=2; i<=n; i++){
        v.push_back(i);
    }

    for(int i=2; i<=sqrt(n); i++){
        if(v[i] == 0){ continue; }
        for(int j=2*i; j<=n; j+=i){
            v[j] = 0;
        }
    }

    for(int i=0; i<v.size(); i++){
        if(v[i] != 0){ answer++; }
    }

    return answer;
}
