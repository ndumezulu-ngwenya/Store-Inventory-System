# Store-Inventory-System
Designing a simple console application in C++ that models an online store inventory system, based on the requirements and class relationships described below:

Class Descriptions:
Item: Represents a generic item sold in the online store. Each item is characterized by a unique identifier (ID), a name, and a price. The Item class should provide methods to get and set these properties. Additionally, it should include a method to print item details.
Vendor: Represents a vendor supplying items to the store. A vendor is described by a vendor ID, a name, and an address. This class should provide methods to get and set these properties. The toString() method should return a string representation of the vendor, including all its details.
StoreItem: Extends the Item class. In addition to the properties inherited from Item, StoreItem includes a property to store the vendor (supplier) of the item. The class should override the method to print item details to include vendor information if available. It should also include a method getVendorName() that returns the name of the vendor if set, or "Unknown" if not.
Implementation Details:
•
The StoreItem class should be initialized with an ID, name, and price. Vendor details should be set using a separate method, setVendor(), which takes a Vendor object as a parameter.
•
The toString() method in both Vendor and StoreItem should return a string representation of the object's state in a readable format. For StoreItem, implement two versions of toString(): one that only returns item details and another that also includes vendor details based on a boolean parameter.
