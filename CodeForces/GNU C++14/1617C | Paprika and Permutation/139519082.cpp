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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n;
        scanf("%lli",&n);
 
        ll chk[n+1];
        memset(chk,0,sizeof(chk));
        multiset<ll> x;
        for(ll i=1;i<=n;i++){
            ll temp;
            scanf("%lli",&temp);
            if(temp<=n && !chk[temp]) chk[temp]=1;
            else x.insert(temp);
        }
        x.insert(Max);
        ll ans=0;
        for(ll i=1;i<=n;i++){
            if(chk[i]) continue;
            multiset<ll>::iterator it=x.upper_bound(2*i);
            //cout<<i<<" "<<(*it)<<endl;
            if((*it)==Max){
                printf("-1\n");
                goto read;
            }
            ans++;
            x.erase(it);
        }
        printf("%lli\n",ans);
    }
 
    return 0;
}