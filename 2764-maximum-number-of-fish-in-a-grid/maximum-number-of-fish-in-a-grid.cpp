class Solution {
public:
    vector<vector<int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int bfs(int i, int j, int m, int n, vector<vector<int>>& grid){
        queue<pair<int,int>>que;
        que.push({i,j});
        int maxCount = grid[i][j];
       
        grid[i][j] = 0;

        while(!que.empty()){
            i = que.front().first;
            j = que.front().second;
            que.pop();

            //dir array
            for(auto& dir: directions){
                int i_ = i+ dir[0];
                int j_ = j+ dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0){
                    que.push({i_,j_});
                    maxCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }
        return maxCount; 
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFishCount = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    maxFishCount = max(maxFishCount,bfs(i,j,m,n,grid));
                }
            }
        }

        return maxFishCount;
    }
};