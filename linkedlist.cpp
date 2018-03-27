#include<iostream>

using namespace std;
struct node{
	int data;
	node *next;
};
node *head;
void insert(int x){
	node *temp=new node;
	temp->data=x;
	temp->next=head;
	head=temp;


	}
	
	


}



