#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int count = 0;
    int a, b;
    priority_queue< int, vector<int>, greater<int> > pq;

    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }

    while(true){
        if(pq.top() >= K){ return count; }
        else if(pq.size() == 1 && pq.top() < K){ return -1; }
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b*2);
        count++;
    }
}
