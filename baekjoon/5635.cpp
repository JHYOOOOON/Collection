#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

bool compare(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b){
    if(a.Y.Y != b.Y.Y){ return a.Y.Y > b.Y.Y; }
    else if(a.Y.X != b.Y.X){ return a.Y.X > b.Y.X; }
    else if(a.X.Y != b.X.Y) { return a.X.Y > b.X.Y; }
}

int main(){
    int n;
    cin >> n;
    vector<pair<pair<string, int>, pair<int, int>>> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].X.X >> v[i].X.Y >> v[i].Y.X >> v[i].Y.Y;
    
    sort(v.begin(), v.end(), compare);

    cout << v[0].X.X << "\n" << v[n-1].X.X << "\n";

    return 0;
}
