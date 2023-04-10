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
        
        ll l,r,x,a,b;
        cin>>l>>r>>x>>a>>b;
 
        if(a==b) cout<<0<<endl;
        else if(abs(a-b)>=x) cout<<1<<endl;
        else if((a-l>=x && b-l>=x) || (r-a>=x && r-b>=x)) cout<<2<<endl;
        else if(r-l>=x && ((a-l>=x && r-b>=x) || (r-a>=x && b-l>=x))) cout<<3<<endl;
        else cout<<-1<<endl;
 
    }
 
    return 0;
}