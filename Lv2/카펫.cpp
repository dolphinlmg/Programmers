#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int a, b, c, x, y;
    
    a = 1;
    b = -1 * (brown / 2 - 2);
    c = yellow;
    
    x = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a); 
    y = -1 * b - x;
    
    answer.push_back(x + 2);
    answer.push_back(y + 2);
    
    return answer;
}