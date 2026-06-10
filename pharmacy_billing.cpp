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
        // Stores the error message associated with the exception
    string message;
public:
    // Constructor of PharmacyException
    // Receives an error message and stores it in 'message'
    PharmacyException(string msg) {
        message = msg;
    }
    // Getter function
    // Returns the stored error message
    string getMessage() {
        return message;
    }
};
 
// Child exception: when quantity is 0 or negative

class InvalidQuantityException : public PharmacyException {
public:
    // Constructor of InvalidQuantityException
    // Calls the parent class constructor and sends
    // a predefined error message
    InvalidQuantityException() : PharmacyException("Error: Quantity must be greater than zero!") {}
};
 
// Child exception: when price is 0 or negative
class InvalidPriceException : public PharmacyException {
public:
    // Constructor of InvalidPriceException
    // Calls parent constructor with a predefined message
    InvalidPriceException() : PharmacyException("Error: Price must be greater than zero!") {}
};
 
 
// ===========================================================
//   STEP 2: ABSTRACT CLASS  -->  Abstraction
// ===========================================================
 
// Product is the base class of all products
// It is also an abstract class because it contains pure virtual functions
class Product {
// protected means child classes can access these
protected:
 // Stores product name
    string name;
     // Stores price per unit
    double price;
     // Stores quantity of hte product
    int    quantity;
 
public:
    // --- Default Constructor ---
        // Runs when an object is created without arguments

    Product() {
        name     = "Unknown";
        price    = 0.0;
        quantity = 0;
    }
 
    // --- Parameterized Constructor ---
    // Runs when values are provided during object creation
    Product(string n, double p, int q) {
                // Initialize name with n

        name     = n;
                // Initialize price with p

        price    = p;
                // Initialize quantity with q

        quantity = q;
    }
 
    // --- Copy Constructor ---
    // Creates a new object by copying another Product object
    Product(const Product& other) {
                // Copy name from existing object

        name     = other.name;
                // Copy price from existing object

        price    = other.price;
                // Copy quantity from existing object

        quantity = other.quantity;
    }
 
    // --- Getters (Encapsulation) ---
    
    string getName()     { return name;     }// Returns product name
    double getPrice()    { return price;    }// Returns product price
    int    getQuantity() { return quantity; }// Returns product quantity
 
    // --- Setters with validation (Encapsulation) ---
    void setPrice(double p) {// Sets a new price
        if (p <= 0) // Check if price is invalid
        throw InvalidPriceException();// Throw custom exception
        price = p;
    }
    void setQuantity(int q) {// Sets a new quantity
        if (q <= 0) // Check if quantity is invalid
        throw InvalidQuantityException();// Throw custom exception
        quantity = q;// Store valid quantity
    }
 
    // --- Pure Virtual Functions --> makes Product ABSTRACT ---
    // Every child MUST define these

    // Every child class MUST provide its own
    // implementation of calculateCost()
    virtual double calculateCost() = 0;
    virtual void   displayItem()   = 0;// Every child class MUST provide its own
    // implementation of displayItem()
    virtual string getCategory()   = 0;// Every child class MUST provide its own
    // implementation of getCategory()
 
    // Virtual destructor
    virtual ~Product() {} // Ensures proper destruction when deleting
    // derived objects through Product pointers
};

 
// ===========================================================
//   STEP 3: DERIVED CLASS 1 - Medicine  --> single Inheritance
// ===========================================================
 
class Medicine : public Product {
    string medicineType; // Stores the type of medicine
    // Examples: Tablet, Syrup, Injection
 
public:
    // Default Constructor
    // Calls Product's default constructor first
    Medicine() : Product() {
        medicineType = "General";
    }
 
    // Parameterized Constructor // Receives medicine details from user
    Medicine(string n, double p, int q, string type) : Product(n, p, q) {// Calls Product's parameterized constructor
        // and initializes inherited data members
        medicineType = type;// Initialize medicine type
    }
 
    // --- Function Overriding + Runtime Polymorphism ---
    // Overrides Product's pure virtual function
    double calculateCost() override {
         // Total cost = price × quantity
        return price * quantity;
    }
 
    void displayItem() override {// Overrides Product's pure virtual function
        cout << "  [Medicine]  " << name// Display medicine information
             << "  | Type: "     << medicineType// Show medicine type
             << "  | Price: Rs." << price// Show price per unit
             << "  | Qty: "      << quantity// Show quantity
             << "  | Total: Rs." << calculateCost()// Show total cost
             << endl;
    }
 
