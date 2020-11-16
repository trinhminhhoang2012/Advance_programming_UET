#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* parent;
	vector<Node*> children;
};

Node *root;
Node* tree_nodes[1001];

void preOrder_travelsal(Node*v) {
	cout<<v->key<<' ';
	for (int i=0; i<v->children.size(); i++){
		preOrder_travelsal(v->children[i]);
	}	
}

void posOrder_travelsal(Node*v) {
	for (int i=0; i<v->children.size(); i++){
		posOrder_travelsal(v->children[i]);
	}
	cout<<v->key<< ' ';
	
}

int depth(Node*v) {
	if (v == tree_nodes[1]){
		return 0;	
	} else {
		return depth(v->parent)+1;
	}
}
int main(){
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		tree_nodes[i] = new Node();
		tree_nodes[i] -> key = i;
	}
	
	for (int i=2; i<=n; i++){
		int p;
		cin>>p;
		tree_nodes[i] -> parent = tree_nodes[p];
		tree_nodes[p] -> children.push_back(tree_nodes[i]);
	}

	/*for (int i=2; i<=n; i++){
		if (tree_nodes[i]->children.size()>0){
			cout<<tree_nodes[i]->key<<' ';
		}
	}
	cout<<endl;
	
	for (int i=1; i<=n; i++){
		if (tree_nodes[i]->children.size() == 0){
			cout<<tree_nodes[i]->key<<' ';
		}
	}*/
	
	preOrder_travelsal(tree_nodes[1]);
	cout<<endl;
	posOrder_travelsal(tree_nodes[1]);
	cout<<endl;
	//depth level
	for (int i=1; i<=n; i++){
		cout<<depth(tree_nodes[i])<<' ';
	}
}
