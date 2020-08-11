#include<bits/stdc++.h>
using namespace std;
 
int main()
{
int y,ctr=0;
cin>>y;
for(int x=2;x<=y;x++)
    {
      if(y%x==0)
        ctr++;
    }
    cout<<ctr;
}