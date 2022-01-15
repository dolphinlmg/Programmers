#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> lost_idx, reserve_idx;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int i = 0, j = 0;
    
    while (i < lost.size() && j < reserve.size()) {
        int l = lost.at(i), r = reserve.at(j);
        if (l == r) {
            lost_idx.push_back(i);
            reserve_idx.push_back(j);
            i++; j++;
        }
        else if (l < r)
            i++;
        else if (l > r)
            j++;
    }
    
    for (auto iter = lost_idx.rbegin(); iter != lost_idx.rend(); iter++) 
        lost.erase(lost.begin() + *iter);
    
    for (auto iter = reserve_idx.rbegin(); iter != reserve_idx.rend(); iter++) 
        reserve.erase(reserve.begin() + *iter);
    
    i = 0; j = 0;
    int lend = 0;
    
    while (i < lost.size() && j < reserve.size()) {
        int l = lost.at(i), r = reserve.at(j);
        if (l < r - 1)
            i++;
        else if (l == r - 1 || l == r + 1) {
            lend++; i++; j++;
        }
        else if (l > r + 1)
            j++;
    }
    
    answer = n - lost.size() + lend;
    
    return answer;
}