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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{  
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        if(n==1 && m==1){
            cout<<0<<endl;
            continue;
        }
        cout<<n-1+m-1+1+min(n,m)-1<<endl;
    }
 
    return 0;
}