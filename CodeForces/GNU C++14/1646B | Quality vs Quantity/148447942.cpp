#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    long long int t;
    scanf("%lli",&t);
    while(t--){
    int a[200005];
    long long int n,k,x,y,flag;
    scanf("%lli",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lli",&a[i]);
    }
    sort(a,a+n);
    x=a[0];
    y=0;
    flag=0;
    for(int i=1,j=n-1;i<j;i++,j--)
 
    {
        x+=a[i];
        y+=a[j];
        if(x<y)
        {
            flag=1;
            break;
        }
    }
    if(flag==1) printf("YES\n");
    else printf("NO\n");
    }
    return 0;
}