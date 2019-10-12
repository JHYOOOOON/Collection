#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[5], sum = 0;
    for(int i=0; i<5; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+6);
    cout << sum/5 << endl << arr[3];

    return 0;
}
