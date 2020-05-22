#include <iostream>
using namespace std;

int main(){
    int n = 1;
    long long s, sum = 0;
    cin >> s;

    while(1){
        sum += n;
        if(sum > s){
            n--;
            break;
        }
        n++;
    }

    cout << n << "\n";

    return 0;
}
