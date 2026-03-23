//A  CryptoBox class stores private key material. Define a friend function dumpForAudit(const CryptoBox&) that may inspect private fields for compliance reporting. Prove that regular functions cannot access those fields.
#include <iostream>
using namespace std;

class CryptoBox {
private:
    int privateKey;

public:
    CryptoBox(int key) {
        privateKey = key;
    }

    friend void dumpForAudit(const CryptoBox& cb);
};

void dumpForAudit(const CryptoBox& cb) {
    cout << "Audit Report - Private Key: " << cb.privateKey << endl;
}


void tryAccess(const CryptoBox& cb) {


    cout << "Normal function cannot access private data\n";
}

int main() {
    CryptoBox box(12345);

    dumpForAudit(box);

    tryAccess(box);

    return 0;
}
