#include<stdio.h>
main()
{FILE *fp,*sk;
unsigned long int key;
int i=0,d,m,j=0,k=0;
char drive;
system("del /s sks.txt");
system("cls");
 system("color 1f");
 printf("WELCOME TO AARAAI!!!");
 printf("\nVersion 1.4");
 printf("\nDeveloper: S.K.SANJEEV KUMAR.\n\n\n\n");
 sk=fopen("C:\\Users\\Default\\AppData\\Roaming\\araiiek.dat","r");
 if(sk==NULL)
 {
   printf("Hai....Please Enter the Key:");
   scanf("%Id",&key);
   key=1030908;
   if(key==1030908)
   {sk=fopen("C:\\Users\\Default\\AppData\\Roaming\\araiiek.dat","w");
     fprintf(sk,"key");
     fclose(sk);  
     system("cls");
      printf("WELCOME TO AARAAI!!!");
 printf("\nVersion 1.4");
 printf("\nDeveloper: S.K.SANJEEV KUMAR.\n\n\n\n");
   }
   else
   {
     printf("Sorry...not a valid key");
     k=1;
     system("cls");
   }
 }

 sanju:
 {
   
if(k==0)
{
printf("\nHai...Please select the drive...\n");
drive=getch();
while(i<=1)
{
char san[50],st[100],op[500],en='"',dir[500]="dir /b /s ",c[5]="C:\\",de[5]="D:\\",e[5]="E:\\",f[5]="F:\\",g[5]="G:\\",h[5]="H:\\",ai[5]="I:\\",open[500],app[20]=" >>sks.txt";
if(i==1)
{
 printf("Next..\n");
} 
if(drive=='c'||drive=='C')
{
  strcat(dir,c);
}

else if(drive=='d'||drive=='D')
{
  strcat(dir,de);
}
else if(drive=='e'||drive=='E')
{
  strcat(dir,e);
}
else if(drive=='f'||drive=='F')
{
  strcat(dir,f);
}
else if(drive=='g'||drive=='G')
{
  strcat(dir,g);
}
else if(drive=='h'||drive=='H')
{
  strcat(dir,h);
}
else if(drive=='i'||drive=='I')
{
  strcat(dir,ai);
}
else
{
  printf("invalid folder\n");
  i=0;
  goto sanju;
}
st[0]='"';
st[1]='\0';
if(i==0)
{
printf("\nWhat do you want to open:");
}
gets(san);
m=strlen(san);
for(j=0;j<m;j++)
{
  if(san[j]==' ')
  {
    san[j]='*';
  }
}
strcat(st,san);
d=strlen(st);
st[d]='*';
st[d+1]='"';
st[d+2]='\0';
if(strcmp(san,"***")==0)
{ printf("Thank you For using AARAAI");
  break;}
else if(strcmp(san,"```")==0)
{ i=0;
  goto sanju;
}
strcat(dir,st);
strcat(dir,app);
system(dir);
fp=fopen("sks.txt","r");
op[0]='"';
op[1]='\0';
fgets(open,500,fp);
strcat(op,open);
op[strlen(op)-1]='"';
system(op);
fclose(fp);
system("del sks.txt");
i=1;		
			}
		}
 	}
}
