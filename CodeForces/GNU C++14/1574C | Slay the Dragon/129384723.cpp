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
 
    ll n,s=0;
    scanf("%lli",&n);
    vector<ll> a;
    for(ll i=0;i<n;i++){
        ll x;
        scanf("%lli",&x);
        a.pb(x);
        s+=x;
    }
    sort(all(a));
    ll q;
    scanf("%lli",&q);
    while(q--){
        ll x,y,ans;
        scanf("%lli %lli",&x,&y);
        ll id=lower_bound(all(a),x)-a.begin();
        if(id==a.size()){
            ans=x-a[n-1];
            ans+=max(0LL,y-s+a[n-1]);
        }
        else{
            ans=max(0LL,y-s+a[id]);
            if(id){
                ll p=x-a[id-1];
                p+=max(0LL,y-s+a[id-1]);
                ans=min(ans,p);
            }
        }
        printf("%lli\n",ans);
    }
 
    return 0;
}