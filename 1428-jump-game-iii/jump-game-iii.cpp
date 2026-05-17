class Solution {
public:

    bool dfs(vector<int>& arr, int start, int n){
        if(start >= n || start < 0 || arr[start] < 0){
            return false;
        }

        if(arr[start] == 0){
            return true;
        }

        arr[start] = arr[start] * (-1);
        
        bool a = dfs(arr,start + arr[start], n);
        bool b = dfs(arr, start - arr[start], n);

        return a || b;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        return dfs(arr, start, n);      
    }
};