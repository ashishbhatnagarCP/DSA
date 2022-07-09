#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
Node *left;
Node *right;
int data;

Node(int data){
        left=NULL;
        right=NULL;
        this->data=data;
}

};

Node* buildTree(){
        cout<<"Enter value of data"<<endl;
        int data;
        cin>>data;
        if(data== -1)
                return NULL;

        Node* newNode = new Node(data);

        cout << "Enter the data for left child of " << data << endl;
        newNode->left = buildTree();

        cout << "Enter the data for right child of " << data << endl;
        newNode->right = buildTree();

        return newNode;

}

void preOrder(Node* root){
        if(root==NULL)
                return;

        cout<<root->data<<" ";

        preOrder(root->left);

        preOrder(root->right);

}

void postOrder(Node* root){
        if(root==NULL)
                return;

        postOrder(root->left);

        postOrder(root->right);

        cout<<root->data<<" ";

}

void inOrder(Node* root){
        if(root==NULL)
                return;

        inOrder(root->left);

        cout<<root->data<<" ";

        inOrder(root->right);

}

int height(Node* root){
        if(root==NULL)
                return 0;
        return 1+max(height(root->left),height(root->right));
}

int diameter(Node* root){
        if(root==NULL)
                return 0;

        int option1=diameter(root->left);// if any big diameter exist inside the left subtree itself.
        int option2=diameter(root->right);// if any big diameter exist inside the right subtree itself.
        int option3=1+height(root->left)+height(root->right);// the main diameter function, to calculate from node.

        return max(option1,max(option2,option3));
}

int getDiameter(Node* root){
        if(root==NULL)
                return 0;
        return diameter(root)-1;
}

void lvlOrder(Node* root){
        if(root==NULL)
                return;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
                Node* front=q.front();
                q.pop();
                if(front==NULL) {
                        cout<<endl;
                        if(!q.empty()) {
                                q.push(NULL);
                        }
                }else{
                        cout<<front->data<<endl;

                        if(front->left!=NULL)
                                q.push(front->left);
                        if(front->right!=NULL)
                                q.push(front->right);

                }
        }

}


int main(){
        //create tree
        Node* root = NULL;
        root = buildTree();
        preOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        cout<<height(root);
}



/*
   Sample inputs

   //1
   3 2 -1 -1 -1

   //2
   10 5 3 -1 -1 7 6 -1 -1 -1 11 -1 -1

 */
