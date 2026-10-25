#include "GroceryItem.h"

GroceryItem::GroceryItem(std::string name, int quantity)
{
    itemName = name;
    itemQuantity = quantity;
}

std::string GroceryItem::getItemName() const
{
    return itemName;
}

int GroceryItem::getItemQuantity() const
{
    return itemQuantity;
}

void GroceryItem::addQuantity(int amount)
{
    itemQuantity = itemQuantity + amount;
}