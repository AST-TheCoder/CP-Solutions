#include<stdio.h>
int read() {
 char c=getchar(); int x=0,f=1;
 while (c<'0' || c>'9') {
  if (c=='-') f=-1;
  c=getchar();
 }
 while (c>='0' && c<='9') {
  x=x*10+c-'0';
  c=getchar();
 }
 return x*f;
}
int main()
{
 int n;
 n=read();
 int a[n+1],p[n+1],i,x,ans[n+1],k=0,c[n+1];
 for(i=1;i<=n;i++){
  a[i]=read();
  if(a[i]) ans[i]=n+1;
  else ans[i]=0;
  c[i]=-1;
 }
 for(i=2;i<=n;i++){
  x=read();
  p[i]=x;
  c[x]=i;
 }
 for(i=n;i>1;i--){
  if(c[i]==-1){
   ans[i]=1;
   k++;
  }
  x=p[i];
  if(a[x]){
   if(ans[x]>ans[i]) ans[x]=ans[i];
  }
  else ans[x]+=ans[i];
 }
 printf("%d\n",k+1-ans[1]);
 return 0;
}