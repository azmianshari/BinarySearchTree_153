#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;
	
	//Constructor untuk class node.
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;
	
	BinaryTree() {
		ROOT = NULL; //Menginisialisasi ROOT ke null.
	}
	void insert(string element) {
		Node* newNode = new Node(element, NULL, NULL); //Alokasi memori untuk new node
		newNode->info = element; //Menetapkan nilai data field ke new node 
		newNode->leftchild = NULL; //Mengarahkan leftchild new node ke NULL
		newNode->rightchild = NULL; //Mengarahkan rightchild new node ke NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); //Mencari node yang akan menjadi induk dari node baru.

		if (parent == NULL) { //Jika parent bernilai NULL (Tree Empty)
			ROOT = newNode;
			return;
		}
		if (element < parent->info) { //Jika nilai field dari node baru kurang dari parent
			parent->leftchild = newNode; //Buat leftchild dari parent menunjuk ke node baru
		}
		else if (element > parent->info) {//Jika nilai field dari node baru lebih dari parent
			parent->rightchild = newNode; //Buat rightchild dari parent menunjuk ke node baru
		}
	}
	void search(string element, Node*& parent, Node*& currentNode){ //Fungsi search
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
	void Inorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			Inorder(ptr->leftchild);
			cout << ptr->info << " ";
			Inorder(ptr->rightchild);
		}
	}
	void Preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " ";
			Preorder(ptr->leftchild);
			Preorder(ptr->rightchild);
		}
	}
};