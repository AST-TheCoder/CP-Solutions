/******************************************************/
/******************************************************/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         Al-Shahriar Tonmoy - Red_Sparkle         **/
/**  Department of Computer Science and Engineering  **/
/**               Barisal University                 **/
/**               It's time to bloom.                **/
/******************************************************/
/******************************************************/
 
#include<bits/stdc++.h>
using namespace std;
#define     ll              long long int
#define     ul              unsigned long long int
#define     dob             double
#define     st              string
#define     ch              char
#define     pairl           pair<ll,ll>
#define     pairs           pair<string,int>
#define     pairi           pair<int,string>
#define     pairss          pair<string,string>
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     fr              first
#define     se              second
#define     T               true
#define     F               false
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     maxi            1000000000000014
#define     mini            -100000000000014
#define     mod             1000000007
#define     an              2000005
#define     maps            map<string,int>
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
ve b,a[an],ts;
bool c[an];
int u[an],v[an],xi[an];
mapi mpe;
 
void DFS(int source)
{
 
    c[source]=T;
 
    //for(int i=0;i<a[source].size();i++) cout<<a[source][i]<<" ";
    //cout<<endl;
    xi[source]=1;
    for(int i=0;i<a[source].size();i++){
 
        if(c[a[source][i]]==F){
 
            DFS(a[source][i]);
 
            xi[source]+=(xi[a[source][i]]);
 
        }
 
    }
    //cout<<endl;
    //cout<<xi[source]<<" "<<source<<endl;
    //cout<<endl;
    ts.pi(source);
    return;
 
}
 
int main()
{
 
    int n,k;
 
    cin>>n>>k;
 
    for(int i=1;i<n;i++){
 
        int p;
 
        cin>>p;
 
        a[p].pi(i+1);
 
    }
 
    for(int i=0;i<=n;i++) reverse(all(a[i]));
 
    DFS(1);
 
    reverse(all(ts));
 
    for(int i=0;i<k;i++){
 
        cin>>u[i]>>v[i];
 
    }
 
    for(int i=0;i<ts.size();i++) mpe[ts[i]]=i;
 
    int c;
 
    //for(int i=0;i<ts.size();i++) cout<<ts[i]<<" ";
    //cout<<endl;
 
    for(int i=0;i<k;i++){
 
        c=mpe[u[i]]+v[i]-1;
        //cout<<xi[u[i]]<<" ";
        if(v[i]<=xi[u[i]]) cout<<ts[c]<<endl;
        else cout<<-1<<endl;
 
    }
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/