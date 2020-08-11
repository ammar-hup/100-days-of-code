#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,ctr=0,sum=0;
    cin>>n;
    int arr[n];
        for (int& x:arr)
        {
            cin>>x;
        }
            sort(arr,arr+n);
            sum=arr[0]+arr[n-1];
                for(int i=n-1;i>0;i--)
                    {
                    for(int j=i-1;j>=0;j--)
                        {
                      if(arr[i]+arr[j]==sum)
                        ctr++;
 
                        }
 
                    }
           cout<<ctr;
 
}