#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, max = 0, maxIdx, curLoc = location;
    bool isSwaped = false;
    vector<int>& v = priorities;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            if (v.at(j) > v.at(i)) {
                if (i == curLoc) curLoc = v.size() - 1;
                else curLoc--;
                v.push_back(v.at(i));
                v.erase(v.begin() + i);
                isSwaped = true;
                break;
            }
        }
        
        if (isSwaped) {
            isSwaped = false;
            i--;
            continue;
        }
        
        if (i == curLoc) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}