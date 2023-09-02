#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 17:05 ~ 
// 미사일을 최소로 사용해서 모든 폭격 미사일 요격
// 발사한 미사일은 x축에 평행한 직선 형태의 모양 (s,e)
// x좌표에서 y축에 수평이 되도록 미사일 발사, x좌표 걸친 모든 미사일 요격
// 요격 미사일은 실수인 x좌표에서도 발사 가능

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    std::sort (targets.begin(), targets.end(), [](vector<int> &a, vector<int> &b) {
       return a[1] < b[1]; 
    });
    
    int e = targets[0][1];
    answer++;
    
    for (auto target : targets) {
        int start   = target[0];
        int end     = target[1];
        
        if (start >= e) {
            e = end;
            answer++;
        }
    }
    
    return answer;
}