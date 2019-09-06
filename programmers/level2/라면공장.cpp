#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j=0;
    priority_queue<int, vector<int>,less<int>> storage;

    for(int i=0; i<k; i++){
        if(dates[j]==i){
            storage.push(supplies[j]);
            if(j!=supplies.size()-1){j++;}
        }
        if(stock == 0){
            stock+=storage.top();
            storage.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}
