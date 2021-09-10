/*
Search One Linked List from Another Linked List
Here, We follow a simple iterative algorithm.
Take the head node of list in which we want to find its sublist, then start matching the firt list from head node of other list.
If whole lists match return true else break and take first list to first node again and second list to its second node.
Keep repeating untill you reach last node. If first list becomes NULL then list is found otherwise not found.
*/
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node *a;
Node *b;

bool search_list() {
    Node* ptr1 = a;
    Node* ptr2 = b;
    if(a==NULL && b==NULL) {
        return true;
    }
    if(a==NULL || b==NULL) {
        return false;
    }

    while(b!=NULL) {
        ptr2 = b;
        while(ptr1!=NULL) {
            if(b==NULL) {
                return false;
            } else if(ptr1->data == ptr2->data) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else {
                break;
            }
        }
        if(ptr1==NULL) {
            return true;
        }
        ptr1 = a;
        b = b->next;
    }
    return false;
}

void Insert_a(int data) {
    Node *temp = new Node();
    temp->next = a;
    temp->data = data;
    a = temp;
}

void Insert_b(int data) {
    Node *temp = new Node();
    temp->next = b;
    temp->data = data;
    b= temp;
}

void Print_a() {
    Node* n = new Node();
    n = a;
    while(n!=NULL) {
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<endl;
}

void Print_b() {
    Node* n = new Node();
    n = b;
    while(n!=NULL) {
        std::cout<<n->data<<" ";
        n = n->next;
    }
    std::cout<<endl;
}

int main() {
    a = NULL, b = NULL ;
    int n;
    std::cout<<"Enter the Number of Elements to be inserted in first List : ";
    std::cin>>n;
    for(int i=0; i<n; i++) {
        int data;
        std::cin>>data;
        Insert_a(data);
    }
    //Print_a();
    int m;
    std::cout<<"Enter the number of elements in Search List : ";
    std::cin>>m;

    for(int i=0; i<m; i++) {
        int data;
        std::cin>>data;
        Insert_b(data);
    }
    //Print_b();

    if(search_list()) {
        cout<<"List Found \n";
    } else {
        cout<<"List Not Found\n";
    }
}
/*
Time Complexity : O(N*M)
Space Complexity : O(N*M)

Sample Input :
    4
    1 2 3 4
    6
    1 2 1 2 3 4
Sample Output :
    List Found
*/
