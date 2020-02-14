
#include <iostream>
using namespace std; 

/* A linked list node */
struct Node 
{ 
    char data; 
    struct Node *next; 
}; 

struct Node *addToEmpty(struct Node *last, int data) 
{ 
    // This function is only for empty list 
    if (last != NULL) 
      return last; 
  
    // Creating a node dynamically. 
    struct Node *temp =  
           (struct Node*)malloc(sizeof(struct Node)); 
  
    // Assigning the data. 
    temp -> data = data; 
    last = temp; 
  
    // Creating the link. 
    last -> next = last; 
  
    return last; 
} 



struct Node *addEnd(struct Node *last, int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
      
    struct Node *temp =  
        (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
  
    return last; 
} 

void traverse(struct Node *last) 
{ 
    struct Node *p; 
  
    // If list is empty, return. 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
  
    // Pointing to first Node of the list. 
    p = last -> next; 
  
    // Traversing the list. 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
    cout<<endl;
  
} 

int numSwaps(struct Node* head_ref, int count){
    struct Node *curr;
    curr = head_ref;
    struct Node *temp= nullptr;
    // cout<<"Reached";
    char d,change;
    while(curr->next!= head_ref){
        d = curr->data;
        curr=curr->next;
        temp=curr->next;
        while(temp->data!=d)
        {
            temp=temp->next;
        }
        if(temp== head_ref || temp->data==curr->data){
            continue;
        }
        else{
            count++;
            cout<<"Swapping is bewtween  "<<curr->data<<" ,"<<temp->data<<endl;
            change = curr->data;
            curr->data=temp->data;
            temp->data = change;
        }
        traverse(head_ref);
    }
    return count;
}

/* Driver program to test above function */
int main() 
{ 
	Node *last = NULL; 
    int count = 0;
	/* The constructed linked list is: 
	1->2->3->4->5->6->7 */
    last = addToEmpty(last, 'A'); 
    last = addEnd(last, 'B'); 
    last = addEnd(last, 'C'); 
    last = addEnd(last, 'A'); 
    last = addEnd(last, 'B'); 
    last = addEnd(last, 'C');
    last = addEnd(last, 'A');  
    last = addEnd(last, 'B'); 
    last = addEnd(last, 'C'); 

    

	// cout << "Linked list before calling swapNodes() "; 
	traverse(last); 

    count = numSwaps(last, count);
    cout<<count;
	return 0; 
} 

// This is code is contributed by rathbhupendra 
