//
//  main.cpp
//  9
//
//  Created by Darnell on 2018/10/9.
//  Copyright © 2018年 Darnell. All rights reserved.
//



struct ListNode {
    int m_value;
    ListNode * m_pNext;
};

class List{
public:
    ListNode * CreateListFromTail();//尾插法⽆无头节点
    void InsertListNodeFromBack(ListNode *&L, int pos, int value);   //后插入
    void InsertListNodeFromFront(ListNode *&L, int pos, int value); //前插入
    int ListLen(ListNode *L);//链表⻓长度
    ListNode * ReverseList(ListNode *L);//反转
    void DeleteListNode(ListNode *L, int value);//删除链表
};

ListNode *List:: CreateListFromTail(){
    ListNode *pHead = NULL; ListNode *pTail = pHead; int input;
    while (cin>>input && input != -1) {
        ListNode *pTmp = new ListNode; pTmp->m_value = input;
        if (pHead == NULL) pHead = pTmp;
        else
            pTail->m_pNext = pTmp;
            pTail = pTmp;
            pTmp = NULL;
        
    }
    if (pTail != NULL) pTail->m_pNext = NULL;
    return pHead;
    
}

void List::InsertListNodeFromFront(ListNode *&L, int pos, int value){
            ListNode *tmp = new ListNode; tmp->m_value = value;
            if (L == NULL || pos == 0)
            {
                tmp->m_pNext = L; L = tmp;
            }
            if ( pos >= ListLen(L) || pos < 0) {
                cout << "Error input pos."<< endl;
            }
            ListNode *pInsert = L; while (--pos)
            {
                pInsert = pInsert->m_pNext; }
            tmp->m_pNext = pInsert->m_pNext; pInsert->m_pNext = tmp;
            
    
}

void List::InsertListNodeFromBack(ListNode *&L, int pos, int value) {
    ListNode *tmp = new ListNode; tmp->m_value = value;
    if (L == NULL || pos == 0){
        tmp->m_pNext = L; L = tmp;
       
    }
    ListNode *pInsert = L;
    while (pos--){
        pInsert = pInsert->m_pNext; }
        tmp->m_pNext = pInsert->m_pNext; pInsert->m_pNext = tmp;
    
    
}
void DeleteListNode(ListNode *L, int value) {
    ListNode *pDelete = L; if (L->m_value == value) {
        L = L->m_pNext; delete pDelete; return;
    }
    ListNode *pFront = NULL;
    while (pDelete != NULL && pDelete->m_value != value) {
        pFront = pDelete;
        pDelete = pDelete->m_pNext;
        
    }
    if (pDelete == NULL) {
        cout << "Not found value in L.";
    }
    if (pDelete->m_value == value) {
        pFront->m_pNext = pDelete->m_pNext;
        delete pDelete; }
    }
ListNode * ReverseList(ListNode *L){
    if(L == NULL || L->m_pNext == NULL) return NULL;
    ListNode * pCurrent = NULL;
    while (L != NULL) {
        ListNode * tmp = L->m_pNext;
        L->m_pNext = pCurrent;/
        L = tmp;
    }
    return pCurrent;
    
}
int ListLen(ListNode *L){
    int len = 0;
    while (L != NULL) {
        L = L->m_pNext;
        ++len;
    }
    return len;
}
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL) return pHead2;
    if (pHead2 == NULL) return pHead1;
    ListNode *pNewHead = NULL, *pNewTail = NULL;
    ListNode *pNode1 = pHead1, *pNode2 = pHead2;
    while (pNode1 != NULL && pNode2 != NULL) {
        ListNode *pTmp = NULL;
        if (pNode1->m_value < pNode2->m_value) {
            pTmp = pNode1;
            pNode1 = pNode1->m_pNext; }
        else {
            pTmp = pNode2;
            pNode2 = pNode2->m_pNext; }
        if (pNewHead == NULL) {
            pNewHead = pNewTail = pTmp; }
        else {
            pNewTail->m_pNext = pTmp;
            pNewTail = pNewTail->m_pNext; }
    }
    if ( pNode1 == NULL ) //对多余m-n个节点的处理理 {
        pNewTail->m_pNext = pNode2; }
    if ( pNode2 == NULL ) {
        pNewTail->m_pNext = pNode1; }
    return pNewHead;
}

