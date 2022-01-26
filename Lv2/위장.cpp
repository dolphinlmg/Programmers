#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    
    for (auto c : clothes) {
        if (m.find(c.at(1)) == m.end()) 
            m.insert(make_pair(c.at(1), 1));
        else 
            m[c.at(1)]++;
    }
    
    for (auto e : m) 
        answer *= (e.second + 1);
    
    return answer - 1;
}