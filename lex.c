#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
char str[80],nkey[50][80],var[50][80],op[50][3],con[50][10],key[50][10],fn[10];
 int v=0,c=0,o=0,k=0,i=0,j=0,id=0,t=0,n=0;
char opt[25]={'>','<','-',',','+','=','.','/','*','&','^','%','!','@','#','$','(',')','_'};
char kwd[30][10]={"do","while","for","void","if","elseif","char","float","double","switch","int","l ong","break","case","return"};
 FILE *fp;
clrscr();
 printf("ENTER THE INPUT FILE\n");
 scanf("%s",fn);
 fp=fopen(fn,"r");
 while(fgets(str,80,fp))
{
i=0;
while(str[i]!='\0')
{
  if(isalpha(str[i]))
 {
 for(j=0;;j++,i++)
 {
 if(isalnum(str[i]))
 var[v][j]=str[i];
 else
 break;
 }
 var[v][j]='\0';
 id=0;
 for(j=0;j<32;j++)
 if(strcmp(var[v],kwd[j])==0)
 {
  strcpy(key[k],var[v]);
  k++;
  id=1;
  break;
  }
  if(str[i]=='('&&id!=1)
  {
  strcpy(nkey[n],var[v]);
  n++;
  id=1;
  }
  if(id!=1)
  v++;
 }
else
if(isdigit(str[i]))
{
for(j=0;;j++,i++)
{
if(isdigit(str[i]))
con[c][j]=str[i];
 else
break;
 }
con[c][j]='\0';
 c++;
}
else
if(str[i]=='#')
{
break;
 }
else
if(str[i]=='"')
{
 i++;
for(j=0;str[j]!='"';j++,i++)
nkey[n][j]='\0';
n++;
i++;
}
else
{
if(str[i]==str[i+1]&&str[i]=='/')
break;
id=0;
for(j=0;j<7;j++)
if(str[i]==opt[j])
{
 op[0][0]=str[i];
 id=1;
break;
 }
 if(id==1)
{
if(str[i]==str[i+1]&&str[i]=='+'||str[i]=='^'||str[i]=='_'||str[i]=='|')
{
op[0][1]=str[i];
op[0][2]='\0';
i++;
}
else
op[0][1]='\0';
o++;
}
i++;
}
}
if(str[i]==EOF)
break;
}
 fclose(fp);
 fp=fopen("output.c","w");
 for(i=0;i<v;i++)
 if(strcmp(var[i],var[j])==0)
 var[j][o]=' ';
 fprintf(fp,"IDENTIFIERS");
 for(j=0;j<v;j++)
 {
 fprintf(fp,"%s\n",var[j]);
  t++;
 }
 fprintf(fp,"KEYWORDS");
 for(j=0;j<n;j++)
  fprintf(fp,"%s\n",nkey[j]);
 fprintf(fp,"CONSTANTS");
 for(j=0;j<c;j++)
 fprintf(fp,"%s\n",con[j]);
 getch();
 }
