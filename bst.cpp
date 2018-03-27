#include<iostream>
using namespace std;

struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;

};



struct bstnode* getnewnode(int data){
	bstnode* newNode=new bstnode();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
}

struct bstnode* insert(bstnode* root,int data){
	if (root=NULL) {root=getnewnode(data);}
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);

	}
	return root;
}



int main(){
	bstnode* root=NULL;
	
root=insert(root,15);
root=insert(root,20);
root=insert(root,45);
root=insert(root,25);
root=insert(root,2);
root=insert(root,1);


}