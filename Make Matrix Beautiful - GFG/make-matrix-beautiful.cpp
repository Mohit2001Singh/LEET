//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
         vector<int> r(n, 0);
        vector<int> c(n, 0);
        int rm = INT_MIN, cm = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                r[i] += matrix[i][j];
                c[j] += matrix[i][j];
                rm = max(rm, r[i]);
                cm = max(cm, c[j]);
            }
        }
        int ans = 0;
        if(rm > cm){
            for(auto j : r){
                ans += rm - j;
            }
        }else{
            for(auto j : c){
                ans += cm - j;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends