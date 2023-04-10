#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{   
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
     ll n;
     cin>>n;
     ll a[n],b[n];
     for(ll i=0;i<n;i++){
      cin>>a[i];
      b[i]=a[i];
     }
     for(ll i=1;i<n;i++) a[i]^=a[i-1];
     for(ll i=0;i<n-1;i++){
      ll x=0,cnt=0;
      for(ll j=i+1;j<n;j++){
       x^=b[j];
       if(x==a[i]){
        cnt++;
        x=0;
       }
      }
      //cout<<(a[i]^a[n-1])<<" "<<cnt%2<<" "<<x<<" "<<cnt<<endl;
      if(((a[i]^a[n-1])==a[i] && cnt%2==1 && x==0 && cnt) || ((a[i]^a[n-1])==0 && cnt%2==0 && x==0 && cnt)){
       cout<<"YES"<<endl;
       goto read;
      }
     }
     cout<<"NO"<<endl;
    }
 
 return 0;
}