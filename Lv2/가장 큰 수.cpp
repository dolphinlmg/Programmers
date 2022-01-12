#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return stoi(a + b) > stoi(b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>v;
    
    for (auto num : numbers) 
        v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), cmp);
    
    for (auto num : v) {
        if (answer == "" && num == "0")
            continue;
        answer += num;
    }
    
    if (answer == "") 
        answer = "0";
    
    return answer;
}