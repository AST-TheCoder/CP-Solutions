#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++){
          cin>>a[i];
        }
        ll p=-1,q=-1;
        for(ll i=1,j=n;i<j;i++,j--){
          if(a[i]!=a[j]){
            p=a[i];
            q=a[j];
            break;
          }
        }
        if(p==-1){
          cout<<"YES"<<endl;
          continue;
        }
        vector<ll> x,y;
        for(ll i=1;i<=n;i++){
          if(a[i]!=p) x.pb(a[i]);
          if(a[i]!=q) y.pb(a[i]);
        }
        ll ok=0;
        for(ll i=0,j=x.size()-1;i<j;i++,j--){
          if(x[i]!=x[j]){
            ok=1;
            break;
          }
        }
        if(!ok){
          cout<<"YES"<<endl;
          continue;
        }
        ok=0;
        for(ll i=0,j=y.size()-1;i<j;i++,j--){
          if(y[i]!=y[j]){
            ok=1;
            break;
          }
        }
        if(!ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
 
    return 0;
}