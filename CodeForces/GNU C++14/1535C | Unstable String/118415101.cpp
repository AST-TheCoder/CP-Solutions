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
        string s;
        cin>>s;
        s="1"+s;
        ll idx[s.size()],c=1;
        for(ll j=0,i=1;i<s.size();i++){
            if(s[i]!='?'){
                idx[j]=i-1;
                j=i;
                c=(ll)(s[i]-'0');
            }
            else c=(c==0);
            if(i+1==s.size()) idx[j]=i;
        }
        ll l=s.size()-2,r=s.size()-1,ans=0;
        for(;l>=1;l--){
            c=(c==0);
            if(s[l]=='?') continue;
            if((ll)(s[l]-'0')!=c){
                ll ran=(r-l);
                ll p=idx[l]-l;
                ans+=(ran*(ran+1))/2-(p*(p+1))/2;
                r=idx[l];
                c=(ll)(s[l]-'0');
            }
        }
        ll ran=(r-l);
        ans+=(ran*(ran+1))/2;
        cout<<ans<<endl;
    }
 
    return 0;
}