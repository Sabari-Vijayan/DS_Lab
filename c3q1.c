#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char pf[50],ex[50],s[50];
int A[40],top= -1,size,top2= -1;
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

int operation(int a,int b,char c)
{
	int res;
	if(c=='+')
	res=a+b;
	else if(c=='-')
        res=(a-b);
	else if(c=='*')
        res=(a*b);
	else if(c=='/')
        res=(a/b);
	else if(c=='^')
        res= pow(a,b);
	return res;
}

void push2(int item)
{
                top2++;
                A[top2]=item;
}

int pop2()
{
	if(top2==-1)
        printf("stack underflow\n");
        else
        {
               int ret=A[top2];
		top2--;
		return ret;
        }
}

int evaluate(char e[])
{
	int i=0,o1,o2,res;
	char q[2];
	while(e[i]!='\0')
	{
		if(e[i]=='+' ||e[i]== '-' ||e[i]==  '*' ||e[i]==  '/' ||e[i]==  '^')
		{
			o2=pop2();
			o1=pop2();
			res=operation(o1,o2,e[i]);
			push2(res);
			i++;
		}
		else
		{
			q[0]=pf[i];
			q[1]='\0';
			o2=atoi(q);
			push2(o2);
			i++;
		}
	}
	res=pop2();
	return res;
}

int main()
{
	int i=0,k=0;
	printf("enter expression\n");
	scanf("%s",ex);
	size=strlen(ex);
	ex[size]='#';
	ex[size+1]='\0';
	size=strlen(ex);
	push('(');
	while(ex[i]!='#')
//	for(i=0;ex[i]!='#';i++)
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
	puts("postfix expression is");
	puts(pf);
	int c2=0,choice=0;
	printf("DO YOU WANT TO EVALUATE THE POSTFIX EXPRESSION\n\tpress 1 for Yes and any other for no\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("DO THE POSTFIX EXPRESSION CONTAINS ANY CHARACTERS OTHER THAN INTEGERS AND OPERATORS\n\t\tpress 1 for YES and any other for NO\n");
		scanf("%d",&c2);
		if(c2==1)
		{
			printf("enter the postfix expression you want to evaluate\nNOTE:THE EXPRESSION SHOULD CONTAIN INTEGERS AND OPREATORS ONLY\n");
			scanf("%s",pf);
			int rs=evaluate(pf);
			printf("result of the postfix expression is : %d\n",rs);
		}
		else
		{
			printf("result of the postfix expression is : %d\n",evaluate(pf));
		}
	}
	return 0;
}
