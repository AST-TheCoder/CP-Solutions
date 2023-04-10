#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
 
int main()
{
 
 ll n,k;
 cin>>n>>k;
 
 ll a[n],l=INT_MAX,r=1;
 for(ll i=0;i<n;i++){
  cin>>a[i];
  l=min(l,a[i]);
  r=max(r,a[i]);
 }
 
 while(l<r){
  ll m=(l+r)/2,rng=k/2,cnt=0;
  for(ll i=1;i<n-(k%2);i++){
   if(a[i]<=m){
    cnt++;
    i++;
   }
  }
  if(cnt>=rng){
   r=m;
   continue;
  }
  rng+=k%2;cnt=0;
  for(ll i=0;i<n-(k%2==0);i++){
   if(a[i]<=m){
    cnt++;
    i++;
   }
  }
  if(cnt>=rng) r=m;
  else l=m+1;
 }
 
 cout<<l<<endl;
 
    return 0;
}