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
        ll n,k;
        cin>>n>>k;
 
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
 
        ll mex=0,c=0;
        for(ll i=1,u=0;i<=n;i++){
            if(a[i]>mex){
                if(c<k && c<n-u){
                    c++;
                    mex++;
                    i--;
                }
            }
            else if(a[i]==mex){
                if(c<n-u){
                    mex++;
                    u++;
                    a[i]=-1;
                }
            }
            else{
                a[i]=-1;
            }
            if(i==n){
                while(c<k && c<n-u){
                    c++;
                    mex++;
                }
            }
        }
        sort(a+1,a+n+1);
        ll diff=mex,l=1;
        vector<ll> p;
        for(ll i=2;i<=n;i++){
            if(a[i]!=a[i-1]){
                if(a[l]==-1){
                    l=i;
                    continue;
                }
                p.pb(i-l);
                l=i;
            }
        }
        if(a[l]!=-1) p.pb(n-l+1);
        sort(all(p));
        diff+=p.size();
        for(ll i=0;i<p.size();i++){
            if(p[i]<=c){
                c-=p[i];
                diff--;
            }
            else break;
        }
        cout<<diff-mex<<endl;
    }
 
    return 0;
}