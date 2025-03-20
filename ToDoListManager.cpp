/*
This program is to practice the use of a linked list. 
It is to make a To-Do list that can add, remove, and display tasks that need to be done.
*/

#include <iostream>
#include <string>       // for getline

using namespace std;

// Struct for Node
struct Node{
    string data;       // Stores the actual value
    Node* next;     // A pointer pointing to the next node
};

// Class for Node
class todoList{
    // Make head private so it can't be directly accessed outside the class
    private:
        Node* head;

    public:

        todoList() : head(nullptr){};     // Constructor that assigns head to nullptr so it is an empty list upon creation

        // insert function to add elements to the beginning of the linked list
        void insert(string task){
            Node* newNode = new Node();         // Create a new node
            newNode->data = task;               // Assign the task to the new node
            newNode->next =  head;              // Point the new node to the current head
            head = newNode;                     // Move head to point to the new node
        }

        // remove function to remove elements from linked list
        void remove(string task){
            Node* temp = head;      // Start at the head of the list
            Node* previousNode = nullptr;     // Previous node pointer

            // check that list isn't empty
            if(!head){
                cout << "The list is currently empty." << endl;
                return;
            }

            // Check if the task is at the head of the list
            if(head->data == task){
                head = head->next;      // Move head to the next node
                delete temp;            // Delete the old head node
                return;
            }

            // Search through the list until task to be removed is found
            while(temp != nullptr && temp->data != task ){          // Check if end of list or if the data is the task the user entered
                // task is a string, not a pointer, so we can't use the delete key word here. Must delete actual node that the task is in.
                previousNode = temp;        // Keep track of the previous node
                temp = temp->next;
                
            }

            // If we reach the end of th list and don't find the task
            if(temp == nullptr){
                cout << "The task " << task << " is not in the list." << endl;
                return;
            }

            // "Delete" the node (we are skipping it in the list since we can't directly delete it)
            /*
                    temp points to the node we want to remove
                    previousNode points to the node right before temp (our target)
                    We want to change the way the nodes are pointing at the elements to "skip" the target node
                    previousNode->next points to the node after temp
                    temp->next points to the node after the target node
            */
            previousNode->next = temp->next;

        
            // Deallocate temp to free up memory. Dont want memory leaks.
            delete temp; 
            
        }

        // display function to print out our linked lists elements
        void display(){
            Node* temp = head;      // Start at the head of the list

            // Check if the list is empty
            if(!head){
                cout << "The list is currently empty." << endl;
                return;
            }
            
            // Print's each node untill it reaches nullptr (end of list)
            while(temp != nullptr){
                cout << temp -> data << ", ";
                temp = temp -> next;
            }

            // Deallocate temp to free up memory. Dont want memory leaks.
            delete temp;       
        }


};



int main(){
    int userChoice;
    string userTask;
    todoList task;  // Initalize an empty linked list

    cout << "Welcome to our To-Do List Manager!" << endl;

    // print user choices in a do/while loop to print them atleast once.
    do{
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Show Tasks" << endl;
        cout << "\nPlease select a menu choice: " << endl;
        cin >> userChoice;

        // switch case for users choice
        switch (userChoice){
        case 0:
            cout << "Thank you for using our To-Do List Manager, bye!/n";
            break;
        case 1:
            cout << "Enter a task name to add: ";
            cin.ignore();                        // Flush the newline character out of the buffer
            getline(cin, userTask);             // We use getline so we can take in multiple words
            task.insert(userTask);
            break;
        case 2:

            break;
        case 3:
            task.display();
            break;
        default:
            cout << "This is not a valid input, try again./n";
            break;
        }

    }while(userChoice != 0);

    return 0;
}

