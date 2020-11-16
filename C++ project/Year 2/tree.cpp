#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* parent;
	vector<Node*> children; //vector children chua cac con tro toi cac node
};

/*vector<int> a; //a chua cac so nguyen
//cac thao tac co ban
a.push_back(1); //a=[1]
a.push_back(2); //a=[1, 2]
a.push_back(1); //a=[1, 2, 1]
cout<< a.size(); //so phan tu of vector a
for (int i = 0; i< a.size()-1; i++){
	//a[0], a[1]...
}*/

Node *root;
Node* tree_nodes[1001]; //moi node tuong ung 1 phan tu of mang
//dong 1: n
//dong 2 gom n-1 p: p2 p3 p4..pn
//5
//1 1 2 3 (p2 of 2 =1, p3 of 3=1, p4 of 4 = 2, p5 of 5 =3)

int main(){
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		tree_nodes[i] = new Node();
		tree_nodes[i] -> key = i;
		
		//note:
		//Node a; a.parent; a la gia tri kieu node thi dung cham
		//Node*b: b->parent; b la con tro tro den du lieu kieu node, vi vay dung ->
	}
	
	for (int i=2; i<=n; i++){
		int p;
		cin>>p; //(p là parent of i)
		tree_nodes[i] -> parent = tree_nodes[p];
		tree_nodes[p] -> children.push_back(tree_nodes[i]);
	}
	int*a = new int[n+1];
	//output
	//bai 1: in ra 2 dong
	//dong 1: liet ke cac node internal theo id tang dan (tru node root)
	//dong 2: liet ke cac node la (leaf) theo thu tu id tang dan
	//node internal
	for (int i=2; i<=n; i++){
		if (tree_nodes[i]->children.size()>0){
			cout<<tree_nodes[i]->key<<' ';
		}
	}
	cout<<endl;
	//node la	
	for (int i=1; i<=n; i++){
		if (tree_nodes[i]->children.size() == 0){
			cout<<tree_nodes[i]->key<<' ';
		}
	}
	//node la => children rong => size() = 0;
	//tree travelsal: 
	// - preOrder: 1 (2->4) (3->5)
	// - postOrder (4>2) (5>3) 1
}
