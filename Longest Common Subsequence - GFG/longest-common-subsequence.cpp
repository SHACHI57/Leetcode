//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int solve(int i1, int i2, int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        //base case
        if(i1>=n or i2>=m)
        {
            return 0;
        }
        if(dp[i1][i2]!=-1)
        return dp[i1][i2];
        if(s1[i1]==s2[i2])
        {
            return dp[i1][i2]= 1+solve(i1+1,i2+1,n,m,s1,s2,dp);
        }
        return dp[i1][i2]= max(solve(i1+1,i2,n,m,s1,s2,dp),solve(i1,i2+1,n,m,s1,s2,dp));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends