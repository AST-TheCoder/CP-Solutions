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
 
vector<ll> p;
bool c[31626];
 
int main()
{   
    
    for(ll i=2;i<=31625;i++){
        if(!c[i]){
            p.pb(i);
            for(ll j=i;j<=31625;j+=i){
                c[j]=1;
            }
        }
    }
 
    ll t;
    scanf("%lli",&t);
    while(t--){
        ll a,b,k;
        scanf("%lli %lli %lli",&a,&b,&k);
        ll cnt=0;
        if(k==1){
            if(a<b) swap(a,b);
            if(a%b || a==b) printf("NO\n");
            else printf("YES\n");
            continue;
        }
        for(ll i=0;i<p.size();i++){
            while(!(a%p[i])){
                cnt++;
                a/=p[i];
            }
            while(!(b%p[i])){
                cnt++;
                b/=p[i];
            }
        }
        if(a!=1) cnt++;
        if(b!=1) cnt++;
        if(cnt>=k) printf("YES\n");
        else printf("NO\n");
    }
 
    return 0;
}