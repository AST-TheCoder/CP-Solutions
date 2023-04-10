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
        ll n;
        char c;
        scanf("%lli %c",&n,&c);
        string s;
        cin>>s;
        ll k;
        for(k=1;k<=n;k++){
            ll ok=0;
            for(ll i=k-1;i<n;i+=k){
                if(s[i]!=c){
                    ok=1;
                    break;
                }
            }
            if(!ok) break;
        }
        if(k==1) printf("0\n");
        else if(k<=n) printf("1\n%lli\n",k);
        else printf("2\n%lli %lli\n",n-1,n);
    }
 
    return 0;
}