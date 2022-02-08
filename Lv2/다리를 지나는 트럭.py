from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    total_weight = 0
    truck_count = 0
    bridge = deque()
    
    while truck_count != len(truck_weights): 
        if len(bridge) == bridge_length:
            total_weight -= bridge.popleft()
        
        if total_weight + truck_weights[truck_count] <= weight:
            bridge.append(truck_weights[truck_count])
            total_weight += truck_weights[truck_count]
            truck_count += 1
        else:
            bridge.append(0)
        
        answer += 1
    
    return answer + bridge_length
