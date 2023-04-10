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
int c[an],f,in[an];
 
void DFS(int source)
{
 
    c[source]++;
 
    for(int i=0;i<a[source].size();i++){
 
        if(c[a[source][i]]==0){
 
            DFS(a[source][i]);
 
        }
 
    }
 
    ts.pi(source);
 
    return;
 
}
 
int main()
{
 
    int n,i,j;
 
    st s,r;
 
    cin>>n;
 
    for(i=0;i<n;i++){
 
        cin>>s;
 
        if(i!=0){
 
            for(j=0;j<min(s.length(),r.length());j++){
 
                if(s[j]!=r[j]){
 
                    a[r[j]].pi(s[j]);
 
                    in[s[j]]++;
 
                    break;
 
                }
 
            }
 
            if(j==min(s.length(),r.length()) && r.length()>s.length()){
 
                f=1;
 
            }
 
        }
 
        r=s;
 
    }
 
    for(i='a';i<='z' && !f;i++){
 
        if(c[i]==0 && in[i]==0){
 
            DFS(i);
 
        }
 
    }
 
    reverse(all(ts));
 
    if(ts.size()!=26) f=1;
 
    char x;
 
    if(f){
 
        cout<<"Impossible";
 
        return 0;
 
    }
 
    for(i=0;i<26;i++){
 
        x=ts[i];
 
        cout<<x;
 
    }
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/