#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int n;
    int m;
    int ws;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool bt(vector<vector<char>>& board, string word, vector<vector<int>>& vis, int i, int j, int k){
        if(k == ws - 1){
            return true;
        }
        vis[i][j]=k;

        for(int dir = 0; dir < 4; dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(vis[nx][ny] > -1 || board[nx][ny] != word[k+1])
                continue;
            
            if(bt(board,word,vis,nx,ny,k+1))
                return true;
        }

        vis[i][j] = -1;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        ws = word.size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        bool solved = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    solved = bt(board, word, vis, i, j, 0);
                }
                if (solved)
                    return true;
            }
        }
        return false;
    }
};