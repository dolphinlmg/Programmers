def solution(clothes):
    answer = 1
    d = {}
    
    for c in clothes:
        if not(c[1] in d):
            d[c[1]] = 1
        else:
            d[c[1]] += 1
            
    for val in d.values():
        answer *= val + 1
    
    answer -= 1
    
    return answer