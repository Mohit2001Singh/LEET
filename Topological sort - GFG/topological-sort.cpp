//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	void dfs(int i, int V, vector<int>adj[], stack<int>& st, vector<bool>& vis){
// 	    if(vis[i] == true){
// 	        return;
// 	    }
// 	    vis[i] = true;
// 	    for(auto p : adj[i]){
// 	        dfs(p, V, adj, st, vis);
// 	    }
// 	    st.push(i);

// 	}
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    // code here
// 	    vector<int> ans;
// 	    stack<int> st;
// 	    vector<bool> vis(V, false);
// 	    for(int i = 0;i<V;i++){
// 	        if(vis[i] == false){
// 	            dfs(i, V, adj, st, vis);
// 	        }   
// 	    }
// 	    while(!st.empty()){
// 	        ans.push_back(st.top());
// 	        st.pop();
// 	    }
// 	   // for(auto i: ans){
// 	   //     cout<<i<<" "<<endl;
// 	   // }
// 	    return ans;
// 	}

	vector<int> topoSort(int V, vector<int> adj[]){
	    vector<int> inD(V, 0);
	    for(int i = 0;i<V;i++){
	        for(auto j : adj[i]){
	            inD[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i =0;i<V;i++){
	        if(inD[i] ==0 ){
	            q.push(i);
	        }   
	    }
	    vector<int> topo;

	    while(!q.empty()){
	        int a = q.front();
	        q.pop();
	        topo.push_back(a);
	        
	        for(auto i: adj[a]){
	            inD[i]--;
	            if(inD[i] == 0){
	                q.push(i);
	            }
	        }
	    }
	    return topo;
	}

    
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends