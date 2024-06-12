#include "Node.h"

Node::Node() {

}

Node::~Node() {
}

Node::Node(const int& data): data(data), next(nullptr){

}
	
void Node::setData(const int& data){
	this->data = data;
}

int Node::getData(){
	return data;
}
	
void Node::setNext(Node* next){
	this->next = next;
}

Node* Node::getNext(){
	return next;
}