#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,c=0,p=0,m=0;
 string a,b;
 
 cin>>n>>a>>b;
 if(count(all(a),'1')!=count(all(b),'1') || count(all(a),'0')!=count(all(b),'0')){
  cout<<-1<<endl;
  return 0;
 }
 
 for(ll i=0;i<n;i++){
  if(a[i]=='1' && b[i]=='0') c++;
  if(a[i]=='0' && b[i]=='1') c--;
 
  if(c>0) p=max(p,c);
  else m=max(m,-1*c);
 }
 
 cout<<p+m<<endl;
 
    return 0;
}