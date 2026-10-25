#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

#include <string>

class GroceryItem
{
private:
    std::string itemName;
    int itemQuantity;

public:
    //Constructs a GroceryItem object with a name and initial quantity
    //@param name - name of the grocery item
    //@param quantity - initial count of the item
    //@returns - none
    //@throws - none
    GroceryItem(std::string name, int quantity);

    //Gets the name of the grocery item
    //@param - none
    //@returns - item name as string
    //@throws - none
    std::string getItemName() const;

    //Gets the current purchased quantity
    //@param - none
    //@returns - integer count of item
    //@throws - none
    int getItemQuantity() const;

    //Incrase the item quantity by a given amount
    //@param amount - numeric count to add to current quantity
    //@returns - none
    //@throws - none
    void addQuantity(int amount);
};

#endif