#include <string>
#include <vector>
using namespace std;

string binaryConvert(int x, int n){
    string tmp = "";
    while(tmp.length() != n){
        (x%2) ? tmp = '#' + tmp : tmp = ' ' + tmp;
        x/=2;
    }
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> a(n), b(n);
    
    for(int i=0; i<n; i++){
        a[i] = binaryConvert(arr1[i], n);
        b[i] = binaryConvert(arr2[i], n);
    }
    
    for(int i=0; i<n; i++){
        string tmp = "";
        for(int j=0; j<n; j++){
            (a[i][j] == b[i][j] && a[i][j] == ' ') ? tmp += ' ' : tmp += '#';
        }
        answer.push_back(tmp);
    }
    
    
    return answer;
}
