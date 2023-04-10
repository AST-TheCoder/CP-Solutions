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
 
    read:
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        string s;
        cin>>s;
        vector<ll> b,r;
        r.pb(-Max);
        //b.pb(Max);
        for(ll i=0;i<n;i++){
            if(s[i]=='R') r.pb(a[i]);
            else b.pb(a[i]);
        }
        sort(all(r));
        sort(all(b),greater<ll>());
        for(ll i=n,p=r.size()-1,q=0,c=0;i>=1;i--){
            while(p>0 && r[p]>i) p--;
            while(q<b.size() && b[q]>=i) q++;
            if(!p && !(q-c)){
                cout<<"NO"<<endl;
                goto read;
            }
            else if(p) p--;
            else c++;
        }
        cout<<"YES"<<endl;
    }
 
    return 0;
}