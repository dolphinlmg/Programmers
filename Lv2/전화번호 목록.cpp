#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++) {
		if (strncmp(phone_book.at(i).c_str(), phone_book.at(i + 1).c_str(), phone_book.at(i).size()) == 0)
            return false;
    }
    
    return true;
}