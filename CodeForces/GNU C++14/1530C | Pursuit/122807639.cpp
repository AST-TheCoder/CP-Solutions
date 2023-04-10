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
        ll n;
        cin>>n;
 
        ll x[n+1],y[n+1];
        for(ll i=1;i<=n;i++) cin>>x[i];
        for(ll i=1;i<=n;i++) cin>>y[i];
 
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
 
        ll a=0,b=0,c=0,i,j;
        for(i=1,j=1;j<=n;j++){
            if(j/4==i){
                a-=x[i];
                b-=y[i];
                i++;
            }
            a+=x[j];
            b+=y[j];
        }
        ll k=i;
        while(a<b){
            a+=100;
            if(j/4==i){
                a-=x[i];
                i++;
            }
            else if(k>1){
                k--;
                b+=y[k];
            }
            c++;
            j++;
        }
        cout<<c<<endl;
    }
 
    return 0;
}