#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool isPrime(int num) {
    if (num == 0 || num == 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void swap(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
}

void permutation(vector<int>& v, int depth, int n, int r, set<int>& result) {
    if (depth == r) {
        int val = 0;
        for (int i = 0; i < r; i++) {
            val *= 10;
            val += v.at(i);
        }
        result.insert(val);
    }
    
    for (int i = depth; i < n; i++) {
        swap(v.at(i), v.at(depth));
        permutation(v, depth + 1, n, r, result);
        swap(v.at(i), v.at(depth));
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    set<int> result;
    
    for (int i = 0; i < numbers.size(); i++) 
        v.push_back(numbers.at(i) - '0');
    
    for (int i = 1; i <= v.size(); i++) 
    	permutation(v, 0, v.size(), i, result);
        
    for (auto a : result) {
        if (isPrime(a)) answer++;
    }
    
    return answer;
}