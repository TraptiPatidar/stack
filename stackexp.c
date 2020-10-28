#include<stdio.h>
#include<string.h>
int top,stack[20];
void push(char x){
	if(top==20)
		printf("stack full\n");
	else{
		stack[++top]=x;
	}
}
char pop(){
	if(top==-1){
		printf("stack empty\n");
		return(0);
	}
	else return stack[top--];
}
int prec(char o){
	if(o=='/' || o=='*')
		return 5;
	else if(o=='+' || o=='-')
		return 3;
	else return 2;
}
void infix_post(){
	char infix[20],post[20];
	int temp;
	printf("Enter the Expression\n");
	scanf(" %s",infix);
	int l=strlen(infix);
	int i=0,pos=0;
	while(i!=l){
		switch(infix[i]){
			case '(':push(infix[i]);
			break;
			case ')':temp=pop();
			while(temp!='('){
				post[pos++]=temp;
				temp=pop();
			}
			break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			while(prec(stack[top])>=prec(infix[i])){
				temp=pop();
				post[pos++]=temp;
			}
			push(infix[i]);
			break;
			default :post[pos++]=infix[i];
			break;
		}
		i++;
	}
	while(top>=0){
		temp=pop();
		post[pos++]=temp;
	}
	post[pos++]='\0';
	printf("%s\n",post);
}
void infix_pre(){
	char infix[20],post[20];
	int temp;
	printf("Enter the Expression\n");
	scanf(" %s",infix);
	int l=strlen(infix);
	strrev(infix);
	int i=0,pos=0;
	while(i!=l){
		switch(infix[i]){
			case ')':push(infix[i]);
			break;
			case '(':temp=pop();
			while(temp!=')'){
				post[pos++]=temp;
				temp=pop();
			}
			break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			while(prec(stack[top])>=prec(infix[i])){
				temp=pop();
				post[pos++]=temp;
			}
			push(infix[i]);
			break;
			default :post[pos++]=infix[i];
			break;
		}
		i++;
	}
	while(top>=0){
		temp=pop();
		post[pos++]=temp;
	}
	post[pos++]='\0';
	strrev(post);
	printf("%s\n",post);
}

int main(){
	int ch;
	top=-1;
	char choice='y';
	while(choice=='y'){
		printf("1.INFIX TO POSTFIX\n2.INFIX TO PREFIX\nENTER YOUR CHOICE  ");
		scanf("%d",&ch);
		switch(ch){
			case 1:infix_post();
			break;
			case 2:infix_pre();
		}
		printf("enter y to continue and n to exit  ");
		scanf(" %c",&choice);
	}
	return 0;
}