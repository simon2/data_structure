#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
  int value;
  Node *left, *right;
};

Node* createNode(int value);
Node* insert(Node* root, int x);
Node* delete(Node* root, int x);
void travel(Node* root);
Node* search(Node* root, int data);
Node* findmin(Node* root);

int main(){
  int firstV;
  printf("Please input the value for the first node:");
  scanf("%ld",&firstV);
  Node* root = createNode(firstV);
  insert(root,5);
  travel(root);
  insert(root,10);
  travel(root);
  insert(root,15);
  travel(root);
  root = delete(root,15);
  travel(root);
  root = delete(root,1);
  travel(root);
  printf("%ld\n",search(root,10)->value);
  return 0;
}

Node* createNode(int value){
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* root, int x){
  int i;
  if(root == NULL){
    Node* newNode = createNode(x);
    root = newNode;
  }else if(x < root->value){
    root->left = insert(root->left,x);
  }else{
    root->right = insert(root->right,x);
  }
  return root;
}

Node* delete(Node* root, int x){
  if(root == NULL){
    return root;
  }else if(x < root->value){
    root->left = delete(root->left,x);
  }else if(x > root->value){
    root->right = delete(root->right,x);
  }else{
    if(root->left == NULL && root->right == NULL){
      free(root);
      root = NULL;
    }else if(root->left == NULL){
      Node* temp = root;
      root = root->right;
      free(temp);
    }else if(root->right == NULL){
      Node* temp = root;
      root = root->left;
      free(temp);
    }else{
      Node* temp = findmin(root->right);
      root->value = temp->value;
      root->right = delete(root->right,temp->value);
    }
  }
  return root;
}

void travel(Node* root){
  if(root){
    printf("%d ",root->value);
    travel(root->left);
    travel(root->right);
  }
}

Node* search(Node* root, int x){
  if(root == NULL){
    return NULL;
  }else if(x<root->value){
    return search(root->left,x);
  }else if(x>root->value){
    return search(root->right,x);
  }else{
    return root;
  }
}

Node* findmin(Node* root){
  if(root == NULL){
    return NULL;
  }else if(root -> left){
    return findmin(root->left);
  }else{
    return root;
  }
}
