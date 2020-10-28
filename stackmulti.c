#include<stdio.h>
int stack[13],top1,top2;
void push1(){
	if(top1==6)
		printf("stack full\n");
	else{
		printf("enter data  ");
		scanf("%d",&stack[++top1]);
	}
}
void push2(){
	if(top2==12)
		printf("stack full\n");
	else{
		if(top2==-1)
			top2=7;
		else
			top2++;
		printf("enter data  ");
		scanf("%d",&stack[top2]);
	}
}
void pop1(){
	if(top1==-1)
		printf("stack empty\n");
	else
		printf("no deleted = %d\n",stack[top1--]);
}
void pop2(){
	if(top2==-1)
		printf("stack empty\n");
	else{
		printf("no deleted = %d\n",stack[top2]);
		if(top2==6)
			top2=-1;
		else top2--;
	}
}
void traverse(){
	int p;
	printf("STACK 1 ELEMENTS\n");
	if(top1==-1)
		printf("stack empty\n");
	else{
		int p;
		p=top1;
		while(p!=-1){
			printf("%d\n",stack[p--]);
		}
	}
	printf("STACK 2 ELEMENTS\n");
	if(top2==-1)
		printf("stack empty\n");
	else{
		p=top2;
		while(p!=-1){
			printf("%d\n",stack[p]);
			if(p==7)
				p=-1;
			else p--;
	}
	}

}
int main(){
	int ch;
	top1=-1;
	top2=-1;
	char choice='y';
	while(choice=='y'){
		printf("1.PUSH IN FIRST STACK\n2.POP IN FIRST STACK\n3.PUSH IN SECOND STACK\n4.POP IN SECOND STACK\n5.TRAVERSE\nENTER YOUR CHOICE  ");
		scanf("%d",&ch);
		switch(ch){
			case 1:push1();
			break;
			case 2:pop1();
			break;
			case 3:push2();
			break;
			case 4:pop2();
			break;
			case 5:traverse();
		}
		printf("enter y to continue and n to exit  ");
		scanf(" %c",&choice);
	}
	return 0;
}