#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[4] = {0, 1, 2, 3}, m, a, b;
    cin >> m;
    while (m--){
        cin >> a >> b;
        swap(arr[a], arr[b]);
    }
    for (int i = 1; i <= 3; i++)
        if (arr[i] == 1)
            cout << i << "\n";

    return 0;
}
