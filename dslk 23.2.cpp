#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *taonode(int x){
	node *nnode=new node();
	nnode->data=x;
	nnode->next=NULL;
	return nnode;
	}
void duyetnode(node *head){
	while (head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
		}
	}
void *taondau(node *&head, int x){
	if (head==NULL){
		node *nnode=taonode(x);
		head=nnode;
		}
	else{
		node *nnode=taonode(x);
		nnode->next=head;
		head=nnode;
		}
		
	}
node *taoncuoi(node *&head, int x){
	node *nnode=taonode(x);
	node *p=head;
	while (p->next!=NULL){
		p=p->next;
		}
	p->next=nnode;
	}
void demnode(node *head){
	int biendem=0;
	while (head!=NULL){
		biendem++;
		head=head->next;
		}
	cout<< biendem;
	}
void tron2dslk(node *&head,node *&hhead){
	node *nnode=head;
	while(nnode->next!=NULL){
		nnode=nnode->next;
		}
	nnode->next=hhead;
	}
	
void sxdslk(node *&head) {
    if (head == NULL || head->next == NULL) return;

    node *nnode1 = head;
    while (nnode1 != NULL) {
        node *nnode2 = nnode1->next;
        while (nnode2 != NULL) {
            if (nnode1->data > nnode2->data) {
                int temp = nnode2->data;
                nnode2->data = nnode1->data;
                nnode1->data = temp;
            }
            nnode2 = nnode2->next;
        }
        nnode1 = nnode1->next;
    }
}
			
						
int main(){
	node *head=NULL;
	taondau(head,3);
	taondau(head,5);
	sxdslk(head);
	duyetnode(head);
	return 0;
	}
	
