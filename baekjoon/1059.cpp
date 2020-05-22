#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int l, n, start_n = 0, end_n;
    cin >> l;
    vector<int> lucky(l);

    for(int i=0; i<l; i++) cin >> lucky[i];
    sort(lucky.begin(), lucky.end());

    cin >> n;

    for(int i=0; i<l; i++)
        if(lucky[i] == n){
            cout << 0 << "\n";
            return 0;
        } else if(lucky[i] < n){
            start_n = lucky[i];
        } else{
            end_n = lucky[i];
            break;
        }

    cout << end_n-n-1 + (end_n-n)*(n-start_n-1) << "\n";
    return 0;
}
