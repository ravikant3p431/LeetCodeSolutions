/*  Driver Code Starts
This Code is implemented without the usage of the vectors 
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
   
    public:
    int t[1001][1001];
    int RecursiveCode(int W, int wt[], int val[], int n);
    int RecursiveWithMemoization(int W, int wt[], int val[], int n);
    int TopDownDP(int W, int wt[], int val[], int n);
    int knapSack(int W, int wt[], int val[], int n) 
    { 
     //   memset(t,-1,sizeof(t));
    .   for(int i=0 ;i< n ;i++)
        {
            for(int j=0 ; j< W ;j++)
            {
                if( i==0 || j ==0)
                t[i][j] = 0;
            }
        }
       //return RecursiveWithMemoization(W,wt,val,n);
       return TopDownDP(W,wt,val,n);
    }
};
int Solution::TopDownDP(int W, int wt[], int val[], int n)
{
    for(int i=1 ; i< n+1;i++)
    for(int j=1 ; j< W+1;j++)
    {
        if(wt[i-1] <= j)
        {
           t[i][j] = max( val[i-1] + t[i-1][j-wt[i-1]],
                     t[i-1][j]
                    );
        }
        else if(wt[i-1] > j)
            t[i][j] =  t[i-1][j];
        
    }
    
    return t[n][W];
}
int Solution::RecursiveCode(int W, int wt[], int val[], int n)
{
    // This will not pass all the test cases, this is just to understand the recursion
     
       if (n ==0 || W == 0)
       return 0;
       if (wt[n-1]  <= W)
       {
           return max( val[n-1] + knapSack(W-wt[n-1],wt,val,n-1),
                        knapSack(W,wt,val,n-1)
                        );
       }
       else if(wt[n-1] > W)
        return knapSack(W,wt,val,n-1);
       
}
int Solution::RecursiveWithMemoization(int W, int wt[], int val[], int n)
    {
        //recursion with memoization
        if(n ==0 || W ==0 )
        return 0;
        if(t[n][W] != -1)
        return t[n][W];
       if (wt[n-1]  <= W)
       {
           return t[n][W] = max( val[n-1] + RecursiveWithMemoization(W-wt[n-1],wt,val,n-1),
                        RecursiveWithMemoization(W,wt,val,n-1)
                        );
       }
       else if(wt[n-1] > W)
        return t[n][W] = RecursiveWithMemoization(W,wt,val,n-1);
        
       
    }
// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
