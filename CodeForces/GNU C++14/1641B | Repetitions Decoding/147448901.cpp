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
    ll t;
    cin>>t;
 
    read:
 
    while(t--){
        ll n,chk=0;
        cin>>n;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
 
        vector<ll> len;
        vector<pair<ll,ll>> q;
        for(ll i=1;i<=n;i+=2){
            if(!a[i]) continue;
            ll ok=0;
            for(ll j=i+1;j<=n;j++){
                if(a[i]==a[j]){
                    ok=1;
                    a[i]=a[j]=0;
                    for(ll k=j+1;k-j+i<j;k++){
                        q.pb({k+chk-i,a[k-j+i]});
                    }
                    chk+=(2*(j-i));
                    len.pb(2*(j-i));
                    for(ll k=0;;k++){
                        if(i+k+1>=j-k) break;
                        swap(a[i+k+1],a[j-k]);
                    }
 
                    //cout<<i<<" "<<j<<endl;
                    //for(ll k=1;k<=n;k++) cout<<a[k]<<" ";cout<<endl;
                    break;
                }
            }
            if(!ok){
                cout<<-1<<endl;
                goto read;
            }
        }
 
        cout<<q.size()<<endl;
        for(ll i=0;i<q.size();i++) cout<<q[i].first<<" "<<q[i].second<<endl;
 
        cout<<len.size()<<endl;
        for(ll i=0;i<len.size();i++) cout<<len[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}