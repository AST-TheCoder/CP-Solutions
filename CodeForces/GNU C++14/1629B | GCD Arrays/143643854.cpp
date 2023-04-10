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
        ll l,r,k;
        cin>>l>>r>>k;
 
        ll c=r-l+1;
        if(c%2){
            if(l%2) c=c/2+1;
            else c/=2;
        }
        else c/=2;
        if(l==1 && r==1) cout<<"NO"<<endl;
        else if(l==r) cout<<"YES"<<endl;
        else if(k>=c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}