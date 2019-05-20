#include <iostream>

using namespace std;

int gcd(int m, int n) {
	int r;
	while (1) {
		r = m % n;
		if (r == 0) { return n; }
		else {
			m = n;
			n = r;
		}
	}
}

int main(void)
{
	int width, height;
	cin >> width >> height;

	cout << (width/gcd(width,height))*(height/gcd(width,height)) << endl;

	return 0;
}