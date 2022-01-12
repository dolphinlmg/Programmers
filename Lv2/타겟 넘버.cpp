#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    if (numbers.size() == 0 && target == 0)
        return 1;
    else if (numbers.size() == 0)
        return 0;
    
    int last = numbers.at(numbers.size() - 1);
    numbers.pop_back();
    
    return solution(numbers, target - last) + solution(numbers, target + last);
}