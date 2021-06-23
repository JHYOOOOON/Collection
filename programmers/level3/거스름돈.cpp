#include <string>
#include <vector>
#define MAX 100000 + 1
#define MOD 1000000007
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    long long d[MAX];
    
    d[0] = 1;
    for(int i=money[0]; i<=n; i+=money[0]) d[i] = 1;
    
    for(int i=1; i<money.size(); i++)
        for(int j=0; j<=n; j++)
            if(j >= money[i])
                d[j] += d[j-money[i]] % MOD;
    
    answer = d[n];
    return answer;
}
