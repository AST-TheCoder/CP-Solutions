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
        ll n,m,k;
        cin>>n>>m>>k;
 
        string a,b,ans;
        cin>>a>>b;
        sort(all(a));
        sort(all(b));
 
        for(ll i=0,j=0,x=0,y=0;i<n && j<m;){
            if((a[i]<b[j] && x<k) || y==k){
                ans+=a[i];
                x++;
                y=0;
                i++;
            }
            else{
                ans+=b[j];
                y++;
                x=0;
                j++;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}