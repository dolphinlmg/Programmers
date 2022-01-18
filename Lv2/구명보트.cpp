#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int count = people.size();

    sort(people.begin(), people.end(), std::greater<int>());

    int left = 0, right = people.size() - 1;

    while (left < right) {
        int left_weig = people.at(left), right_weig = people.at(right);
        if (left_weig + right_weig <= limit) {
            count -= 2;
            answer++;
            left++;
            right--;
        } else {
            left++;
        }
    }

    answer += count;

    return answer;
}