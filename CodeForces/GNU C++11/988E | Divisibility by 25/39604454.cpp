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
#define     cha              char
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
#define     mapi            map<int,int>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     nu              100005
 
ll a[10];
 
st s,d;
 
int main()
{
 
    cin>>s;
 
    ll l=s.length();
    ll i,j,p,q,r,t,k,x,y;
 
    for(i=0;i<l;i++){
 
        a[s[i]-'0']++;
 
    }
 
    if(a[5] && a[0]);
    else if(a[0]>=2);
    else if(a[7] && a[5]);
    else if(a[2] && a[5]);
    else{
        cout<<-1;
        return 0;
    }
 
    if(l==3 && a[0]==1 && a[5]==0){
 
        cout<<-1;
        return 0;
 
    }
 
    if(a[0]>=2){
 
        d="00";
 
        for(i=l-1,j=0,p=0;i>=0;i--){
 
            if(s[i]=='0' && j<2){
 
                j++;
                p+=(l-i-j);
 
            }
            else{
                d+=s[i];
            }
 
        }
 
    }
    else p=maxi;
 
    if(a[5] && a[0]){
 
        if(a[5]==1 && a[0]==l-1){
 
            if(l==2) q=0;
            else q=maxi;
 
        }
 
        else{
 
            d="05";
 
            for(i=l-1,q=0;i>=0;i--){
 
                if(s[i]=='0'){
 
                    q+=l-i-1;
                    break;
 
                }
 
            }
            for(i=l-1,j=0,k=0;i>=0;i--){
 
                if(s[i]=='5' && k==0){
 
                    if(i<=l-2){
                        q+=l-i-2;
                    }
 
                    k++;
                    x=i;
 
                }
 
                else if(s[i]=='0' && j==0){
 
                    j++;
                    y=i;
 
                }
 
                else{
 
                    d+=s[i];
 
                }
 
            }
 
            for(i=l-1;i>=0 && d[i]=='0';i--);
            q+=l-i-1;
            if(x>y && x!=l-1) q++;
 
        }
 
    }
    else q=maxi;
 
    if(a[2] && a[5]){
 
        if(a[2]==1 && a[5]==1 && a[0]==l-2 && l!=2) r=maxi;
        else{
 
            d="52";
 
            for(i=l-1,r=0;i>=0;i--){
 
                if(s[i]=='5'){
 
                    r+=l-i-1;
                    break;
 
                }
 
            }
            for(i=l-1,j=0,k=0;i>=0;i--){
 
                if(s[i]=='2' && k==0){
 
                    if(i<=l-2){
                        r+=l-i-2;
                    }
                    k++;
 
                    x=i;
 
                }
 
                else if(s[i]=='5' && j==0){
 
                    j++;
                    y=i;
 
                }
 
                else{
 
                    d+=s[i];
 
                }
 
            }
 
            for(i=l-1;i>=0 && d[i]=='0';i--);
            r+=l-i-1;
            if(x>y && x!=l-1) r++;
 
        }
 
    }
    else r=maxi;
 
    if(a[7] && a[5]){
 
        if(a[7]==1 && a[5]==1 && a[0]==l-2 && l!=2) t=maxi;
        else{
 
            d="57";
 
            for(i=l-1,t=0;i>=0;i--){
 
                if(s[i]=='5'){
 
                    t+=l-i-1;
                    break;
 
                }
 
            }
            for(i=l-1,j=0,k=0;i>=0;i--){
 
                if(s[i]=='7' && k==0){
 
                    if(i<=l-2){
                        t+=l-i-2;
                    }
                    k++;
 
                    x=i;
 
                }
 
                else if(s[i]=='5' && j==0){
 
                    j++;
                    y=i;
 
                }
 
                else{
 
                    d+=s[i];
 
                }
 
            }
 
            for(i=l-1;i>=0 && d[i]=='0';i--);
            t+=l-i-1;
            if(x>y && x!=l-1) t++;
 
        }
 
    }
    else t=maxi;
 
    //cout<<p<<" "<<q<<" "<<r<<" "<<t<<" ";
 
    cout<<(min(p,min(q,min(r,t))));
 
 return 0;
}
/*****************  ALHAMDULILLAH  *****************/