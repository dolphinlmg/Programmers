#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for (auto cmd : operations) {
        if (cmd.at(0) == 'I') 
            ms.insert(stoi(cmd.substr(2)));
        else if (cmd.at(2) == '1' && ms.size() > 0) 
            ms.erase(--ms.end());
        else if (cmd.at(2) == '-' && ms.size() > 0)
            ms.erase(ms.begin());
    }
    
    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*--ms.end());
        answer.push_back(*ms.begin());
    }
    
    return answer;
}