/*
 ************************************************************
 *         PHARMACY BILLING SYSTEM
 *         Semester End Project - C++
 *
 *  OOP Concepts Covered:
 *  1.  Classes & Objects
 *  2.  Encapsulation
 *  3.  Abstraction  (abstract class)
 *  4.  Inheritance  (single + multilevel)
 *  5.  Polymorphism (runtime + compile-time)
 *  6.  Constructors (default, parameterized, copy)
 *  7.  Function Overloading
 *  8.  Function Overriding
 *  9.  Exception Handling
 *  10. File Handling  (save bill to file)
 ************************************************************
*/
 
#include <iostream>
#include <fstream>    // for file handling
#include <string>
using namespace std;
 
 
// ===========================================================
//   STEP 1: CUSTOM EXCEPTIONS  -->  Exception Handling
// ===========================================================
 
// Base exception class
class PharmacyException {
    string message;
public:
    PharmacyException(string msg) {
        message = msg;
    }
    string getMessage() {
        return message;
    }
};
 
// Child exception: when quantity is 0 or negative
class InvalidQuantityException : public PharmacyException {
public:
    InvalidQuantityException() : PharmacyException("Error: Quantity must be greater than zero!") {}
};
 
// Child exception: when price is 0 or negative
class InvalidPriceException : public PharmacyException {
public:
    InvalidPriceException() : PharmacyException("Error: Price must be greater than zero!") {}
};
 
 
// ===========================================================
//   STEP 2: ABSTRACT CLASS  -->  Abstraction
// ===========================================================
 
class Product {
// protected means child classes can access these
protected:
    string name;
    double price;
    int    quantity;
 
public:
    // --- Default Constructor ---
    Product() {
        name     = "Unknown";
        price    = 0.0;
        quantity = 0;
    }
 
    // --- Parameterized Constructor ---
    Product(string n, double p, int q) {
        name     = n;
        price    = p;
        quantity = q;
    }
 
    // --- Copy Constructor ---
    Product(const Product& other) {
        name     = other.name;
        price    = other.price;
        quantity = other.quantity;
    }
 
    // --- Getters (Encapsulation) ---
    string getName()     { return name;     }
    double getPrice()    { return price;    }
    int    getQuantity() { return quantity; }
 
    // --- Setters with validation (Encapsulation) ---
    void setPrice(double p) {
        if (p <= 0) throw InvalidPriceException();
        price = p;
    }
    void setQuantity(int q) {
        if (q <= 0) throw InvalidQuantityException();
        quantity = q;
    }
 
    // --- Pure Virtual Functions --> makes Product ABSTRACT ---
    // Every child MUST define these
    virtual double calculateCost() = 0;
    virtual void   displayItem()   = 0;
    virtual string getCategory()   = 0;
 
    // Virtual destructor (good practice)
    virtual ~Product() {}
};

 
// ===========================================================
//   STEP 3: DERIVED CLASS 1 - Medicine  -->  Inheritance
// ===========================================================
 
class Medicine : public Product {
    string medicineType;   // e.g. Tablet, Syrup, Injection
 
public:
    // Default Constructor
    Medicine() : Product() {
        medicineType = "General";
    }
 
    // Parameterized Constructor
    Medicine(string n, double p, int q, string type) : Product(n, p, q) {
        medicineType = type;
    }
 
    // --- Function Overriding + Runtime Polymorphism ---
    double calculateCost() override {
        return price * quantity;
    }
 
    void displayItem() override {
        cout << "  [Medicine]  " << name
             << "  | Type: "     << medicineType
             << "  | Price: Rs." << price
             << "  | Qty: "      << quantity
             << "  | Total: Rs." << calculateCost()
             << endl;
    }
 
    string getCategory() override {
        return "Medicine (" + medicineType + ")";
    }
 
    string getMedicineType() { return medicineType; }
};
 
 
// ===========================================================
//   STEP 4: DERIVED CLASS 2 - Supplement  -->  Inheritance
// ===========================================================
 
class Supplement : public Product {
    double discountPercent;
 
public:
    // Default Constructor
    Supplement() : Product() {
        discountPercent = 0.0;
    }
 
    // Parameterized Constructor
    Supplement(string n, double p, int q, double disc) : Product(n, p, q) {
        discountPercent = disc;
    }
 
    // --- Function Overriding --- (different logic: applies discount)
    double calculateCost() override {
        double gross    = price * quantity;
        double discount = gross * discountPercent / 100.0;
        return gross - discount;
    }
 
