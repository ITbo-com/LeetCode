#include<bits/stdc++.h>

using namespace std;

/*
1. bfs에서 vis 판별 시기 또 잘못 판단함. (큐에서 pop할 시기엔 이미 중복 처리가 끝난 상태임)
2. vis가 매번 초기화될 수 있게 해야함
3. bfs로 구현하다 보니까, 멀리 돌아서 예전에 들렀던 곳으로 가면 중복처리 되서 애가 안 되는 줄 앎. dfs로 해야 수월했을 듯...
--> 애초에 bfs로 안 됨. 내가 말한 그대로의 이유로... dfs+백트래킹이라고 한다
*/

class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(vector<vector<char>> & board, string word, vector<vector<int>>& vis, int n, int m, int ws){

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int ws = word.size();


        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(board[i][j] == word[0]){

                    queue<pair<int,int>> q1;
                    q1.push({i,j});
                    vector<vector<int>> vis(n, vector<int>(m, -1));
                    vis[i][j] = 0;

                    while(!q1.empty()){
                        auto cur = q1.front();
                        q1.pop();

                        if(vis[cur.first][cur.second] == ws - 1){
                            return true;
                        }

                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;
                            if(vis[nx][ny] > -1 || board[nx][ny] != word[vis[cur.first][cur.second]+1])
                                continue;
                            
                            vis[nx][ny] = vis[cur.first][cur.second] + 1;
                            q1.push({nx,ny});
                        }
                    }


                }
            }
        }

        return false;


    }
};