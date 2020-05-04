#include <iostream>
using namespace std;

int main(){
    int stu, k, a, b;
    int room[7][2] = {0};
    cin >> stu >> k;
    for(int i=0; i<stu; i++){
        cin >> a >> b;
        room[b][a]++;
    }

    int cnt = 0;
    for(int i=1; i<=6; i++){
        for(int j=0; j<=1; j++){
            if(!room[i][j]) continue;
            cnt += (room[i][j]-1) / k + 1;
        }
    }
    std::cout << cnt << "\n";

    return 0;
}