    void displayItem() override {
        double gross = price * quantity;
        cout << "  [Supplement]  " << name
             << "  | Discount: "   << discountPercent << "%"
             << "  | Price: Rs."   << price
             << "  | Qty: "        << quantity
             << "  | Total: Rs."   << calculateCost()
             << endl;
    }
 
    string getCategory() override {
        return "Supplement";
    }
};
 
 
// ===========================================================
//   STEP 5: DERIVED CLASS 3 - TaxedMedicine
//           Inherits Medicine  -->  Multi-level Inheritance
// ===========================================================
 
class TaxedMedicine : public Medicine {
    double taxPercent;
 
public:
    TaxedMedicine(string n, double p, int q, string type, double tax)
        : Medicine(n, p, q, type) {
        taxPercent = tax;
    }
 
    // --- Overriding again at level 3 ---
    double calculateCost() override {
        double base = price * quantity;
        double tax  = base * taxPercent / 100.0;
        return base + tax;
    }
 
    void displayItem() override {
        double base = price * quantity;
        cout << "  [Taxed Medicine]  " << name
             << "  | Tax: "            << taxPercent << "%"
             << "  | Price: Rs."       << price
             << "  | Qty: "            << quantity
             << "  | Total: Rs."       << calculateCost()
             << endl;
    }
 
    string getCategory() override {
        return "Taxed Medicine";
    }
};
 
 
// ===========================================================
//   STEP 6: BILLING CLASS  -->  Encapsulation + File Handling
//           Uses array instead of vector (basics level)
// ===========================================================
 
class Basket {
    Product* items[50];   // array of product pointers (max 50 items)
    int      count;
    string   customerName;
 
public:
    // Constructor
    Basket() {
        count        = 0;
        customerName = "Customer";
        for (int i = 0; i < 50; i++)
            items[i] = NULL;
    }
 
    Basket(string name) {
        count        = 0;
        customerName = name;
        for (int i = 0; i < 50; i++)
            items[i] = NULL;
    }
 
    // Add product to basket
    void addItem(Product* p) {
        if (count >= 50) {
            cout << "  Basket is full!" << endl;
            return;
        }
        items[count] = p;
        count++;
        cout << "  Item added to basket!" << endl;
    }
 
    // Show all items on screen  -->  Runtime Polymorphism
    void showBasket() {
        if (count == 0) {
            cout << "\n  Your basket is empty." << endl;
            return;
        }
        cout << "\n  -------- Items in Basket --------" << endl;
        for (int i = 0; i < count; i++) {
            cout << "  " << (i+1) << ". ";
            items[i]->displayItem();   // polymorphism: correct version called
        }
        cout << "  ---------------------------------" << endl;
    }
 
    // Calculate grand total
    double getTotal() {
        double total = 0;
        for (int i = 0; i < count; i++)
            total += items[i]->calculateCost();
        return total;
    }
 
    int getCount() { return count; }
 
    // --- Function Overloading ---
    // Save bill to file - version 1: use default filename
    void saveBill() {
        saveBill("pharmacy_bill.txt");
    }
 
    // Save bill to file - version 2: user gives filename
    void saveBill(string filename) {
        if (count == 0) {
            cout << "\n  Nothing to save. Basket is empty!" << endl;
            return;
        }
 
        ofstream file(filename.c_str());   // open file for writing
 
        if (!file) {
            cout << "\n  Error: Could not create file!" << endl;
            return;
        }
 
        file << "============================================" << endl;
        file << "        AL-SHIFA PHARMACY" << endl;
        file << "        Your Health, Our Priority" << endl;
        file << "============================================" << endl;
        file << "Customer : " << customerName << endl;
        file << "--------------------------------------------" << endl;
        file << "No.  Item Name          Category     Amount" << endl;
        file << "--------------------------------------------" << endl;
 
        for (int i = 0; i < count; i++) {
            file << (i+1) << ".   "
                 << items[i]->getName()     << "\t\t"
                 << items[i]->getCategory() << "\t"
                 << "Rs." << items[i]->calculateCost()
                 << endl;
        }
 
        file << "--------------------------------------------" << endl;
        file << "TOTAL AMOUNT PAYABLE:  Rs." << getTotal()     << endl;
        file << "============================================" << endl;
        file << "   Thank you! Get well soon." << endl;
        file << "============================================" << endl;
 
        file.close();   // always close the file
 
        cout << "\n  Bill saved to file: " << filename << endl;
    }
 
