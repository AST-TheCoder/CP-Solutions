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
 
    read:
    while(t--){
        ll n,q;
        scanf("%lli %lli",&n,&q);
        string s;
        cin>>s;
        ll c[n+1];
        vector<pair<ll,ll>> x,y;
        c[0]=0;
        for(ll i=0,p=0;i<n;i++){
            if(i%2){
                if(s[i]=='+') s[i]='-';
                else s[i]='+';
            }
            if(s[i]=='+'){
                p++;
                x.pb({p,i+1});
            }
            else{
                p--;
                y.pb({p,i+1});
            }
            c[i+1]=p;
        }
        sort(all(x));
        sort(all(y));
        //cout<<s<<endl;
        while(q--){
            ll l,r;
            scanf("%lli %lli",&l,&r);
            ll d=abs(c[r]-c[l-1]);
            if(d==0){
                printf("0\n");
                continue;
            }
            else if(d%2) printf("1\n");
            else{
                printf("2\n%lli ",r);
                r--;
            }
            d=c[r]-c[l-1];
            ll id,ps;
            pair<ll,ll> v;
            if(d>0){
                v={c[l-1]+d/2+1,l};
                ps=c[l-1]+d/2+1;
            }
            else{
                v={c[l-1]+d/2,l};
                ps=c[l-1]+d/2;
            }
            id=lower_bound(all(x),v)-x.begin();
            if(id!=x.size() && x[id].second<=r && x[id].first==ps){
                printf("%lli\n",x[id].second);
                continue;
            }
            if(d>0) v={c[l-1]+d/2,l};
            else v={c[l-1]+d/2-1,l};
            id=lower_bound(all(y),v)-y.begin();
            printf("%lli\n",y[id].second);
        }
    }
 
    return 0;
}