#include<stdio.h>
main()
{FILE *fp;
int i=0,d;
char drive;
 system("color 1f");
 printf("WELCOME TO AARAAI!!!");
 printf("\nVersion 1.1");
 printf("\nDeveloper: S.K.SANJEEV KUMAR.\n\n\n\n");

 sanju:
 {
printf("\nHai...Please select the drive...\n");
drive=getch();
while(i<=1)
{char san[50],st[100],op[500],en='"',dir[500]="dir /b /s ",c[5]="C:\\",de[5]="D:\\",e[5]="E:\\",f[5]="F:\\",g[5]="G:\\",h[5]="H:\\",ai[5]="I:\\",open[500],app[20]=" >>sks.txt";
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
printf("\nWhat do you want to play:");}
gets(san);
strcat(st,san);

d=strlen(st);
st[d]='"';
st[d+1]='\0';
if(strcmp(san,"   ")==0)
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
system("del /s sks.txt");
i=1;}
}
  }


