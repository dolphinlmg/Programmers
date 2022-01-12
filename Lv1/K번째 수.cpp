#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto cmd : commands) {
        vector<int> tmp;
        tmp.insert(tmp.end(), array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp.at(cmd[2] - 1));
    }
    
    return answer;
}