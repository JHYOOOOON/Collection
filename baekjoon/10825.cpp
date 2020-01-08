#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    int kor, eng, mth;
} STUDENT;

bool cmp(STUDENT a, STUDENT b){
    if (a.kor != b.kor){
        return a.kor > b.kor;
    } else if (a.eng != b.eng){
        return a.eng < b.eng;
    } else if (a.mth != b.mth){
        return a.mth > b.mth;
    } else {
        return a.name < b.name;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    STUDENT arr[100001];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].mth;
    }
    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++){
        cout << arr[i].name << "\n";
    }
    return 0;
}
