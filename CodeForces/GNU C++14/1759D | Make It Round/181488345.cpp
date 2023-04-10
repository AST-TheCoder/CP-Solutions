#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
 
    ll t;;
    cin>>t;
 
    read:
    while(t--){
        
        ll n,m;
        cin>>n>>m;
 
        ll x=0,y=0,v=n;
        while(n%2==0){
            x++;
            n/=2;
        }
 
        while(n%5==0){
            y++;
            n/=5;
        }
 
        ll k=1;
 
        if(x>y){
            ll p=x-y;
            while(p--){
                if(k*5<=m) k*=5;
            }
        }
        else{
            ll p=y-x;
            while(p--){
                if(k*2<=m) k*=2;
            }
        }
 
        while(k*10<=m) k*=10;
        k=(m/k)*k;
 
        cout<<v*k<<endl;
 
    }
 
    return 0;
}