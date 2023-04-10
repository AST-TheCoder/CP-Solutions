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
 
ll mark[2000001],a[1000001],chk[2000001];
 
int main()
{   
    
    ll t;
    scanf("%lli",&t);
 
    read:
    while(t--){
        ll n,c;
        scanf("%lli %lli",&n,&c);
 
        for(ll i=0;i<=2*c;i++){
            mark[i]=0;
            chk[i]=0;
        }
 
        for(ll i=1;i<=n;i++){
            scanf("%lli",&a[i]);
            mark[a[i]]=1;
        }
        for(ll i=1;i<=2*c;i++) chk[i]=mark[i]+chk[i-1];
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++){
            if(i==1 || a[i]!=a[i-1]){
                for(ll j=2*a[i]-1;j-a[i]<=c;j+=a[i]){
                    if(!mark[(ll)(j/a[i])]){
                        ll ran=chk[j]-chk[j-a[i]];
                        if(ran){
                            printf("NO\n");
                            goto read;
                        }
                    }
                }
            }
        }
 
        printf("YES\n");
    }
 
    return 0;
}