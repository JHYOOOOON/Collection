#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    // 바닥
    if (i == n-1) {
      for(int j=0; j<2*(i+1)-1; j++){ cout << '*'; }
    } else { // 몸통
      for(int j=0; j<n-1-i; j++){ cout << ' '; }
      cout << '*';
      if(i != 0){ // 첫줄 아니면
        for(int k=0; k<2*i-1; k++){ cout << ' '; }
        cout << '*';
      }
    }
    cout << endl;
  }
  return 0;
}
