#include <iostream>

using namespace std;

struct node {
    int value; // du lieu can luu
    node* next; // con tro tro toi du lieu ngay sau no trong linked list
};

node *head; // con tro dau tien trong linked list

// chen gia tri v vao dau linked list
void insert_first(int v) {
    // cap phat bo nho DONG cho node se chua gia tri v
    node *new_node = new node();
    new_node->value = v; new_node->next = NULL;
    
    new_node->next = head; // new_node se dung dau tien trong linked list
    head = new_node; // head moi se la new_node
}

// chen gia tri v vao cuoi linked list
void insert_last(int v) {

    // GOI Y: xuat phat tu head, theo con tro next di chuyen den cuoi linked list, sau do chen v vao cuoi linked list
}

// tra ve CON TRO DAU TIEN chua gia tri v
// hoac tra ve NULL neu linked list ko chua v
node *search(int v) {

}

// xoa gia tri v ra khoi linked list (neu co)
void remove(int v) {

}

// in ra (tren 1 dong) toan bo phan tu dang co trong linked list
void print_all() {

}

int main() {
    head = NULL; // linked list ban dau rong []
    insert_first(2); // 2
    insert_first(1); // 1->2
    insert_last(3); // 1->2->3
    insert_last(4); // 1->2->3->4
    
    print_all(); // in 1 2 3 4
    
    node *x = NULL;
    x = search(1); cout << x->value << "\n"; // in ra 1
    x = search(2); cout << x->value << "\n"; // in ra 2
    x = search(4); cout << x->value << "\n"; // in ra 4
    x = search(5); if (x == NULL) cout << "5 not found!\n"; // "5 not found!"
    
    remove(2); // 1->3->4
    print_all(); // in 1 3 4
    
    remove(1); // 3->4
    print_all(); // in 3 4
    
    remove(4); // 3
    print_all(); // in 3
    
    remove(3); // link list rong
    print_all(); // khong in ra gi
}
