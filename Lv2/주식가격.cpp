#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<int> st;
    
    for (int i = 0; i < prices.size(); i++) {
        if (st.empty() || prices.at(st.back()) <= prices.at(i)) {
            st.push_back(i);
        } else {
            int idx = st.back();
            st.pop_back();
            answer.at(idx) = i - idx;
            i--;
        }
    }
    
    while (!st.empty()) {
        int idx = st.back();
        st.pop_back();
        answer.at(idx) = prices.size() - idx - 1;
    }
    
     
    return answer;
}