#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> s;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++)
        for(int j=i+1; j<numbers.size(); j++)
            s.insert(numbers[i] + numbers[j]);
    
    set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
        answer.push_back(*it);
    
    return answer;
}
