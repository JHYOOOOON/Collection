#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int count=0;
    long n=num;
    if(n==1){return 0;}
    while(1){
        if(n%2==0){
            n/=2;
            count++;
        }
        else{
            n=n*3+1;
            count++;
        }

        if(n==1) {return count;}
        if(count==500) {return -1;}
    }
}
