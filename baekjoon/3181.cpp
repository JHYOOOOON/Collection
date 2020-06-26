#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, tmp;
    stringstream stream;
    vector<string> v;

    getline(cin, s);
    stream.str(s);
    while (stream >> tmp) {
        if (v.empty())
            v.push_back(tmp);
        else if (tmp != "i" && tmp != "pa" && tmp != "te" && tmp != "ni" &&
                 tmp != "niti" && tmp != "a" && tmp != "ali" && tmp != "nego" &&
                 tmp != "no" && tmp != "ili")
            v.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++) cout << char(v[i][0] - 'a' + 'A');

    return 0;
}
