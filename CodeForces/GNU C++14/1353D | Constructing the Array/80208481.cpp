#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 while(t--){
  int n;
  cin>>n;
 
  int ans[n+1];
  priority_queue<pair<int,pair<int,int>>> x;
  x.push(make_pair(n,make_pair(-1,-n)));
 
  for(int i=1;i<=n;i++){
   pair<int,pair<int,int>> p=x.top();
   x.pop();
 
   p.second.first=-p.second.first;
   p.second.second=-p.second.second;
 
   int pos=(p.second.first+p.second.second)/2;
   ans[pos]=i;
 
   x.push(make_pair(pos-p.second.first,make_pair(-p.second.first,-pos+1)));
   x.push(make_pair(p.second.second-pos,make_pair(-pos-1,-p.second.second)));
  }
 
  for(int i=1;i<=n;i++){
   cout<<ans[i]<<" ";
  }cout<<endl;
 }
}