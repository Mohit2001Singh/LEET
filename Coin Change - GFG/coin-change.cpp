//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // BRUTE
    // long long int ans = 0;
    
    // void solve(int coins[], int sum, int i){
    //     if(i==0){
    //         if(sum % coins[i] == 0){
    //             ans++;
    //             return;
    //         }else{
    //             return;
    //         }
    //     }
    //     solve(coins, sum, i-1);
    //     if(sum >= coins[i]){
    //         solve(coins, sum - coins[i], i);
    //     }
    // }
    // long long int count(int coins[], int N, int sum) {

    //     // code here.
    //     solve(coins, sum, N-1);
    //     return ans;
    // }
    
    // Memo
    // long long solve(int coins[], int sum, int i, vector<vector<long long>>& v){
    //     if(i==0){
    //         return (sum%coins[0] == 0);
    //     }
    //     if(v[i][sum] != -1){return v[i][sum];}
    //     long long nott = solve(coins, sum, i-1, v);
    //     long long take = 0;
    //     if(sum >= coins[i]){
    //         take = solve(coins, sum - coins[i], i, v);
    //     }
    //     return v[i][sum] = take+nott;
    // }
    // long long int count(int coins[], int N, int sum) {
    //     vector<vector<long long>> v(N, vector<long long> (sum+1, -1));
    //     return solve(coins, sum, N-1, v);
    // }
    
    // bottom up
    long long int count(int coins[], int N, int sum){
        vector<vector<long long>> v(N, vector<long long> ( sum + 1, -1));
        for(int i = 0;i<=sum;i++){
            v[0][i] = (i%coins[0] == 0);
        }
        for(int s = 0;s <= sum; s++){
            for(int i = 1;i<=N-1;i++){
                long long nt = v[i-1][s];
                long long t = 0;
                if(s>=coins[i]){
                    t = v[i][s- coins[i]];
                }
                v[i][s] = t+nt;
            }
        }
        return v[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends