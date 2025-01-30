class Solution {
public:
    bool bfs(int u, int v, unordered_map<int,vector<int>> &adj,
        vector<vector<int>>& edges){

        int n = edges.size();
        vector<bool>visited(n+1); // so that everynode has same idx
        queue<int>que;
        que.push(u);
        

        while(!que.empty()){
            int node = que.front();
            que.pop();
            visited[node] = true;
            if(node == v){
                return true;
            }
            for(auto v_:adj[node]){
                if(!visited[v_]){
                    que.push(v_);
                    
                }

            }
        }
        return false;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //make the graph
        //while that check if both vertex are connected
        //return the vertexes
        int n = edges.size();
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i < n; i++){
          
                int u = edges[i][0];
                int v = edges[i][1];

                if(adj.find(u) != adj.end() && adj.find(v) != adj.end()
                 && bfs(u,v,adj,edges)){
                    return{u,v};
                }

                //if not then add it in the graph
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            return {};
        

    }
};