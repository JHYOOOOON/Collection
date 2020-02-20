#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string s, tmp = "";
    bool flag, error;
    char x;
    deque<string> dq;

    // 테스트케이스 입력
    cin >> t;
    while (t--){
        // 방향 알려주는 변수 true: 정, false: 역
        flag = true;
        // error 유무 변수
        error = false;
        // dq 비우기
        dq.clear();
        // 문자열 입력
        cin >> s;
        // 원소 개수 입력
        cin >> n;
        // dq 입력받기
        while (1){
            cin >> x;
            if (x >= '0' && x <= '9'){
                tmp += x;
            }else if (x == ','){
                dq.push_back(tmp);
                tmp = "";
            }else if (x == ']'){
                if (n != 0){
                    dq.push_back(tmp);
                    tmp = "";
                }
                break;
            }
        }
        // R, D 수행
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'R'){
                flag = flag ? false : true;
            }
            else{
                // dq가 비었을 때 D가 들어오면 오류처리
                if (dq.empty()){
                    error = true;
                    break;
                }
                // 정방향일 때는 앞에 원소를, 역방향일 때는 뒤에 원소를 빼줌
                if (flag){
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }
        // 에러 났을 때는 에러 출력
        if (error){
            cout << "error" << "\n";
        }
        // 정방향일 때는 정방향으로 역방향일 때는 역방향으로 출력
        else {
            cout << '[';
            if (flag){
                for (int i = 0; i < dq.size(); i++){
                    cout << dq[i];
                    if (i == dq.size() - 1)
                        continue;
                    cout << ',';
                }
            } else{
                for (int i = dq.size() - 1; i >= 0; i--){
                    cout << dq[i];
                    if (i == 0)
                        continue;
                    cout << ',';
                }
            }
            cout << ']' << "\n";
        }
    }
    return 0;
}
