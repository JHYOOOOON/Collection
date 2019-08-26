#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    if(number[0] == number[number.length()-1] && number [1] == number[number.length()-2]){
        number = number.substr(0,number.length()-k);
        return number;
    }

    for(k; k>0; k--){
        for(int i=0; i<number.length(); i++){
            if(number[i] < number[i+1]){
                number = number.substr(0,i) + number.substr(i+1);
                break;
            }
            else if(i == number.length() - 1){
                number = number.substr(0,i);
                break;
            }
        }
    }
    return number;
}
