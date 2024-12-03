#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *taonode(int x) {
    node *nnode = new node();
    nnode->data = x;
    nnode->next = nullptr;
    return nnode;
}

void duyetnode(node *head) {
    node *p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

node *addnode(node *&head, int x) {
    node *p = taonode(x);
    if (head == nullptr) {
        head = p;
    } else {
        node *nnode = head;
        while (nnode->next != nullptr) {
            nnode = nnode->next;
        }
        nnode->next = p;
    }
    return head;
}

//chen node co gia tri x vao truoc node co gia tri k
void chennode(node *&head, int k, int x) {
    node *p = head;
    while (p != nullptr) {
        if (p->data == k) {
            node *nnode = taonode(x);
            nnode->next = p->next;
            p->next = nnode;
            return;
        }
        p = p->next;
    }
}
void xoandau(node *&head){
	head=head->next;
}
void xoancuoi(node *&head){
	node *p=head;
	while (p->next->next!=nullptr){
		p=p->next;
	}
	p->next=nullptr;
}
void xoangiua(node *&head,int k){
	node *p=head;
	for (int i=0;i<k-1;i++){
		p=p->next;
	}
	node *nnode=p->next->next;
	p->next=nnode;
}

int main() {
    int n;
    cin >> n;
    int a[10];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;   
    cin >> k;
    //int x;
    //cin >> x;
    node *head = nullptr;
    for (int i = 0; i < n; i++) {
        head = addnode(head, a[i]);
    }
    //chennode(head, k, x);
    if (k==0){
    	xoandau(head);
	}
	else{
		xoangiua(head,k);
	}
    duyetnode(head);
    return 0;
}

