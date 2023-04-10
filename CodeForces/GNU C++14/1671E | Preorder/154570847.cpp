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
 
string t[263000];
string s;
ll ans[263000],n;
ll mod=998244353;
 
void dfs(ll x){
    if(2*x>=n){
        ans[x]=1;
        t[x]+=s[x];
        return;
    }
    dfs(2*x);
    dfs(2*x+1);
    t[x]+=s[x];
    ans[x]=(ans[2*x]*ans[2*x+1])%mod;
    if(t[2*x]!=t[2*x+1]){
        ans[x]=(2*ans[x])%mod;
        if(t[2*x]<t[2*x+1]) t[x]=t[x]+t[2*x]+t[2*x+1];
        else t[x]=t[x]+t[2*x+1]+t[2*x];
    }
    else t[x]=t[x]+t[2*x]+t[2*x+1];
}
 
int main()
{   
    
    ll dep;
    cin>>dep;
 
    cin>>s;
    s="#"+s;
    n=s.size();
 
    dfs(1);
    cout<<ans[1]<<endl;
 
    return 0;
}