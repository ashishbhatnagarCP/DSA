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
//this method gives number of nodes. Hence we need to decrease the answer by 1.Since height gets calculated by edges.
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

//similar to diameter, but this is not optimized as the TC is O(n^2)
bool isBalanced(Node* root){
        if(root==NULL)
                return true; // if no nodes,means tree is balanced. the true here will be used as 1

        bool option1=isBalanced(root->left);
        bool option2=isBalanced(root->right);
        bool option3=abs(height(root->left)-height(root->right))<=1;//this is main check. but since we are recalculating height it is not efficient.

        return (option1 && option2 && option3);
}

pair<int,bool> isBalancedOptimizedRec(Node* root){
        if(root==NULL)
                return make_pair(0,true);

        pair<int,bool> left=isBalancedOptimizedRec(root->left);
        pair<int,bool> right=isBalancedOptimizedRec(root->right);

        if(left.second && right.second && abs(left.first-right.first)<=1)
                return make_pair(max(left.first,right.first)+1,true);
        else
                return make_pair(max(left.first,right.first)+1,false);
}


bool isBalancedOptimized(Node* root){
        pair<int,bool> ans= isBalancedOptimizedRec(root);
        return ans.second;
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

bool isSymmetric(Node* a,Node* b){
        //checks
        if(a==NULL && b==NULL)
                return true;
        else if(a!=NULL && b==NULL)
                return false;
        else if(a==NULL && b!=NULL)
                return false;
        else if(a->data!=b->data)
                return false;

        // below will only be called if left->data==right->data
        return isSymmetric(a->left,b->right) && isSymmetric(a->right,b->left);

}

bool isSymmetric(Node* node){
        if(node==NULL)
                return true;
        return isSymmetric(node->left,node->right);
}

bool hasPathSum(Node* root,int sum){
        if(root==NULL)
                return false;

        if(root->data==sum && root->left==NULL && root->right==NULL)
                return true;

        bool left=hasPathSum(root->left,sum-root->data);
        bool right=hasPathSum(root->right,sum-root->data);

        return left || right;

}

Node* lowestCommonAncestor(Node* root,Node* p, Node* q){

        if(root==NULL)
                return NULL;

        if(root==p || root==q)
                return root;

        else{
                Node* left=lowestCommonAncestor(root->left,p,q);
                Node* right=lowestCommonAncestor(root->right,p,q);

                if(left !=NULL && right!=NULL)
                        return root;
                else if(left==NULL)
                        return right;
                else
                        return left;
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
