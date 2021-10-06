#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

set<tuple<int, int, int>> visited;
queue<tuple<int, int, int>> q;

void checkVisited(int x, int y, int z){
    int arr[3];

    arr[0] = x, arr[1] = y, arr[2] = z;
    sort(arr, arr+3);
    if(visited.find({arr[0], arr[1], arr[2]}) != visited.end()) return;
    visited.insert({arr[0], arr[1], arr[2]});
    q.push({arr[0], arr[1], arr[2]});

    return;
}

int main(){
    int a, b, c;
    int arr[3];
    for(int i=0; i<3; i++) cin >> arr[i];
    sort(arr, arr+3);

    visited.insert({arr[0], arr[1], arr[2]});
    q.push({arr[0], arr[1], arr[2]});

    int x, y, z;
    while(!q.empty()){
        tie(x, y, z) = q.front();
        q.pop();
        
        if(x == y && y == z){
            cout << "1\n";
            return 0;
        }

        if(x != y){
            int nx, ny;
            if(x > y){
                nx = x - y;
                ny = y + y;
            } else{
                nx = x + x;
                ny = y - x;
            }
            checkVisited(nx, ny, z);
        }

        if(y != z){
            int ny, nz;
            if(y > z){
                ny = y - z;
                nz = z + z;
            } else{
                ny = y + y;
                nz = z - y;
            }
            checkVisited(x, ny, nz);
        }

        if(x != z){
            int nx, nz;
            if(x > z){
                nx = x - z;
                nz = z + z;
            } else{
                nx = x + x;
                nz = z - x;
            }
            checkVisited(nx, y, nz);
        }
    }

    cout << "0\n";

    return 0;
}
