#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int card[21];
    for(int i=0; i<20; i++) card[i] = i+1;

    // 구간
    int a, b; 
    for(int i=0; i<10; i++){
        cin >> a >> b;
        reverse(card+a-1, card+b);
    }

    for(int i=0; i<20; i++) cout << card[i] << " ";
}
