#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main(){
    int a[8]={1,2,3,4,5,6,7,8}, b[8];

    for(int i=0; i<8; i++){
        scanf("%d", &b[i]);
    }

    for(int i=0; i<8; i++){
        if(a[i] != b[i]){break;}
        else if(a[i] == b[i] && i==7){
            printf("ascending\n");
            return 0;
        }
    }

    sort(a,a+8,greater<int>());
    for(int i=0; i<8; i++){
        if(a[i] != b[i]){break;}
        else if(a[i] == b[i] && i==7){
            printf("descending\n");
            return 0;
        }
    }
    printf("mixed\n");
    return 0;
}
