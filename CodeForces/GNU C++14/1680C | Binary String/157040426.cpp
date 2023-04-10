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
    ll t;
    cin>>t;
 
    read:
    while(t--){
        string s;
        cin>>s;
 
        ll a[s.size()];
        memset(a,0,sizeof(a));
 
        for(ll i=0;i<s.size();i++){
            if(s[i]=='1') a[i]=1;
            if(i) a[i]+=a[i-1];
        }
 
        ll l=0,r=s.size(),ans=0;
        while(l<=r){
            ll m=(l+r)/2;
            ll c=0;
            ll ok=0;
            for(ll i=0,j=0;j<s.size();j++){
                if(s[j]=='0') c++;
                while(c>m){
                    if(s[i]=='0') c--;
                    i++;
                }
                if(c<=m){
                    ll chk=a[s.size()-1]-a[j];
                    if(i) chk+=a[i-1];
                    if(chk<=m){
                        ok=1;
                        break;
                    }
                }
            }
            if(ok){
                ans=m;
                r=m-1;
            }
            else l=m+1;
            //cout<<m<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}