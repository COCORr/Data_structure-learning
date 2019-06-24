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
    BinaryTreeNode(const T& ele){
        element=ele;
        leftchild=NULL;
        rightchild=NULL;
    }
    BinaryTreeNode(){
        element=0;
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
    
    int count[100];
    int maxWidth=0;
    int getWidth(BinaryTreeNode<T> * pointer,int k=0){
        if (pointer==NULL) {
            return 0;
        }
        count[k]++;
        if (maxWidth<count[k]) {
            maxWidth=count[k];
        }
        getWidth(pointer->leftchild,k+1);
        getWidth(pointer->rightchild,k+1);
        return 1;
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
    
    void preOrder(BinaryTreeNode<T> * root){
        
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
};


int main(){
    BinaryTreeNode<int> a(1);
    BinaryTreeNode<int> b(2);
    BinaryTreeNode<int> c(3);
    BinaryTreeNode<int> d(4);
    BinaryTreeNode<int> e(5);
    BinaryTreeNode<int> f(6);
    BinaryTreeNode<int> g(7);
    BinaryTreeNode<int> h(8);
    BinaryTree<int> tree;
    
    a.setLeftChild(&b);
    a.setRightChild(&c);
    b.setRightChild(&e);
    b.setLeftChild(&d);
    c.setLeftChild(&f);
    c.setRightChild(&g);
    d.setLeftChild(&h);
    cout<<tree.IsCompleteTree(&a)<<endl;
    tree.getWidth(&a);
    cout<<tree.maxWidth<<endl;
    
    char * s1="12485367";
    char * s2="84251637";
    char * s3="84526731";
    BinaryTree<char> tree2;
    tree2.preOrder(tree2.CreatebyInorderandPreorder(s2, s1, 8));
    cout<<endl;
    tree2.inOrder(tree2.CreatebyInorderandPostorder(s2, s3, 8));
    cout<<endl;
}
