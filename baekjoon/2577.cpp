#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a, b, c, x, arr[10] = {0};
    scanf("%d %d %d", &a, &b, &c);
    x = a*b*c;

    while(1){
        arr[x%10]++;
        x/=10;
        if(x<1){break;}
    }

    for(int i=0; i<10; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
