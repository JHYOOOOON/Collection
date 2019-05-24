#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	int num = A * B*C;
	int a[10] = { 0 };

	do {
		a[num % 10]++;
		num /= 10;
	} while (num != 0);


	for (int i = 0; i < 10; i++) {
		cout << a[i] << endl;
	}

	return 0;
}
