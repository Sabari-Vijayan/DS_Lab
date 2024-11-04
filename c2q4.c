#include<stdio.h>
#include<string.h>
int top=-1,size,i=0;
char str[50],st[50],item;
void push(char item)
{
        if(top==size-1)
        printf("stack overflow\n");
        else
        {
                top++;
                st[top]=item;
        }
}

char pop()
{
        if(top==-1)
        {
          printf("stack underflow\n");
        }
        else
        {
                item=st[top];
                top--;
                return item;
        }
}


int palindrome()
{
	while(str[i]!='\0')
	{
		push(str[i]);
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=pop())
		{
		return -1;
		}
		else
		i++;
	}
	return 1;
}

int main()
{
	printf("enter a string\n");
	scanf("%s",str);
	size=strlen(str);
	int res=palindrome();
	if(res!=-1)
	printf("the given string is palindrome\n");
	else
	printf("the given string is not palindrome\n");
	return 0;
}

