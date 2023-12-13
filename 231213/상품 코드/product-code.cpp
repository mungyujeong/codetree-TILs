#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    string name;
    int code;

    Product(string name = "codetree", int code = 50) {
        this->name = name;
        this->code = code;
    }
};

int main() {
    string name;
    int code;
    cin >> name >> code;
    Product p = Product();

    cout << "product " << p.code << " is " << p.name << endl;
    p.code = code; p.name = name;
    cout << "product " << p.code << " is " << p.name << endl;
    return 0;
}