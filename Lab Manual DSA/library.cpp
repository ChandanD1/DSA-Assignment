// Singly Linked List:
// 1.Implement Library Catalog
// - Design a system to keep track of books in a library
// -Each node represents a book, and the linked list facilitates easy addition
// and removal of books.
// -Searching of a book by title / author name.
// -Other customisations if you want to add

#include <iostream>
using namespace std;

class Node {
    public:
        string title;
        string author;
        Node * next;

        Node(string title, string author){
            this->title = title;
            this->author = author;
            this->next = NULL;
        }
};

//-----------------------All operations on the linked list----------------------
void addBook(Node*& head, string title, string author) {
    Node* n = new Node(title, author);

    if (head == NULL) {
        head = n;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = n;
        n->next = NULL;
    }
}

void deleteBook(Node*& head, string title, string author) {
    if (head == NULL) {
        cout << "Empty catalog! No book to remove\n";
        return;
    }

    if (head->title == title && head->author == author) {
        Node* deletedNode = head;
        head = head->next;
        delete deletedNode;
        cout << title << " by " << author << " removed from the library." << endl;
        return;
    }

    Node* ptr = head;
    while (ptr->next != NULL && (ptr->next->title != title || ptr->next->author != author)) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        cout << title << " by " << author << " not found in the library." << endl;
        return;
    }

    Node* deletedNode = ptr->next;
    ptr->next = ptr->next->next;

    delete deletedNode;
    cout << title << " by " << author << " removed from the library." << endl;
}


void searchBook(Node * &head, string title){
    if(head == NULL){
        cout << "No book in library itself\n";
        return;
    }

    Node * ptr = head;
    bool isFound = false;

    while(ptr != NULL){
        if(ptr->title == title){
            isFound = true;
            cout << ptr->title << " by " << ptr->author << " found in the library!\n";
            return;
        }
        ptr = ptr->next;
    }

    if(isFound == false){
        cout << ptr->title << " not found in the library :(\n";
    }
}

void searchByAuthor(Node * &head, string author){
    if (head == NULL) {
        cout << "Catalog is empty\nAdd books to search them.\n";
        return;
    }
    
    Node * ptr = head;
    int i = 1;
    cout << "\nBooks by " << ptr->author << " in the library:\n";
    while(ptr != NULL){
        if (ptr->author == author) {
            cout << i << ") " << ptr->title << "\n";
            ptr = ptr->next;
            i++;
        }
    }
}

void viewAllBooks(Node*& head) {
    if (head == NULL) {
        cout << "Catalog is empty\nAdd books to view them.\n";
        return;
    }

    Node* ptr = head;
    cout << "\nBooks in the library:\n";
    int i = 1;
    while (ptr != NULL) {
        cout << i << ") Book title: " << ptr->title << "; Book Author: " << ptr->author << "\n";
        ptr = ptr->next;
        i++;
    }
}

//-------------------------Main function-------------------------

int main(){
    Node * head = NULL;
    int choice;
    string bookTitle,bookAuthor;

    cout << "\nWelcome to the Library Catalog System!\n";
    

    do{
        cout << "\n1) Add Book\n";
        cout << "2) Remove Book\n";
        cout << "3) Search Book\n";
        cout << "4) Search by Author\n";
        cout << "5) View all books\n";
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
            case 1: cout << "Enter book title: ";
                    getline(cin, bookTitle);
                    cout << "Enter book author: ";
                    getline(cin, bookAuthor);
                    addBook(head,bookTitle,bookAuthor);
                    cout << "Book added into catalog successfully!\n";
                    break;
            case 2: cout << "Enter book title: ";
                    getline(cin, bookTitle);
                    cout << "Enter book author: ";
                    getline(cin, bookAuthor);
                    deleteBook(head,bookTitle,bookAuthor);
                    break;
            case 3: cout << "Enter book title: ";
                    getline(cin, bookTitle);
                    searchBook(head,bookTitle);
                    break;
            case 4: cout << "Enter author\'s name: ";
                    getline(cin, bookAuthor);
                    searchByAuthor(head,bookAuthor);
                    break;
            case 5: viewAllBooks(head);
                    break;
            case 6: cout << "Exiting library catalog..Goodbye!\n";
                    break;
            default: cout << "Enter valid choice!\n";
        }
    }while(choice != 6);

}