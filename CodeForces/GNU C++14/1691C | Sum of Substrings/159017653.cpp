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
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n,k;
        cin>>n>>k;
 
        string s;
        cin>>s;
 
        ll c1=0,c2=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='1') break;
            c1++;
        }
        if(c1==n){
            cout<<0<<endl;
            continue;
        }
        for(ll i=n-1;i>=0;i--){
            if(s[i]=='1') break;
            c2++;
        }
 
        ll ans=count(all(s),'1')*11;
 
        if(c2<=k){
            k-=c2;
            ans-=10;
            if(c1<=k && ans!=1){
                ans--;
            }
        }
        else if(c1<=k) ans--;
        cout<<ans<<endl;
    }
 
    return 0;
}