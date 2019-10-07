#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef tuple<int, int, int> triple;

int main(){
    int n, x, y;
    scanf("%d", &n);
    vector<pair<int, int>> weight;
    vector<int> ans(n, n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        weight.push_back(pair<int,int>(x,y));
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(weight[i].first > weight[j].first
            && weight[i].second > weight[j].second){
                ans[i]--;
            }else if(weight[i].first < weight[j].first
            && weight[i].second < weight[j].second){
                ans[j]--;
            }else{
                ans[i]--;
                ans[j]--;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }

    return 0;
}
