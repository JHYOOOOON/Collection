#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

struct filename{
    string original, head;
    int number;
};

bool compare(filename a, filename b){
    if(a.head != b.head) return a.head < b.head;
    return a.number < b.number;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<filename> split_filename(files.size());
    
    for(int i=0; i<files.size(); i++){
        split_filename[i].original = files[i];
        string tmp = "";
        bool num_check = false;
        for(char c : files[i]){
            if(isdigit(c) && !num_check){
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                split_filename[i].head = tmp;
                num_check = true;
                tmp = c;
            } else if(!isdigit(c) && num_check){
                break;
            } else { tmp += c; }
        }
        split_filename[i].number = stoi(tmp);
    }
    
    stable_sort(split_filename.begin(), split_filename.end(), compare);
    
    for(filename fn : split_filename) answer.push_back(fn.original);
    
    return answer;
}
