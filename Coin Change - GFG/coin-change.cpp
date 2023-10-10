//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  long long solve(int i, int coins[], int sum, int N, vector<vector<long long>> &dp)
  {
      //base case
      if(i>=N)
      {
          if(sum==0)
          return 1;
          return 0;
      }
      if(dp[i][sum]!=-1)
      return dp[i][sum];
      long long ways=0;
      if(coins[i]<=sum)
      {
          ways=solve(i,coins,sum-coins[i],N,dp);
      }
      long long ways1=solve(i+1,coins,sum,N,dp);
      return dp[i][sum]= ways+ways1;
  }
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N,vector<long long >(sum+1,-1));
        return solve(0,coins,sum,N,dp);
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