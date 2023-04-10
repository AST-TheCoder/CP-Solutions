#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n;
 cin>>n;
 ll a[2*n+1],sum=0;
 for(ll i=1;i<=n;i++) cin>>a[i];
 for(ll i=1;i<=n;i++) a[n+i]=a[i];
 
 for(ll i=1;i<=n;i+=2) sum+=a[i];
 ll ans=sum;
 
 for(ll i=2;i<=2*n;i+=2){
  sum-=a[i-1];
  sum+=a[i];
  ans=max(ans,sum);
 }
 
 cout<<ans<<endl;
 
    return 0;
}