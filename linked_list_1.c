// This program works well for a singly linked list, except for delete previously added node only works one time
#include<stdio.h>
#include<stdlib.h>
int main(){
	typedef struct node {
		int data;
		struct node *next;
	} node;
	node *head, *newnode, *temp, *last, *last_1;
	int choice = 1; int count = 0; last_1 = NULL;
	head = NULL;
	while (choice != 0){
		printf("\nEnter choice:\n1. enter new element\n2. enter element at position\n3. delete last entered node (works only 1 time)\n4. delete nth node\n5. print entire linked list\n0. exit\n");
		scanf("%d", &choice);
		switch (choice){
		    
			case 1: {
			printf("case 1 running, entering element at the end of the linked list\n");
				newnode = (node*) malloc(sizeof(node));
				printf("enter value: "); int a; scanf("%d", &a);
				newnode->data = a; newnode->next = NULL;
				if (head == NULL){ last_1 = NULL; //no req of last_1 when head
					head = newnode;
					last = newnode;                //last
					count++;
					break;
				}
				else {
					temp = head;
					while(temp->next != NULL){
						temp = temp->next;
					}
					last_1 = temp;                 //last_1
					temp->next = newnode;
					last = newnode;                //last
					count++;
					break;
				}
			}
			
			case 2: {
				printf("case 2 running, element at position\n");
				printf("enter position n (not conventional index but nth element) (nodes shift towards tail): "); int n; scanf("%d", &n);
				printf("enter value: "); int a; scanf("%d", &a);
				newnode = (node*) malloc(sizeof(node)); newnode->data = a;
				
				if (head == NULL) { head = newnode; last = newnode; count++; break;} // first element, n == 1, head == NULL //last
				else if (n == 1) { // adding at head, n == 1, head != NULL
					if (count == 1){ last_1 = NULL; //no last_1 req when adding to head
						newnode->next = head;
						// head->next = NULL;
						head = newnode;
						last = head;         //last
						count++;
						break;
					}
					else { last_1 = NULL; //no last_1 req when adding to head
						newnode->next = head;
						head = newnode;
						last = newnode;      //last
						count++;
						break;
					}
				}
				else if (n > 1 && n<=count+1) {
					if (n >= count+1){ // adding node add the end
						newnode->next = NULL;
						temp = head;
						while(temp->next != NULL){ // traverse to last node
							temp=temp->next;
						}
						last_1 = temp;       //last_1
						temp->next = newnode;
						last = newnode;      //last
						count++;
						break;
					}
					int pos = 1;            //adding node in between
					temp = head;
					while (pos<n-1){ // n != count+1, its between head and count
						temp=temp->next; // traverse to n-1th node
						pos++;
					}
					last_1 = temp;           //last_1
					newnode->next = temp->next;
					temp->next=newnode;
					last = newnode;           //last
					count++;
					break;
				}
				else{ 
					printf("not enough elements\n"); break;
				}
			}
			
			case 3:{
			    if (last_1 == NULL){ //last added node is head
			        head = head->next;
			        free(last);
			        count--;
			        break;
			    }
			    else {
			        last_1->next = last->next;
			        free(last);
			        count--;
			        break;
			    }
			}
			
			case 4:{
			    printf("case 4: delete nth node\n");
			    printf("delete position: "); int d; scanf("%d", &d);
			    if (d>count) {printf("position exceeds number of nodes\n"); break;}
			    int pos = 1; temp = head;
			    while(pos<d-1){
			        temp = temp->next;
			        pos++;
			    }
			    printf("%d at %dth position has been freed\n", temp->next->data, pos+1);
			    node* p = temp->next;
			    temp->next = temp->next->next;
			    free(p);
			    count--;
			    break;
			}
			
		    case 5: {
			    int pos = 1; temp = head;
			    printf("%d", temp->data);
			    while(pos<count){
				    temp = temp->next;
				    printf("-> %d", temp->data);
				    pos++;
			    }
			    break;
		    }
			default: break;
		}
	}
}
