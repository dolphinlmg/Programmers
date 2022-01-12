#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> p;
    
    for (int i = 0; i < participant.size(); i++) {
        if (p.find(participant.at(i)) == p.end()) {
            p.insert(make_pair(participant.at(i), 1));
        } else {
            p[participant.at(i)] += 1;
        }
    }
    
   	for (int i = 0; i < completion.size(); i++) {
        p[completion.at(i)] -= 1;
    } 
    
    for (auto a : p) {
        if (a.second == 1) answer = a.first;
    }
    
    return answer;
}