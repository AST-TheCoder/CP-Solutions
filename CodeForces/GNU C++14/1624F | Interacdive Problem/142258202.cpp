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
    ll n;
    cin>>n;
 
    ll l=1,r=n-1,s=0,q=0,ans=1;
    while(l<=r){
        ll m=(l+r)/2,x;
        ll temp=m+s;
        //cout<<l<<" "<<m<<" "<<r<<" "<<temp<<endl;
        if(!(temp%n)){
            if(q==temp/n){
                l=m+1;
                ans=m;
            }
            else r=m-1;
            continue;
        }
        temp=n-(temp%n);
        s+=temp;
        cout<<"+ "<<temp<<endl;
        cin>>x;
        if(q==x) r=m-1;
        else{
            ans=m;
            l=m+1;
        }
        q=x;
    }
    
    cout<<"! "<<ans+s<<endl;
 
    return 0;
}