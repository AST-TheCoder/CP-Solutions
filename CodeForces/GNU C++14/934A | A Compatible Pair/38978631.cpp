#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll m,n;
 
    cin>>n>>m;
 
    ll a[n],b[n];
 
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) b[i]=-2*pow(10,18);
 
    for(int i=0,t;i<m;i++){
        cin>>t;
        for(int j=0;j<n;j++){
            b[j]=max(b[j],t*a[j]);
        }
    }
 
    sort(b,b+n,greater<ll>());
    cout<<b[1];
 
    return 0;
}