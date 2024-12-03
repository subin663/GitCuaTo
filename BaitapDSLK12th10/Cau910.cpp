#include <iostream>
using namespace std;

struct node {
    string gtri;      
    node *tiep;  
};

// Ham tao 1 node moi
node *taonode(string x) {
    node *nnode = new node();  
    nnode->gtri = x;           
    nnode->tiep = NULL;       
    return nnode;
}

// ham them nut vao cuoi danh sach
void taoncuoi(node *&head, string x) {
	if (x.length() > 20) {
        cout << "Chuoi '" << x << "' co do dai lon hon 20, khong the them vao danh sach." << endl<<endl;
        return;
    }
    node *nnode = taonode(x);
    if (head == NULL) {
        head = nnode; 
    } else {
        node *p = head;
        while (p->tiep != NULL) { 
            p = p->tiep;
        }
        p->tiep = nnode; 
    }
}

// Duyet danh sach lien ket
void duyetnode(node *head) {
    while (head != NULL) {
        cout << head->gtri << " | ";  
        head = head->tiep;        
    }
    cout << endl;
}


//Ham cho biet vi tri cua phan tu co chuoi ki tu ngan nhat
void cau9(node *head) {
    int vitri = 1; 
    int ans=1;
    string minLength=head->gtri;
    node *temp=head;
    while (temp != NULL) {
        if (temp->gtri.length() < minLength.length()) {
        	minLength=temp->gtri;
            ans=vitri;
        }
        temp = temp->tiep; 
        vitri+=1;
    }
    cout << "Vi tri phan tu co chuoi ki tu ngan nhat: " << ans << endl; 
}

//Ham cho biet vi tri cua phan tu co chuoi ki tu dai nhat
void cau10(node *head) {
    int vitri = 1; 
    int ans=1;
    string minLength=head->gtri;
    node *temp=head;
    while (temp != NULL) {
        if (temp->gtri.length() > minLength.length()) {
        	minLength=temp->gtri;
            ans=vitri;
        }
        temp = temp->tiep; 
        vitri+=1;
    }
    cout << "Vi tri phan tu co chuoi ki tu dai nhat: " << ans << endl; 
}




int main() {
    node *head = NULL; 
    taoncuoi(head, "Le Tan Vinhhhh");
    taoncuoi(head, "Tran Ngoc Hunggggggggggggggggggggggg");
    taoncuoi(head, "Tran Nhat Ny");
    taoncuoi(head, "Ngo Nhat Huy");
    taoncuoi(head, "ny");
    cout << "Danh sach lien ket: ";
    duyetnode(head);
    cau9(head);
    cau10(head);
    return 0;
}

