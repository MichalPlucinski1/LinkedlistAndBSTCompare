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
#include<cstdlib>
#include<ctime>

using namespace std;

void makeVector(vector<int> &numbers, int size)
{
    int random = rand() % (size);

    for (int i = 1; i < size; i++)
    {
        while (find(numbers.begin(), numbers.end(), random) != numbers.end()) {
            random = rand() % (size * 100);
        }
            
        numbers.push_back(random);
    }
    
} 

void printVector(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << "vec[" << i << "]= " << numbers[i] << endl;
    }
}
class Node {
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class Linkedlist {
    Node* head;

public:

    Linkedlist() { head = NULL; }


    void insertNode(int);

   
    void printList();

    void deleteNode(int);


    void searchNode(int);


    void searchList(vector<int>);


    ~Linkedlist();
};


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

Linkedlist::~Linkedlist() {

    if (head == NULL) {
        //cout << "List empty." << endl;
        return;
    }
    
    do {
        Node* temp = head;
        head = temp->next;
        cout << "deleting " << temp->data << endl;
        delete temp;
    } while (head != NULL);
    

}


void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node* newNode = new Node(data);
    //cout << "inserting " << data << endl;
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
       
        if (temp2->data > data)
        {
            newNode->next = temp2;
            temp->next = newNode;
           
            return;
        }

        // Update temp
        temp = temp->next;
        
    }

    // Insert at the last.
    temp->next = newNode;
}

void Linkedlist::searchList(vector<int> num) {
    for (int i = 0; i < num.size(); i++)
    {
        this->searchNode(num[i]);
    }
}

void Linkedlist::searchNode(int searched) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == searched) {
            cout << "znalazlem " << searched << endl;
            return;
        }
        if (temp->data > searched) {
            cout << "nie znalazlem " << searched <<" dotarlem do "<<temp->data << endl;
            return;
        }
        temp = temp->next;
       
       
        
    }
    cout << "nie znalazlem" << endl;
}


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



void makeListFromVector(Linkedlist *list, vector<int> num) {
    for (int i = 0; i < num.size(); i++)
    {
        list->insertNode(num[i]);
    }
}



// Driver Code
int main()
{
    srand(time(NULL));
    Linkedlist *list = new Linkedlist();

 

    cout << "Elements of the list are: ";

  
    vector <int> num;

    makeVector(num, 10);
    makeListFromVector(list, num);

    cout << "print vector: " << endl;
    printVector(num);
    cout << endl;

    // Print the list
    cout << "printing list: " << endl;
    list->printList();
    cout << endl;

    list->searchList(num);

    //delete list;
    /*
    // Delete node at position 2.
    list.deleteNode(2);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    */
    return 0;
}