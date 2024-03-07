using namespace std;

class STRING{
char *ptr;
public:
STRING(){
ptr=0;
}
STRING(const char *s){
int i;
for(i=0;s[i];i++);
ptr=new char[i+1];
i=0;
while(s[i]){
ptr[i]=s[i];
i++;
}
ptr[i]='\0';
}
STRING(STRING &temp){
int i;
for(i=0;temp.ptr[i];i++);
ptr=new char[i+1];
i=0;
while(temp.ptr[i]){
ptr[i]=temp.ptr[i];
i++;
}
ptr[i]='\0';
}

char&  operator[](int I){
return ptr[I];
}

friend STRING operator*(STRING &t,int n);
friend STRING operator+(STRING &t1,STRING &t2);

friend bool operator<(STRING &t1,STRING &t2);
friend bool operator>(STRING &t1,STRING &t2);
friend bool operator<=(STRING &t1,STRING &t2);
friend bool operator>=(STRING &t1,STRING &t2);
friend bool operator==(STRING &t1,STRING &t2);
friend bool operator!=(STRING &t1,STRING &t2);

friend istream& operator>>(istream&,STRING&);
friend ostream& operator<<(ostream&,STRING);

friend int my_strlen(STRING s);
friend void my_strcpy(STRING &src,STRING &des);
friend void my_strncpy(STRING &src,STRING &des,int n);
friend void my_strcat(STRING &src,STRING &des);
friend int  my_strcmp(STRING &src1,STRING &src2);
friend int  my_strncmp(STRING &src1,STRING &src2,int n);
friend char *my_strch(STRING  &src, char ch); 
friend char *my_strrch(STRING &src,char ch);
friend void  my_strupr(STRING &src);
friend void  my_strlwr(STRING &src);
friend void  my_strtoggle(STRING &src);
friend void  my_strrev(STRING &src);
friend char *my_strstr(STRING &m_str,STRING &sub_str);

};



