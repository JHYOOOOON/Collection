#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n >> str;

    vector<int> alpha(n, 0);
    for(int i=0; i<n; i++) cin >> alpha[i];

    stack<double> st;
    for(char c : str){
        if('A' <= c && c <= 'Z') st.push(alpha[c-'A']);
        else{
            double y = st.top();
            st.pop();
            double x = st.top();
            st.pop();

            switch(c){
                case '+': {
                    st.push(x+y);
                    break;
                }
                case '-': {
                    st.push(x-y);
                    break;
                }
                case '*': {
                    st.push(x*y);
                    break;
                }
                case '/': {
                    st.push(x/y);
                    break;
                }           
            }
        }
    }

    printf("%.2f", st.top());

    return 0;
}
