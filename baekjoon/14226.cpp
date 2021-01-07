#include <iostream>
#include <queue>
#include <tuple>
#define MAX 1000 + 1
using namespace std;

int s;
bool visited[MAX][MAX];

int main(){
    cin >> s;
    
    queue<tuple<int, int, int>> q;
    q.push({1, 0, 0});
    visited[1][0] = 1;

    int emoti, clip, time;
    while(!q.empty()){
        tie(emoti, clip, time) = q.front();
        q.pop();

        if(emoti == s){
            cout << time << "\n";
            return 0;
        }

        if(!visited[emoti][emoti]){
            visited[emoti][emoti] = 1;
            q.push({emoti, emoti, time+1});
        }

        if(clip > 0 && emoti + clip < MAX){
            if(!visited[emoti + clip][clip]){
                visited[emoti + clip][clip] = 1;
                q.push({emoti + clip, clip, time + 1});
            }
        }

        if(emoti - 1 >= 0 && !visited[emoti - 1][clip]){
            visited[emoti - 1][clip] = 1;
            q.push({emoti - 1, clip, time + 1});
        }
    }
}
