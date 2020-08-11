#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
float s,k,a,b;
float mi=numeric_limits<float>::max();
cin>>s>>k;
for(int x=0;x<s;x++)
    {
       cin>>a>>b;
       mi=min(a/b,mi);
    }
cout << fixed << setprecision(7) << mi*k  <<endl;
}