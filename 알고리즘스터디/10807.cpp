#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, v, cnt = 0;
    cin >> n;
    vector<int> num(n);

    for(int i=0; i<n; i++) cin >> num[i];
    cin >> v;

    cnt = count(num.begin(), num.end(), v);
    
    cout << cnt << "\n";

    return 0;
}
