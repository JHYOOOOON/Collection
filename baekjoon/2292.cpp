#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, ans = 1, tmp = 1;
  scanf("%d", &N);
  while(1){
    if(N <= tmp){ break; }
    tmp += 6*(ans++);
  }
  printf("%d", ans);

  return 0;
} 
