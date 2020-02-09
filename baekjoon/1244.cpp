#include <iostream>
using namespace std;

int s[101];

void swap(int a, int b){
    for(int i=a; i<=b; i++)
        (!s[i]) ? s[i] = 1 : s[i] = 0;
}

int main(){
    int n, st, x, cnt;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> s[i];
    cin >> st;
    while(st--){
        cin >> x >> cnt;
        if(x == 1){
            for(int i=cnt; i<=n; i+=cnt)
                (!s[i]) ? s[i] = 1 : s[i] = 0;
        } else if(x == 2) {
            int a = cnt, b = cnt;
            for(int i=1; ;i++){
                if((s[cnt-i] == s[cnt+i]) && (cnt-i >= 1 && cnt+i <= n)){
                    a = cnt-i;
                    b = cnt+i;
                } else { break; }
            }
            swap(a, b);
        }
    }

    for(int i=1; i<=n; i++){
        cout << s[i];
        if(i%20 == 0 || i == n) {
            cout << '\n';
            continue;
        }
        cout << ' ';
    }

    return 0;
}
