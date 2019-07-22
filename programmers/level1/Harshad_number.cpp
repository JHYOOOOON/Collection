#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int y=x;
    int sum=0;
    do{
        sum+=x%10;
        x/=10;
    }while(x>=1);
    answer=(y%sum==0)?true:false;
    return answer;
}
