#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool sosu[10010];

void isSosu(){
    sosu[1] = true;
    for(int i=2; i<=sqrt(10000); i++){
        if(sosu[i]) continue;
        for(int j=i+i; j<=10000; j+=i)
            sosu[j] = 1;
    }
}

int main(){
    int p;
    cin >> p;
    while(p--){
        int n, m, tmp;
        bool ishappy = true;
        cin >> n >> m;
        tmp = m;
        
        isSosu();
        if(sosu[m]) ishappy = false;

        set<int> st;
        while(1){
            int s = 0;
            while(m >= 1){
                s += (m%10) * (m%10);
                m /= 10;
            }
            if(s == 1) break;
            if(st.find(s) != st.end()){ ishappy = false; break; }
            else{ st.insert(s); }
            m = s;
        }

        cout << n << ' ' << tmp << ' ';
        (ishappy) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
