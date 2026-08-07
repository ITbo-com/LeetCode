#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q1, q2;
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q1.push({i,j});
                }
            }
        }

        while(!q1.empty()){
            auto cur = q1.front();
            q1.pop();

            for(int dir = 0 ; dir < 4; dir++){
                int nx = cur.first+dx[dir];
                int ny = cur.second+dy[dir];

                if(nx>=n || nx < 0 || ny >= m || ny < 0)
                    continue;
                if(grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                q2.push({nx,ny});
            }

            if(q1.empty() && !q2.empty()){
                cnt++;
                q1=q2;
                while(!q2.empty())
                    q2.pop();
            }

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }        

        return cnt;
    }
};