#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());

    for(int i=0;i<people.size();i++){
        if(limit - people[i] - people[people.size()-1] >= 0){
            people.erase(people.begin() + people.size() - 1);
        }
        answer++;
    }
    return answer;
}
