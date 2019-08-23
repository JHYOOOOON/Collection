#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int index = 0, next_index = 0;

    if(skill.length() == 1){ return skill_trees.size(); }

    for(int i=0; i<skill_trees.size(); i++){
        for(int j=0; j<skill.length() - 1; j++){
            index = skill_trees[i].find(skill[j]);
            next_index = skill_trees[i].find(skill[j+1]);
            if((index == -1 && next_index != -1)
              || (index > next_index && next_index != -1)){ break; }
            else if(j == skill.length() - 2){ answer++; break; }
        }
    }
    return answer;
}
