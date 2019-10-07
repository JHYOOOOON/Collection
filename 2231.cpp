#include <iostream>

using namespace std;

int subplus(int x){
    int sum = 0;
    while(1){
        if(x<1){return sum;}
        sum += x%10;
        x/=10;
    }
}

int find(int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = i + subplus(i);
        if(sum == n){return i;}
    }
    return 0;
}

int main(){
    int n, ans;
    cin >> n;
    ans = find(n);

    cout << ans;

    return 0;
}
