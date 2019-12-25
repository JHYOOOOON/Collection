#include <iostream>
#include <algorithm>
using namespace std;

int d[10001], podo[10001], n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> podo[i];
  }
  d[1] = podo[1];
  d[2] = podo[1] + podo[2];
  for(int i=3; i<=n; i++){
    d[i] = max(d[i-1], max(d[i-2] + podo[i], d[i-3] + podo[i-1] + podo[i]));
  }
  cout << d[n] << endl;
  return 0;
}
