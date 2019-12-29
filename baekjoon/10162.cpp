#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, t;
  cin >> t;
  if(t % 10 != 0){
    cout << -1 << endl;
  } else {
    a = t / 300;
    t %= 300;
    b = t / 60;
    t %= 60;
    c = t / 10;
    t %= 10;
    cout << a << ' ' << b << ' ' << c << endl;
  }

  return 0;
}
