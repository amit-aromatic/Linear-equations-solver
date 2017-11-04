//PROGRAM TO SOLVE LINEAR EQUATIONS IN MAX. OF 80 VARIABLES
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include"det2busd.cpp"
#include"graphics.cpp"
void main()
{
float cof[80][80],con[80],cal[80][80],sol[80],r,D,d;
int i,j,n,c,flag=1,h=0;//i,j for rows& columns;n=no.of variables;c=general counter;
// h used in homogenity
//cof=array of coefficients;con of constants;cal of calculating array,is numerator of crammer's rule;sol is solution set;
clrscr();
printf("                      LINEAR  EQUATIONS SOLVER  \n");
for(i=0;i<80;i++)
printf("Ä");
printf("Solves linear equayions of the type:\na1x+b1y+.....=p1\na2x+b2y+.....=p2\n..........\n......so on");
printf("\nEnter no. of variables:");
scanf("%d",&n);
//INPUT
for(i=0;i<n;i++)
{
printf("Equation %d:\n",i+1);
for(j=0;j<n+1;j++)
{ if(j==n){
	 printf("Enter constant of equation %d:",i+1);
	 scanf("%f",&r);
	}
else {
	 printf("Enter coefficient of variable %d:",j+1);
	 scanf("%f",&r);
     }
if(j==n){
	 con[i]=r;
	}
else {
      cof[i][j]=r;
     }
}
}

cout<<"\n\nThe entered system is...\n"
    <<"Eqn  ";

for(i=0;i<n;i++)
cout<<"Var"<<i+1<<"       ";

cout<<"constant\n";

for(i=0;i<n;i++)
{
printf("\n%d:",i+1);
for(j=0;j<n+1;j++)
{
 if(j!=n) printf("%10.3g",cof[i][j]);
 else     printf("%10.3g",con[i]);
}
}


//CALCULATION OF D
D=det(cof,n);
//CASE OF HOMOGENITY
for(c=0;c<n;c++)
{
if(con[c]==0){
	      h++; //increment h if constant of cth eqn. is 0
	     }
}
if(h==n){//if h==no. of eqns. , then eqns. are homogeneous.So check further..
	  printf("\nThe equations are homogeneous.");
	   if(D==0)
	   printf("\nThe system has infinite solutions.");
	   else printf("\nThe solution is trivial.");
	   goto end;
	   }
//CASE OF D=0 (non homogenity)
if(D==0){
	    for(c=0;c<n;c++)
	     {
	       for(i=0;i<n;i++)
		{
		  for(j=0;j<n;j++)
		     {
		    if(j==c){
		    cal[i][j]=con[i];
			    }
		      else  {
			   cal[i][j]=cof[i][j];
			    }
		     }
		}
		 d=det(cal,n);
		 sol[c]=d;//ie. DO NOT DIVIDE BY D(=0).
	     }
		 for(c=0;c<n;c++){
			  if(sol[c]!=0){flag=0;break;}}
			//FLAG BECOMES 0 IN CASE OF INCONSISTENCY
			 (flag==1)?printf("\nThe system has infinite solutions"): printf("\nThe system is inconsistent");
			 goto end;
      }

//CASE OF D!=0(non homogenity)
for(c=0;c<n;c++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(j==c){
	cal[i][j]=con[i];
	}
else  {
       cal[i][j]=cof[i][j];
      }
}
}
d=det(cal,n);
sol[c]=d/D;
}

//OUTPUT

printf("\n\nThe solution is:\n");
for(i=0;i<n;i++)
{
printf("\nvar %d= %-8g",i+1,sol[i]);
}
//LABEL end used FOR TERMINATION IN CASE of HOMOGENITY OR D IS EQUAL TO 0 OTHERWISE
end:
cout<<"\n\nPress any key to exit...";
getch();
cbab();
}