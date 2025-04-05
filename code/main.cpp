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
                virtual void show() {
                        cout << "نام: " << name << " | قیمت: " << price << " | موجودی: " << amount << endl;

};
class games : public product {
        public:
                games(string name, int price, double amount): product( name , price , amount ){}

                void show() override {
                        cout << " Game | " << name << " | " << price << " | " << amount << endl;
                }

};
class consols : public product {
        public:
                consols(string name, int price, double amount) : product( name , price , amount ) {}

                void show() override {
                        cout << " Consol | " << name << " | " << price << " | " << amount << endl;
                }

};
class headphone : public product {
        public:
                headphone(string name, int price, double amount) : product( name , price , amount ) {}

                void show() override {
                        cout << "Headphon | " << name << " | " << price << " | " << amount << endl;
                }
};







int main() {

}
