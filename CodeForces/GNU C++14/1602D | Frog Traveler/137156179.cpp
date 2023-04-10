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
 
    ll n;
    cin>>n;
 
    ll a[n+1],b[n+1];
 
    a[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]=i-a[i];
    }
 
    b[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>b[i];
        b[i]=i+b[i];
    }
 
    ll chk[n+1];
    vector<ll> ans;
    memset(chk,-1,sizeof(chk));
    chk[n]=0;
 
    for(ll i=n,y=n;;){
        //cout<<i<<" "<<y<<endl;
        ll x=Max,id,temp;
        for(ll j=a[i];j<y;j++){
            if(chk[b[j]]!=-1) continue;
            chk[b[j]]=chk[i]+1;
            if(a[b[j]]<x){
                x=a[b[j]];
                id=b[j];
                temp=j;
            }
        }
        ans.pb(temp);
        if(x>=a[i]) break;
        y=a[i];
        i=id;
    }
 
    cout<<chk[0]<<endl;
    if(chk[0]!=-1){
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
 
    return 0;
}