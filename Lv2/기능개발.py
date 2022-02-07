import math

def solution(progresses, speeds):
    answer = []
    count = 1
    days = [math.ceil((100 - p) / s) for p, s in zip(progresses, speeds)]
    
    for i in range(len(days) - 1):
        if days[i] < days[i + 1]:
            answer.append(count)
            count = 1
        else:
            days[i + 1] = days[i]
            count += 1
    
    answer.append(count)
    
    return answer
