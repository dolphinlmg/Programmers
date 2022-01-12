#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    for (int i = 1; i <= citations.size(); i++) {
        if (citations.at(i - 1) >= i)
            answer = i;
    }
    
    return answer;
}