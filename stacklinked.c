#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* top;
void push(){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data  ");
	scanf("%d",&p->data);
	if(top==NULL)
		p->next=NULL;
	else
		p->next=top;
	top=p;
}
void pop(){
	struct node *p;
	if(top==NULL)
		printf("stack empty\n");
	else{
		printf("no deleted=%d\n",top->data );
		p=top;
		top=top->next;
		free(p);
	}
}
void traverse(){
	struct node *p;
	p=top;
	while(p!=NULL){
		printf("%d\n",p->data );
		p=p->next;
	}
}
int main(){
	int ch;
	top=NULL;
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