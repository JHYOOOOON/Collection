#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, arr[10], t, num = 0;
  scanf("%d %d", &N, &K);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  for(int i=N-1; i>=0; i--){
    t = K/arr[i];
    K -= arr[i]*t;
    num += t;
    if(K == 0) break;
  }
  printf("%d", num);

  return 0;
}
