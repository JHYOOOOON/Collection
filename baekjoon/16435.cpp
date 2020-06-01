#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, l, h;
    cin >> n >> l;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(v[i] > l) break;
        l++;
    }
    cout << l << "\n";
    return 0;
}
