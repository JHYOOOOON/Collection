#include <iostream>
#define MAX 10
#define d first
#define w second
using namespace std;

int n;
pair<int, int> eggs[MAX];
int mx = 0;

void cnt() {
    int tmp = 0;
    for (int i = 0; i < n; i++)
        if (eggs[i].d <= 0) tmp++;

    // 깨진 계란 최대
    mx = max(mx, tmp);
    return;
}

void crackEggs(int idx) {
    // 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란이면
    if (idx == n) {
        cnt();
        return;
    }

    // 이미 깨진 계란이면 오른쪽 계란으로
    if (eggs[idx].d <= 0) {
        crackEggs(idx + 1);
        return;
    }

    // 계란을 깼는지 확인
    bool flag = true;
    for (int i = 0; i < n; i++) {
        // 자기자신이거나 깨진 계란이면 넘어가기
        if (i == idx || eggs[i].d <= 0) continue;
        flag = false;

        eggs[idx].d -= eggs[i].w;
        eggs[i].d -= eggs[idx].w;

        crackEggs(idx + 1);

        eggs[idx].d += eggs[i].w;
        eggs[i].d += eggs[idx].w;
    }

    // 다른 계란이 다 깨져서 계란을 못깼으면 마지막으로
    if (flag) crackEggs(n);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> eggs[i].d >> eggs[i].w;

    crackEggs(0);

    cout << mx << "\n";

    return 0;
}
