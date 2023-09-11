#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> fees[201];

vector<int> dijkstra (const int src){
    priority_queue<vector<int>> pq;
    
    vector<int> dist(201);
    for (int i = 1; i <= 200; i++) {
        dist[i] = 0x7fffffff;
    }
    dist[src] = 0;
    
    pq.push({0, src});
    while (!pq.empty()) {
        vector<int> info = pq.top();
        pq.pop();
        int w = info[0], x = info[1];
        
        if (dist[x] < w) continue;
        
        for (const vector<int> &item : fees[x]) {
            int nx = item[0], ncost = item[1];
            ncost += w;
            
            if (ncost < dist[nx]) {
                dist[nx] = ncost;
                pq.push({ncost, nx});
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for (const vector<int> &fare : fares) {
        fees[fare[0]].push_back({fare[1], fare[2]});
        fees[fare[1]].push_back({fare[0], fare[2]});
    }
    
    vector<int> dist_s = dijkstra(s);
    vector<int> dist_a = dijkstra(a);
    vector<int> dist_b = dijkstra(b);
    
    
    
    int cost = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        cost = std::min (cost, dist_s[i] + dist_a[i] + dist_b[i]);
    }
    
    return cost;
}