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
		
	}
	
};