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
        cin>>n;
        string s;
        cin>>s;
 
        ll c[n],b[n];
        vector<ll> id;
        ll ans=Max;
        for(ll i=0;i<n;i++){
            if(!i) c[i]=b[i]=0;
            else{
                b[i]=b[i-1];
                c[i]=c[i-1];
            }
            if(s[i]=='b') b[i]++;
            if(s[i]=='c') c[i]++;
            if(s[i]=='a') id.pb(i);
        }
        for(ll i=0,j=2;j<id.size();i++,j++){
            if(b[id[j]]-b[id[i]]<3 && c[id[j]]-c[id[i]]<3)
                ans=min(ans,id[j]-id[i]+1);
        }
        for(ll i=0,j=1;j<id.size();i++,j++){
            if(b[id[j]]-b[id[i]]<2 && c[id[j]]-c[id[i]]<2)
                ans=min(ans,id[j]-id[i]+1);
        }
        if(ans==Max) ans=-1;
        cout<<ans<<endl;
    }
 
    return 0;
}