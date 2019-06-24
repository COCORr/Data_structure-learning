//
//  main.cpp
//  7
//
//  Created by Darnell on 2018/11/12.
//  Copyright © 2018年 Darnell. All rights reserved.
//
//  树的类实现


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode{
    friend class BinaryTree<T>;
private:
    T element;
    BinaryTreeNode<T> * leftchild;
    BinaryTreeNode<T> * rightchild;
public:
    BinaryTreeNode(){
        element=0;
        leftchild=NULL;
        rightchild=NULL;
    }
    BinaryTreeNode(const T& ele){
        element=ele;
        leftchild=NULL;
        rightchild=NULL;
    }
    BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r){
        element=ele;
        leftchild=l;
        rightchild=r;
    }
    BinaryTreeNode<T> * getLeftChild() const{
        return leftchild;
    }
    BinaryTreeNode<T> * getRightChild() const{
        return rightchild;
    }
    void setLeftChild(BinaryTreeNode<T> * l){
        leftchild=l;
    }
    void setRightChild(BinaryTreeNode<T> * r){
        rightchild=r;
    }
    T getValue() const{
        return element;
    }
    void setValue(const T& val){
        element=val;
    }
    bool isLeaf() const{
        if (leftchild==NULL&&rightchild==NULL) {
            return true;
        }
        return false;
    }
};

template<class T>
class BinaryTree{
private:
    BinaryTreeNode<T> * root;
public:
    BinaryTree(){
        root=NULL;
    }
    BinaryTree(BinaryTreeNode<T> * node){
        root=node;
    }
    ~BinaryTree(){
    }
    bool isEmpty(){
        if (root==NULL) {
            return true;
        }
        return false;
    }
    BinaryTreeNode<T> getRoot() const{
        return root;
    }
    void breadthFirstOrder(BinaryTreeNode<T> * root){
        queue<BinaryTreeNode<T> *>nodeQueue;
        BinaryTreeNode<T> * pointer = root;
        if (pointer) {
            nodeQueue.push(pointer);
        }
        while (!nodeQueue.empty()) {
            pointer=nodeQueue.front();
            //对pointer 操作
            cout<<pointer->element<<" ";
            nodeQueue.pop();
            if (pointer->getLeftChild()) {
                nodeQueue.push(pointer->getLeftChild());
            }
            if (pointer->getRightChild()) {
                nodeQueue.push(pointer->getRightChild());
            }
        }
    }
    void preOrder(BinaryTreeNode<T> * root){
        
        
//        if (root!=NULL) {
//            //对结点操作
//            preOrder(root->leftchild);
//            preOrder(root->rightchild);
//        }
        
        stack<BinaryTreeNode<T> * > nodeStack;
        BinaryTreeNode<T> * pointer =root;
        
        while (!nodeStack.empty()||pointer) {
            if (pointer) {
                //对pointer操作
                cout<<pointer->element<<" ";
                if (pointer->rightchild!=NULL) {
                    nodeStack.push(pointer->rightchild);
                }
                pointer=pointer->leftchild;
            }else{
                pointer=nodeStack.top();
                nodeStack.pop();
            }
        }
        
        
    }
    
