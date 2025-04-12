
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

    // نمایش محصولات
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
    void reduceStock(double amount) { quantity -= amount; }
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
    vector<product> all_cart;
    int wallet = 0;
    int Wallet = 0;

public:
    // اضافه کردن محصولات
    void addGame(string name, int price, double amount) {
        all_games.push_back(games(name, price, amount));
    }

    void addConsol(string name, int price, double amount) {
        all_consols.push_back(consols(name, price, amount));
    }

    void addHeadphone(string name, int price, double amount) {
        all_headphones.push_back(headphone(name, price, amount));
    }

    // افزایش کیف پول فروشگاه
    void chargeWallet(int amount) {
        wallet += amount;
        cout << "\n Wallet charged. Current balance: " << wallet << endl;
    }

    // نشان دادن کیف پول فروشگاه
    void showWallet() {
        cout << "\n Shop wallet balance: " << wallet << endl;
    }

    // افزایش کیف پول مشتری
    void chargeWalletCustomer(int Amount) {
        Wallet += Amount;
        cout << "\n Customer wallet charged. Current balance: " << Wallet << endl;
    }

    // نشان دادن کیف پول مشتری
    void showWalletcustomer() {
        cout << "\n Customer wallet balance: " << Wallet << endl;
    }

    // نمایش همه محصولات
    void showAllProducts() {
        cout << "\n Games List:" << endl;
        for (auto& g : all_games) g.show();

        cout << "\n Consoles List:" << endl;
        for (auto& c : all_consols) c.show();

        cout << "\n Headphones List:" << endl;
        for (auto& h : all_headphones) h.show();
    }

    // جستجوی محصولات
    void searchProduct(string keyword) {
        bool found = false;

        for (auto& g : all_games)
            if (g.getName() == keyword) { g.show(); found = true; }

        for (auto& c : all_consols)
            if (c.getName() == keyword) { c.show(); found = true; }

        for (auto& h : all_headphones)
            if (h.getName() == keyword) { h.show(); found = true; }

        if (!found)
            cout << " No product found with that name.\n";
    }

    // ارزش کل محصولات
    void totalValue() {
        int total = 0;

        for (auto& g : all_games) total += g.getPrice() * g.getStock();
        for (auto& c : all_consols) total += c.getPrice() * c.getStock();
        for (auto& h : all_headphones) total += h.getPrice() * h.getStock();

        cout << "\nTotal value of all products: " << total << endl;
    }

    // نمایش محصولات بر اساس دسته‌بندی
    void showByCategory(string cat) {
        if (cat == "game") for (auto& g : all_games) g.show();
        else if (cat == "consol") for (auto& c : all_consols) c.show();
        else if (cat == "headphone") for (auto& h : all_headphones) h.show();
        else cout << "Invalid category!" << endl;
    }

    // حذف بازی
    void removeGame(string name) {
        for (int i = 0; i < all_games.size(); i++) {
            if (all_games[i].getName() == name) {
                all_games.erase(all_games.begin() + i);
                cout << " Game removed.\n";
                return;
            }
        }
        cout << " Game not found.\n";
    }

    // افزودن به سبد خرید
    void addtocart(string name, int price, int amount) {
        all_cart.push_back(product(name, price, amount));
    }

    // نمایش سبد خرید
    void viewcart() {
        for (auto& item : all_cart) item.show();
    }

    // خرید سبد
    void buyCart() {
        int total = 0;
        for (auto& item : all_cart) total += item.getPrice() * item.getStock();

        if (total > Wallet) {
            cout << "Not enough balance. Please charge your wallet.\n";
            return;
        }

        Wallet -= total;
        wallet += total;
        all_cart.clear();
        cout << "Purchase successful!\n";
    }
};

// منوی ادمین
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

        if (choice == 1 || choice == 2 || choice == 3) {
            string name; int price; double qty;
            cout << "Name: "; cin >> name;
            cout << "Price: "; cin >> price;
            cout << "Quantity: "; cin >> qty;

            if (choice == 1) shop.addGame(name, price, qty);
            else if (choice == 2) shop.addConsol(name, price, qty);
            else shop.addHeadphone(name, price, qty);
        } else if (choice == 4) {
            string name;
            cout << "Game name to remove: "; cin >> name;
            shop.removeGame(name);
        } else if (choice == 5) shop.showAllProducts();
        else if (choice == 6) {
            string name;
            cout << "Product name: "; cin >> name;
            shop.searchProduct(name);
        } else if (choice == 7) shop.totalValue();
        else if (choice == 8) {
            int amount;
            cout << "Amount: "; cin >> amount;
            shop.chargeWallet(amount);
        } else if (choice == 9) shop.showWallet();

    } while (choice != 0);
}

// منوی مشتری
void customerMenu(gamingshop& shop) {
    int choice;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. Show all products\n";
        cout << "2. Search product\n";
        cout << "3. Charge customer wallet\n";
        cout << "4. Show customer wallet\n";
        cout << "5. Add to cart\n";
        cout << "6. View cart\n";
        cout << "7. Buy cart\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) shop.showAllProducts();
        else if (choice == 2) {
            string name;
            cout << "Product name: "; cin >> name;
            shop.searchProduct(name);
        } else if (choice == 3) {
            int Amount;
            cout << "Amount: "; cin >> Amount;
            shop.chargeWalletCustomer(Amount);
        } else if (choice == 4) shop.showWalletcustomer();
        else if (choice == 5) {
            string name;
            int price, amount;
            cout << "Name: "; cin >> name;
            cout << "Price: "; cin >> price;
            cout << "Amount: "; cin >> amount;
            shop.addtocart(name, price, amount);
        } else if (choice == 6) shop.viewcart();
        else if (choice == 7) shop.buyCart();

    } while (choice != 0);
}

// صفحه اصلی
int main() {
    gamingshop shop;

    while (true) {
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
                cout << "Incorrect password. Access denied!\n";
            }
        } else if (role == "customer") {
            customerMenu(shop);
        } else {
            cout << "Only admin and customer roles are supported.\n";
        }

    }
    return 0;
}
