#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Y = 0, M = 0;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    for(int i=0; i<N; i++){
        Y += (v[i]/30 + 1) * 10;
        M += (v[i]/60 + 1) * 15;
    }

    if(M < Y){
        cout << "M " << M << endl;
    }else if (M > Y){
        cout << "Y " << Y << endl;
    }else{
        cout << "Y M " << Y << endl;
    }

    return 0;
}
