#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] + arr[1] + arr[2] != 180)
        cout << "Error\n";
    else if (arr[0] == arr[1] && arr[1] == arr[2])
        cout << "Equilateral\n";
    else if (arr[0] == arr[1] || arr[1] == arr[2])
        cout << "Isosceles\n";
    else
        cout << "Scalene\n";
    return 0;
}
