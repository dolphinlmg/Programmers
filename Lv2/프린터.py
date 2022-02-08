from collections import deque

def solution(priorities, location):
    answer = 0
    queue = deque(enumerate(priorities))
    
    while True:
        left = queue.popleft()
        if any(left[1] < q[1] for q in queue):
            queue.append(left)
        else:
            answer += 1
            if left[0] == location:
                return answer
