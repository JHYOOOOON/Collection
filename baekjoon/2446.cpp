#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int k=0; k<i; k++){
            printf(" ");
        }
        for(int j=0; j<N*2-(2*i+1); j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<N-i-1; j++){
            printf(" ");
        }
        for(int k=2*i+1; k>0; k--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
