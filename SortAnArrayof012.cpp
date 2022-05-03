// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
       int firstelement = 0;
       int currentelement = 0;
       int lastelement = n-1;
       
      while(currentelement < n && currentelement <= lastelement
       && currentelement >= firstelement){
           if(arr[currentelement] == 0){
               int temp = arr[firstelement];
               arr[firstelement] = arr[currentelement];
               arr[currentelement] = temp;
               firstelement++;
               currentelement++;
           }
           else if(arr[currentelement] == 2){
              int temp = arr[lastelement] ;
              arr[lastelement] = arr[currentelement];
              arr[currentelement] = temp;
               //currentelement++;
               lastelement--;
           }
           else
           currentelement++;
       }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
