#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int temp = 1;
    map<string, int>hash;

    for(int i=0; i<clothes.size(); i++){
        hash[clothes[i][1]]++;
    }

    map<string, int>::iterator iter;
    for (iter = hash.begin(); iter != hash.end(); ++iter){
        answer *= iter->second + 1;
    }

    return answer - 1;
}
