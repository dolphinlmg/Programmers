#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
  	int count[3] = { 0, 0, 0 };
    vector<pair<int, int>> v;
    int length = answers.size();
    int two_answer[] = { 1, 3, 4, 5 };
    int three_answer[] = { 3, 1, 2, 4, 5 };
    
    for (int i = 0; i < 3; i++) {
        v.push_back(pair<int, int>(i + 1, 0));
    }
    
    for (int i = 0; i < length; i++) { 
        if (i % 5 + 1 == answers.at(i))
            v.at(0).second++;
        
        if (i % 2 == 0 && answers.at(i) == 2)
            v.at(1).second++;
        else if (i % 2 != 0 && answers.at(i) == two_answer[(i / 2) % 4])
            v.at(1).second++;
           
        if (answers.at(i) == three_answer[(i / 2) % 5])
            v.at(2).second++;
    }
    
    sort(v.begin(), v.end(), compare);
    
    //cout << v.at(0).first << " " << v.at(1).first << " " << v.at(2).first << endl;
    //cout << v.at(0).second << " " << v.at(1).second << " " << v.at(2).second << endl;
    
    answer.push_back(v.at(0).first);
    
    for (int i = 1; i < 3; i++) {
        if (v.at(0).second == v.at(i).second)
            answer.push_back(v.at(i).first);
    }
    
    return answer;
}