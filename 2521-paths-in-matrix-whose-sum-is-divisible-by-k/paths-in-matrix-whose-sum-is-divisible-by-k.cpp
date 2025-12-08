class Solution {
public:
    int mod = 1e9+7;
    //memoize
    vector<vector<vector<int>>>t;

    int solve(vector<vector<int>>& grid, int i, int j , int m,
     int n, int k,int currSum){
        //base case 
        if(i >= m || j >= n){
            //invalid
            return 0;
        }

        //if in the last cell check value
        if(i == m-1 && j == n-1){
            return (currSum + grid[i][j])% k == 0 ? 1: 0;
        }
        //check if memoized
        if(t[i][j][currSum] != -1){
            return t[i][j][currSum];
        }

        //check down and right
        //send modulo so no int overflow
        int down = solve(grid, i+1, j, m,n,k,(currSum + grid[i][j])%k);
        int right = solve(grid, i, j+1, m,n,k,(currSum + grid[i][j])%k);

        //add the current grid
        

        return t[i][j][currSum] = (down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        t.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));

        int ans = solve(grid, 0,0, m,n,k,0);

        return ans;
    }
};