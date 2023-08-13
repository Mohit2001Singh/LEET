//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1000000007;
    int nthFibonacci(int n){
        // code here
        if(n == 0 || n == 1){
            return n;
        }
        int p = 0;
        int c = 1;
        for(int i = 2;i<=n;i++){
            int nn = (p+c)%mod;
            p = c%mod;
            c = nn%mod;
        }
        return c%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends