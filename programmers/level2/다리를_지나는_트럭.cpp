#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0, time = 0, idx = 0;
    queue<pair<int, int>> q;
    while(++time){
        if(!q.empty() && q.front().second == time){
            sum -= q.front().first;
            q.pop();
        }
        if(sum + truck_weights[idx] <= weight && idx < truck_weights.size()){
            q.push({truck_weights[idx], time + bridge_length});
            sum += truck_weights[idx++];
        }
        if(q.empty() && idx == truck_weights.size()) break;
    }
    return time;
}