    // --- CHECKOUT: show full bill on screen + save to file ---
    void checkout() {
        if (count == 0) {
            cout << "\n  Cannot checkout. Your basket is empty!" << endl;
            return;
        }
 
        double total        = getTotal();
        double amountPaid   = 0;
        double change       = 0;
 
        // ---- Print bill on screen ----
        cout << "\n";
        cout << "  ============================================" << endl;
        cout << "           AL-SHIFA PHARMACY"                   << endl;
        cout << "        Your Health, Our Priority"              << endl;
        cout << "  ============================================" << endl;
        cout << "  Customer : " << customerName                  << endl;
        cout << "  --------------------------------------------" << endl;
        cout << "  No.  Item                   Amount"          << endl;
        cout << "  --------------------------------------------" << endl;
 
        for (int i = 0; i < count; i++) {
            cout << "  " << (i+1) << ".   "
                 << items[i]->getName()
                 << "\t\t Rs." << items[i]->calculateCost()
                 << endl;
        }
 
        cout << "  --------------------------------------------" << endl;
        cout << "  Total Items        : " << count              << endl;
        cout << "  --------------------------------------------" << endl;
        cout << "  TOTAL AMOUNT       : Rs." << total           << endl;
        cout << "  --------------------------------------------" << endl;
 
        // ---- Ask how much customer is paying ----
        cout << "\n  Enter amount paid by customer: Rs.";
        cin  >> amountPaid;
 
        if (amountPaid < total) {
            throw PharmacyException("Error: Amount paid is less than total bill!");
        }
 
        change = amountPaid - total;
 
        cout << "\n  --------------------------------------------" << endl;
        cout << "  Amount Paid        : Rs." << amountPaid       << endl;
        cout << "  Change to Return   : Rs." << change           << endl;
        cout << "  --------------------------------------------" << endl;
        cout << "  ** Payment Successful! **"                    << endl;
        cout << "  ============================================" << endl;
        cout << "       Thank you! Get well soon."               << endl;
        cout << "  ============================================" << endl;
 
        // ---- Also save to file automatically ----
        ofstream file("pharmacy_bill.txt");
        if (file) {
            file << "============================================" << endl;
            file << "        AL-SHIFA PHARMACY"                   << endl;
            file << "        Your Health, Our Priority"           << endl;
            file << "============================================" << endl;
            file << "Customer : " << customerName                 << endl;
            file << "--------------------------------------------" << endl;
            file << "No.  Item                    Amount"         << endl;
            file << "--------------------------------------------" << endl;
 
            for (int i = 0; i < count; i++) {
                file << (i+1) << ".   "
                     << items[i]->getName()     << "\t\t"
                     << items[i]->getCategory() << "\t"
                     << "Rs." << items[i]->calculateCost()
                     << endl;
            }
 
            file << "--------------------------------------------" << endl;
            file << "Total Items        : " << count              << endl;
            file << "--------------------------------------------" << endl;
            file << "TOTAL AMOUNT       : Rs." << total           << endl;
            file << "Amount Paid        : Rs." << amountPaid      << endl;
            file << "Change Returned    : Rs." << change          << endl;
            file << "============================================" << endl;
            file << "   Thank you! Get well soon."                << endl;
            file << "============================================" << endl;
            file.close();
 
            cout << "\n  Receipt saved to: pharmacy_bill.txt" << endl;
        }
    }
 
    // Destructor: free memory
    ~Basket() {
        for (int i = 0; i < count; i++)
            delete items[i];
    }
};
 
 
// ===========================================================
//   HELPER FUNCTIONS
// ===========================================================
 
void printLine() {
    cout << "  ==========================================" << endl;
}
 
void printMenu() {
    cout << "\n";
    printLine();
    cout << "       AL-SHIFA PHARMACY BILLING SYSTEM" << endl;
    printLine();
    cout << "  1. Add Medicine"          << endl;
    cout << "  2. Add Supplement"        << endl;
    cout << "  3. Add Taxed Medicine"    << endl;
    cout << "  4. View Basket"           << endl;
    cout << "  5. View Total Amount"     << endl;
    cout << "  6. Save Bill to File"           << endl;
    cout << "  7. Save Bill (Custom filename)" << endl;
    cout << "  8. CHECKOUT (Pay & Print Bill)" << endl;
    cout << "  0. Exit"                        << endl;
    printLine();
    cout << "  Enter choice: ";
}
 
 
// ===========================================================
//   MAIN FUNCTION
// ===========================================================
 
