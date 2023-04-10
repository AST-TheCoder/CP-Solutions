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
using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{   
    
    ll n,k,e=0,o=0;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%2) o++;
        else e++;
    }
 
    if(n==k){
        if(o%2) cout<<"Stannis"<<endl;
        else cout<<"Daenerys"<<endl;
    }
    else if(k%2==0){
        ll m=(n-k)/2;
        if(o<=m || e<=m || (n-k)%2==0) cout<<"Daenerys"<<endl;
        else cout<<"Stannis"<<endl;
    }
    else{
        ll m=(n-k+1)/2;
        if(e<=m || ((n-k)%2 && n-k-m<o)) cout<<"Stannis"<<endl;
        else cout<<"Daenerys"<<endl;
    }
 
    return 0;
}