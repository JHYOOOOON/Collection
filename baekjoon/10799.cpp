#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<char> s;
	string laser;
	char tmp;
	int result = 0;
	cin >> laser;
	for(int i=0; i<laser.length(); i++){
		switch (laser[i]){
			case '(': {
				tmp = '(';
				s.push('(');
				break;
			}
			case ')': {
				s.pop();
				if(tmp == '('){
					result += s.size();
				}else{ result++; }
				tmp = ')';
				break;
			}
		}
	}
	cout << result << endl;

	return 0;
}
