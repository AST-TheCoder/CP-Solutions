#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 
 read:
 while(t--){
  int n,k;
  cin>>n>>k;
 
  int a[n+1],ok=0;
  for(int i=1;i<=n;i++){
   cin>>a[i];
   if(a[i]==k) ok=1;
  }
 
  if(!ok){
   cout<<"No"<<endl;
   goto read;
  }
 
  if(n<=2){
   for(int i=1;i<=n;i++){
    if(a[i]<k){
     ok=0;
    }
   }
   if(!ok) cout<<"No"<<endl;
   else cout<<"Yes"<<endl;
   goto read;
  }
 
  for(int i=1;i<=n-2;i++){
   if((a[i]>=k && a[i+1]>=k) || (a[i]>=k && a[i+2]>=k) || (a[i+1]>=k && a[i+2]>=k)){
    cout<<"Yes"<<endl;
    goto read;
   }
  }
 
  cout<<"No"<<endl;
 }
 return 0;
}