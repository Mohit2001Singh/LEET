//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    // int ls(int n, int a[], int i, int prev, vector<vector<int>>& v){
    //     if(i == n){
    //         return 0;
    //     }
    //     if(v[i][prev+1]!=-1){
    //         return v[i][prev+1];
    //     }
    //     int nt = ls(n, a, i+1, prev, v);
    //     int t = INT_MIN;
    //     if(prev == -1 || a[i] > a[prev]){
    //         t = 1 + ls(n, a, i+1, i, v);
    //     }
    //     return v[i][prev+ 1] = max(t,nt);
    // }
    // //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   // your code here
    //     vector<vector<int>> v(n, vector<int>(n+1,-1));
    //     return ls(n, a, 0, -1, v);
    // }
    
    int longestSubsequence(int n, int a[]){
        vector<int> lis_arr;
        lis_arr.push_back(a[0]);
        
        for(int i = 1;i<n;i++){
            if(lis_arr[lis_arr.size()-1] < a[i]){
                lis_arr.push_back(a[i]);
            }else{
                auto idx = lower_bound(lis_arr.begin(), lis_arr.end(),a[i]) - lis_arr.begin();
                lis_arr[idx] = a[i];
            }
        }
        return lis_arr.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends