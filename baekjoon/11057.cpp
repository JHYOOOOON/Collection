#include <bits/stdc++.h>
using namespace std;
int d[1001][11], n, sum = 0;
int num = 10007;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for(int i=0; i<=9; i++){
    d[1][i] = 1;
  }

  for(int i=2; i<=n; i++){
    for(int j=0; j<=9; j++){
      for(int k=j; k<=9; k++){
        d[i][j] += d[i-1][k];
        d[i][j] %= num;
      }
    }
  }

  for(int i=0; i<=9; i++){
    sum += d[n][i];
  }
  cout << sum % num << endl;
  return 0;
}
