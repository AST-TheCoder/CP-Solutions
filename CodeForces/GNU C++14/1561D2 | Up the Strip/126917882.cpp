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
 
int a[4000001];
int main()
{   
    
 
    int n,mod;
    cin>>n>>mod;
 
 
    ll c=1,s=0,cnt=0;
    a[1]=1;
    a[0]=0;
 
    vector<ll> d[100];
    for(ll i=2;i<=n;i++){
        ll id=i%100;
        if(i==2 || id==1){
            for(ll j=0;j<100;j++){
                cnt++;
                d[j].clear();
            }
            ll l=((i/100)+1)*100;
            for(ll j=101;j*j<=l;j++){
                ll st=(i-1)/j;
                st=(st+1)*j;
                if(st<j*j) st=j*j;
                if(st<=l) d[st%100].pb(j);
                cnt++;
            }
        }
        for(ll j=-100;j<d[id].size();j++){
            cnt++;
            ll v;
            if(j<0){
                v=j+101;
                if(i%v || v*v>i) continue;
            }
            else v=d[id][j];
            s+=a[v];
            s%=mod;
            s-=a[v-1];
            s+=mod;
            s%=mod;
            if(i>v*v && v!=1){
                ll p=(i-1)/v;
                s-=a[p];
                s+=mod;
                s%=mod;
                s+=a[p+1];
                s%=mod;
            }
        }
        
        ll x=(c+s)%mod;
        a[i]=(int)x;
        c+=(ll)a[i];
        c%=mod;
    }
 
    //cout<<cnt<<endl;
    cout<<a[n]<<endl;
 
    return 0;
}