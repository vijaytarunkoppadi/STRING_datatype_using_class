#include<iostream>
#include"header.hpp"

using namespace std;

int main(){
STRING s1("hello"),s2=s1,s3("hello world"),s4,s5;
char *c;
bool k;

cout<<s1[1]<<endl;
cout<<my_strlen(s1)<<endl;
cout<<my_strrch(s1,'l')<<endl;
cout<<my_strch(s1,'l')<<endl;
cout<<my_strcmp(s1,s2)<<endl;
cout<<my_strncmp(s1,s2,3)<<endl;
my_strupr(s1);
cout<<s1;
my_strlwr(s1);
cout<<s1;
//my_strtoggle(s1);
//cout<<s1;
//my_strrev(s1);
//cout<<s1;
//c=my_strstr(s3,s1);
//cout<<c<<endl;
k=(s1==s2);
cout<<k<<endl;
k=(s1!=s2);
cout<<k<<endl;
k=(s1>=s2);
cout<<k<<endl;
k=(s1<=s2);
cout<<k<<endl;
k=(s1<s2);
cout<<k<<endl;
k=(s1>s2);
cout<<k<<endl;

c=my_strstr(s3,s1);
cout<<c<<endl;
cout<<s3;
cout<<"enter the string"<<endl;
cin>>s4;
cout<<s4;
}
