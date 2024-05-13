#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

using namespace std;

// Vendor class represents a vendor supplying items to the store
class Vendor {
private:
    int vendorId;
    string name;
    string address;

public:
    // Constructor to initialize vendor details
    Vendor(int id, const string& n, const string& addr) : vendorId(id), name(n), address(addr) {}

    // Method to return a string representation of the vendor
    string toString() const {
        return "Vendor ID: " + to_string(vendorId) + "\nName: " + name + "\nAddress: " + address;
    }
};

// Item class represents a generic item sold in the store
class Item {
private:
    int itemId;
    std::string name;
    double price;

public:
    // Constructor to initialize item details
    Item(int id, const string& n, double p) : itemId(id), name(n), price(p) {}

    // Method to return a string representation of the item
    string toString() const {
        return "Item ID: " + to_string(itemId) + "\nName: " + name + "\nPrice: R" + to_string(price);
    }
};

// StoreItem class extends Item and adds a vendor property
class StoreItem : public Item {
private:
    Vendor* vendor;

public:
    // Constructor to initialize StoreItem with item details
    StoreItem(int id, const std::string& n, double p) : Item(id, n, p), vendor(nullptr) {}

    // Method to set the vendor of the StoreItem
    void setVendor(Vendor* v) {
        vendor = v;
    }

    // Method to return a string representation of the StoreItem
    string toString(bool includeVendor = false) const {
        if (!includeVendor || vendor == nullptr)
            return Item::toString();
        else
            return Item::toString() + "\n" + vendor->toString();
    }

    // Method to get the vendor name of the StoreItem
    string getVendorName() const {
        if (vendor != nullptr)
            return vendor->toString();
        else
            return "Unknown";
    }
};

int main() {
    // Create vendor instances
    Vendor vendor1(1, "Vendor 1", "123 Khumalo Street");
    Vendor vendor2(2, "Vendor 2", "456 Themba Street");

    // Create StoreItem instances
    StoreItem item1(101, "Item 1", 10.99);
    item1.setVendor(&vendor1);

    StoreItem item2(102, "Item 2", 15.49);
    item2.setVendor(&vendor2);

    // Display item information and vendor name
    cout << "Store Item 1:\n" << item1.toString() << endl;
    cout << "Vendor Name for Item 1: " << item1.getVendorName() << endl;

    cout << "\nStore Item 2:\n" << item2.toString(true) << endl;
    cout << "Vendor Name for Item 2: " << item2.getVendorName() << endl;

    return 0;
}
