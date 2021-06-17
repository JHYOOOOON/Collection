#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // v: arr1의 행, m: arr1의 열, arr2의 행, h: arr2의 열
    int v = arr1.size(), m = arr1[0].size(), h = arr2[0].size();
    vector<vector<int>> answer(v, vector<int>(h, 0));
    
    for(int i=0; i<v; i++)
        for(int j=0; j<h; j++){
            int n = 0;
            while(n < m){
                answer[i][j] += arr1[i][n] * arr2[n][j];
                n++;
            }
        }
    
    return answer;
}
