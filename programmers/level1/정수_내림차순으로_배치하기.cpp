#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string tmp = to_string(n);
    sort(tmp.begin(), tmp.end(), greater<char>());
    answer = stoll(tmp);
    return answer;
}
