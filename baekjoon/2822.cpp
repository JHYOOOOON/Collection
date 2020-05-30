#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(){
    vector<pair<int, int>> num;
    int score;
    for(int i=1; i<=8; i++){
        cin >> score;
        num.push_back({score, i});
    }
    sort(num.begin(), num.end(), greater<pair<int, int>>());

    vector<int> index;
    int sum = 0;
    for(int i=0; i<5; i++){
        index.push_back(num[i].second);
        sum += num[i].first;
    }
    sort(index.begin(), index.end());

    cout << sum << "\n";
    for(int i=0; i<5; i++) cout << index[i] << ' ';

    return 0;
}
