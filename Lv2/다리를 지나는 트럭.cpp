#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, truck_count = 0, total_weight = 0;
    queue<int> q;
    
    while (truck_count < truck_weights.size()) {
        if (q.size() == bridge_length) {
            int poped = q.front();
            q.pop();
            if (poped != 0)
                total_weight -= poped;
        }
        
        
        if (total_weight + truck_weights.at(truck_count) <= weight && q.size() < bridge_length) {
            total_weight += truck_weights.at(truck_count);
            q.push(truck_weights.at(truck_count++));
        }
        else
            q.push(0);
        
        answer++;
    }
     
    answer += bridge_length;
    
    return answer;
}