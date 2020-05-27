#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b){
    if(a.X.X != b.X.X) return a.X.X > b.X.X;
    else if(a.X.Y != b.X.Y) return a.X.Y > b.X.Y;
    else if(a.Y.X != b.Y.X) return a.Y.X > b.Y.X;
    else{ return a.Y.Y > b.Y.Y; }
}

int main(){
    int t, tmp;
    pair<pair<int, int>, pair<int, int>> score[4] = {{{0,0}, {0,0}}};
    score[1].Y.Y = 1;
    score[2].Y.Y = 2;
    score[3].Y.Y = 3;
    cin >> t;
    while(t--){
        for(int i=1; i<=3; i++){
            cin >> tmp;
            score[i].X.X += tmp;
            if(tmp == 3){ score[i].X.Y++; }
            else if(tmp == 2){ score[i].Y.X++; }
        }
    }
    sort(score+1, score+4, compare);
    if((score[1].X.X == score[2].X.X) &&
        (score[1].X.Y == score[2].X.Y) &&
        (score[1].Y.X == score[2].Y.X)){
            cout << 0 << ' ' << score[1].X.X << "\n";
        } else{ cout << score[1].Y.Y << ' ' << score[1].X.X << "\n"; }
        
    return 0;
}
