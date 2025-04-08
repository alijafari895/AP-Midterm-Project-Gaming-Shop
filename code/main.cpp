#include <iostream>
#include <vector>
#include <string>
using namespace std;

class product {
protected:
    string name;
    int price;
    double quantity;

public:
    product(string name, int price, double quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    void show() const {
        cout << "\n--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "--------------------------" << endl;
    }

    string getName() const { return name; }
    int getPrice() const { return price; }
    double getStock() const { return quantity; }
};

class games : public product {
public:
    games(string name, int price, double quantity) : product(name, price, quantity) {}
};

class consols : public product {
public:
    consols(string name, int price, double quantity) : product(name, price, quantity) {}
};

class headphone : public product {
public:
    headphone(string name, int price, double quantity) : product(name, price, quantity) {}
};

class gamingshop {
private:
    vector<games> all_games;
    vector<consols> all_consols;
    vector<headphone> all_headphones;
    int wallet = 0;

public:
    void addGame(string name, int price, double amount) {
        all_games.push_back(games(name, price, amount));
    }

    void addConsol(string name, int price, double amount) {
        all_consols.push_back(consols(name, price, amount));
    }

    void addHeadphone(string name, int price, double amount) {
        all_headphones.push_back(headphone(name, price, amount));
    }

    void chargeWallet(int amount) {
        wallet += amount;
        cout << "\n💳 Wallet charged. Current balance: " << wallet << endl;
    }

    void showWallet() {
        cout << "\n💰 Shop wallet balance: " << wallet << endl;
    }

    void showAllProducts() {
        cout << "\n🎮 Games List:" << endl;
        for (int i = 0; i < all_games.size(); i++) {
            all_games[i].show();
        }

        cout << "\n🕹️ Consoles List:" << endl;
        for (int i = 0; i < all_consols.size(); i++) {
            all_consols[i].show();
        }

        cout << "\n🎧 Headphones List:" << endl;
        for (int i = 0; i < all_headphones.size(); i++) {
            all_headphones[i].show();
        }
    }

    void searchProduct(string keyword) {
        bool found = false;

        for (int i = 0; i < all_games.size(); i++) {
            if (all_games[i].getName() == keyword) {
                all_games[i].show();
                found = true;
            }
        }

        for (int i = 0; i < all_consols.size(); i++) {
            if (all_consols[i].getName() == keyword) {
                all_consols[i].show();
                found = true;
            }
        }

        for (int i = 0; i < all_headphones.size(); i++) {
            if (all_headphones[i].getName() == keyword) {
                all_headphones[i].show();
                found = true;
            }
        }

        if (!found)
            cout << "❌ No product found with that name.\n";
    }

    void totalValue() {
        int total = 0;

        for (int i = 0; i < all_games.size(); i++) {
            total += all_games[i].getPrice() * all_games[i].getStock();
        }

        for (int i = 0; i < all_consols.size(); i++) {
            total += all_consols[i].getPrice() * all_consols[i].getStock();
        }

        for (int i = 0; i < all_headphones.size(); i++) {
            total += all_headphones[i].getPrice() * all_headphones[i].getStock();
        }

        cout << "\n💵 Total value of all products: " << total << endl;
    }

    void showByCategory(string cat) {
        if (cat == "game") {
            for (int i = 0; i < all_games.size(); i++) {
                all_games[i].show();
            }
        } else if (cat == "consol") {
            for (int i = 0; i < all_consols.size(); i++) {
                all_consols[i].show();
            }
        } else if (cat == "headphone") {
            for (int i = 0; i < all_headphones.size(); i++) {
                all_headphones[i].show();
            }
        } else {
            cout << "❌ Invalid category!" << endl;
        }
    }

    void removeGame(string name) {
        for (int i = 0; i < all_games.size(); i++) {
            if (all_games[i].getName() == name) {
                all_games.erase(all_games.begin() + i);
                cout << "✅ Game removed.\n";
                return;
            }
        }
        cout << "❌ Game not found.\n";
    }
};

void adminMenu(gamingshop& shop) {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add game\n";
        cout << "2. Add console\n";
        cout << "3. Add headphone\n";
        cout << "4. Remove game\n";
        cout << "5. Show all products\n";
        cout << "6. Search product\n";
        cout << "7. Total inventory value\n";
        cout << "8. Charge shop wallet\n";
        cout << "9. Show shop wallet\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name; int price; double qty;
            cout << "Game name: "; cin >> name;
            cout << "Price: "; cin >> price;
            cout << "Quantity: "; cin >> qty;
            shop.addGame(name, price, qty);
        } else if (choice == 2) {
            string name; int price; double qty;
            cout << "Console name: "; cin >> name;
            cout << "Price: "; cin >> price;
            cout << "Quantity: "; cin >> qty;
            shop.addConsol(name, price, qty);
        } else if (choice == 3) {
            string name; int price; double qty;
            cout << "Headphone name: "; cin >> name;
            cout << "Price: "; cin >> price;
            cout << "Quantity: "; cin >> qty;
            shop.addHeadphone(name, price, qty);
        } else if (choice == 4) {
            string name;
            cout << "Game name to remove: "; cin >> name;
            shop.removeGame(name);
        } else if (choice == 5) {
            shop.showAllProducts();
        } else if (choice == 6) {
            string name;
            cout << "Product name: "; cin >> name;
            shop.searchProduct(name);
        } else if (choice == 7) {
            shop.totalValue();
        } else if (choice == 8) {
            int amount;
            cout << "Amount: "; cin >> amount;
            shop.chargeWallet(amount);
        } else if (choice == 9) {
            shop.showWallet();
        }

    } while (choice != 0);
}

int main() {
    gamingshop shop;
    string role;

    cout << "Login as (admin/customer): ";
    cin >> role;

    if (role == "admin") {
        string pass;
        cout << "Password: ";
        cin >> pass;
        if (pass == "admin1admin") {
            adminMenu(shop);
        } else {
            cout << "❌ Incorrect password. Access denied!\n";
        }
    } else {
        cout << "⛔ Only admin menu is implemented.\n";
    }

    return 0;
}
