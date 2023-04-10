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
 
ll chk[1000007];
 
int main()
{   
    ll n,m;
    cin>>n>>m;
 
    vector<vector<ll>> val;
 
    for(ll i=2;i<=n;i++){
        if(!chk[i]){
            vector<ll> temp;
 
            for(ll j=i;j<=n;j*=i){
                temp.pb(j);
                chk[j]=1;
            }
            val.pb(temp);
        }
    }
 
    ll ans=1;
    for(ll i=0;i<val.size();i++){
        vector<pair<ll,ll>> temp;
        temp.pb({1,1});
 
        for(ll j=val[i].size();j>=1;j--){
            ll sz=temp.size();
            ll cnt=0;
            for(ll k=0;k<sz;k++){
                if(temp[k].second==1){
                    ll lcm=(temp[k].first*j)/__gcd(temp[k].first,j);
                    cnt+=(m*j)/lcm;
                    temp.pb({lcm,0});
                }
                else{
                    ll lcm=(temp[k].first*j)/__gcd(temp[k].first,j);
                    cnt-=(m*j)/lcm;
                    temp.pb({lcm,1});
                }
            }
            ans+=cnt;
            //cout<<val[i][0]<<" "<<cnt<<endl;
        }
    }
 
    cout<<ans<<endl;
 
    return 0;
}