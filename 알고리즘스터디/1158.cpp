#include <iostream>
#include <list>
using namespace std;

int main(){
    int n, k;
    list<int> l;
    cin >> n >> k;
    for(int i=1; i<=n; i++) l.push_back(i);

    cout << '<';
    while(!l.empty()){
        for(int i=1; i<k; i++){
            l.push_back(l.front());
            l.pop_front();
        }
        cout << l.front();  l.pop_front();
        if(l.empty()) continue;
        cout << ", ";
    }
    cout << '>';

    return 0;
}
