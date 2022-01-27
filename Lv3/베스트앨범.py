from collections import defaultdict

def solution(genres, plays):
    answer = []
    dic_idx_play = defaultdict(list)
    dic_play_sum = defaultdict(int)
    
    for i, (genre, play) in enumerate(zip(genres, plays)):
        dic_idx_play[genre].append((i, play))
        dic_play_sum[genre] += play
        
    for (genre, play) in sorted(dic_play_sum.items(), key = lambda x: -x[1]):
        for (idx, play) in sorted(dic_idx_play[genre], key = lambda x: -x[1])[:2]:
            answer.append(idx)
    
    return answer