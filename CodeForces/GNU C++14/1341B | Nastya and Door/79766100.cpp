#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 
 while(t--){
  int n,k;
  cin>>n>>k;
 
  int a[n],b[n];
  memset(b,0,sizeof(b));
 
  for(int i=0;i<n;i++) cin>>a[i];
 
  for(int i=1;i<n-1;i++){
   if(a[i]>a[i-1] && a[i]>a[i+1]){
    b[i]=1;
   }
  }
 
  for(int i=1;i<n;i++) b[i]+=b[i-1];
 
  int x=1,l=1;
  for(int i=0,j=k-1;j<n;i++,j++){
   if(b[j-1]-b[i]+1>x){
    x=b[j-1]-b[i]+1;
    l=i+1;
   }
  }
 
  cout<<x<<" "<<l<<endl;
 
 }
 
 return 0;
}