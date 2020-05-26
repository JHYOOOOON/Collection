#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string a, b, a_real = "", b_real = "", sum = "";
	bool flag = false;
    int len, a_len, b_len;
	cin >> a >> b;
    a_len = a.length();
    b_len = b.length();
	len = abs(a_len - b_len);
	if(a_len > b_len){
		a_real = a;
		for(int i=0; i<len; i++) b_real += '0';
		b_real += b;
	} else if(a_len < b_len){
		b_real = b;
		for(int i=0; i<len; i++) a_real += '0';
		a_real += a;
	} else{
        a_real = a;
        b_real = b;
    }

	len = a_real.length();
	for(int i=len-1; i>=0; i--){
		if(a_real[i] == b_real[i] && a_real[i] == '0'){
            sum = (flag) ? '1' + sum : '0' + sum;
			flag = false;
		} else if(a_real[i] != b_real[i]){
            sum = (flag) ? '0' + sum : '1' + sum;
		} else{
            sum = (flag) ? '1' + sum : '0' + sum;
            flag = true;
		}
	}
	if(flag){ sum = '1' + sum; }

    for(int i=0; i<sum.length(); i++){
        if(sum[i] == '1'){
            sum = sum.substr(i);
            cout << sum << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
	return 0;
}
