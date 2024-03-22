#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    pair<set<int>, set<int>> p[101]; // [자신이 이긴 노드들, 자신이 진 노드들];
    for (auto result : results) {
        int winner  =   result[0];
        int loser   =   result[1];
        
        p[winner].first.insert(loser);
        p[loser].second.insert(winner);
    }
    
    for (int i = 1; i <= n; i++) {
        queue <int> losers; // 자신이 이긴 노드들
        queue <int> winners; // 자신이 진 노드들
        
        for (auto iter = p[i].first.begin(); iter != p[i].first.end(); iter++) {
            losers.push(*iter);
        }
        
        for (auto iter = p[i].second.begin(); iter != p[i].second.end(); iter++) {
            winners.push(*iter);
        }
        
        bool isVisited_winners[101] = { };
        bool isVisited_losers[101] = { };
        
        
        while (!losers.empty()) {
            int now = losers.front();
            p[now].second.insert(i);
            p[i].first.insert(now);
            isVisited_losers[now] = true;
            losers.pop();
            
            for (auto iter = p[now].first.begin(); iter != p[now].first.end(); iter++) {
                if (!isVisited_losers[*iter]) {
                    isVisited_losers[*iter] = true;
                    losers.push(*iter);
                }
            }
        }
        
        while (!winners.empty()) {
            int now = winners.front();
            
            // cout << now << " " << i << endl;
            p[now].first.insert(i);
            p[i].second.insert(now);
            isVisited_winners[now] = true;
            winners.pop();
            
            for (auto iter = p[now].second.begin(); iter != p[now].second.end(); iter++) {
                if (!isVisited_winners[*iter]) {
                    isVisited_winners[*iter] = true;
                    winners.push(*iter);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
//         cout << "win: ";
//         for (auto iter = p[i].first.begin(); iter != p[i].first.end(); iter++) {
//             cout << *iter << " ";
//         }
//         cout << endl;
        
//         cout << "lose: ";
//         for (auto iter = p[i].second.begin(); iter != p[i].second.end(); iter++) {
//             cout << *iter << " ";
//         }
//         cout << endl;
        
        if (p[i].first.size() + p[i].second.size() == n - 1) answer++;
    }
    
    return answer;
}