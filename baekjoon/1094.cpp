#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, cnt = 0, sum = 64;
    vector<int> len;
    len.push_back(64);
    cin >> x;
    while(x != sum){
        len[len.size()-1] /= 2;
        len.push_back(len[len.size()-1]);
        if(sum - len[len.size()-1] >= x){
            sum -= len[len.size()-1];
            len.erase(len.end()-1);
        }
    }
    cout << len.size() << "\n";
    return 0;
}
