#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool genre_cp(pair<int, string> a, pair<int, string> b){
    return a.first > b.first;
}

bool play_cp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_store;
    
    for(int i=0; i<genres.size(); i++)
        genre_store[genres[i]] += plays[i];
    
    vector<pair<int, string>> genre_sort;
    for(auto it=genre_store.begin(); it!=genre_store.end(); it++)
        genre_sort.push_back({it->second, it->first});
    
    sort(genre_sort.begin(), genre_sort.end(), genre_cp);
    
    for(auto g : genre_sort){
        // {plays, number}
        vector<pair<int, int>> temp;
        string genre = g.second;
        for(int i=0; i<plays.size(); i++)
            if(genres[i] == genre) temp.push_back({plays[i], i});
        
        sort(temp.begin(), temp.end(), play_cp);
        int len = (temp.size() < 2) ? temp.size() : 2;
        for(int i=0; i<len; i++) answer.push_back(temp[i].second);
    }
    
    return answer;
}
