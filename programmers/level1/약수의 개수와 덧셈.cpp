#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(left; left<=right; left++){
        int cnt = 0;
        for(int i=1; i<=left; i++)
            if(left % i == 0) cnt++;
        (cnt % 2) ? answer -= left : answer += left;
    }
    return answer;
}
