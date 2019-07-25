#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int j=1;
    int sum=0;
    do{
        for(int i=j;i<=n/2+1;i++){
            sum+=i;
            if(sum==n){answer++; break;}
            else if(sum>n){break;}
        }
        sum=0;
        j++;
    }while(j<n/2+1);
    return answer;
}
