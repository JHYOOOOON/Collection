#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int main(){
    float c, n, sum = 0, avg, per = 0;
    scanf("%f", &c);
    for(int i=0; i<c; i++){
        scanf("%f", &n);
        vector<int> stud(n);
        for(int j=0; j<n; j++){
            scanf("%d", &stud[j]);
            sum += stud[j];
        }
        avg = sum / n;

        for(int j=0; j<n; j++){
            if(stud[j] > avg){ per++; }
        }
        printf("%.3lf%%\n", per/n*100);
        per = 0; sum = 0;
    }

    return 0;
}
