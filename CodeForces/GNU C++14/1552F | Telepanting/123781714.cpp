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
 
    ll n,mod=998244353;
    cin>>n;
 
    pair<pair<ll,ll>,ll> a[n+1];
    a[0]={{0,0},0};
    for(ll i=1;i<=n;i++)
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
    
    sort(a,a+n+1,greater<pair<pair<ll,ll>,ll>>());
    ll ans=0,x=1,pos=a[0].first.first+1;
    priority_queue<pair<ll,ll>> q;
 
    for(ll i=0;i<=n;i++){
        while(!q.empty()){
            pair<ll,ll> val=q.top();
            if(val.first<a[i].first.first) break;
            q.pop();
            //cout<<pos<<" "<<val.first<<" "<<x<<" "<<"End"<<endl;
            ans+=((pos-val.first)*x);
            ans%=mod;
            pos=val.first;
            x-=val.second;
            x+=mod;
            x%=mod;
        }
        //cout<<pos<<" "<<a[i].first.first<<" "<<x<<" "<<"Start"<<endl;
        ans+=((pos-a[i].first.first+mod)*x);
        ans%=mod;
        pos=a[i].first.first;
        ll p;
        if(!a[i].second) p=(x-1+mod)%mod;
        else p=x;
        x+=p;
        x%=mod;
        //cout<<i<<" "<<x<<endl;
        q.push({a[i].first.second,p});
    }
    cout<<ans<<endl;
 
    return 0;
}