#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(9);
    int tmp = 0;
    bool flag = false;
    for(int i=0; i<9; i++){
        cin >> a[i];
        tmp += a[i];
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(i == j) break;
            if(tmp - a[i] - a[j] == 100){
                flag = true;
                a[i] = 101;
                a[j] = 101;
                break;
            }
        }
        if(flag) break;
    }

    sort(a.begin(), a.end());
    for(int i=0; i<7; i++) cout << a[i] << endl;

    return 0;
}
