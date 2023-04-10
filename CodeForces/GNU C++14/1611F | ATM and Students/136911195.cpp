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
 
    read:
    while(t--){
        ll n,s;
        cin>>n>>s;
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll l=0,r=0,len=-1;
        for(ll i=1,j=1,m=0;j<=n;){
            m+=a[j];
            while(m<-s){
                m-=a[i];
                i++;
            }
            if(i>j){
                j=i;
                continue;
            }
            if(j-i+1>len){
                len=j-i+1;
                l=i,r=j;
            }
            j++;
        }
        if(len!=-1) cout<<l<<" "<<r<<endl;
        else cout<<len<<endl;
    }
 
    return 0;
}