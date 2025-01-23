class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;
        vector<int>countRow(m,0);
        vector<int>countCol(n,0);

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1){
                    //populate the array
                    countRow[row] += 1;
                    countCol[col] += 1;
                } 
            }
        }

        //find the array
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && (countRow[row] > 1 || countCol[col] > 1)){
                    result++;
                }
            }
        }
        return result;
    }
};