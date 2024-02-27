// Array:
// 1. Inventory Management System:
// - Design an inventory management system for a any small business. Use
// an array to store the quantity of different products in stock. Implement
// functionalities to add products (quantity of product), update quantities,
// display the current inventory.
// - Perform inventory management functionalities and alert when a product
// is running low on stock.
// Note:
// - Each element in the array represents a different product.
// - Allow the addition and removal of products dynamically.

#include <iostream>
#include <string>

using namespace std;

// Define a structure for each product
struct Product {
    string name;
    int quantity;
};

const int MAX_PRODUCTS = 100;
Product inventory[MAX_PRODUCTS];
int numProducts = 0;

// Function to add a product with its quantity
void addProduct(const string& productName, int productQuantity) {
    if (numProducts < MAX_PRODUCTS) {
        inventory[numProducts].name = productName;
        inventory[numProducts].quantity = productQuantity;
        numProducts++;
    } else {
        cout << "Error: Inventory is full. Cannot add more products.\n";
    }
}
void updateQuantity(const string& productName, int newQuantity) {
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].name == productName) {
            inventory[i].quantity = newQuantity;
            cout << "Quantity updated successfully!\n";
            return;
        }
    }
    cout << "Error: Product not found in the inventory.\n";
}
void displayInventory() {
    cout << "\nCurrent Inventory:\n";
    for (int i = 0; i < numProducts; ++i) {
        cout << inventory[i].name << ": " << inventory[i].quantity << " units\n";
    }
}

void checkLowStock(const string& productName, int threshold = 10) {
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].name == productName && inventory[i].quantity < threshold) {
            cout << "Alert: " << productName << " is running low on stock! Remaining: " << inventory[i].quantity << " units\n";
            return;
        }
        else{
            cout << productName << " well in stock!\n";
        }
    }
}

int main() {
    int choice;

    cout << "Welcome to the Inventory Management System! \n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Product\n";
        cout << "2. Update Quantity\n";
        cout << "3. Display Inventory\n";
        cout << "4. Check Low Stock\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string productName;
                int quantity;
                cout << "Enter product name: ";
                cin >> productName;
                cout << "Enter quantity: ";
                cin >> quantity;
                addProduct(productName, quantity);
                break;
            }
            case 2: {
                string productName;
                int newQuantity;
                cout << "Enter product name: ";
                cin >> productName;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                updateQuantity(productName, newQuantity);
                break;
            }
            case 3:
                displayInventory();
                break;
            case 4: {
                string productName;
                cout << "Enter product name: ";
                cin >> productName;
                checkLowStock(productName);
                break;
            }
            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
