#include<stdio.h>
int stack[5],top;
void push(){
	if(top==4)
		printf("stack full\n");
	else{
		printf("enter data  ");
		scanf("%d",&stack[++top]);
	}
}
void pop(){
	if(top==-1)
		printf("stack empty\n");
	else
		printf("no deleted = %d\n",stack[top--]);
}
void traverse(){
	if(top==-1)
		printf("stack empty\n");
	else{
		int i=top;
		while(i!=-1){
			printf("%d\n",stack[i]);
			i--;
		}
	}
}
int main(){
	int ch;
	top=-1;
	char choice='y';
	while(choice=='y'){
		printf("1.PUSH\n2.POP\n3.TRAVERSE\nENTER YOUR CHOICE  ");
		scanf("%d",&ch);
		switch(ch){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:traverse();
		}
		printf("enter y to continue and n to exit  ");
		scanf(" %c",&choice);
	}
	return 0;
}