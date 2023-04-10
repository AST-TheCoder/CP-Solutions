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
#define     cha             char
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
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
 
ll eq(ll x1,ll y1,ll x2,ll y2,ll x,ll y)
{
 
    if(((y-y1)*(x1-x2))-((x-x1)*(y1-y2))>0) return 1;
 
    else if(((y-y1)*(x1-x2))-((x-x1)*(y1-y2))<0) return -1;
 
    else return 0;
 
}
 
ll le(ll x1,ll y1,ll x2,ll y2)
{
 
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
 
}
 
pairl ip(ll x1,ll y1,ll x2,ll y2,ll p1,ll q1,ll p2,ll q2)
{
 
    ll x,y;
 
    x=((-(x1*y2-y1*x2)*(p1-p2)+(p1*q2-q1*p2)*(x1-x2))/(((y1-y2)*(p1-p2))-(q1-q2)*(x1-x2)));
 
    y=((x*(q1-q2)+(p1*q2-q1*p2))/(p1-p2));
 
    return mp(x,y);
 
}
 
int main()
{
 
    ll x[4],y[4],p[4],q[4],ck1,ck2,i,j,l1,l2,lf,o=0,z=0;
 
    pairl r;
 
    ve c;
 
    for(i=0;i<4;i++) cin>>x[i]>>y[i];
    for(i=0;i<4;i++) cin>>p[i]>>q[i];
 
    for(i=0;i<4;i++){
 
        for(j=0;j<4;j++){
 
            ck1=eq(x[i%4],y[i%4],x[(i+1)%4],y[(i+1)%4],p[j%4],q[j%4]);
 
            lf=le(x[i%4],y[i%4],x[(i+1)%4],y[(i+1)%4]);
 
            ck2=eq(x[i%4],y[i%4],x[(i+1)%4],y[(i+1)%4],p[(j+1)%4],q[(j+1)%4]);
 
 
            //cout<<i<<" "<<j<<" "<<ck1<<" "<<ck2<<endl;
 
            if(ck1==1 || ck2==1) o++;
            if(ck1==0 || ck2==0) z++;
 
            if(ck1!=ck2){
 
                c.pi(ck1);
                c.pi(ck2);
 
                r=ip(x[i%4],y[i%4],x[(i+1)%4],y[(i+1)%4],p[j%4],q[j%4],p[(j+1)%4],q[(j+1)%4]);
 
                l1=le(x[i%4],y[i%4],r.fr,r.se);
                l2=le(x[(i+1)%4],y[(i+1)%4],r.fr,r.se);
 
                //cout<<r.fr<<" "<<r.se<<endl;
 
                if(l1+l2==lf){
 
                    cout<<"YES";
                    return 0;
 
                }
 
            }
 
        }
 
    }
 
    if((c.size()==0 && (o==0 || o==32) && !z) || (c.size()==16 && (o==8 || o==24) && !z)){
        cout<<"YES";
        return 0;
    }
 
    cout<<"NO";
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/