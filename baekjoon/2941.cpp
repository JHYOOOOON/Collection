#include <iostream>
#include <string>
using namespace std;

int main(){
    string croatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    int tmp;
    cin >> s;

    for(int i=0; i<8; i++){
        while(1){
            tmp = s.find(croatia[i]);
            if(tmp == -1){break;}
            if(i == 2){s.replace(tmp, 3, "a");}
            else{s.replace(tmp, 2, "a");}
        }
    }

    cout << s.length();

    return 0;
}
