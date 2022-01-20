#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(m + 1, vector<int>(n + 1, 1));
    
    for (auto v : puddles) {
        int y = v.at(1);
        int x = v.at(0);
        
        map[x][y] = 0;
        
        if (x == 1) {
            for (int i = y; i < n + 1; i++)
                map[x][i] = 0;
        }
        
        if (y == 1) {
            for (int i = x; i < m + 1; i++)
                map[i][y] = 0;
        }
    }
    
    for (int i = 0; i < m + 1; i++)
        map[i][0] = 0;
    
    for (int i = 0; i < n + 1; i++)
        map[0][i] = 0;
    
    for (int x = 2; x < m + 1; x++) {
        for (int y = 2; y < n + 1; y++) {
            if (map[x][y] == 0) continue;
            map[x][y] = (map[x - 1][y] + map[x][y - 1]) % 1000000007;
        }
    }
   
    return map[m][n];
}