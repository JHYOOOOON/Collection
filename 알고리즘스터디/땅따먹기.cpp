#include <iostream>
#include <vector>
#define MAX 100000 + 1
using namespace std;

int d[MAX][4];

int solution(vector<vector<int>> land){
    int answer = 0;
    int landsize = land.size();

    for(int i=0; i<4; i++) d[0][i] = land[0][i];
    
    for(int i=1; i<landsize; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                if(j != k)
                    d[i][k] = max(d[i][k], d[i-1][j] + land[i][k]);
    
    for(int i=0; i<4; i++) answer = max(answer, d[landsize-1][i]);
    
    return answer;
}
