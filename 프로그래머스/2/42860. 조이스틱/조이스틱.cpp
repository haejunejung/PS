#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;

    int move = name.size() - 1;
    
    for (int L1 = 0; L1 < name.size(); L1++) {
        answer += min(name[L1] - 'A', 'Z' - name[L1] + 1);
    
        int L2_idx = L1 + 1;
        while (L2_idx < name.size()) {
            if (name[L2_idx] != 'A') {
                break;
            }
            
            L2_idx++;
        }
        int L2 = (name.size() - 1) - (L2_idx - 1);
        move = min(move, L1 + L2 +min(L1, L2));
        
    }
    
    return answer + move;
}