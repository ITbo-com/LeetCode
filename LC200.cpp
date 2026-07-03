class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        int cnt=0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i=0; i<m; i++){
            for (int j=0; j<n;j++){
                
                if(vis[i][j] == true || grid[i][j] == '0')
                    continue;
                
                cnt++;

                queue<pair<int,int>> q1;
                q1.push({i,j});
                vis[i][j]=true;

                while(!q1.empty()){
                    auto cur = q1.front();
                    q1.pop();
                    
                    for(int dir=0; dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if(vis[nx][ny] == true || grid[nx][ny] == '0')
                            continue;

                        vis[nx][ny] = true;
                        q1.push({nx,ny});
                    }
                }

            }
        }
        return cnt;
    }
};