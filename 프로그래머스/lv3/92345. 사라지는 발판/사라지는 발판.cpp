#include <string>
#include <vector>

using namespace std;

int n,m;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isInRange (const int y, const int x) {
    return (0 <= y && y < n && 0 <= x && x< m);
}
                
bool isFinished (vector<vector<int>> &board, const int y, const int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (isInRange(ny, nx) && board[ny][nx])
            return false;
    }
    return true;
}

pair<bool, int> solve (vector<vector<int>> &board, int y1, int x1, int y2, int x2) {
    if (isFinished (board, y1, x1)) return { false, 0 };
    if (y1 == y2 && x1 == x2) return { true, 1 };
    
    bool canWin = false;
    int minTurn = 0x7fffffff, maxTurn = 0;
    
    for (int i = 0; i < 4; i++) {
        int ny = y1+ dy[i];
        int nx = x1+ dx[i];
        
        if (!isInRange(ny, nx) || !board[ny][nx]) continue;
        
        board[y1][x1] = 0;
        pair<bool, int> result = solve (board, y2, x2, ny, nx);
        board[y1][x1] = 1;
        
        if (!result.first) {
            canWin = true;
            minTurn = min(minTurn, result.second + 1);
        }
        
        else if (!canWin) {
            maxTurn = max(maxTurn, result.second + 1);
        }
    }
    
    return { canWin, (canWin ? minTurn : maxTurn) };
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size(); m = board[0].size();
    
    return solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}