#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 cout.flush();
 int t;
 cin>>t;
 
 while(t--){
 
  int n,k;
  cin>>n>>k;
 
  vector<int> v[k];
  for(int i=0;i<k;i++){
   int c;
   cin>>c;
   for(int j=0;j<c;j++){
    int x;
    cin>>x;
    v[i].push_back(x);
   }
  }
 
  int m,p;
  cout<<"? "<<n;
  for(int i=1;i<=n;i++) cout<<" "<<i;
  cout<<endl;
  cin>>m;
 
  int l=0,r=k-1;
  while(l<r){
   int mid=(l+r)/2,q;
   vector<int> x;
   for(int i=l;i<=mid;i++){
    for(int j=0;j<v[i].size();j++){
     x.push_back(v[i][j]);
    }
   }
   if(x.size()){
    cout<<"? "<<x.size();
    for(int i=0;i<x.size();i++) cout<<" "<<x[i];
    cout<<endl;
    cin>>q;
   }
 
   if(q!=m) l=mid+1;
   else r=mid;
  }
  if(n-v[l].size()){
   cout<<"? "<<n-v[l].size();
   for(int i=1;i<=n;i++){
    if(!count(v[l].begin(),v[l].end(),i)) cout<<" "<<i;
   }cout<<endl;
   cin>>p;
  }
 
  string s;
  cout<<"!";
  for(int i=0;i<k;i++){
   if(i==l) cout<<" "<<p;
   else cout<<" "<<m;
  }cout<<endl;
  cin>>s;
 }
 
 return 0;
}