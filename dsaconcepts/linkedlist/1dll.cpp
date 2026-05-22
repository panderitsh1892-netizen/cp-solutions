/*
Topic: Linked List, Dynamic Memory Allocation

Key Idea:
This program demonstrates:
1. Creating a linked list node
2. Converting an array into a linked list
3. Finding length of linked list
4. Searching an element in linked list

--------------------------------------------------

What is a Linked List?

A linked list is a linear data structure where:
- each node stores data
- and a pointer to the next node

Structure:

[data | next]

--------------------------------------------------

Node Structure

struct Node{

    int data;
    Node* next;
};

data  -> stores value
next  -> stores address of next node

--------------------------------------------------

Constructors

--------------------------------------------------

Constructor 1

Node(int data1, Node* next1)

Used when:
both data and next node are known.

Example:
Node* temp = new Node(5, nullptr);

--------------------------------------------------

Constructor 2

Node(int data1)

Used when:
only data is given.

next automatically becomes nullptr.

--------------------------------------------------

Function: convertarr2LL()

Purpose:
Convert array into linked list.

--------------------------------------------------

Step 1:
Create head node using first array element.

Node* head = new Node(arr[0]);

head points to first node.

--------------------------------------------------

Step 2:
mover pointer is used for traversal.

Node* mover = head;

--------------------------------------------------

Step 3:
Loop through remaining array elements.

For every element:
- create new node
- connect previous node
- move forward

--------------------------------------------------

Example

Array:
[12,5,8,7]

Linked List becomes:

12 -> 5 -> 8 -> 7 -> NULL

--------------------------------------------------

Function: lengthofLL()

Purpose:
Count number of nodes.

--------------------------------------------------

Logic

Start from head and move until NULL.

while(temp){
    count++;
    temp = temp->next;
}

--------------------------------------------------

Time Complexity:
O(n)

--------------------------------------------------

Function: checkIfpresent()

Purpose:
Search whether a value exists in linked list.

--------------------------------------------------

Logic

Traverse entire list.

If:
temp->data == val

return 1

Else continue searching.

If value never found:
return 0

--------------------------------------------------

Example

Search 5:

12 -> 5 -> 8 -> 7

Found at second node.

--------------------------------------------------

Main Function

--------------------------------------------------

Step 1:
Create vector.

vector<int> arr = {12,5,8,7};

--------------------------------------------------

Step 2:
Convert array into linked list.

Node* head = convertarr2LL(arr);

--------------------------------------------------

Step 3:
Print head value.

Output:
12

--------------------------------------------------

Step 4:
Print linked list length.

Output:
4

--------------------------------------------------

Step 5:
Check whether 5 exists.

Output:
1

--------------------------------------------------

Important Concepts Learned

1. Dynamic memory allocation using new
2. Pointer traversal
3. Node linking
4. Building linked list manually
5. Using temp/mover pointers

--------------------------------------------------

Common Mistakes

1. Forgetting #include<vector>
2. Not updating mover pointer
3. Losing head pointer
4. Forgetting nullptr initialization
5. Infinite traversal due to wrong links

--------------------------------------------------

Time Complexities

Array to Linked List:
O(n)

Length Calculation:
O(n)

Search:
O(n)
*/

#include<iostream>
#include<vector>

using namespace std;

struct Node{

    public:
    int data;
    Node* next;

    // Constructor with data and next pointer
    public:
    Node(int data1, Node* next1){

        data = data1;
        next = next1;
    }

    // Constructor with only data
    public:
    Node(int data1){

        data = data1;
        next = nullptr;
    }
};

// Convert array to linked list
Node* convertarr2LL(vector<int> &arr){

    // Create head node
    Node* head = new Node(arr[0]);

    Node* mover = head;

    // Create remaining nodes
    for(int i = 1; i < arr.size(); i++){

        Node* temp = new Node(arr[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;
}

// Find length of linked list
int lengthofLL(Node* head){

    int count = 0;

    Node* temp = head;

    while(temp){

        temp = temp->next;

        count++;
    }

    return count;
}

// Search value in linked list
int checkIfpresent(Node* head, int val){

    Node* temp = head;

    while(temp){

        if(temp->data == val)
            return 1;

        temp = temp->next;
    }

    return 0;
}

int main(){

    vector<int> arr = {12,5,8,7};

    // Convert array to linked list
    Node* head = convertarr2LL(arr);

    // Print first node
    cout << head->data << endl;

    // Print length
    cout << lengthofLL(head) << endl;

    // Search element
    cout << checkIfpresent(head,5);
}