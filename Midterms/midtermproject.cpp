#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

class Item {
private:
    int id;
    int quantity;
    string name;
    string category;
    double price;

public:
    Item(string n, string c, int q, double p, int i) {
        this->id = i;
        this->quantity = q;
        this->name = n;
        this->category = c;
        this->price = p;
    }

    void setQuantity(int q) {
        this->quantity = q;
    }

    void setPrice(double p) {
        this->price = p;
    }

    int getId() const {
        return id;
    }

    int getQuantity() const {
        return quantity;
    }

    string getName() const {
        return name;
    }

    string getCategory() const {
        return category;
    }

    double getPrice() const {
        return price;
    }

    void display() const {
        cout << id << "\t\t " << name << "\t\t " << quantity << "\t\t " << price << "\t\t " << category << endl;
    }
};

vector<Item> items;
int autoID = 1;

void header() {
    cout << "ID\t\tName\t\tQuantity\t\tPrice\t\tCategory" << endl;
}

void addItem() {
    string name, category;
    int quantity;
    double price;

    cin.ignore();
    bool validInput;

    do {
        validInput = true;

        cout << "Enter Name of Product: ";
        getline(cin, name);
        bool validName = true;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                validName = false;
                break;
            }
        }
        if (!validName) {
            cout << "Invalid name. Only alphabetic characters are allowed.\n";
            validInput = false;
            continue;
        }

        cout << "Enter Category: ";
        getline(cin, category);
        bool validCategory = true;
        for (char c : category) {
            if (!isalpha(c) && c != ' ') {
                validCategory = false;
                break;
            }
        }
        if (!validCategory) {
            cout << "Invalid category. Only alphabetic characters are allowed.\n";
            validInput = false;
            continue;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;
        if (cin.fail() || quantity < 0) {
            cout << "Invalid quantity. Please enter a valid positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
            continue;
        }

        cout << "Enter Product Price: ";
        cin >> price;
        if (cin.fail() || price < 0) {
            cout << "Invalid price. Please enter a valid positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }

    } while (!validInput);

    items.push_back(Item(name, category, quantity, price, autoID));
    autoID++;
    cout << "Item added successfully!" << endl;
}

void updateItem() {
    int id;
    bool ifFound = false;
    bool validInput;

    do {
        validInput = true;
        cout << "Input item ID: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Invalid ID input. Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == id) {
            int updateItemChoice;
            cout << "Price[1] or Quantity[2]: ";
            cin >> updateItemChoice;

            while (true) {
                if (updateItemChoice == 1) {
                    double oldPrice = items[i].getPrice();
                    double newPrice;

                    do {
                        validInput = true;
                        cout << "New Price: ";
                        cin >> newPrice;
                        if (cin.fail() || newPrice < 0) {
                            cout << "Invalid price. Please enter a valid positive number.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            validInput = false;
                        }
                    } while (!validInput);

                    items[i].setPrice(newPrice);
                    cout << "Price of " << items[i].getName() << " is updated from " << oldPrice << " to " << newPrice << endl;
                    break;
                }
                else if (updateItemChoice == 2) {
                    int oldQuantity = items[i].getQuantity();
                    int newQuantity;

                    do {
                        validInput = true;
                        cout << "New Quantity: ";
                        cin >> newQuantity;
                        if (cin.fail() || newQuantity < 0) {
                            cout << "Invalid quantity. Please enter a valid positive number.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            validInput = false;
                        }
                    } while (!validInput);

                    items[i].setQuantity(newQuantity);
                    cout << "Quantity of " << items[i].getName() << " is updated from " << oldQuantity << " to " << newQuantity << endl;
                    break;
                }
                else {
                    cout << "Invalid Input" << endl;
                }
            }
            ifFound = true;
            break;
        }
    }
    if (!ifFound) {
        cout << "Item not found!" << endl;
    }
}

void removeItem() {
    int id;
    bool ifFound = false;
    bool validInput;

    do {
        validInput = true;
        cout << "Input item ID: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Invalid ID input. Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == id) {
            cout << "Item " << items[i].getName() << " has been removed from the inventory" << endl;
            items.erase(items.begin() + i);
            ifFound = true;
            break;
        }
    }

    if (!ifFound) {
        cout << "Item not found!" << endl;
    }
}

