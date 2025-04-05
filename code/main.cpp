#include <iostream>
#include <vector>
#include <string>
using namespace std;

class product {
protected:
    string name;
    int price;
    double quntity;
public:
    product(string name, int price, double quntity) {
        this->name = name;
        this->price = price;
        this->quntity = quntity;
    }

    void show() {
        cout << "Name: " << this->name << endl;
        cout << "Price: " << this->price << endl;
        cout << "Quntity: " << this->quntity << endl;
    }

};
class games : public product {
public:
    games(string name, int price, double quntity): product( name , price , quntity ){}
};
class consols : public product {
public:
    consols(string name, int price, double quntity) : product( name , price , quntity ) {}
};
class headphone : public product {
public:
    headphone(string name, int price, double quntity) : product( name , price , quntity ) {}
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
        cout << "💳 کیف پول شارژ شد. موجودی فعلی: " << wallet << endl;
    }

    void showWallet() {
        cout << "💰 موجودی کیف پول: " << wallet << endl;
    }
};


