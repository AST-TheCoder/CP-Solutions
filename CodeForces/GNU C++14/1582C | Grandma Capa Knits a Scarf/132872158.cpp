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
    cin>>t;
 
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=Max;
        for(char c='a'-1;c<='z';c++){
            ll ok=0,cnt=0;
            for(ll i=0,j=n-1;i<j;){
                if(s[i]==s[j]) i++,j--;
                else if(s[i]==c) i++,cnt++;
                else if(s[j]==c) j--,cnt++;
                else{
                    ok=1;
                    break;
                }
            }
            if(!ok) ans=min(ans,cnt);
        }
        if(ans==Max) ans=-1;
        cout<<ans<<endl;
    }
 
    return 0;
}