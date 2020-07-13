#include <iostream>
using namespace std;

int main() {
    int month, date;
    cin >> month >> date;
    if (month == 2) {
        if (date == 18)
            cout << "Special\n";
        else if (date < 18)
            cout << "Before\n";
        else
            cout << "After\n";
    } else if (month < 2) {
        cout << "Before\n";
    } else {
        cout << "After\n";
    }

    return 0;
}
