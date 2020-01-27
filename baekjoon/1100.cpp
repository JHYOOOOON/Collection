#include <bits/stdc++.h>
using namespace std;

int main(){
    char chess[8][8];
    int cnt = 0;
    for(int i=0; i<8; i++)
        cin >> chess[i];
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(((i%2 == 0 && j%2 == 0) || (i%2 == 1 && j%2 == 1)) && chess[i][j] == 'F')
                cnt++;
    cout << cnt << "\n";
    return 0;
}
