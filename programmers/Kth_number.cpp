#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
for(int a=0;a<commands.size();a++){
    for(int b=commands[a][0]-1;b<commands[a][1];b++){
        v.push_back(array[b]);
    }
     sort( v.begin(), v.end());
    answer.push_back(v[commands[a][2]-1]);
    v.clear();
}

    return answer;
}
