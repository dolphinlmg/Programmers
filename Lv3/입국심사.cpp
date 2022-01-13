#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long calc_people(unsigned long long total_time, vector<int>& times) {
    unsigned long long ret = 0;
    for (auto time : times)
        ret += total_time / time;
    return ret;
}

unsigned long long binary_search(int n, unsigned long long max_time, vector<int>& times) {
    unsigned long long ret;
    unsigned long long mid = max_time / 2, left = 0, right = max_time;

    while (mid > 0) {
        unsigned long long calc = calc_people(mid, times);
        if (calc > n) {
            ret = mid;
            right = mid;
            mid = (left + mid) / 2;
        }
        else if (calc == n) {
            while (calc == n) {
                ret = mid;
                mid--;
                calc = calc_people(mid, times);
            }
            break;
        }
        else {
            left = mid;
            mid = (mid + right) / 2;
            if (left == mid) break;
        }
    }

    return ret;
}

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    unsigned long long max_time = *max_element(times.begin(), times.end()) * n;

    answer = binary_search(n, max_time, times);

    return answer;
}