#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, bill;
    cin >> n >> m;
    vector<int> pack(m);
    vector<int> single(m);

    for(int i=0; i<m; i++) cin >> pack[i] >> single[i];
    sort(pack.begin(), pack.end());
    sort(single.begin(), single.end());

    bill = min(single[0]*n, ((n-1)/6 + 1)*pack[0]);
    if(n > 6 && n/6*pack[0] + n%6*single[0] < bill) bill = n/6*pack[0] + n%6*single[0];

    cout << bill << "\n";

    return 0;
}
