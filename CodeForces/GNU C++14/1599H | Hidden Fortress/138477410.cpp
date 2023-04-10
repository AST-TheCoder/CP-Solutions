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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll a,d,z=1000000000,x,y,p,q;
    cout<<"?"<<" "<<1<<" "<<1<<endl;
    cin>>a;
    cout<<"?"<<" "<<1<<" "<<z<<endl;
    cin>>d;
 
    ll t=(z+a-d+3)/2;
    cout<<"?"<<" "<<1<<" "<<t<<endl;
    cin>>x;
    if((z+a-d+3)%2){
        t++;
        cout<<"?"<<" "<<1<<" "<<t<<endl;
        cin>>t;
        x=min(x,t);
    }
    x++;
 
    cout<<"?"<<" "<<x<<" "<<1<<endl;
    cin>>y;
    y++;
 
    cout<<"?"<<" "<<z<<" "<<y<<endl;
    cin>>p;
    p=z-p;
 
    cout<<"?"<<" "<<x<<" "<<z<<endl;
    cin>>q;
    q=z-q;
 
    cout<<"!"<<" "<<x<<" "<<y<<" "<<p<<" "<<q<<endl;
 
    return 0;
}