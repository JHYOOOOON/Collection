#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int k, n;
    cin >> k;

    for(int i=1; i<=k; i++){
        int gap = 0;
        cin >> n;
        vector<int> stu(n);
        
        for(int i=0; i<n; i++) cin >> stu[i];
        sort(stu.begin(), stu.end());
        for(int i=1; i<n; i++)
            if(stu[i] - stu[i-1] > gap)
                gap = stu[i] - stu[i-1];

        cout << "Class " << i << "\n";
        cout << "Max " << stu[n-1] << ", Min " << stu[0] << ", Largest gap " << gap << "\n";
    }

    return 0;
}
