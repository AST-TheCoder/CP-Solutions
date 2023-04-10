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
    while(t--){
        ll k;
        cin>>k;
        ll x=1;
        while(x*x<k) x++;
        ll d=(x*x)-((x-1)*(x-1)),m=k-((x-1)*(x-1));
        if(m<=d/2) cout<<m<<" "<<x<<endl;
        else{
            m-=d/2;
            cout<<x<<" "<<x-m+1<<endl;
        }
    }
 
    return 0;
}