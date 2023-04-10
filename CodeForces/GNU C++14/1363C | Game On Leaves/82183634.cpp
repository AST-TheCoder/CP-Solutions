#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 int t;
 cin>>t;
 
 while(t--){
  int n,x;
  cin>>n>>x;
 
  int c=0;
  for(int i=1;i<n;i++){
   ll p,q;
   cin>>p>>q;
   if(p==x || q==x) c++;
  }
 
  if(c<=1) cout<<"Ayush"<<endl;
  else{
   if((n-1)%2) cout<<"Ayush"<<endl;
   else cout<<"Ashish"<<endl;
  }
 }
 
 return 0;
}