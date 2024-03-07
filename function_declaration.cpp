#include<iostream>
#include<fstream>
#include"header.hpp"


void my_strcpy(STRING &src,STRING &des){
des.ptr=new char[my_strlen(src)+1];
int i;
for(i=0;src.ptr[i];i++){
des.ptr[i]=src.ptr[i];
}
des.ptr[i]='\0';
}

void my_strncpy(STRING &src,STRING &des,int n){
int i;
des.ptr=new char[n+1];
for(i=0;i<n;i++)
des.ptr[i]=src.ptr[i];
des.ptr[i]='\0';
}

void my_strcat(STRING &src,STRING &des){
STRING temp;
int i,j;
temp.ptr=new char[my_strlen(des)+1];
my_strcpy(des,temp);
delete []des.ptr;
des.ptr=new char[my_strlen(src)+my_strlen(des)+1];
my_strcpy(temp,des);
for(i=0,j=my_strlen(des);src.ptr[i];i++,j++)
	des.ptr[j]=src.ptr[i];
des.ptr[j]='\0';
delete []temp.ptr;
}

int my_strlen(STRING s){
int c=0;
while(*(s.ptr)){
c++;
s.ptr++;
}
return c;
}

int my_strcmp(STRING &src1,STRING &src2){
int i;
for(i=0;src1.ptr[i];i++){
if(src1.ptr[i]!=src2.ptr[i])
	break;
}
return (src1.ptr[i]-src2.ptr[i]);
}

int my_strncmp(STRING &src1,STRING &src2,int n){
int i;
for(i=0;i<n;i++){
if(src1.ptr[i]!=src2.ptr[i])
return (src1.ptr[i]-src2.ptr[i]);
}
return 0;
}

char *my_strch(STRING &src,char ch){
int i;
while(src.ptr[i]){
if(src.ptr[i]==ch)
	return src.ptr+i;
i++;
}
return 0;
}

char *my_strrch(STRING &src,char ch){
int i;
for(i=my_strlen(src);i>=0;i--){
if(src.ptr[i]==ch)
	return src.ptr+i;
}
return 0;
}

void my_strupr(STRING &src){
int i;
for(i=0;src.ptr[i];i++){
	if(src.ptr[i]>='a'&&src.ptr[i]<='z')
		src.ptr[i]=src.ptr[i]-32;}
}

void my_strlwr(STRING &src){
int i;
for(i=0;src.ptr[i];i++){
	if(src.ptr[i]>='A'&&src.ptr[i]<='Z')
		src.ptr[i]=src.ptr[i]+32;
}
}

void my_strtoggle(STRING &src){
int i;
for(i=0;src.ptr[i];i++){
if(src.ptr[i]>='A'&& src.ptr[i]<='Z')
	src.ptr[i]=src.ptr[i]+32;
else if(src.ptr[i]>='a'&&src.ptr[i]<='z')
	src.ptr[i]=src.ptr[i]-32;
}
}

void my_strrev(STRING &src){
int i,j;
char p;
for(j=my_strlen(src)-1,i=0;i<j;i++,j--){
p=src.ptr[i];
src.ptr[i]=src.ptr[j];
src.ptr[j]=p;
}
}

/*
char *my_strstr(STRING &m_str,STRING &sub_str){
while(*(m_str.ptr)){
if(my_strcmp(sub_str,m_str)==0)
	return m_str.ptr;
m_str.ptr++;
}
//if(*(m_str.ptr)=='\0')
return 0;
}
*/

char *my_strstr(STRING &m_str,STRING &sub_str){
int j=0,i,k;
for(i=0;m_str.ptr[i];i++){
j=0;
if(m_str.ptr[i]==sub_str[j]){
for(j=1,k=i+1;sub_str.ptr[j];j++,k++)
{
if(m_str.ptr[k]!=sub_str.ptr[j])
break;
}
if(sub_str.ptr[j]=='\0')
return m_str.ptr+i;
}
}
return NULL;
}


istream& operator>>(istream& in,STRING& t){
int n;
ofstream fout;
fout.open("data",ios::out);
char s;
while((s=cin.get())!='\n'){
fout<<s;
}
fout.seekp(0,ios::end);
n=fout.tellp();
fout.close();
t.ptr=new char[n+2];
ifstream fin;
fin.open("data",ios::in);
fin.getline(t.ptr,n+2);
fin.close();
return in;
}


ostream& operator<<(ostream& out,STRING t){
out<<t.ptr<<endl;
return out;
}

bool operator<(STRING &t1,STRING &t2){
int k;
k=my_strcmp(t1,t2);
if(k<0)
return true;
else
return false;
}
bool operator>(STRING &t1,STRING &t2){
int k;
k=my_strcmp(t1,t2);
if(k>0)
return true;
else
return false;
}
bool operator>=(STRING &t1,STRING &t2){
int k=my_strcmp(t1,t2);
if(k>0){
	return true;}
else if(k==0){
	return true;}
else if(k<0){
	return false;}
	return 0;
}

bool operator<=(STRING &t1,STRING &t2){
int k=my_strcmp(t1,t2);
if(k<0){
	return true;}
else if(k==0){
	return true;}
else if(k>0){
	return false;}
	return 0;
}

bool operator==(STRING &t1,STRING &t2){
if(my_strcmp(t1,t2)==0)
	return true;
else 
	return false;
}

bool operator!=(STRING &t1,STRING &t2){
if(my_strcmp(t1,t2)!=0)
	return true;
else 
	return false;
}

STRING operator*(STRING &t,int n){
STRING temp;
temp.ptr=new char[(my_strlen(t.ptr)*n)+1];
for(int i=0;i<n;i++)
	my_strcat(temp,t);
return temp;
}

STRING operator+ (STRING &t1,STRING &t2){
STRING add;
add.ptr=new char[my_strlen(t1)+my_strlen(t2)+1];
my_strcpy(add,t1);
my_strcat(add,t2);
return add;
}
