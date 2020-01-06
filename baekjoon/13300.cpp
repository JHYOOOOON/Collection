#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, s, y, cnt = 0;
    int stu[7][2]= {0};
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d %d", &s, &y);
        stu[y][s]++;
    }
    for(int i=1; i<=6; i++){
        cnt += stu[i][0] / k + stu[i][1] / k;
        if(stu[i][0] % k != 0) cnt++;
        if(stu[i][1] % k != 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
