#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> dwarf(9);
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> dwarf[i];
        sum += dwarf[i];
    }

    sort(dwarf.begin(), dwarf.end());

    int idx1 = -1, idx2 = -1;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum - (dwarf[i] + dwarf[j]) == 100){
                idx1 = i;
                idx2 = j;
                break;
            }
        }
        if(idx1 != -1) break;
    }

    for(int i=0; i<9; i++)
        if(i != idx1 && i != idx2) cout << dwarf[i] << "\n";
    
    return 0;
}
