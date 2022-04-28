
class Solution
{
    public:
    //Solution using Recursion When Traversing from the First Index and ending upto N
    int lcsUsingRecursionTraversingFromZero(int s1_index,int s2_index,string &s1,string &s2);
    
    //Solution Using Memoization and Recursion When Traversing from FirstIndex Zero to Upto N
    int lcsUsingRecurseMemoizationTraversingFromZero(int s1_index, int s2_index, string &s1, string &s2,vector<vector<int>>&memo);
    
  //Solution using Recursion when traversing from nth position or Back
    int lcsUsingRecursionTraversingFromBack(int x,int y,string &s1,string &s2);  
    
    //Memoization on accessing from back
    int lcsUsingRecurseMemoizationTraversingFromBack(int x,int y,string &s1,string &s2,vector<vector<int>> &memo);  

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>memo(s1.length()+1,vector<int>(s2.length()+1,-1)); //2D Vector for using in Memoization
          //  return lcsUsingRecursionTraversingFromBack(x,y,s1,s2);
          //  return lcsUsingRecursionTraversingFromZero(0,0,s1,s2);
          //  return lcsUsingRecurseMemoizationTraversingFromZero(0,0,s1,s2,memo);
          return lcsUsingRecurseMemoizationTraversingFromBack(x,y,s1,s2,memo); 
    }
};
int Solution::lcsUsingRecurseMemoizationTraversingFromBack(int x,int y,string &s1,string &s2,vector<vector<int>> &memo)
{
    if(x == 0 || y == 0 )
    memo[x][y] = 0;
    if(memo[x][y] !=  -1)
    return memo[x][y];
    else if(s1[x-1] == s2[y-1])
    return memo[x][y] = 1 + lcsUsingRecurseMemoizationTraversingFromBack(x-1,y-1,s1,s2,memo);
    else
    memo[x][y] = max(lcsUsingRecurseMemoizationTraversingFromBack(x-1,y,s1,s2,memo)
                ,lcsUsingRecurseMemoizationTraversingFromBack(x,y-1,s1,s2,memo));
}
int Solution::lcsUsingRecursionTraversingFromBack(int x,int y,string &s1,string &s2)
{
        if( x == 0 || y == 0 )
         return 0;
         if(s1[x-1] == s2[y-1])
         return 1+ lcsUsingRecursionTraversingFromBack(x-1,y-1,s1,s2);
         else 
         return max(lcsUsingRecursionTraversingFromBack(x-1,y,s1,s2)
         ,lcsUsingRecursionTraversingFromBack(x,y-1,s1,s2));
}
int Solution::lcsUsingRecursionTraversingFromZero(int s1_index,int s2_index,string &s1,string &s2)
{
if(s1_index == s1.length() || s2_index == s2.length())
           return 0;
           if(s1[s1_index] == s2[s2_index])
                return 1 + lcsUsingRecursionTraversingFromZero(s1_index+1,s2_index+1,s1,s2);
                else
                return max(lcsUsingRecursionTraversingFromZero(s1_index,s2_index+1,s1,s2),lcsUsingRecursionTraversingFromZero(s1_index+1,s2_index,s1,s2));
}
int Solution::lcsUsingRecurseMemoizationTraversingFromZero(int s1_index,int s2_index,string &s1,string &s2,
 vector<vector<int>>&memo)
 {       
        if(s1_index == s1.length() || s2_index == s2.length())
            memo[s1_index][s2_index] = 0;
        if(memo[s1_index][s2_index] != -1)
        return memo[s1_index][s2_index];
           else if(s1[s1_index] == s2[s2_index])
                return memo[s1_index][s2_index]=  1 + lcsUsingRecurseMemoizationTraversingFromZero(s1_index+1,s2_index+1,s1,s2,memo);
                else
                return memo[s1_index][s2_index] =  max(lcsUsingRecurseMemoizationTraversingFromZero(s1_index,s2_index+1,s1,s2,memo)
                                                          ,lcsUsingRecurseMemoizationTraversingFromZero(s1_index+1,s2_index,s1,s2,memo));
}
