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
    
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
 
        string s;
        cin>>s;
 
        ll n=s.size();
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans+=(s[i]-'a'+1);
        }
        //cout<<ans<<endl;
        if(n==1) cout<<"Bob"<<" "<<ans<<endl;
        else if(n%2) cout<<"Alice"<<" "<<ans-2*(min(s[0],s[n-1])-'a'+1)<<endl;
        else cout<<"Alice"<<" "<<ans<<endl;
    }
 
    return 0;
}