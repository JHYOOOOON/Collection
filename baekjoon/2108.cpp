#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    int n;
    double sum = 0, aver;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> choi;
    // 입력받을 때 sum을 같이 구해줌
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    // 받은 값 배열 오름차순 정렬
    sort(v.begin(), v.end());
    // 최빈값 구하기
    int cnt, tmp;
    for(int i=0; i<n; i+=cnt){
        cnt = 1;
        tmp = v[i];
        for(int j=i+1; j<n; j++){
            if(v[j] == tmp) cnt++;
            else break;
        }
        choi.push_back({cnt, v[i]});
    }
    // 최빈값 조건에 따라 정렬
    sort(choi.begin(), choi.end(), compare);
    // 평균값 구하기 (-0이 나올 때가 있어서 처리해줌)
    aver = round(sum/n);
    if(aver == -0) aver = 0;
    
    // 산술평균
    cout << aver << "\n";
    // 중앙값
    cout << v[n/2] << "\n";
    // 최빈값
    if(choi[0].first == choi[1].first){
        cout << choi[1].second << "\n";
    } else {cout << choi[0].second << "\n"; }
    // 범위(아까 정렬해놔서 끝값에서 처음값 빼면 됨)
    cout << v[n-1] - v[0] << "\n";

    return 0;
}
