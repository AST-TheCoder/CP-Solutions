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
#define     T               true
#define     F               false
#define     se              second
#define     sqr(x)          pow(x,2)
#define     all(v)          v.begin(),v.end()
#define     maxi            1000000000000014
#define     mini            -1000000000000014
#define     mod             1000000007
#define     an              1000000
#define     maps            map<string,int>
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              200005
 
ll s[nu],f,p[4];
 
mapi r,t;
 
int main() {
 
    ll k;
 
    cin>>k;
 
    ll a[k],i,j,d,l,x;
 
    ve b[k];
 
    for(i=0;i<k;i++){
 
        cin>>a[i];
 
        for(j=0;j<a[i];j++){
 
            cin>>x;
 
            b[i].pi(x);
 
            s[i]+=x;
 
        }
 
        if(!f){
 
                //cout<<endl;
 
            for(j=0;j<a[i];j++){
 
                if(f) break;
 
                d=s[i]-b[i][j];
 
                //cout<<d<<" ";
 
                if(t[d]!=i+1){
 
                    r[d]++;
 
                        //cout<<r[d]<<endl;
 
                    t[d]=i+1;
 
                }
 
                if(r[d]>1){
 
                    f=1;
 
                    p[0]=i+1;
 
                    p[1]=j+1;
 
                    for(l=1;i-l>=0;l++){
 
                        for(j=0;j<a[i-l];j++){
 
                            if(s[i-l]-b[i-l][j]==d){
 
                                p[2]=i-l+1;
 
                                p[3]=j+1;
 
                                break;
 
                            }
 
                            if(s[i-l]-b[i-l][j]==d) break;
 
                        }
 
                    }
 
                }
 
            }
 
        }
 
    }
 
    if(f){
 
        cout<<"YES"<<endl<<p[0]<<" "<<p[1]<<endl<<p[2]<<" "<<p[3]<<endl;
 
        return 0;
 
    }
 
    cout<<"NO";
 
    return 0;
}
/*****************  ALHAMDULILLAH  *****************/