#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    string a, b;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        (a==b)?printf("Possible\n"):printf("Impossible\n");
    }
    return 0;
}
