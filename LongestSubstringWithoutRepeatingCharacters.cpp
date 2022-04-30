class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        int CurrentLength =0 ;
        int MaxLength =0 ;
       // map<char,int>mp;
        string answer = "";
        string news = "";
       //out<<"empty Length"<<answer.length()<<endl;
        for(int i =0 ; i< s.length(); ++i)
        {
           
            // cout<<answer.find(s[i])<<endl; // if found then it will return the index where it  the matching character has been found 
           int k =answer.find(s[i]);
            if(  k== -1) // return -1 when s[i] is not present in the answer
           {
             //  cout<<"racv"<<endl;
               answer+=s[i];
             // cout<<answer<<endl;
           }
            else 
            { 
               //urrentLength = answer.length();'
                MaxLength = MaxLength >answer.length() ? MaxLength : answer.length();
                answer.erase(0,k+1);
                answer+=s[i];
            }        
            
        }
         MaxLength = MaxLength >answer.length() ? MaxLength : answer.length();
               
        return MaxLength;
        
//         if(s.length()<=1)
//             return s.length();
        
//         int MaxLen = 0;
//         string answer = "";
        
//         for(int i=0;i<s.length(); ++i)
//         {
//             int pos = answer.find(s[i]);
//             if(pos == -1)
//             {
//                 answer += s[i];
//             }
//             else
//             {
//                 MaxLen = MaxLen >answer.length() ? MaxLen : answer.length();
//                 answer.erase(0,pos+1);
//                 answer+=s[i];
               
//             }
//         }
//         MaxLen = MaxLen >answer.length() ? MaxLen : answer.length();
//         return MaxLen;
    }
};
