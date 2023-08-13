//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        int a = 0;
        while(a < n - 2){
            int temp = X - A[a];
            int l = a + 1;
            int r = n-1;
            while(l < r){
                if(temp - A[l] - A[r] == 0){
                    return true;
                }
                if(temp - A[l] - A[r] > 0){
                    l++;
                }else{
                    r--;
                }
            }
            a++;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends