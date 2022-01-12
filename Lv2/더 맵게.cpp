#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto sc : scoville) 
        pq.push(sc);
    
    while (pq.size() > 1) {
       if (pq.top() >= K) 
           break;
        int a, b, c;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        
        c = a + b * 2;
        pq.push(c);
        
        answer++;
    }
    
    if (pq.top() < K)
        answer = -1;
    
    return answer;
}