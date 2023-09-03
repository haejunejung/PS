#include <iostream>

using namespace std;

int main () {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    const int MAX_SIZE = 10001;

    int count [MAX_SIZE] = { }, maximum = 0;
    while (N--) {
        int weight;
        cin >> weight;

        count[0] += 1;
        count[weight + 1] -= 1;

        maximum = std::max(maximum, weight);
    }

    int answer = 0;
    for (int i = 0; i <= maximum; i++) {
        count[i + 1] += count[i];

        answer = std::max(answer, count[i] * i);
    }

    std::cout << answer << std::endl;

    return 0;
}