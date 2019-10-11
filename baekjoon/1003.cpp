#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> d[41];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcase;
    cin >> testcase;
    vector<int> n(testcase);

    d[0] = {1, 0};
    d[1] = {0, 1};

    for(int i=0; i<testcase; i++){
        cin >> n[i];
        for(int j=2; j<=n[i]; j++){
            d[j] = { d[j-1].first + d[j-2].first, d[j-1].second + d[j-2].second };
        }
        cout << d[n[i]].first << ' ' << d[n[i]].second << endl;
    }

    return 0;
}
