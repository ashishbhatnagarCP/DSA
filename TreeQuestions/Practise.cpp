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

//easy
vector<int> levelOrderTraversal(Node* root){
        vector<int> ans;
        if(root==NULL)
                return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
                Node* front=q.front();
                q.pop();
                ans.push_back(front->data);
                if(front->left!=NULL)
                        q.push(front->left);
                if(front->right!=NULL)
                        q.push(front->right);
        }
        return ans;
}

vector<int> leftViewOfTree(Node* root){
        vector<int> ans;
        if(root==NULL)
          return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int count=q.size();
            for(int i=0;i<count;i++){
              Node* front=q.front();
              q.pop();
              if(i==0)
                ans.push_back(front->data);
              if(front->left!=NULL)
                q.push(front->left);
              if(front->right!=NULL)
                q.push(front->right);
            }
        }
        return ans;
}

vector<int> rightViewOfTree(Node* root){
        vector<int> ans;
        if(root==NULL)
          return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int count=q.size();
            for(int i=0;i<count;i++){
              Node* front=q.front();
              q.pop();
              if(i==count-1)//this is the main check
                ans.push_back(front->data);
              if(front->left!=NULL)
                q.push(front->left);
              if(front->right!=NULL)
                q.push(front->right);
            }
        }
        return ans;
}


int main(){
        //create tree
        Node* root = NULL;
        root = buildTree();
        preOrder(root);
}

//2
//10 5 3 -1 -1 7 6 -1 -1 -1 11 -1 -1
