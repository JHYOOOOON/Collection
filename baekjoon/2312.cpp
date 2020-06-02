#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=2; i<=n; i++){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n/=i;
            }
            if(cnt)
                cout << i << ' ' << cnt << "\n";
            if(n == 1) break;
        }
    }

    return 0;
}
