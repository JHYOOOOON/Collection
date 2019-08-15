#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string answer = "";

void country(int n){
    char arr[3]={'4','1','2'};

    if(n<=0){return;}
    answer+=arr[n%3];

    if(n%3==0){country(n/3-1);}
    else{country(n/3);}
}


string solution(int n) {
    country(n);
    reverse(answer.begin(), answer.end());

    return answer;
}