    void inOrder(BinaryTreeNode<T> * root){
//        if (root!=NULL) {
//            preOrder(root->leftchild);
//            //对结点操作
//            preOrder(root->rightchild);
//        }
    
    
    
        stack<BinaryTreeNode<T> * > nodeStack;
        BinaryTreeNode<T> * pointer =root;
        
        while (!nodeStack.empty()||pointer) {
            if (pointer) {
                nodeStack.push(pointer);
                pointer=pointer->leftchild;
            }else{
                pointer=nodeStack.top();
                //对pointer操作
                cout<<pointer->element<<" ";
                pointer=pointer->rightchild;
                nodeStack.pop();
            }
        }
    }
    void postOrder(BinaryTreeNode<T> * root){
//        if (root!=NULL) {
//            postOrder(root->leftchild);
//            postOrder(root->rightchild);
//            //对结点进行操作
//        }
        
        stack<BinaryTreeNode<T> *> nodeStack;
        BinaryTreeNode<T> * pointer=root;
        BinaryTreeNode<T> * pre=root;
        
        while (pointer) {
            for (; pointer->leftchild!=NULL; pointer=pointer->leftchild) {
                nodeStack.push(pointer);
            }
            while (pointer!=NULL && (pointer->rightchild==NULL||pointer->rightchild==pre)) {
                //对节点操作
                cout<<pointer->element<<" ";
                pre=pointer;
                if (nodeStack.empty()) {
                    return;
                }
                pointer=nodeStack.top();
                nodeStack.pop();
            }
            nodeStack.push(pointer);
            pointer=pointer->rightchild;
        }
    }
    int Nodenumber_0(BinaryTreeNode<T> * pointer){
        int i=0;
        if (pointer) {
            if (pointer->leftchild==NULL && pointer->rightchild==NULL) {
                i=1;
            }else{
                i=Nodenumber_0(pointer->leftchild)+Nodenumber_0(pointer->rightchild);
            }
        }
        return i;
    }
    int Nodenumber_1(BinaryTreeNode<T> * pointer){
        int i=0;
        if (pointer) {
            if ((pointer->leftchild==NULL&&pointer->rightchild!=NULL)||(pointer->leftchild!=NULL&&pointer->rightchild==NULL)) {
                i=1+Nodenumber_1(pointer->leftchild)+Nodenumber_1(pointer->rightchild);
            }else{
                i=Nodenumber_1(pointer->leftchild)+Nodenumber_1(pointer->rightchild);
            }
        }
        return i;
    }
    int Nodenumber_2(BinaryTreeNode<T> * pointer){
        int i=0;
        if (pointer) {
            if (pointer->leftchild!=NULL&&pointer->rightchild!=NULL) {
                i=1+Nodenumber_2(pointer->leftchild)+Nodenumber_2(pointer->rightchild);
            }else{
                i=Nodenumber_2(pointer->leftchild)+Nodenumber_2(pointer->rightchild);
            }
        }
        return i;
    }
    bool IsCompleteTree(BinaryTreeNode<T> * pointer){
        if (!pointer) {
            return false;
        }
        queue<BinaryTreeNode<T> *> queuenode;
        queuenode.push(pointer);
        while (pointer!=NULL) {         //全部压入，null也压入
            queuenode.pop();
            queuenode.push(pointer->leftchild);
            queuenode.push(pointer->rightchild);
            pointer=queuenode.front();
        }
        
        queuenode.pop(); //弹出一个null
        
        while(!queuenode.empty()){
            if (queuenode.front()!=NULL) {
                return false;
            }
            queuenode.pop();
        }
        return true;
    }
    int getHeight(BinaryTreeNode<T> * pointer){
        if (pointer==NULL) {
            return 0;
        }else{
            int m=getHeight(pointer->leftchild);
            int n=getHeight(pointer->rightchild);
            return (m>n)?(m+1):(n+1);
        }
    }
    int count[100];
    int maxWidth=0;
    int getWidth(BinaryTreeNode<T> * pointer,int k=0){
//        if (pointer==NULL) {
//            return 0;
//        }
//        int maxWidth=0;
//        BinaryTreeNode<T> * temp;
//        queue<BinaryTreeNode<T> *> queuenode;
//        queuenode.push(pointer);
//        while (1) {
//            int len = queuenode.size();
//            if (len==0) {
//                break;
//            }
//            while (len>0) {
//                temp=queuenode.front();
//                queuenode.pop();
//                if (temp->leftchild!=NULL) {
//                    queuenode.push(temp->leftchild);
//                }
//                if (temp->rightchild!=NULL) {
//                    queuenode.push(temp->rightchild);
//                }
//            }
//            maxWidth= maxWidth>queuenode.size()? maxWidth:queuenode.size();
//        }
//        return maxWidth;
        if (pointer==NULL) {
            return 0;
        }
        count[k]++;
        if (maxWidth<count[k]) {
            maxWidth=count[k];
        }
        getWidth(pointer->leftchild,k+1);
        getWidth(pointer->rightchild,k+1);
        
    }
    
