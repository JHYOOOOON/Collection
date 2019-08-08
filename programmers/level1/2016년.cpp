#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string>week={"THU","FRI","SAT","SUN","MON","TUE","WED"};
    vector<int>v={31,29,31,30,31,30,31,31,30,31,30,31};
    int day=b;
    for(int i=1;i<a;i++){
        day+=v[i-1];
    }
    string answer=week[day%7];
    return answer;
}
