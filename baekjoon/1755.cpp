#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string s[15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int m, n;
    cin >> m >> n;

    vector<pair<string, int>> v;
    for(int i=m; i<=n; i++){
        string alpha = (i < 10) ? s[i] : s[i/10] + s[i%10];
        v.push_back({alpha, i});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n-m+1; i++){
        cout << v[i].second << ' ';
        if((i+1) % 10 == 0) cout << "\n";
    }

    return 0;
}
