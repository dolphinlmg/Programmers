#include <string>
#include <vector>

using namespace std;

void dfs(int start, vector<bool>& visited, vector<vector<int>>& computers) {
    visited[start] = true;
    
    for (int i = 0; i < computers.size(); i++) {
        if (visited[i] == false && computers[start][i] == 1) 
            dfs(i, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == true) 
            continue;
        dfs(i, visited, computers);
        answer++;
    }
    
    return answer;
}