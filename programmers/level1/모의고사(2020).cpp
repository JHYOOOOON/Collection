#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int math1[5]={1,2,3,4,5};
    int math2[8]={2,1,2,3,2,4,2,5};
    int math3[10]={3,3,1,1,2,2,4,4,5,5};
    int score[3]={0};
    int max;

    for(int i=0;i<answers.size();i++){
        if(math1[i%5]==answers[i]){score[0]++;}
        if(math2[i%8]==answers[i]){score[1]++;}
        if(math3[i%10]==answers[i]){score[2]++;}
    }
    max=score[0];
    for(int i=1;i<=2;i++){
        max=(max>score[i])?max:score[i];
    }
    for(int i=0;i<3;i++){
        if(score[i]==max){answer.push_back(i+1);}
    }
    return answer;
}
