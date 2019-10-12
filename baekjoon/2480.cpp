#include <iostream>
using namespace std;

int main(){
    int dice, arr[7] = {0, }, cnt = 0;
    for(int i=0; i<3; i++){
        scanf("%d", &dice);
        arr[dice]++;
    }
    for(int i=1; i<7; i++){
        if(arr[i] == 3){ cout << 10000 + i*1000; break; }
        else if(arr[i] == 2){ cout << 1000 + i*100; break; }
        else if(arr[i] == 1){
            cnt++;
            if(cnt == 3){ cout << i*100; break;}
        }
    }
    
    return 0;
}
