#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int arr[9], max, index;

    for(int i=0; i<9; i++){
        scanf("%d", &arr[i]);
    }

    max = *max_element(arr, arr+9);
    
    for(int i=0; i<9; i++){
        if(max == arr[i]){index = i+1; break;}
    }

    printf("%d\n%d", max, index);

    return 0;
}
