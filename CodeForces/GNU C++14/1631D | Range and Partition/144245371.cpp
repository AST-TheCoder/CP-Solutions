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
 
ll a[100000];
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=k-1;
        ans+=(n-ans+2)/2;
 
        ll a[n+1],c[n+1];
        memset(c,0,sizeof(c));
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            c[a[i]]++;
        }
        for(ll i=1;i<=n;i++) c[i]+=c[i-1];
 
        ll x=1,y=n,d=y-x;
 
        for(ll i=1;i<=n;i++){
            ll l=i,r=n;
            while(l<r){
                ll m=(l+r)/2;
                ll temp=c[m]-c[i-1];
 
                if(temp>=ans) r=m;
                else l=m+1;
            }
            if(c[r]-c[i-1]>=ans && r-i<d){
                d=r-i;
                x=i;
                y=r;
            }
        }
        cout<<x<<" "<<y<<endl;
        for(ll i=1,l=1,c1=0,c2=0;i<=n;i++){
            if(k==1){
                cout<<i<<" "<<n<<endl;
                break;
            }
            if(a[i]>=x && a[i]<=y) c1++;
            else c2++;
 
            if(c1>c2){
                cout<<l<<" "<<i<<endl;
                l=i+1;
                k--;
                c1=0,c2=0;
            }
        }
    }
 
    return 0;
}