//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detect(vector<int>adj[], int V, vector<bool>& vis, int i){
        vis[i] = true;
        queue<pair<int, int>> q;
        q.push({i, -1});
        
        while(!q.empty()){
            int node= q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto adjacentNode : adj[node]){
                if(vis[adjacentNode] == false){
                    vis[adjacentNode] = true;
                    q.push({adjacentNode, node});
                }else if(adjacentNode != parent){
                    return true;
                }
            }
            
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false);
        for(int i  =0;i<V;i++){
            if(vis[i] == false){
                if(detect(adj, V, vis, i) == true){
                    return true;
                }
            }
        }
        return false;
    }
   
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends