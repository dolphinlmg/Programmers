#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int prev_end_time = 0; // 이전 작업이 끝나는 시간
    int idx = 1; // 다음에 pq에 들어갈 idx
    int count = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // make_pair(소요시간, 요청시간)

    sort(jobs.begin(), jobs.end());

    prev_end_time = jobs.front().front();
    pq.push(make_pair(jobs.front().back(), jobs.front().front()));

    while (count < jobs.size()) {
        while (idx < jobs.size() && jobs.at(idx).front() <= prev_end_time) {
            pq.push(make_pair(jobs.at(idx).back(), jobs.at(idx).front()));
            idx++;
        }
        
        if (pq.empty()) {
            prev_end_time = jobs.at(idx).front();
        } else {
        	pair<int, int> next_job = pq.top();
        	pq.pop();
        	answer += (prev_end_time + next_job.first) - next_job.second;
        	prev_end_time += next_job.first;
            count++;
        }
        
    }

    return answer / jobs.size();
}