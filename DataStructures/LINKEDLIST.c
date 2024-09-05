#include<stdio.h>

typedef struct n{
	int element;
	n *next;
}Node;

Node *Find(Node *Header, int e){
	Node *Position = Header->next;
	while(Position->element != e){
		Position = Position->next;
	}
	return Position;
}

int main(){
	Node *Header = new Header;
	Header->next = NULL;
	
	return 0;
}

