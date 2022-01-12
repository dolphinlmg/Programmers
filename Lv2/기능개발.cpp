#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ptr = 0, day, count;
    
    for (day = 0; ; day++) {
        if (ptr >= progresses.size()) break;
        
        for (int i = 0; i < progresses.size(); i++) 
            progresses.at(i) += speeds.at(i);
        
        for (count = 0;;count++) {
            if (ptr < progresses.size() && progresses.at(ptr) >= 100) {
                ptr++;
                continue;
            }
            else break;
        }
            
        if (count != 0) answer.push_back(count);
    }
    
    
    
    return answer;
}