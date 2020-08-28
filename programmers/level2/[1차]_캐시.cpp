#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> l;
    list<string>::iterator it;
    
    if(!cacheSize) return cities.size() * 5;
        
    for(string s : cities){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        it = find(l.begin(), l.end(), s);
        if(it == l.end()){
            answer += 5;
            if(l.size() == cacheSize) l.pop_front();
        } else{
            answer += 1;
            l.erase(it);
        }
        l.push_back(s);
    }
    return answer;
}
