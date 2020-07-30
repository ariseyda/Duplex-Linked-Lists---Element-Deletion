#include<stdio.h>
#include<stdlib.h>

//Duplex Linked Lists - Element Deletion

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node* start=NULL;
struct node* q=NULL;

struct node* createNode(int data){
	
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	return newNode;
	
	
}
void deleteBegin(){
	
	
	if(start==NULL){
		printf("There is no node");
		return;
	}
	else if(start->next==NULL){
		
		free(start);
		start=NULL;
		return;
		
	}
	
	struct node* temp=start->next;
	free(start);
	temp->prev=NULL;
	start=temp;
	
	
	
	
	
}
void deleteBetween(int data){
	
	q=start;
	if(start==NULL){
		printf("There is no node");
		return;
	}
	if(start->next==NULL){
		
		free(start);
		start=NULL;
		return;
		
	}
	if(data==start->data){
		deleteBegin();
		return;
	}
	while(q->data!=data){
		q=q->next;
	}
	
	struct node* next=q->next;
	struct node* prev=q->prev;
	free(q);
	next->prev=prev;
	prev->next=next;
	
	
	
	
	
	
	
	
	
}
void deleteEnd(){
	
	q=start;
	if(start==NULL){
		printf("There is no node");
		return;
	}
	if(start->next==NULL){
		deleteBegin();
		
	}
	else{
		
		while(q->next!=NULL){
			q=q->next;
		}
		
		struct node* temp=q->prev;
		free(q);
		temp->next=NULL;
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
}
void addBegin(int data){
	
	struct node* addbegin=createNode(data);
	
	q=start;
	if(q==NULL){
		start=addbegin;
	}
	else{
		q->prev=addbegin;
		addbegin->next=q;
		addbegin->prev=NULL;
		start=addbegin;
	}
	
}
void addBetween(int addprev,int data){
	
	struct node* newnode=createNode(data);
	
	q=start;
	if(start==NULL){
		start=newnode;
	}
	else if(start->data==addprev){
		addBegin(data);
	}
	else{
		while(q->data!=addprev){
		q=q->next;
	  }
	    struct node* temp=q->prev;
	    temp->next=newnode;
	    newnode->prev=temp;
	    q->prev=newnode;
	    newnode->next=q;
	}
	
	
}
void addEnd(int data){
	
	struct node *addend=createNode(data);
	
	if(start==NULL){
		start=addend;
	}
	else{
		q=start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=addend;
		addend->prev=q;
		addend->next=NULL;
	}

	
}
void printNode(){
	q=start;
		while(q->next!=NULL){
			printf("%d=>",q->data);
			q=q->next;
		}
		printf("%d",q->data);
}
int main(){
	
	
	int n,data,data1;
	
	while(1){
		
		printf("\n1-AddEnd\n2-AddBegin\n3-AddBetween\n4-DeleteBegin\n5-DeleteEnd\n6-DeleteBetween\n");
		scanf("%d",&n);
		switch(n){
			
			case 1:
				printf("\nEnter the element you want to add:");
				scanf("%d",&data);
				addEnd(data);
				printNode();
				break;
			case 2:
			    printf("\nEnter the element you want to add:");
				scanf("%d",&data);
				addBegin(data);
				printNode();
				break;
			case 3:
			    printf("\nEnter the element you want to add:");
				scanf("%d",&data);	
				printf("\nEnter the node to be added in front of it:");
				scanf("%d",&data1);
				addBetween(data1,data);
				printNode();
				break;
			case 4:	
				deleteBegin();
				printNode();
				break;
			case 5:
			    deleteEnd();
				printNode();
				break;
			case 6:
				printf("\nEnter the element you want to delete:");
				scanf("%d",&data1);
			    deleteBetween(data1);
				printNode();
				break;		
		}
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
