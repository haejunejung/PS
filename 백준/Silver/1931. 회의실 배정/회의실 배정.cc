#include <iostream>
#include <vector>
#include <algorithm>

// 회의의 시작 시간과 끝나는 시간이 정해져 있다.
// 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대 개수를 찾아라.
using namespace std;

int main () {

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> meetings;
    int s, e;
    while (N--) {
        cin >> s >> e;

        meetings.push_back({s, e});
    }

    std::sort (meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }

        return a[1] < b[1];
    });

    int answer = 1;
    s = meetings[0][0];
    e = meetings[0][1];

    for (int i = 1; i < meetings.size(); i++) {
        s = meetings[i][0];

        if (s >= e) {
            e = meetings[i][1];
            answer++;
        }
    }
    
    std::cout << answer;

    return 0;
}