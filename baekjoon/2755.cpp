#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t, n;
    double score, sum, total_n = 0;
    string s, score_c;
    cin >> t;
    while(t--){
        cin >> s >> n >> score_c;
        total_n += n;
        if(score_c[0] == 'F'){ score = 0; }
        else{
            switch(score_c[0]){
                case 'A': score = 4; break;
                case 'B': score = 3; break;
                case 'C': score = 2; break;
                case 'D': score = 1; break;
            }
            switch(score_c[1]){
                case '+': score += 0.3; break;
                case '0': score += 0; break;
                case '-': score -= 0.3; break;
            }
        }
        sum += n * score;
    }
    
    printf("%.2lf", sum / total_n + 0.000000000001);

    return 0;
}
