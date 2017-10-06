#include<iostream>
#include<string>
using namespace std;
int top=-1;
char a[100];
void push(char s)
{
top++;
a[top]=s;
if(top==100)
{
cout<<"Overflow ";
return ;}
}
void pop()
{
a[top]=NULL;
--top;
}
int main()
{
string s1;
cin>>s1;
int i=0;
while(i!=s1.length())
{
if(s1[i]=='('||s1[i]=='{'||s1[i]=='[')
push(s1[i]);
else if(s1[i]==')'||s1[i]=='}'||s1[i]==']')
{
if(a[top]=='('&&s1[i]==')')
pop();
else if(a[top]=='{'&&s1[i]=='}')
pop();
else if(a[top]=='['&&s1[i]==']')
pop();
else
{
cout<<"delemiter mismatch";
return -1;
}
}
else {//do nothingh
}
if(top==-1)
{cout<<"delemiter doesnot match\n\n\nHence no error occur";
return 0;}

i++;
}
if(top>=0)
	cout<<"delemiter mismatch\n\n\n";
return 0;
}