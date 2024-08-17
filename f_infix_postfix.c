#include<stdio.h>
#define Max 100
char s[Max];
int top=-1;
char ch,p[100],temp[100];

int priority(char p)
{
        switch(p)
        {
                case '/':
                case '*':return 1;
                case '+':
                case '-':return 0;
                default:return 2;
        }
}
void push(char ch)
{
        if(top==Max-1)
                printf("stack overflow\n");
        else
                s[++top]=ch;
}
char pop(void)
{
        return(s[top--]);
}
void evaluate()
{
        char op1,op2;
        int i=0,d;
        while(temp[i])
        {
                if((temp[i]>=48 && temp[i]<=57))
                        push(temp[i]-48);
                else if(temp[i]=='+'||temp[i]=='-'||temp[i]=='*'||temp[i]=='/')
                {
                        op2=pop();
                        op1=pop();
                        switch(temp[i])
                        {
                                case '+':ch=op1+op2;
                                         break;
                                case '-':ch=op1-op2;
                                         break;
                                case '*':ch=op1*op2;
                                         break;
                                case '/':ch=op1/op2;
                                         break;
                        }
                        push(ch);
                }
                i++;
        }
	printf("result is: %d\n",s[top]);
}
void convert()
{
        int i=0,j=0;
        while(p[i])
        {
                if(p[i]=='('||p[i]=='{'||p[i]=='[')
                {
                        push(p[i]);
                  //      printf("%c\n",s[top]);
                }
                else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
                {
                        if(top==-1||s[top]=='('||s[top]=='{'||s[top]=='[')
                        {
                                push(p[i]);
                         //    printf("%c\n",s[top]);
                        }
                        else
                        {
                                if(top!=-1 && priority(p[i])<=priority(s[top]))
                                {
                                        temp[j++]=pop();
                                }
                                        push(p[i]);
                        }

                 }
                else if(p[i]==')')
                {

                   while((ch=pop())!='(')
                           temp[j++]=ch;
                }
                /*else if(p[i]=='}')
                {
                  while((ch=pop())!='{')
                          temp[j++]=ch;
                }
                else if(p[i]==']')
                {
                  while((ch=pop())!='[')
                          temp[j++]=ch;
                }*/
                else
                     temp[j++]=p[i];
                i++;
        }
        while(top!=-1)
                temp[j++]=pop();
        temp[j]='\0';
}
int main()
{
        int i=0;
        printf("enter expression\n");
        gets(p);
                convert();
        printf("postfix expression is:%s\n",temp);
        evaluate();
} 
