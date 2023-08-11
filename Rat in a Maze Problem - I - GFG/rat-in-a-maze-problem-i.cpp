//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isvalid(int i, int j, vector<vector<int>>& m, int n){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j] == 0){
            return false;
        }
        return true;
    }
 
    void find(vector<vector<int>>& m, int n, int i, int j, vector<string>& ans, string a){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j] == 0){
            return;
        }
        if(i == n-1 && j == n-1){
            ans.push_back(a);
            return;
        }
        m[i][j] = 0;
        if(isvalid(i+1, j, m, n)){
            a+="D";
            find(m, n, i+1, j, ans, a);
            a.pop_back();
        }
        if(isvalid(i-1, j, m, n)){
            a+="U";
            find(m, n, i-1, j, ans, a);
            a.pop_back();
        }
        if(isvalid(i, j+1, m, n)){
            a+="R";
            find(m, n, i, j+1, ans, a);
            a.pop_back();
        }
        if(isvalid(i, j-1, m, n)){
            a+="L";
            find(m, n, i, j-1, ans, a);
            a.pop_back();
        }
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return {"-1"};
        }
        find(m, n, 0, 0, ans, "");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends