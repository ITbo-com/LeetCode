#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    const int INF = 1e9;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq1;

        vector<vector<int>> cost(m, vector<int>(n,INF));

        cost[0][0] = 0;
        pq1.push({0,{0,0}});

        while(!pq1.empty()){

            auto cur = pq1.top().second;
            auto nowcost = pq1.top().first;
            pq1.pop();

            if(cost[cur.first][cur.second] < nowcost )
                continue;

            if(cur == pair<int,int>{m-1, n-1})
                break;
            
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx >= m || nx < 0 || ny >= n || ny < 0)
                    continue;
                int k = max(cost[cur.first][cur.second],abs(heights[nx][ny] - heights[cur.first][cur.second]) );
                if(cost[nx][ny] <= k)
                    continue;
                
                cost[nx][ny] = k;
                pq1.push({k, {nx, ny}});
            }


        }

        return cost[m-1][n-1];

    }
};