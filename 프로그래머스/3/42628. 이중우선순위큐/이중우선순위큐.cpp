#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque <int> dq;
    
    for (auto op : operations) {
        if (op[0] == 'I') {
            
            std::string str_num;
            for (int i = 2; i < op.size(); i++) {
                str_num += op[i];
            }
            int num = stoi(str_num);
            
            if (dq.empty()) dq.push_back(num);
            else if (dq.front() > num) dq.push_front(num);
            else {
                dq.push_back(num);
                sort(dq.begin(), dq.end());
            }
        }
        
        if (op[0] == 'D') {
            if (dq.empty()) continue;
            
            if (op[2] == '-') {
                dq.pop_front(); // 작은거 제거
            } else {
                dq.pop_back(); // 큰 거 제거
            }
        }
    }
    
    if (dq.size() >= 2) {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    } else if (dq.size() == 1) {
        answer.push_back(dq.front());
        answer.push_back(dq.front());
    } else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}