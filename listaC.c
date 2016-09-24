/*
 * Eliminar los elementos pares de una lista circular simple 
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *next;
}list;

list *head, *tail;

//insertion tail
void insert_tail(int xdata)
{
	list *Node = (list*)malloc(sizeof(list));
	Node->data = xdata;
	if(head == NULL){
		head = tail = Node;
		head->next = head;
	}else{
		tail->next = Node;
		tail = tail->next;
		tail->next = head;
	}
}

// remove 
void remove_node(list *node){
	list *i = head;
	while(i->next != node){
		i = i->next;
	}
	if(head->next ==  head){
		head == NULL;
	}else{
		if(node == head){
			head = head->next;
			i->next = head;
		}else if(node == tail){
			tail = i;
			tail->next = head;
		}else{
			i->next = node->next; 
		}
	}
	node->next = NULL;
	free(node);
}

//search pairs
void pairs()
{
	list *i=head, *aux;
	while(i->next != head ){
		if(i->data % 2 == 0){
				aux = i;
				i = i->next;
				remove_node(aux);
		}else{
			i = i->next;
		}
	}
	if(i->data % 2 == 0){
		remove_node(i);
	}
}

//to show
void show()
{
	list *i = head;
	if(head != NULL){
		while(i->next != head){
			printf("{%d}->", i->data);
			i = i->next;
		}
		printf("{%d}->NULL\n", i->data);
	}else{
		printf("Lista vacia\n");
	}
}

int main()
{
	//insertion list
	int j = 0;
	for(j = 1; j <=10; j++){
		insert_tail(j);
	}	
	printf("\n");
	show();
	printf("\n Lista sin elementos pares\n");
	pairs();
	show();
}

