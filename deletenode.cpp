#include<isotream>
using namespace std;

struct bstnode* delete(struct bstnode* root,int key){

	if (root=NULL) return root;
	else if (key<root->data){
		root->left=delete(root->left,key);
	}
	else if(key>root->data){root->right=delete(root->right,key); }

	else{
		if(root->left==NULL){struct bstnode*temp=root->right;
			free(root);
			return temp;}
		else if(root->right==NULL){struct bstnode*temp=root->left; free(root);return temp;}

		struct bstnode* temp=minvalue(root->right);

		root->data=temp->data;

		root->right=delete(root->right,temp->key)


	}

	return root;
}