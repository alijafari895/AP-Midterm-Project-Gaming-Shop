#include <iostream>
#include <vector>
#include <string>
using namespace std;

class gamingshop {
};

class product {
        protected:
                string name;
                int price;
                double amount;
        public:
                product(string name, int price, double amount) {
                        this->name = name;
                        this->price = price;
                        this->amount = amount;
                }

                void show() {
                        cout << "Name: " << this->name << endl;
                        cout << "Price: " << this->price << endl;
                        cout << "Amount: " << this->amount << endl;
                }

};
class games : public product {
        public:
                games(string name, int price, double amount): product( name , price , amount ){}
};
class consols : public product {
        public:
                consols(string name, int price, double amount) : product( name , price , amount ) {}
};
class headphone : public product {
        public:
                headphone(string name, int price, double amount) : product( name , price , amount ) {}
};