void displayAllItems() {
    header();
    for (int i = 0; i < items.size(); i++) {
        items[i].display();
    }
}

void displayByID() {
    int id;
    bool ifFound = false;
    bool validInput;

    do {
        validInput = true;
        cout << "\nInput item ID: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Invalid ID input. Please enter a valid ID.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    header();
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getId() == id) {
            items[i].display();
            ifFound = true;
            break;
        }
    }

    if (!ifFound) {
        cout << "\nItem not found!" << endl;
    }
}

void displayByCategory() {
    string category;
    bool ifFound = false;
    bool validInput;

    do {
        validInput = true;
        cout << "\nInput item Category: ";
        cin >> category;

        if (category.empty()) {
            cout << "Category cannot be empty.\n";
            validInput = false;
        }
    } while (!validInput);

    header();
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getCategory() == category) {
            items[i].display();
            ifFound = true;
        }
    }

    if (!ifFound) {
        cout << "\nNo items found!" << endl;
    }
}

void displaySearchItem() {
    int choice;
    bool validInput;

    do {
        validInput = true;
        cout << "Search Item: " << endl;
        cout << "ID[1] or Category[2]: ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid input. Please enter 1 for ID or 2 for Category.\n";
            validInput = false;
        }
    } while (!validInput);

    if (choice == 1) {
        displayByID();
    }
    else {
        displayByCategory();
    }
}

void displayLowStock() {
    if (items.empty()) {
        cout << "\nInventory is empty. No items to display.\n";
        return;
    }

    bool ifFound = false;
    header();
    for (int i = 0; i < items.size(); i++) {
        if (items[i].getQuantity() <= 10) {
            items[i].display();
            ifFound = true;
        }
    }

    if (!ifFound) {
        cout << "\nNo low stock items found!" << endl;
    }
}

void sortItems() {
    int sortBy, order;
    bool validInput;

    do {
        validInput = true;
        cout << "\nSort by Quantity[1] or Price[2]: ";
        cin >> sortBy;
        if (cin.fail() || (sortBy != 1 && sortBy != 2)) {
            cout << "Invalid input. Please enter 1 for Quantity or 2 for Price.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    do {
        validInput = true;
        cout << "Ascending[1] or Descending[2]: ";
        cin >> order;
        if (cin.fail() || (order != 1 && order != 2)) {
            cout << "Invalid input. Please enter 1 for Ascending or 2 for Descending.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    } while (!validInput);

    if (sortBy == 1) {
        if (order == 1) {
            sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                return a.getQuantity() < b.getQuantity();
            });
        }
        else {
            sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                return a.getQuantity() > b.getQuantity();
            });
        }
    }
    else {
        if (order == 1) {
            sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                return a.getPrice() < b.getPrice();
            });
        }
        else {
            sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                return a.getPrice() > b.getPrice();
            });
        }
    }

    cout << "\nItems sorted successfully!\n";
    displayAllItems();
}

int main() {
    int choice;

    do {
        cout << "\n--------------------------" << endl;
        cout << "Menu" << endl;
        cout << "1 - Add Item" << endl;
        cout << "2 - Update Item" << endl;
        cout << "3 - Remove Item" << endl;
        cout << "4 - Display All Items" << endl;
        cout << "5 - Search Item" << endl;
        cout << "6 - Sort Items" << endl;
        cout << "7 - Display Low Stock Items" << endl;
        cout << "8 - Exit" << endl;
        cout << "--------------------------" << endl;

        bool validInput;
        do {
            validInput = true;
            cout << "\nEnter your Choice: ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 8) {
                cout << "Invalid input. Please enter a valid menu choice between 1 and 8.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = false;
            }
        } while (!validInput);

        if (choice == 1) {
            addItem();
        }
        else if (choice == 2) {
            updateItem();
        }
        else if (choice == 3) {
            removeItem();
        }
        else if (choice == 4) {
            displayAllItems();
        }
        else if (choice == 5) {
            displaySearchItem();
        }
        else if (choice == 6) {
            sortItems();
        }
        else if (choice == 7) {
            displayLowStock();
        }
        else if (choice == 8) {
            cout << "Thank you!" << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}
