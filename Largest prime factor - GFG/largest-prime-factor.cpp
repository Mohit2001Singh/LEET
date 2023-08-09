//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isprime(long long int N){
        int sq = sqrt(N);
        for(int i = 2;i<=sq;i++){
            if(N%i==0){
                return false;
            }
        }
        return true;
    }
    long long int largestPrimeFactor(int N){
        // code here
        if(isprime(N)){
            return N;
        }
        long long int sq = sqrt(N);
        for(long long int i = sq;i>=2;i--){
            if(N%i==0){
                if(isprime(N/i) and N/i > i){
                    return N/i;
                }
                else if(isprime(i)){
                    return i;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends