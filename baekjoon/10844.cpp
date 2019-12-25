#include <bits/stdc++.h>
using namespace std;
int d[101][11], n, sum = 0;
int num = 1000000000;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  
  for(int i=0; i<=9; i++){
    d[1][i] = 1;
  }

  for(int i=2; i<=n; i++){
    for(int j=0; j<10; j++){
      if(j == 0) d[i][j] = d[i-1][j+1] % num;
      else if(j == 9) d[i][j] = d[i-1][j-1] % num;
      else d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % num;
    }
  }

  for(int i=1; i<=9; i++){
    sum = (sum + d[n][i]) % num;
  }
  cout << sum;
  return 0;
}
