#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer;
    int len = number.size() - k;
    vector<int> v;
    
	for (auto c : number) {
        while (!v.empty() && v.back() < c && k > 0) {
            v.pop_back();
            k--;
        }
        v.push_back(c);   
    }
    
    for (int i = 0; i < len; i++) 
        answer += v.at(i);
    
    return answer;
}