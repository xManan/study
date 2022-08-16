#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int val;
    int isLefty;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct Queue{
    Node* arr[1000];
    Node** head;
    Node** tail;
} Queue;

#define push_s(stack, node) *(stack++) = node
#define pop_s(stack) *(--stack)

#define push_q(queue, node) *((queue.tail)++) = node
#define pop_q(queue) *((queue.head)++)

Node* make_node(int x){
    Node* tmp   = (Node*)malloc(sizeof(Node));
    tmp->val = x;
    tmp->isLefty = 0;
    tmp->left   = NULL;
    tmp->right  = NULL;
    tmp->parent = NULL;
    return tmp;
}
void printNodeVal(Node* n){
    if(n == NULL) printf("NULL\n");
    else printf("%d\n", n->val);
}
void switch_child_parent(Node* child){
    if(child->parent == NULL) return;
    Node* tmp;
    if(child->isLefty == 1){
        tmp = child->parent->right;
    }
    else{
        tmp = child->parent->left;
    }
    child->parent->left = child->left;
    child->parent->right = child->right;
    if(child->isLefty == 1){
        child->left = child->parent; 
        child->right = tmp; 
    }
    else{
        child->right = child->parent;
        child->left = tmp; 
    }
    if(child->parent->left != NULL){
        child->parent->left->parent = child->parent;
    }
    if(child->parent->right != NULL){
        child->parent->right->parent = child->parent;
    }
    if(tmp != NULL){
        tmp->parent = child;
    }
    Node* tmp1 = child->parent;
    Node* tmp2 = child->parent->parent;
    child->parent->parent = child;
    child->parent = tmp2; 
    if(tmp2 != NULL){
        if(tmp1->isLefty == 1){
            tmp2->left = child;
        }
        else{
            tmp2->right = child;
        }
    }
    int tmp3 = child->isLefty;
    child->isLefty = tmp1->isLefty;
    tmp1->isLefty = tmp3;
}

Node* addNode(Node* root, Node* node){
    if(node == NULL || root == NULL) return root;
    Node* newRoot = root;
    Queue q;
    q.head = q.arr;
    q.tail = q.arr;
    push_q(q, root);
    while(q.head != q.tail){
        Node* curr = pop_q(q);
        if(curr->left == NULL){
            curr->left = node;
            node->isLefty = 1;
            node->parent = curr;
            while(node->parent != NULL && node->val > node->parent->val){
                if(node->parent->parent == NULL) newRoot = node;
                switch_child_parent(node);
            }
            return newRoot;
        }
        if(curr->right == NULL){
            curr->right = node;
            node->parent = curr;
            while(node->parent != NULL && node->val > node->parent->val){
                if(node->parent->parent == NULL) newRoot = node;
                switch_child_parent(node);
            }
            return newRoot;
        }
        push_q(q, curr->left);
        push_q(q, curr->right);
    }
    return newRoot;
}

void printTree(Node* root){
    if(root == NULL) return;
    Queue q;
    q.head = q.tail = q.arr;
    push_q(q, root);
    int index = 1;
    while(q.tail != q.head){
        Node* curr = pop_q(q);
        printf("%d ", curr->val);
        if(curr->left != NULL) push_q(q, curr->left);
        if(curr->right != NULL) push_q(q, curr->right);
    }
    printf("\n");
}

int main(){
    Node* root = make_node(5);
    root = addNode(root, make_node(4));
    root = addNode(root, make_node(9));
    root = addNode(root, make_node(3));
    root = addNode(root, make_node(7));
    root = addNode(root, make_node(1));
    printTree(root);
    return 0;
}
