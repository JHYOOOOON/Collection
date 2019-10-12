#include <iostream>
using namespace std;

int main(){
    char arr[5] = {'E', 'A', 'B', 'C', 'D'};
    int cnt = 0, tmp;

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin >> tmp;
            if(tmp == 0){ cnt++; }
        }
        cout << arr[cnt] << endl;
        cnt = 0;
    }

    return 0;
}
