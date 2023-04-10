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
    scanf("%lli",&t);
 
    while(t--){
        ll n,cnt=0;
        scanf("%lli",&n);
 
        vector<ll> a;
        for(ll i=0;i<n;i++){
            ll x;
            scanf("%lli",&x);
            if(x%2) a.pb(x);
            else cnt++;
        }
 
        ll ans=0;
        for(ll i=n-1;cnt;i--,cnt--){
            ans+=i;
        }
        //cout<<"OK"<<endl;
        for(ll i=0;a.size()!=0 && i<a.size()-1;i++){
            for(ll j=i+1;j<a.size();j++){
                if(__gcd(a[i],a[j])>1) ans++;
            }
        }
        printf("%lli\n",ans);
    }
 
    return 0;
}