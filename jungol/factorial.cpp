#include <iostream>

using namespace std;

long long factorial(int n);

int main(void)
{
	int n;
	cin >> n;

	cout << factorial(n) << endl;
	
	return 0;
}

long long factorial(int n)
{
	if (n <= 1) {
		cout << "1! = 1" << endl;
		return 1;
	}
	else {
		cout << n << "! = " << n << " * " << n - 1 << '!' << endl;
		return n * factorial(n - 1);
	}
}