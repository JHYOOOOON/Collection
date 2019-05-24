#include <iostream>

using namespace std;

void kind1(int n);
void kind2(int n);
void kind3(int n);
void kind4(int n);

int main(void)
{
	int n, m;
	cin >> n >> m;
	if (n < 1 || n>100 || n % 2 == 0 || m < 1 || m>4)
	{
		cout << "INPUT ERROR!" << endl; return 0;
	}
	
	switch (m)
	{
	case 1: kind1(n); break;
	case 2: kind2(n); break;
	case 3: kind3(n); break;
	case 4: kind4(n); break;
	}

	return 0;
}


void kind1(int n)
{
	int i, j;
	for (i = 0; i < n / 2 + 1; i++) {
		for (j = 0; j <i+1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	for (i = 0; i < n / 2; i++) {
		for (j = n / 2; j > i; j--) {
			cout << '*';
		}
		cout << endl;
	}

}
void kind2(int n)
{
	int i, j, k;
	for (i = 0; i < n / 2 + 1; i++) {
		for (j = n / 2; j > i; j--) {
			cout << ' ';
		}
		for (k = 0; k <= i; k++) {
			cout << '*';
		}
		cout << endl;
	}
	for (i = 0; i < n / 2; i++) {
		for (j = 0; j <= i; j++) {
			cout << ' ';
		}
		for (k = n / 2; k > i; k--) {
			cout << '*';
		}
		cout << endl;
	}
}
void kind3(int n)
{
	int i, j, k;
	for (i = 0; i < n / 2 + 1; i++) {
		for (k = 0; k < i; k++) {
			cout << ' ';
		}
		for (j = n; j > 2 * i; j--) {
			cout << '*';
		}
		cout << endl;
	}
	for (i = 0; i < n / 2; i++) {
		for (k = n / 2; k > i + 1; k--) {
			cout << ' ';
		}
		for (j = 3 + 2 * i; j > 0; j--) {
			cout << '*';
		}
		cout << endl;
	}
}
void kind4(int n)
{
	int i, j, k;
	for (i = 0; i < n / 2 + 1; i++) {
		for (j = 0; j < i; j++) {
			cout << ' ';
		}
		for (k = n / 2 + 1; k > i; k--) {
			cout << '*';
		}
		cout << endl;
	}
	for (i = 0; i < n / 2; i++) {
		for (j = 0; j < n / 2; j++) {
			cout << ' ';
		}
		for (k = 0; k < i + 2; k++) {
			cout << '*';
		}
		cout << endl;
	}
}