    string getCategory() override {// Overrides Product's pure virtual function
        return "Medicine (" + medicineType + ")";// Return category name
    }
 // Getter function
    // Returns medicine type
    string getMedicineType() { return medicineType; }
};
 
 
// ===========================================================
//   STEP 4: DERIVED CLASS 2 - Supplement  --> single Inheritance
// ===========================================================
 
class Supplement : public Product {
    double discountPercent;// Stores discount percentage for the supplement

 
public:
    // Default Constructor
    Supplement() : Product() {// Calls Product's default constructor first
        discountPercent = 0.0;// Default discount is 0%
    }
 
    // Parameterized Constructor
    Supplement(string n, double p, int q, double disc) : Product(n, p, q) {
        // Receives supplement details// Calls Product's parameterized constructor
        // to initialize inherited members
        discountPercent = disc;// Store discount percentage

    }
 
    // --- Function Overriding --- (different logic: applies discount)
    double calculateCost() override {// Overrides Product's calculateCost() function
        double gross    = price * quantity;// Calculate original amount before discount
        double discount = gross * discountPercent / 100.0;// Calculate discount amount
        return gross - discount;// Return final amount after discount
    }
 
    void displayItem() override {// Overrides Product's displayItem() function
        double gross = price * quantity;        // Calculate original amount before discount

        cout << "  [Supplement]  " << name// Display supplement information
             << "  | Discount: "   << discountPercent << "%"             // Display discount percentage

             << "  | Price: Rs."   << price// Display price per unit
             << "  | Qty: "        << quantity// Display quantity
             << "  | Total: Rs."   << calculateCost()// Display final amount after discount
             << endl;
    }
 
    string getCategory() override {// Overrides Product's getCategory() function
        return "Supplement";// Return category name
    }
};
 
 
// ===========================================================
//   STEP 5: DERIVED CLASS 3 - TaxedMedicine
//           Inherits Medicine  -->  Multi-level Inheritance // Product → Medicine → TaxedMedicine
// ===========================================================
 
class TaxedMedicine : public Medicine {
    double taxPercent;// Stores tax percentage applied on medicine
 
public:
    TaxedMedicine(string n, double p, int q, string type, double tax)// Receives medicine details and tax rate
        : Medicine(n, p, q, type) { // Calls Medicine constructor first
        // Medicine constructor then calls Product constructor
        taxPercent = tax;// Store tax percentage
  
    }
 
    // --- Overriding again at level 3 ---
    // Overrides calculateCost() again
    // Different logic: adds tax instead of discount
    double calculateCost() override {
        double base = price * quantity;// Calculate original medicine cost
        double tax  = base * taxPercent / 100.0;// Calculate tax amount
        return base + tax;// Return final cost after adding tax
    }
 
    void displayItem() override {// Overrides displayItem()
        double base = price * quantity;// Calculate original amount
        cout << "  [Taxed Medicine]  " << name        // Display taxed medicine information
             << "  | Tax: "            << taxPercent << "%"// Display tax percentage
             << "  | Price: Rs."       << price // Display price per unit
             << "  | Qty: "            << quantity// Display quantity
             << "  | Total: Rs."       << calculateCost()// Display final amount after tax
             << endl;
    }
 
    string getCategory() override {// Overrides getCategory()
        return "Taxed Medicine";// Return category name
    }
};
 
 
// ===========================================================
//   STEP 6: BILLING CLASS  -->  Encapsulation + File Handling
//           Uses array instead of vector (basics level)
// ===========================================================
 
class Basket {
    Product* items[50];   // array of product pointers 
    // Enables runtime polymorphism (base pointer → derived object)
                                    
    int      count;// Keeps track of number of items currently in basket

    string   customerName;// Stores name of the customer
 
public:
    // Constructor: runs automatically when object is created
    Basket() {
        count        = 0; // Initialize basket as empty (no items yet)
        customerName = "Customer";// Default customer name
        for (int i = 0; i < 50; i++)// Loop to initialize all array slots
            items[i] = NULL;// Set all pointers to NULL (no garbage values)
    }
 
    Basket(string name) {// Constructor with customer name parameter
        count        = 0;// Basket starts empty

        customerName = name;// Assign user-provided name
        for (int i = 0; i < 50; i++)// Initialize all array slots
            items[i] = NULL;// Set each pointer to NULL
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
 
