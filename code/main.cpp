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

};
class consols : public product {
        public:
                consols(string name, int price, double amount) : product( name , price , amount ) {}
};
class headphone : public product {
        public:
                headphone(string name, int price, double amount) : product( name , price , amount ) {}
};







int main() {

}
