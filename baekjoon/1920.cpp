#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tmp;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    // 배열 a를 이진탐색을 위해 오름차순 정렬
    sort(a.begin(), a.end());

    cin >> m;
    while(m--){
        cin >> tmp;
        if(binary_search(a.begin(), a.end(), tmp)){
            cout << 1 << "\n";
        } else { cout << 0 << "\n"; }
    }
    return 0;
}
