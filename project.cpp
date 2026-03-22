
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_ITEMS = 100;

/* ================= BASE CLASS ================= */
class Item {
protected:
    int id;
    char name[30];
    int quantity;
    float price;

public:
    Item() {
        id = 0;
        quantity = 0;
        price = 0;
        strcpy(name, "");
    }

    virtual void input() {
        cout << "Enter Item ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Item Name: ";
        cin.getline(name, 30);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    virtual void display() {
        cout << id << "\t" << name << "\t" << quantity << "\t" << price << endl;
    }

    int getId() {
        return id;
    }

    int getQuantity() {
        return quantity;
    }

    void updateQuantity(int q) {
        quantity = q;
    }
};

/* ================= DERIVED CLASS ================= */
class Product : public Item {
private:
    char category[20];

public:
    void input() {
        Item::input();
        cin.ignore();
        cout << "Enter Category: ";
        cin.getline(category, 20);
    }

    void display() {
        Item::display();
        cout << "Category: " << category << endl;
    }
};

/* ================= INVENTORY CLASS ================= */
class Inventory {
private:
    Product items[MAX_ITEMS];
    int count;

public:
    Inventory() {
        count = 0;
        loadFromFile();
    }

    void addItem() {
        if (count >= MAX_ITEMS) {
            cout << "Inventory Full!\n";
            return;
        }

        items[count].input();
        count++;
        saveToFile();
        cout << "Item added successfully.\n";
    }

    void viewItems() {
        if (count == 0) {
            cout << "Inventory empty.\n";
            return;
        }

        cout << "\nID\tName\tQty\tPrice\n";
        for (int i = 0; i < count; i++) {
            items[i].display();
            cout << "---------------------\n";
        }
    }

    void updateStock() {
        int searchId;
        cout << "Enter Item ID to update: ";
        cin >> searchId;

        for (int i = 0; i < count; i++) {
            if (items[i].getId() == searchId) {
                int newQty;
                cout << "Enter new quantity: ";
                cin >> newQty;
                items[i].updateQuantity(newQty);
                saveToFile();
                cout << "Stock updated.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void removeItem() {
        int searchId;
        cout << "Enter Item ID to remove: ";
        cin >> searchId;

        for (int i = 0; i < count; i++) {
            if (items[i].getId() == searchId) {
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                }
                count--;
                saveToFile();
                cout << "Item removed.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void saveToFile() {
        ofstream file("inventory.txt");
        file << count << endl;

        for (int i = 0; i < count; i++) {
            file.write((char*)&items[i], sizeof(Product));
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file("inventory.txt");
        if (!file)
            return;

        file >> count;
        file.ignore();

        for (int i = 0; i < count; i++) {
            file.read((char*)&items[i], sizeof(Product));
        }
        file.close();
    }
};

/* ================= MAIN FUNCTION ================= */
int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Update Stock\n";
         cout << "4. Remove Item\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inventory.addItem();
            break;
        case 2:
            inventory.viewItems();
            break;
        case 3:
            inventory.updateStock();
            break;
        case 4:
            inventory.removeItem();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