    T getMax(BinaryTreeNode<T> * pointer){
//        T max=0;
//        queue<BinaryTreeNode<T> *>nodeQueue;
//        if (pointer) {
//            nodeQueue.push(pointer);
//        }
//        while (!nodeQueue.empty()) {
//            pointer=nodeQueue.front();
//            //对pointer 操作
//            if (max<pointer->element) {
//                max=pointer->element;
//            }
//            cout<<pointer->element<<" ";
//            nodeQueue.pop();
//            if (pointer->getLeftChild()) {
//                nodeQueue.push(pointer->getLeftChild());
//            }
//            if (pointer->getRightChild()) {   ·
//                nodeQueue.push(pointer->getRightChild());
//            }
//        }
        if (pointer->leftchild==NULL&&pointer->rightchild==NULL) {
            return  pointer->element;
        }else if(pointer->leftchild!=NULL&&pointer->rightchild==NULL){
            return pointer->element>getMax(pointer->leftchild)?pointer->element:getMax(pointer->leftchild);
        }else if(pointer->leftchild==NULL&&pointer->rightchild!=NULL){
            return pointer->element>getMax(pointer->rightchild)?pointer->element:getMax(pointer->rightchild);
        }else{
            return pointer->element>(getMax(pointer->leftchild)>getMax(pointer->rightchild)?
                                     getMax(pointer->leftchild):getMax(pointer->rightchild))?pointer->element:(getMax(pointer->leftchild)>getMax(pointer->rightchild)?
                                                                                                               getMax(pointer->leftchild):getMax(pointer->rightchild));
        }
    }
    void exchangeTheLeftandRight(BinaryTreeNode<T> * pointer){
//        queue<BinaryTreeNode<T> *>nodeQueue;
//        BinaryTreeNode<T> * temp;
//        if (pointer) {
//            nodeQueue.push(pointer);
//        }
//        while (!nodeQueue.empty()) {
//            pointer=nodeQueue.front();
//            //对pointer 操作
//            //cout<<pointer->element<<" ";
//            nodeQueue.pop();
//            temp=pointer->leftchild;
//            pointer->leftchil=pointer->rightchild;
//            pointer->rightchild=temp;
//
//            if (pointer->getLeftChild()) {
//                nodeQueue.push(pointer->getLeftChild());
//            }
//            if (pointer->getRightChild()) {
//                nodeQueue.push(pointer->getRightChild());
//            }
//        }
        BinaryTreeNode<T> * temp;
        if (!pointer) {
            return;
        }
        temp=pointer->leftchild;
        pointer->leftchild=pointer->rightchild;
        pointer->rightchild=temp;
        if (pointer->leftchild) {
            exchangeTheLeftandRight(pointer->leftchild);
        }
        if (pointer->rightchild) {
            exchangeTheLeftandRight(pointer->rightchild);
        }
    }
        void deleteleave(BinaryTreeNode<T> * pointer){
            if (!pointer) {
                return;
            }
            if (pointer->leftchild==NULL&&pointer->rightchild==NULL) {
                delete pointer;
            }else{
                deleteleave(pointer->leftchild);
                deleteleave(pointer->rightchild);
            }
    }
    
    BinaryTreeNode<T> * CreatebyInorderandPreorder(char * inorder,char * preorder, int lenth){
        if (lenth==0) {
            return NULL;
        }
        BinaryTreeNode<T> * node=new BinaryTreeNode<T>;
        node->element=preorder[0];
        int i=0;
        for (i=0; i<lenth; i++) {
            if (inorder[i]==*preorder) {
                break;
            }
        }
        node->leftchild=CreatebyInorderandPreorder(inorder, preorder+1,i);
        node->rightchild=CreatebyInorderandPreorder(inorder+i+1, preorder+i+1, lenth-i-1);
        return node;
    }
    BinaryTreeNode<T> * CreatebyInorderandPostorder(char * inorder,char * postorder,int lenth){
        if(lenth==0) {
            return NULL;
        }
        BinaryTreeNode<T> * node=new BinaryTreeNode<T>;
        node->element=postorder[lenth-1];
        int i=0;
        for (i=0; i<lenth; i++) {
            if (inorder[i]==postorder[lenth-1]) {
                break;
            }
        }
        node->leftchild=CreatebyInorderandPostorder(inorder, postorder, i);
        node->rightchild=CreatebyInorderandPostorder(inorder+i+1, postorder+i, lenth-i-1);
        return node;
    }
    
    //二叉搜索树的查找
    bool searchBinarySearch(BinaryTreeNode<T> *pointer,T key){
        if (pointer==NULL) {
            return false;
        }
        if (pointer->element==key) {
            return true;
        }else if (key<pointer->element){
            return searchBinarySearch(pointer->leftchild, key);
        }else if (key>pointer->element){
            return searchBinarySearch(pointer->rightchild, key);
        }
    }
    
