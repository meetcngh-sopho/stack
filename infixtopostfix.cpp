#include<iostream>
#include<string>
using namespace std;
int top=-1;
char stack[100];
void push(char s)
{
	top++;
	if(top==100)
	{
		cout<<"Overflow";

	return;
	}
	stack[top]=s;
}
char pop()
{
	char a=stack[top];
	stack[top]=NULL;
	top--;
	return a;
}
int main()
{
	char a=')';
	char s1[100];
	cin>>s1;
	push('(');
	int length=0,i;
 for ( i = 0; s1[i] != '\0'; i++)
    {
        length++;
    }
	s1[i]=')';
	s1[i+1]='\0';
	length=0;
	for (int i = 0; s1[i] != '\0'; i++)
    {
        length++;
    }
	cout<<length<<endl;
	 i=0;
	 int j=0;
	char s[100];
	while(i!=length)
	{
			if(s1[i]>='a'&&s1[i]<='z')
			{
		cout<<s1[i]<<endl;
				s[j]=s1[i];
				i++;
				j++;
			}

			else if(s1[i]=='^')
			{
				if(stack[top]=='^')
					{
						a=pop();
						s[j]=a;
						j++;
						push(s1[i]);
						i++;
					}
					else
					{push(s1[i]);i++;}
			}
			else if(s1[i]=='+'||s1[i]=='-')
				{
					
					if(stack[top]=='*'||stack[top]=='/'||stack[top]=='^'||stack[top]=='+'||stack[top]=='-')
					{
						
						a=pop();
						s[j]=a;j++;
						if(stack[top]=='*'||stack[top]=='/'||stack[top]=='^'||stack[top]=='+'||stack[top]=='-')
						{a=pop();
						s[j]=a;j++;}
						else{push(s1[i]);
						i++;}
					}
					else
					{push(s1[i]);i++;}
					}
				else if(s1[i]=='*'||s1[i]=='/')
				{if(stack[top]=='*'||stack[top]=='/'||stack[top]=='^')
					{
						
						a=pop();
						s[j]=a;j++;
						
						push(s1[i]);
						i++;
						
					}
					else
					{push(s1[i]);i++;
					}
				}
			
				else if(s1[i]==')')
				{while(10)
					{
						a=pop();
						s[j]=a;j++;
						
						if(stack[top]=='(')
						{
							pop();
							i++;
							break;
						}
					
					}
					}
					else if(s1[i]=='(')
					{
					push(s1[i]);i++;		
					}
					else {//do nothing 
					}
			


				
			}
			s[21]='\0';
for (int i = 0; s[i] != '\0'; i++)
    {
cout<<s[i];
    }

	return 0;
	}
	
