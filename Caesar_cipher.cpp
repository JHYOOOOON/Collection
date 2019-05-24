#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	int x;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] < 91) && (s[i] + n > 90)) {
			x = s[i] + n - 91;
			answer += 'A' + x;
		}
		else if ((s[i] < 123) && (s[i] + n > 122)) {
			x = s[i] + n - 123;
			answer += 'a' + x;
		}
		else {
			if (s[i] == ' ') { answer += ' '; }
			else { answer += s[i] + n; }
		}
	}
	return answer;
}

int main(void) {
	string s;
	int n;
	int count = 0;
	while (1)
	{
		cin >> s >> n;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] > 122 || s[i] < 65 || (s[i] < 97 && s[i]>90)) {
				count++;
			}
		}
		if (count > 0) { continue; }
		else { break; }
	}

	cout<<solution(s, n);

	return 0;
}