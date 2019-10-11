#include <string>
#include <vector>

using namespace std;

int d[501][501];

int solution(vector<vector<int>> triangle) {
    for(int i=0; i<triangle.size(); i++){
        d[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }
    for(int i=triangle.size()-1; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            d[i][j] = max(d[i+1][j], d[i+1][j+1]) + triangle[i][j];
        }
    }
    return d[0][0];
}
