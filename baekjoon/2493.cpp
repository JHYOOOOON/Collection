#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, index;
  scanf("%d", &N);
  vector<int> arr(N), ans(N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  for(int i=0; i<N; i++){
    if(i==0){ans[i] = 0; continue;}
    index = i+1;
    for(int j=i-1; j>=0; j--){
      if(arr[j]>=arr[i]){index = j+1; break;}
    }
    ans[i] = (index != i+1) ? index : 0;
  }

  for(int i=0; i<N; i++){
    printf("%d ",ans[i]);
  }
  return 0;
} 
