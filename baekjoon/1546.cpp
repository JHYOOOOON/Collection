#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main(){
    int n, max;
    double sum = 0;
    scanf("%d", &n);
    vector<int> exam(n);

    for(int i=0; i<n; i++){
        scanf("%d", &exam[i]);
    }

    sort(exam.begin(), exam.end(), greater<int>());
    max = exam[0];

    for(int i=0; i<n; i++){
        sum += double(exam[i])/double(max)*100;
    }

    printf("%.6lf", sum/n);

    return 0;
}
