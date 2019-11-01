#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int k=0; k<i; k++){
            printf(" ");
        }
        for(int j=0; j<2*N-(2*i+1); j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;

}
