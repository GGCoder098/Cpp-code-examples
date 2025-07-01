#include <iostream>
#include <memory>
#include <vector>
#include <map>
using namespace std;

class BankOperation{
protected:
double amount;
string description;

public:

virtual ~BankOperation() = default;
BankOperation(double amount, const string &description): amount(amount), description(description){}
    double getAmount() const { return amount; }
    virtual string getType() const = 0;
    virtual string getTransactionDetails() const { return description; }
};

class MoneyTransfer: public BankOperation {
    public:
    MoneyTransfer(double amount): BankOperation(amount, "Money Transfer"){}
    string getType() const override{ return "Money Transfer"; }
    string getTransactionDetails() const override{ return "Money Transfer of " + to_string(amount) + " units";}
};

class GuaranteeAgreement: public BankOperation {
public:
    GuaranteeAgreement(double amount): BankOperation(amount, "Guarantee Agreement"){}
    string getType() const override{ return "Guarantee Agreement"; }
    string getTransactionDetails() const override{ return "Guarantee Agreement of " + to_string(amount) + " units";}
};

class CertificateIssuance: public BankOperation {
public:
    CertificateIssuance(double amount): BankOperation(amount, "Issuance of a Certificate"){}
    string getType() const override{ return "Issuance of a Certificate"; }
    string getTransactionDetails() const override{ return "Issuance of a Certificate of " + to_string(amount) + " units";}
};

class Bank {
private:
    vector<unique_ptr<BankOperation>> transactions;
    int totalTransactions = 0;
    map<string, int> transactionCount;
    map<string, int> totalAmounts;
    public:
    template <typename T, typename... Args>
    void addTransaction(Args&&... args){
        auto transaction = make_unique<T>(forward<Args>(args)...);
        totalTransactions++;
        const string type = transaction->getType();
        ++transactionCount[type];
        totalAmounts[type] += transaction->getAmount();
        transactions.push_back(move(transaction));
    }
    void showTransactionSummary() const {
        cout << "\nTransaction Summary:\n";
        for (const auto& [type,count] : transactionCount) {
            cout << type << ": " << count << " transactions, Total Amount: " << totalAmounts.at(type) << "\n";
        }
    }
    void showTransactionDetails(const int index = NULL) const {
        if (index) {
            cout << transactions[index]->getTransactionDetails() << endl;
        }
        else {
            for (auto &x : transactions) {
                cout << x->getTransactionDetails() << endl;
            }
        }
    }
};

int main() {
    Bank bank;

    bank.addTransaction<MoneyTransfer>(1000);
    bank.addTransaction<GuaranteeAgreement>(1000);
    bank.addTransaction<CertificateIssuance>(1000);
    bank.showTransactionSummary();
    bank.showTransactionDetails(1);
    bank.showTransactionDetails();

}


