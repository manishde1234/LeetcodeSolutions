class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int water = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        priority_queue<pp,vector<pp>,greater<>> boundary;

        //put all the boundaries in the pq
        //put top row and bottom row (0,n-1)
        for(int row = 0; row < m; row++){
            for(int col:{0,n-1}){
                //height and coordinates
                boundary.push({heightMap[row][col],{row,col}});
                visited[row][col] = true;
            }
        }

        //put side cols 
        for(int col = 0; col < n; col++){
            for(int row:{0,m-1}){
                boundary.push({heightMap[row][col],{row,col}});
                visited[row][col] = true;
            }
        }

        //traverse through the neighbours
        while(!boundary.empty()){
            pp data = boundary.top();
            boundary.pop();

            int height = data.first;
            int i = data.second.first;
            int j = data.second.second;

            //go to the neighbours and check
            for(auto dir: directions){
                int i_ = i+dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && 
                    j_ < n && !visited[i_][j_]){
                    //add the diff
                    water += max(height - heightMap[i_][j_], 0);
                    //add to pq
                boundary.push({max(height,heightMap[i_][j_]),{i_,j_}});
                visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};