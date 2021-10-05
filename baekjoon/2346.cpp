#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, x;
    deque<pair<int, int>> balloons;
    
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        balloons.push_back({i, x});
    }

    int idx, nxt;
    while(!balloons.empty()){
        idx = balloons.front().first;
        nxt = balloons.front().second;
        balloons.pop_front();
        cout << idx << " ";

        if(nxt > 0){
            nxt--;
            while(nxt--){
                balloons.push_back(balloons.front());
                balloons.pop_front();   
            }
        } else{
            nxt *= -1;
            while(nxt--){
                balloons.push_front(balloons.back());
                balloons.pop_back();    
            }
        }
    }
    return 0;
}
