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
 
string s;
ll a[20];
ll solve(ll i){
    ll p,ans=0;
    if(i>=s.size()) return 1;
    if(a[i]!=19){
        if(a[i]>=10){
            ll r=a[i]/2,l=a[i]-9;
            if(a[i]%2) p=2*(r-l+1);
            else p=2*(r-l)+1;
        }
        else p=a[i]+1;
        ans+=solve(i+1)*p;
    }
    if((i+2<s.size() && a[i+2]<9) || (i+4<s.size() && a[i+2]<10)){
        ll v=a[i]-1;
        if(i>=s.size()) return 1;
        if(v>=10){
            ll r=v/2,l=v-9;
            if(v%2) p=2*(r-l+1);
            else p=2*(r-l)+1;
        }
        else p=v+1;
        a[i+2]+=10;
        ans+=solve(i+1)*p;
        a[i+2]-=10;
    }
    return ans;
}
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        cin>>s;
        for(ll i=0;i<s.size();i++) a[i]=(ll)(s[i]-'0');
        cout<<solve(0)-2<<endl;
    }
 
    return 0;
}