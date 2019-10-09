#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main(){
    int arr[10], remain[42] = {0}, ans = 0;
    for(int i=0; i<10; i++){
        scanf("%d", &arr[i]);
        remain[arr[i]%42]++;
    }

    sort(remain, remain + 42, greater<int>());
    for(int i=0; i<42; i++){
        if(remain[i] == 0){break;}
        ans++;
    }

    printf("%d", ans);

    return 0;
}
