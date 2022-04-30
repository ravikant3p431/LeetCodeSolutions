class Solution {
public:
    int DPSolution(int n);
    int RecursiveSolution(int n);
    int RecursiveSolutionWithMemoization(int n,vector<int> &dp);
    int fib(int n) {
        vector<int> dp (n+1,-1);
        return RecursiveSolutionWithMemoization(n,dp);
       // return RecursiveSolution(n);
       // return DPSolution(n);
    }
};
int Solution::RecursiveSolutionWithMemoization(int n,vector<int> &dp )
{
    if(n <= 1)
        dp[n] =  n;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] =  RecursiveSolutionWithMemoization(n-1,dp)+ 
                RecursiveSolutionWithMemoization(n-2,dp);
   // return  dp[n];

}
int Solution:: RecursiveSolution(int n)
{
    if(n <= 1)
        return n;
    return RecursiveSolution(n-1) +RecursiveSolution(n-2); 
}
int Solution::DPSolution(int n)
{//int dp[n+1];
        if(n <= 1)
            return n;
        int dp1 = 0 ; //optimizing the Space
        int dp2 = 1;
        int current = 0 ;
        for(int i = 2 ; i <= n ; i++)
        {
            current = dp1 + dp2;
            dp1 = dp2;
            dp2= current;
        } //dp[i] = dp[i-1] + dp[i-2];
       // return dp[n+1];
        return current;
    
}
