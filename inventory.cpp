#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item
{
    private:
        string name;
        int quantity;
        double price;

    public:
        Item (string n, int quan, double p) { name = n; quantity = quan; price = p; }

        void displayItem()
        {
            cout << "Item Name: " << name << "\n\tQuantity: " << quantity << "\n\tPrice: $" << price << "\n\tTotal Value: $" << calculateTotalValue() << endl;
        }

        // Modifyer Methods
        void addItem(int amount) { quantity += amount; }
        void removeItem(int amount) { quantity -= amount; }
        void changePrice(int p) { price = p; }
        void changeName(string n) { name = n; }

        // Accessor Methods
        int getItemCount() { return quantity; }
        string getName() { return name; }
        int getPrice() { return price; }
        double calculateTotalValue() { return (quantity*price); }

        // Compaires Given item to org
        bool IsSameItem(Item comp)
        {
            bool SName = name == comp.getName();
            bool SPrice = price == comp.getPrice();
            return SName && SPrice;
        }
};

class Inventory
{
    private:
        vector<Item> items;

    public:
        Inventory() {}

        // Adds Item if there is already that in it just adds the quanity
        void addItem(Item itemName)
        {
            Item* dup = findItem(itemName);

            if (dup == 0)
                items.push_back(itemName);
            else
                dup->addItem(itemName.getItemCount());
        }

        // Loops threw all items in the inventory to see if it exists
        Item* findItem(Item itemName)
        {
            Item* foun = nullptr;

            for (int i = 0; i < items.size(); i++)
            {
                if (itemName.IsSameItem(items[i]))
                    foun = &items[i];
            }
            
            return foun;
        }

        // If item is in the vector gets the positon and removes it
        void removeItem(Item itemName)
        {
            if (findItem(itemName))
            {
                int place = 0;

                for (int i = 0; i < items.size(); i++)
                {
                    if (itemName.IsSameItem(items[i]))
                        place = i;
                }

                items.erase(items.begin()+place);
            }
        }

        // Creates a massive text of all items in the inventory
        void displayInventory()
        {
            cout << "Items in inventory ("<<items.size()<<"):" << endl;
        
            for (int i = 0; i < items.size(); i++)
            {
                items[i].displayItem();
                cout << "--------" << endl;
            }
        }

        // Calulates the total value of the whole inventory
        void totalval()
        {
            double val = 0;

            for (int i = 0; i < items.size(); i++)
            {
                val += items[i].calculateTotalValue();
            }

            cout << "Inventory Total Value: $" << val << endl;
        }
};

int main()
{
    //Creation of everything
    Inventory inv;
    Item i1("Name",2,50.0);
    Item i2("Nam2",1,5.0);
    Item i22("Nam2",1,4.0);
    Item i3("Nam3",5,20.0);
    Item i4("Nam4",2,530.4);
    Item i5("Nam5",13,5.0);
    Item i6("Nam6",553,223.0);

    // Adds Items and removes i3 for list
    inv.addItem(i1);
    inv.addItem(i1);
    inv.addItem(i2);
    inv.addItem(i22);
    inv.addItem(i3);
    inv.addItem(i4);
    inv.addItem(i5);
    inv.addItem(i6);
    inv.removeItem(i3);

    // display and total value of inventroy
    inv.displayInventory();
    inv.totalval();
}