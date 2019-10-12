#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, tmp;
    int arr[100001] = {0, };

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        arr[tmp]++;
    }
    for(int i=1; i<100001; i++){
        while(arr[i] != 0){
            printf("%d\n", i);
            arr[i]--;
        }
    }

    return 0;
}
