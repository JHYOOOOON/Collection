#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> dir[] = {{1, 0}, {0, 1}, {-1, -1}};

vector<int> solution(int n) {
    vector<vector<int>> snail(n, vector<int>(n));
    int num = 1, x = 0, y = 0, k = 0;
    while(1){
        if(snail[x][y]) break; // 다음 자리에 숫자가 있으면 다 채워진 거
        snail[x][y] = num++;
        
        int tmp_x = x, tmp_y = y;
        tmp_x += dir[k].first;
        tmp_y += dir[k].second;
        if(tmp_x < 0 || tmp_x >= n || tmp_y < 0 || tmp_y >= n || snail[tmp_x][tmp_y])
            k = (k + 1 < 3) ? k + 1 : 0;
        
        x += dir[k].first;
        y += dir[k].second;
    }
    
    vector<int> answer;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(snail[i][j]) answer.push_back(snail[i][j]);
                
    return answer;
}
