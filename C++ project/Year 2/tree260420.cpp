#include <iostream>
#include <vector>
 
using namespace std;
 
struct Node {
    int data; // bien luu tru du lieu (ID) cua node cay
    Node *parent; // con tro tro toi node cha cua node hien tai
    Node *left; // con tro tro toi node con trai cua node hien tai
    Node *right; // con tro tro toi node con phai cua node hien tai
};
vector<int> inorder;
vector<int> preorder;
vector<int> postorder;
// ham nay duyet cay goc tai node v theo thu tu preorder
// thu tu ID cac node duoc duyet se duoc luu vao vector order
// ky tu & truoc bien order co y nghia: order duoc truyen vao ham preorder_traversal() bang reference
// su dung ham push_back() cua vector de luu thu tu duyet cay
void preorder_traversal(Node *v, vector<int> &order) {
	
}
 
// tuong tu nhu tren
// ham nay duyet cay goc tai node v theo thu tu inorder
void inorder_traversal(Node *v, vector<int> &order) {
	if (v != NULL){
		inorder_traversal(v->left, inorder);
		cout<<v->data<<' ';
		inorder_traversal(v->right, inorder);
	}
}
 
// tuong tu nhu tren
// ham nay duyet cay goc tai node v theo thu tu postorder
void postorder_traversal(Node *v, vector<int> &order) {
	if (v != NULL){
		preorder_traversal(v->left, inorder);
		preorder_traversal(v->right, inorder);
		cout<<v->data<<' ';
	}
}
 
// ham nay tra ve so luong node thuoc cay con goc tai v (bao gom ca v)
// GOI Y: tim cong thuc de quy tinh subtree_size(v) dua vao subtree_size() cua 2 node con trai, phai cua v
int subtree_size(Node *v) {
	int count=0;
	if (v != NULL){
		count+=subtree_size(v->left)+1;
		count+=subtree_size(v->right)+1;
	}
	return count;
}
 
// kiem tra xem u co phai la node chau chat cua v hay khong (u != v khi ham nay duoc goi)
// return 0 neu u ko phai,
// return 1 neu u thuoc nhanh con trai cua v,
// return 2 neu u thuoc nhanh con phai cua v.
// GOI Y: co the de quy recursive ???
 
int is_descendant(Node *u, Node *v) {
	Node*root = v;
	while (v!=NULL || v->data!=u->data){
		v=v->left;
		if (v->data = u->data){
			return 1;
		}
	}
	v=root;
	while (v!=NULL || v->data!=u->data){
		v=v->right;
		if (v->data = u->data){
			return 2;
		}
	}
	return 0;
}
 
// kiem tra xem u va v co phai la 2 node anh em (sibling) hay ko
// return true hoac false
bool is_siblings(Node *u, Node *v) {
	if (u->parent == v->parent){
		return true;
	} else {
		return false;
	}
}
 
/*
VD: voi cay nhi phan
        4
       / \
      1   3
     / \
    2   5
   
preorder_traversal(goc 4) se cho order = [4, 1, 2, 5, 3]
inorder_traversal(goc 4) se cho order = [2, 1, 5, 4, 3]
postorder_traversal(goc 4) se cho order = [2, 5, 1, 3, 4]
subtree_size(node 1) = 3 vi co 3 node thuoc cay con goc 1 la: 1, 2, 5
subtree_size(node 5) = 1
is_descendant(node 1, node 3) = 0
is_descendant(node 2, node 4) = 1
is_descendant(node 5, node 1) = 2
is_siblings(node 2, node 5) = true
is_siblings(node 2, node 1) = false
*/
 
/*
Hay chay test vi du sau de kiem thu chuong trinh
Cay nhi phan mo ta trong dau vao cung chinh la cay o hinh ve minh hoa o tren
 
Input:
5
2 5
0 0
0 0
1 3
0 0
 
Output dung:
 
preorder: 4 1 2 5 3
inorder: 2 1 5 4 3
postorder: 2 5 1 3 4
subtree sizes: 3 1 1 5 1
descendant/ancestor relation:
1 4 1
2 1 1
2 4 1
3 4 2
5 1 2
5 4 1
siblings pair:
1 3
2 5
 
*/
 
// ham main() da duoc hoan thien, ko can chinh sua
 
int main() {
    // doc n la so luong node cua cay nhi phan
    int n; cin >> n; // cac node co ID tu 1 toi n
   
    Node **tree_nodes = new Node*[n + 1]; // yeu cau chuong trinh cap phat bo nho cho 1 mang gom n+1 node
    for(int i = 1; i <= n; ++i) {
        tree_nodes[i] = new Node(); // new truoc khi su dung
        tree_nodes[i]->data = i; // luu ID cua node
        tree_nodes[i]->parent = tree_nodes[i]->left = tree_nodes[i]->right = NULL;
    }
   
    for(int i = 1; i <= n; ++i) {
        int L, R; cin >> L >> R;
        // doc ID 2 node con trai, phai cua node co ID i
        // neu L = 0 hoac R = 0 nghia la i ko co node con trai/phai
       
        if (L != 0) {
            tree_nodes[i]->left = tree_nodes[L]; // L la node con trai cua i
            tree_nodes[L]->parent = tree_nodes[i]; // i la node cha cua L
        }
       
        if (R != 0) {
            tree_nodes[i]->right = tree_nodes[R]; // R la node con phai cua i
            tree_nodes[R]->parent = tree_nodes[i]; // i la node cha cua R
        }
    }
   
    Node *root = NULL; // xac dinh node goc cua cay
    for(int i = 1; i <= n; ++i)
        if (tree_nodes[i]->parent == NULL) // node goc la node ko co cha (parent)
            root = tree_nodes[i];
   
    // xac dinh va in ra thu tu duyet cay preorder      
    
    
    cout << "preorder: ";
    preorder_traversal(root, preorder);
    for(int i = 0; i < preorder.size(); ++i) cout << preorder[i] << " ";
    cout << "\n";
   
    // xac dinh va in ra thu tu duyet cay inorder      
    
    cout << "inorder: ";
    inorder_traversal(root, inorder);
    for(int i = 0; i < inorder.size(); ++i) cout << inorder[i] << " ";
    cout << "\n";
   
    // xac dinh va in ra thu tu duyet cay postorder      

    
    cout << "postorder: ";
    postorder_traversal(root, postorder);
    for(int i = 0; i < postorder.size(); ++i) cout << postorder[i] << " ";
    cout << "\n";
   
    // xac dinh subtree size cua moi node
    cout << "subtree sizes: ";
    for(int i = 1; i <= n; ++i) cout << subtree_size(tree_nodes[i]) << " ";
    cout << "\n";
   
    // xac dinh cac cap node co quan he con chau/to tien
    cout << "descendant/ancestor relation:\n";
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            int relation = is_descendant(tree_nodes[i], tree_nodes[j]);
            if (relation != 0) cout << i << " " << j << " " << relation << "\n";
        }
 
    // xac dinh cac cap node anh em
    cout << "siblings pair:\n";
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j) {
            if (is_siblings(tree_nodes[i], tree_nodes[j]) == true) {
                cout << i << " " << j << "\n";
            }
        }
}
