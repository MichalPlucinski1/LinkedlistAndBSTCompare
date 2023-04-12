/*
	plan

	0. implement Linkedlist and BST (creating structures, searching, deleting)
	1. create vector with unsorted, non-repetetive numbers (maybe using rand and find). Make list and BST of it
	2. add measuring time
        2.1   need 3D vector[quantity, tree, BST]:  creating, searching and deleting
	3. dump values longo txt, then make excel.
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


// -------------------------- vector functions -----------------------\\

void fillVector(vector<long> &numbers, long size)
{
    long random = rand() % (size);

    for (int i = 1; i < size; i++)
    {
        while (find(numbers.begin(), numbers.end(), random) != numbers.end()) {
            random = rand() % (size * 10);
        }
            
        numbers.push_back(random);
    }
    
} 

void prlongVector(vector<long>& numbers) {
    for (long i = 0; i < numbers.size(); i++) {
        cout << "vec[" << i << "]= " << numbers[i] << endl;
    }
}

// -------------------------- Linked list class and methods -----------------------\\

class Node {
public:
    long data;
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(long data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    Node* head;

public:

    Linkedlist() { head = NULL; }


    void insertNode(long);

   
    void prlongList();

    void deleteNode(long);


    void searchNode(long);


    void searchList(vector<long>);


    ~Linkedlist();
};

void Linkedlist::deleteNode(long nodeOffset)
{
    Node* temp1 = head, * temp2 = NULL;
    long ListLen = 0;

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

    // Change the next polonger
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
        // cout << "deleting " << temp->data << endl;
        delete temp;
    } while (head != NULL);
    

}

void Linkedlist::insertNode(long data)
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

void Linkedlist::searchList(vector<long> num) {
    for (long i = 0; i < num.size(); i++)
    {
        this->searchNode(num[i]);
    }
}

void Linkedlist::searchNode(long s) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == s) {
            //cout << "znalazlem " << s << endl;
            return;
        }
        if (temp->data > s) {
            //cout << "nie znalazlem " << s <<" dotarlem do "<<temp->data << endl;
            return;
        }
        temp = temp->next;
       
       
        
    }
    cout << "nie znalazlem" << endl;
}

void Linkedlist::prlongList()
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

void makeListFromVector(Linkedlist *list, vector<long> num) {
    for (long i = 0; i < num.size(); i++)
    {
        list->insertNode(num[i]);
    }
}


// -------------------------- BST class and methods -----------------------\\

class BST {
    long data;
    BST* left, * right;

public:
    BST();

    BST(long);

    void destructor(BST*);

    BST* insert(BST*, long);

    void inOrder(BST*);

    void searchElement(BST*, long);

    void searchList(BST*,vector<long>);

};

BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BST::BST(long value)
{
    data = value;
    left = right = NULL;
}

BST* BST::insert(BST* root, long value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

void BST::inOrder(BST* root)
{
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

void BST::searchElement(BST* root, long s) {
    if (!root)
        return;
    if (root->data == s)
    {
        cout << "found " << s << endl;
        return;
    }
    if (s < root->data) {
        searchElement(root->left, s);
    }
    else if (s > root->data) { searchElement(root->right, s); }

    return;

}

void BST::searchList(BST* b, vector<long> num){
    for (long i = 0; i < num.size(); i++) {
        b->searchElement(b, num[i]);
    }
}

void BST::destructor(BST* root)
{
    cout << "Im in destructor\n";
    if (root == NULL)
    {
        cout << "deleted" << endl;
        return;
    }
    if (root->right != NULL)
    {
        destructor(root->right);
        root->right = NULL;
    }
        
    if (root->left != NULL)
    {
        destructor(root->left);
        root->left = NULL;
    }
    if ((root->left == NULL) && !(root->right == NULL))
    {
        cout << "deleting last node\n";
        delete root;
    }
        
}

void makeBSTFromVector(BST& b, BST* root, vector<long>& num) {

    //root = b.Insert(root, num[0]);  
    for (long i = 1; i < num.size(); i++) {
        b.insert(root, num[i]);
    }

}

void saveToTXT(vector<long> objects, vector<double>LC, vector<double>LS, vector<double>LD, vector<double>BC, vector<double>BS, vector<double>BD) {
    fstream file;
    file.open("data.txt");
    if (file.good())
    {
        file << "num\tcreating list\tcreating BST\t search list\t search BST\t delete list\t delete BST\n";
        for (int i = 0; i < objects.size(); i++)
        {
            file << i+1 << "\t" << objects[i] <<"\t" << LC[i] << "\t" << BC[i] << "\t" << LS[i] << "\t" << BS[i] << "\t" << LD[i] << "\t" << BD[i]<< "\n";
        }
        file.close();
    }
    else
    {
        file.close();
        cout << "Not good file\n";
        return;
    }
}

void saveToTXT(vector<long> objects, vector<long>LC, vector<long>LS, vector<long>LD, vector<long>BC, vector<long>BS, vector<long>BD) {
    fstream file;
    file.open("data.txt");
    if (file.good())
    {
        file << "num\tcreating list\tcreating BST\t search list\t search BST\t delete list\t delete BST\n";
        for (int i = 0; i < objects.size(); i++)
        {
            file << i + 1 << "\t" << objects[i] << "\t" << LC[i] << "\t" << BC[i] << "\t" << LS[i] << "\t" << BS[i] << "\t" << LD[i] << "\t" << BD[i] << "\n";
        }
        file.close();
    }
    else
    {
        file.close();
        cout << "Not good file\n";
        return;
    }
}

// Driver Code
int main()
{
    //settings
    long numOfStartElements = 10000;
    long numOfEndElements   = 25000;
    long step = 1000;

    long numOfReps = (numOfEndElements - numOfStartElements) / step;
    cout << "num of reps: " << numOfReps << endl;
    //for time measure

    vector<long> numberOfObjects;

    vector<long> timesListCreation;
    vector<long> timesBSTCreation;

    vector<long> timesListSearching;
    vector<long> timesBSTSearching;

    vector<long> timesListDeleting;
    vector<long> timesBSTDeleting;



    srand(time(NULL));
    vector <long> num;
    clock_t start, end;
    long time_taken = 0;

    for (long i = 0; i <= numOfReps ; i++)
    {
        fillVector(num, numOfStartElements);
        numberOfObjects.push_back(numOfStartElements);

        //create list
        auto start = chrono::steady_clock::now();
        //clock_t start, end;
        //start = clock();

        Linkedlist* list = new Linkedlist();
        makeListFromVector(list, num);

        auto end = chrono::steady_clock::now();

        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();
        timesListCreation.push_back(time_taken);

        //search list

        
        //start = clock();
        list->searchList(num);
        
        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        
        timesListSearching.push_back(time_taken);


        //delete list
        //start = clock();
        delete list;

        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);

        timesListDeleting.push_back(time_taken);

        //create BST
        //start = clock();
        BST b, * root = NULL;
        makeBSTFromVector(b, root, num);

        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);

        timesBSTCreation.push_back(time_taken);

        //search BST
        //start = clock();
        
        b.searchList(root,num);

        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);

        timesBSTSearching.push_back(time_taken);
        
        //delete BST
        //start = clock();

        b.destructor(root);

        //end = clock();
        //time_taken = double(end - start) / double(CLOCKS_PER_SEC);

        timesBSTDeleting.push_back(time_taken);


        num.clear();
        numOfStartElements += step;
    }


    cout << "i  obj creat: L BST search L BST" << endl;

    for (int i = 0; i < numberOfObjects.size(); i++)
    {
        cout << i << " : " <<numberOfObjects[i] <<" - " << timesListCreation[i] << " / " << timesBSTCreation[i] << " - " << timesListSearching[i] << " / " <<  timesBSTSearching[i];
        cout<< endl;
    }
    
    saveToTXT(numberOfObjects, timesListCreation, timesListSearching, timesListDeleting, timesBSTCreation, timesBSTSearching, timesBSTDeleting);

    
    /*
    Linkedlist *list = new Linkedlist();

 

    cout << "Elements of the list are: ";

  
   
    

    cout << "prlong vector: " << endl;
    prlongVector(num);
    cout << endl;

    // Prlong the list
    cout << "prlonging list: " << endl;
    list->prlongList();
    cout << endl;

    list->searchList(num);

    delete list;
    
    BST b, * root = NULL;
    root = b.insert(root, num[0]);


    makeBSTFromVector(b, root, num);


    b.inOrder(root);

    b.searchList(root,num);

    b.destructor(root);
    */
    //b.inOrder(root);
    

    return 0;
}