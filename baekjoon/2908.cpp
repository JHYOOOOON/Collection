#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string arr[2];
    cin >> arr[0] >> arr[1];
    reverse(arr[0].begin(), arr[0].end());
    reverse(arr[1].begin(), arr[1].end());
    (arr[0]>arr[1]) ? cout<<arr[0] : cout<<arr[1];
    return 0;
}
