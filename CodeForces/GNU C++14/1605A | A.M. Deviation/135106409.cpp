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
 
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
 
        ll d=abs(a+c-2*b);
        cout<<((d%3)?1:0)<<endl;
    }
 
    return 0;
}