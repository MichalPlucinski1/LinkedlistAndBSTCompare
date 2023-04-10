/*
	plan

	0. implement Linkedlist and BST (creating structures, searching, deleting)
	1. create vector with unsorted, non-repetetive numbers (maybe using rand and find).
	2. create 2nd vector in size of n elements from 1st vector and do operations on it. Then increase n.
	3. add measuring time
	4. dump times into txt, then make excel.
*/




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;

public:
    // Default constructor
    Linkedlist() { head = NULL; }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position
    void deleteNode(int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset)
{
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is greater than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}
Linkedlist list;
// Function to insert a new node.
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
    cout << "inserting " << data << endl;
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    Node* temp2 = temp->next;
    while (temp->next != NULL) {
        temp2 = temp->next;
        cout << "temp->value: " << temp->data << endl;
        cout << "temp2->value: " << temp2->data << endl;
        cout << "element to add: " << data << endl;
        cout << "-------------------" << endl;
        if (temp2->data > data)
        {
            newNode->next = temp2;
            temp->next = newNode;
            list.printList();
            cout << endl;
            return;
        }

        // Update temp
        temp = temp->next;
        list.printList();
        cout << endl;
    }

    // Insert at the last.
    temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Driver Code
int main()
{
    

    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(4);
    list.insertNode(3);
    

    cout << "Elements of the list are: ";

    // Print the list
    list.printList();
    cout << endl;

    /*
    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    */
    return 0;
}