#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int length = 0, total = 0;

vector<pair<string, int>> get_neig(string cur, vector<vector<string>>& left, vector<bool>& visit) {
    vector<pair<string, int>> ret;
    for (int i = 0; i < left.size(); i++) {
        if (visit.at(i) == false && left.at(i).at(0) == cur) 
            ret.push_back(make_pair(left.at(i).at(1), i));
    }
    
    sort(ret.begin(), ret.end());
    
    return ret;
}

bool dfs(vector<string>& cur, vector<vector<string>> left, vector<bool>& visit) {
    if (length == total) return true; 
    vector<pair<string, int>> neig = get_neig(cur.at(cur.size() - 1), left, visit);
    
    if (neig.size() == 0) { // 더이상 진행 불가일때 
        return false;
    } else if (neig.size() == 1) { // 갈수있는곳이 한곳일때
        cur.push_back(neig.at(0).first);
        visit.at(neig.at(0).second) = true;
        length++;
        
        if (dfs(cur, left, visit) == false) {
            cur.pop_back();
            visit.at(neig.at(0).second) = false;
            length--;
            return false;
        }
        
        return true;
    } else { // 갈수있는곳이 여러군데일때
        for (auto a : neig) {
            cur.push_back(a.first);
            visit.at(a.second) = true;
            length++;
            
            if (dfs(cur, left, visit) == false) {
                cur.pop_back();
                visit.at(a.second) = false;
                length--;
                continue;
            }
            
            return true;
        }
        return false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size());
    total = tickets.size();
    answer.push_back("ICN");
    
    dfs(answer, tickets, visit);
    
    return answer;
}