    //二叉搜索树的插入
    BinaryTreeNode<T> * InsertNodetoBinarySearchTree(BinaryTreeNode<T> * node,T value){
        BinaryTreeNode<T> *n=new BinaryTreeNode<T>;
        n->leftchild=NULL;
        n->rightchild=NULL;
        n->element=value;
        BinaryTreeNode<T> *temp=node;
        while (temp!=NULL) {
            if (value<temp->element) {
                if (temp->leftchild==NULL) {
                    temp->leftchild=n;
                    break;
                }else{
                    temp=temp->leftchild;
                }
            }else if (value>temp->element){
                if (temp->rightchild==NULL) {
                    temp->rightchild=n;
                    break;
                }else{
                    temp=temp->rightchild;
                }
            }
        }
        return node;
    }
    
    //二叉搜索树的删除
    bool  DeleteBinarySearchTree(BinaryTreeNode<T> * node){
        BinaryTreeNode<T> *temp=node;
        BinaryTreeNode<T> *pre=NULL;
        if (node==NULL) {
            return false;
        }
        if (temp->leftchild!=NULL) {
            pre=temp;
            temp=temp->leftchild;
            while (temp->rightchild!=NULL) {
                pre=temp;
                temp=temp->rightchild;
            }
            if (temp->leftchild!=NULL) {
                pre->rightchild=temp->leftchild;
            }else{
                pre->leftchild=NULL;
            }
            node->element=temp->element;
            delete temp;
        }else if(temp->leftchild==NULL&&temp->rightchild!=NULL){
            pre=temp;
            temp=temp->rightchild;
            while (temp->leftchild!=NULL) {
                pre=temp;
                temp=temp->leftchild;
            }
            node->element=temp->element;
            if (temp->rightchild!=NULL) {
                pre->leftchild=temp->rightchild;
            }else{
                pre->rightchild=NULL;
            }
            delete temp;
        }else{
            delete temp;
        }
        return true;
    }
    
    
    
};


    
    
    
    
int main() {
//    BinaryTreeNode<int> a(3);
//    BinaryTreeNode<int> b(4);
//    BinaryTreeNode<int> c(5,&a,&b);
//
//    BinaryTree<int> tree;
////    tree.breadthFirstOrder(&c);
////    cout<<endl<<tree.Nodenumber_0(&c);
////    cout<<endl<<tree.Nodenumber_1(&c);
////    cout<<endl<<tree.Nodenumber_2(&c);
////    cout<<endl<<tree.IsCompleteTree(&c)<<endl;
//    cout<<tree.getMax(&c)<<endl;
//    tree.preOrder(&c);
//    cout<<endl;
//    tree.inOrder(&c);
//    cout<<endl;
//    tree.postOrder(&c);
//    cout<<endl;
    
    BinaryTreeNode<int> t(400);
    BinaryTree<int> tree(&t);
    tree.InsertNodetoBinarySearchTree(&t,122 );
    tree.InsertNodetoBinarySearchTree(&t, 450);
    tree.InsertNodetoBinarySearchTree(&t, 99);
    tree.InsertNodetoBinarySearchTree(&t, 250);
    tree.InsertNodetoBinarySearchTree(&t, 500);
    tree.InsertNodetoBinarySearchTree(&t, 110);
    tree.InsertNodetoBinarySearchTree(&t, 200);tree.InsertNodetoBinarySearchTree(&t, 300);tree.InsertNodetoBinarySearchTree(&t, 105);tree.InsertNodetoBinarySearchTree(&t, 330);
    // tree.preOrder(&t);
    tree.breadthFirstOrder(&t);
    cout<<endl;
    BinaryTreeNode<int> * temp=&t;
    temp=t.getLeftChild();
    tree.DeleteBinarySearchTree(temp);
    tree.breadthFirstOrder(&t);
    
//    char * a="abdfgceh";
//    char * b="bfdgaceh";
//    char * c="fgdbheca";
//    BinaryTree<char> tree;
//    //tree.CreatebyInorderandPreorder(b, a, 4);
//    tree.preOrder(tree.CreatebyInorderandPreorder(b, a, 8));
//    cout<<endl;
//    tree.inOrder(tree.CreatebyInorderandPreorder(b, a, 8));
//    cout<<endl;
//    tree.inOrder(tree.CreatebyInorderandPostorder(b, c, 8));
//    cout<<endl;
//    tree.postOrder(tree.CreatebyInorderandPostorder(b, c, 8));
//    cout<<endl;
//
}

















