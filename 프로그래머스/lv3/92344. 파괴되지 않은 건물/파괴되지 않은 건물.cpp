#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;
    
    int prefixSum[1001][1001] =  {};
    
    for (auto skill : skills) {
        int type = skill[0];
        int r1 = skill[1];
        int c1 = skill[2];
        int r2 = skill[3];
        int c2 = skill[4];
        int degree = skill[5];
    
        if (type == 1) {
            prefixSum[r1][c1] -= degree;
            prefixSum[r1][c2 + 1] += degree;
            prefixSum[r2 + 1][c1] += degree;
            prefixSum[r2 + 1][c2 + 1] -= degree; 
        }
        
        else {
            prefixSum[r1][c1] += degree;
            prefixSum[r1][c2 + 1] -= degree;
            prefixSum[r2 + 1][c1] -= degree;
            prefixSum[r2 + 1][c2 + 1] += degree; 
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            prefixSum[i][j+1] += prefixSum[i][j];
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            prefixSum[i+1][j] += prefixSum[i][j];
        }
    }
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] + prefixSum[i][j] > 0) {
                answer++;
            } 
        }
    }

    return answer;
}