int main() {
    string custName;
 
    cout << "\n";
    printLine();
    cout << "    Welcome to AL-SHIFA Pharmacy System" << endl;
    printLine();
    cout << "  Enter your name: ";
    cin.ignore();
    getline(cin, custName);
 
    Basket basket(custName);   // Object created with parameterized constructor
 
    int choice;
 
    do {
        printMenu();
        cin >> choice;
 
        try {
 
            // ---- Add Medicine ----
            if (choice == 1) {
                string name, type;
                double price;
                int    qty;
 
                cout << "\n  --- Add Medicine ---" << endl;
                cout << "  Medicine Name  : "; cin.ignore(); getline(cin, name);
                cout << "  Type (Tablet/Syrup/Injection): "; getline(cin, type);
                cout << "  Price per unit : Rs."; cin >> price;
                cout << "  Quantity       : "; cin >> qty;
 
                if (price <= 0) throw InvalidPriceException();
                if (qty   <= 0) throw InvalidQuantityException();
 
                Medicine* med = new Medicine(name, price, qty, type);
                basket.addItem(med);
            }
 
            // ---- Add Supplement ----
            else if (choice == 2) {
                string name;
                double price, discount;
                int    qty;
 
                cout << "\n  --- Add Supplement ---" << endl;
                cout << "  Supplement Name : "; cin.ignore(); getline(cin, name);
                cout << "  Price per unit  : Rs."; cin >> price;
                cout << "  Quantity        : "; cin >> qty;
                cout << "  Discount (%)    : "; cin >> discount;
 
                if (price    <= 0) throw InvalidPriceException();
                if (qty      <= 0) throw InvalidQuantityException();
                if (discount < 0)  throw PharmacyException("Error: Discount cannot be negative!");
 
                Supplement* sup = new Supplement(name, price, qty, discount);
                basket.addItem(sup);
            }
 
            // ---- Add Taxed Medicine ----
            else if (choice == 3) {
                string name, type;
                double price, tax;
                int    qty;
 
                cout << "\n  --- Add Taxed Medicine ---" << endl;
                cout << "  Medicine Name  : "; cin.ignore(); getline(cin, name);
                cout << "  Type           : "; getline(cin, type);
                cout << "  Price per unit : Rs."; cin >> price;
                cout << "  Quantity       : "; cin >> qty;
                cout << "  Tax Rate (%)   : "; cin >> tax;
 
                if (price <= 0) throw InvalidPriceException();
                if (qty   <= 0) throw InvalidQuantityException();
                if (tax   < 0)  throw PharmacyException("Error: Tax cannot be negative!");
 
                TaxedMedicine* tm = new TaxedMedicine(name, price, qty, type, tax);
                basket.addItem(tm);
            }
 
            // ---- View Basket ----
            else if (choice == 4) {
                basket.showBasket();
            }
 
            // ---- View Total ----
            else if (choice == 5) {
                if (basket.getCount() == 0) {
                    cout << "\n  Basket is empty. Add items first." << endl;
                } else {
                    cout << "\n  Total Items  : " << basket.getCount() << endl;
                    cout << "  Total Amount : Rs." << basket.getTotal() << endl;
                }
            }
 
            // ---- Save Bill (default filename) ----
            else if (choice == 6) {
                basket.showBasket();
                cout << "\n  Total Amount : Rs." << basket.getTotal() << endl;
                basket.saveBill();   // calls overloaded version 1
            }
 
            // ---- Save Bill (custom filename) ----
            else if (choice == 7) {
                string fname;
                cout << "\n  Enter filename (e.g. mybill.txt): ";
                cin.ignore();
                getline(cin, fname);
                basket.showBasket();
                cout << "\n  Total Amount : Rs." << basket.getTotal() << endl;
                basket.saveBill(fname);   // calls overloaded version 2
            }
 
            // ---- CHECKOUT ----
            else if (choice == 8) {
                basket.checkout();
            }
 
            else if (choice == 0) {
                cout << "\n  Thank you, " << custName << "! Visit again. Goodbye!" << endl;
            }
 
            else {
                cout << "\n  Invalid choice. Try again." << endl;
            }
 
        }
        // Catch our custom exceptions
        catch (PharmacyException& e) {
            cout << "\n  " << e.getMessage() << endl;
        }
        // Catch anything unexpected
        catch (...) {
            cout << "\n  Something went wrong! Please try again." << endl;
        }
 
    } while (choice != 0);
 
    return 0;
}
 
