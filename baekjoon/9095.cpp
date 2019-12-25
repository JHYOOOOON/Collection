#include <bits/stdc++.h>
using namespace std;
int d[11], n, t;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;
  while(t--){
    cin >> n;
    for(int i=4; i<=n; i++){
      d[i] = d[i-3] + d[i-2] + d[i-1];
    }
    cout << d[n] << endl;
  }
  return 0;
}
