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
 
    ll n,k;
    cin>>n>>k;
 
    string s;
    cin>>s;
 
    ll ans=0;
 
    for(ll i=0;i<(ll)s.size()-2;i++){
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') ans++;
    }
 
    while(k--){
        ll i;
        char c;
        cin>>i>>c;
        i--;
 
        if(i<n-2 && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') ans--;
        else if(i<n-1 && i>0 && s[i-1]=='a' && s[i]=='b' && s[i+1]=='c') ans--;
        else if(i>=2 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c') ans--;
 
        s[i]=c;
        if(i<n-2 && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') ans++;
        else if(i<n-1 && i>0 && s[i-1]=='a' && s[i]=='b' && s[i+1]=='c') ans++;
        else if(i>=2 && s[i-2]=='a' && s[i-1]=='b' && s[i]=='c') ans++;
 
        cout<<ans<<endl;
    }
 
    return 0;
}