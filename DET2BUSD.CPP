float det(float x[][80],int y)
{
int k,m,i,j,n,c,e,flag=0;
float a[80][80],d[80][80];
float p=1.0;
n=y;
m=n;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=x[i][j];
}
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
d[i][j]=a[i][j];
}
}

for(k=1;k<m;k++)
{
if(d[0][0]==0)
{
for(c=0;c<m;c++)
{
if(d[0][c]!=0){flag=1;break;}}
if(flag==0){return (0);}
else {for(e=0;e<m;e++)
       {
       d[e][0]+=d[e][c];
       }
      }

}
//cout<<"\n ZZ "<<d[0][0]<<" KK "<<n-2;   ////////////////////////////
p*=pow(d[0][0],(n-2));
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
 if(i==n-1||j==n-1){
		    a[i][j]=0;
		   }
 else{
      a[i][j]=d[0][0]*d[i+1][j+1]-d[i+1][0]*d[0][j+1];
     }
}
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
d[i][j]=a[i][j];
}
}
n--;
}

return(d[0][0]/p);
}