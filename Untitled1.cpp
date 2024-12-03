#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *taonode(int x){
    node *nnode=new node ();
    nnode->data=x;
    nnode->next=nullptr;
    return nnode;
}
void duyetnode(node *head){
    node *p=head;
    while (p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
node *addnode(node *&head,int x){
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
void chennode(node *&head, int k, int x){
	node *p=head;
	node *nnode=taonode(x);
    if (head == nullptr || head->data == k) {

        p->next=nnode;
	}
	while (p!=nullptr){
		if (p->next->data==k){
			node *q=p->next;
			p->next=nnode;
			nnode->next=q;
			}
		p=p->next;
		}
	p->next=nnode;
	}
int main(){
    int n;
    cin>>n;
    int a[10];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int x;
    cin>>x;
    node *head=nullptr;
    for (int i=0;i<n;i++){
        addnode(head,a[i]);
    }
	chennode(head,1,10);
    duyetnode(head);
    return 0;
}
