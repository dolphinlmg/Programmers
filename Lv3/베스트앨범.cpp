#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genre_count;
    unordered_map<string, set<pii, greater<pii>>> genre_plays;
    
    for (int i = 0; i < genres.size(); i++) {
        if (genre_count.find(genres.at(i)) == genre_count.end()) // new genre
            genre_count.insert(make_pair(genres.at(i), plays.at(i)));
        else // exist genre 
            genre_count[genres.at(i)] += plays.at(i);
        
        if (genre_plays.find(genres.at(i)) == genre_plays.end()) // new genre
            genre_plays.insert(make_pair(genres.at(i), set<pii, greater<pii>>()));
        genre_plays[genres.at(i)].insert(make_pair(plays.at(i), -i));
    }
    
    // genre_priority
    // <count, genre>
    set<pair<int, string>, greater<pair<int, string>>> genre_count_set;
    
    for (auto a : genre_count) 
        genre_count_set.insert(make_pair(a.second, a.first));
    
    for (auto genre : genre_count_set) {
        string genre_name = genre.second;
        auto iter = genre_plays[genre_name].begin();

        for (int i = 0; i < min((int)genre_plays[genre_name].size(), 2); i++) 
            answer.push_back((iter++)->second * -1);
    }
    
    return answer;
}