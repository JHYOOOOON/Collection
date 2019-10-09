#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, flag = 1, ans = 0;
    scanf("%d", &n);
    vector<string> ox(n);
    
    for(int i=0; i<n; i++){
        cin >> ox[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<ox[i].length(); j++){
            if(ox[i][j] == 'O'){
                ans += flag;
                flag++;
            }else{ flag = 1; }
        }
        printf("%d\n", ans);
        ans = 0;
        flag = 1;
    }

    return 0;
}
