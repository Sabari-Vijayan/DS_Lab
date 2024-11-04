#include<stdio.h>
#include<string.h>
char pf[50],ex[50],s[50];
int top= -1,size;
int income(char c)
{
        if(c=='+' ||c== '-')
          return 1;
        else if(c=='*' ||c== '/')
          return 3;
        else if(c=='^')
          return 6;
        else if(c=='(')
          return 7;
        else if(c==')')
        return 0;
}

int instack(char c)
{
        if(c=='+' ||c== '-')
          return 2;
        else if(c=='*' ||c== '/')
          return 4;
        else if(c=='^')
          return 5;
        else if(c=='(')
          return 0;
}

void push(char c)
{
        if(top==size-1)
        printf("stack overflow\n");
        else
        {
                top++;
                s[top]=c;
        }
}

char pop()
{
        if(top==-1)
        printf("stack underflow\n");
        else
        {
                char item=s[top];
                top--;
                return item;
        }
}

int main()
{
        int i=0,k=0;
        printf("enter expression\n");
        scanf("%s",ex);
        size=strlen(ex);
	int right=size-1;
	while(i<=right)
	{
		char temp=ex[i];
		ex[i]=ex[right];
		ex[right]=temp;
		i++;
		right--;
	}
	i=0;
	while(ex[i]!='\0')
	{
		if(ex[i]=='(')
		ex[i]=')';
		else if(ex[i]==')')
		ex[i]='(';
		i++;
	}
        size=strlen(ex);
        ex[size]='#';
        ex[size+1]='\0';
        size=strlen(ex);
        push('(');
       	i=0;
	while(ex[i]!='#')
	{
                if(ex[i]=='(')
                {
                        push(ex[i]);
                }
                else if(ex[i]==')')
                {
                        while(s[top]!='(')
                        {
                                pf[k]=pop();
                                k++;
                        }
                        pop();
                }
                else if(ex[i]=='+' ||ex[i]== '-' ||ex[i]==  '*' ||ex[i]==  '/' ||ex[i]==  '^')
                {
                  if(income(ex[i]) < instack(s[top]))
                  {
                        while(income(ex[i]) < instack(s[top]))
                        {
                                pf[k]=pop();
                                k++;
                        }
                        push(ex[i]);
                  }
                  else
                  {
                        push(ex[i]);
                  }
                }
                else
                {
                        pf[k]=ex[i];
                        k++;
                }
                i++;

        }
        while(top>=1)
        {
                pf[k]=pop();
                k++;
        }
        pf[k]='\0';
        right=strlen(pf)-1;
	i=0;
        while(i<=right)
        {
                char temp=pf[i];
                pf[i]=pf[right];
                pf[right]=temp;
                i++;
                right--;
        }
	printf("prefix expression is :\n%s\n",pf);
        return 0;
}
