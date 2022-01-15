#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 1);
    
    for (auto l : lost) 
        student.at(l) -= 1;
    
    for (auto r : reserve) 
        student.at(r) += 1;
    
    for (int i = 0; i < n; i++) {
        if (student.at(i) == -1) {
            if (student.at(i - 1) == 1) {
                student.at(i - 1)--;
                student.at(i)++;
            } else if (student.at(i + 1) == 1) {
                student.at(i + 1)--;
                student.at(i)++;
            }
        }
    }
    
    for (auto s : student) 
        if (s >= 0) answer++;
    
    answer--;
    
    return answer;
}