class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        set<int>st;
        int duplicate, missing;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(st.find(grid[i][j]) != st.end()){
                    //duplicate found
                    duplicate = grid[i][j];

                }
                st.insert(grid[i][j]);
            }
        }

        for(int i = 1; i <= n*n; i++){
            if(st.find(i) == st.end()){
                missing = i;
                break;
            }
        }

        return {duplicate, missing};
    }
};