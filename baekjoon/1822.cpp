#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tmp;
    cin >> n >> m;

    // 집합 A
    vector<int> a(n);
    // 집합 B
    vector<int> b(m);
    // 정답
    vector<int> ans;

    // 각 집합 원소값 입력
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int j=0; j<m; j++)
        cin >> b[j];

    // 이진탐색 할 집합 B 오름차순 정렬
    sort(b.begin(), b.end());

    // 이진탐색해서 조건 만족시 정답배열에 푸시
    for(int i=0; i<n; i++)
        if(!binary_search(b.begin(), b.end(), a[i]))
            ans.push_back(a[i]);
    
    // 정답배열 오름차순 정렬
    sort(ans.begin(), ans.end());

    // 출력
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
