#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include "GroceryItem.h"

//Deletes every GroceryItem stored in the map and empties the map
//@param itemMap - map of item names to GroceryItem pointers
//@returns - none
//@throws - none
void freeMapMemory(std::map<std::string, GroceryItem*>& itemMap)
{
    std::map<std::string, GroceryItem*>::iterator it;

    for (it = itemMap.begin(); it != itemMap.end(); ++it)
    {
        delete it->second;
    }

    itemMap.clear();
}

//Reads the input file and counts how many times each item appears
//@param fileName - name of the input file to read
//@param itemMap - map that is filled with the item names and their counts
//@returns - none
//@throws - none
void readDataFile(const std::string& fileName, std::map<std::string, GroceryItem*>& itemMap)
{
    freeMapMemory(itemMap);

    std::ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        std::cout << "Could not open file: " << fileName << std::endl;
        return;
    }

    std::string word;

    while (inputFile >> word)
    {
        if (itemMap.count(word) > 0)
        {
            itemMap[word]->addQuantity(1);
        }
        else
        {
            GroceryItem* newItem = new GroceryItem(word, 1);
            itemMap[word] = newItem;
        }
    }

    inputFile.close();
}

//Converts text to lowercase so item searches ignore capital letters
//@param text - the text to convert
//@returns - the lowercase version of the text
//@throws - none
std::string toLowerCase(std::string text)
{
    for (size_t i = 0; i < text.length(); ++i)
    {
        text.at(i) = static_cast<char>(tolower(text.at(i)));
    }

    return text;
}

//Creates the backup file, then shows a menu until the user chooses to exit
//@param - none
//@returns - 0 when the program ends normally
//@throws - none
int main()
{
    const std::string INPUT_FILE = "project_three_input_file.txt";
    const std::string BACKUP_FILE = "frequency.dat";
    const int OPTION_SEARCH = 1;
    const int OPTION_PRINT_ALL = 2;
    const int OPTION_HISTOGRAM = 3;
    const int OPTION_EXIT = 4;

    std::map<std::string, GroceryItem*> grocerMap;

    readDataFile(INPUT_FILE, grocerMap);

    std::ofstream backupOut;
    backupOut.open(BACKUP_FILE);

    if (backupOut.is_open())
    {
        std::map<std::string, GroceryItem*>::iterator it;
        for (it = grocerMap.begin(); it != grocerMap.end(); ++it)
        {
            std::string name = it->second->getItemName();
            int qty = it->second->getItemQuantity();

            backupOut << name << " " << qty << std::endl;
        }

        backupOut.close();
    }

    int choice = 0;

    while (choice != OPTION_EXIT)
    {
        std::cout << std::endl;
        std::cout << "1. Search item count" << std::endl;
        std::cout << "2. Display all item counts" << std::endl;
        std::cout << "3. Display histogram" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter option: ";

        if (!(std::cin >> choice))
        {
            std::cout << "Please enter a valid number (1-4)." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == OPTION_SEARCH)
        {
            readDataFile(INPUT_FILE, grocerMap);

            std::string searchItem;
            std::cout << "Enter item to search: ";
            std::cin >> searchItem;

            std::string searchLower = toLowerCase(searchItem);
            int quantity = 0;
            std::string displayName = searchItem;

            std::map<std::string, GroceryItem*>::iterator it;

            for (it = grocerMap.begin(); it != grocerMap.end(); ++it)
            {
                if (toLowerCase(it->first) == searchLower)
                {
                    quantity = it->second->getItemQuantity();
                    displayName = it->second->getItemName();
                    break;
                }
            }

            std::cout << displayName << " " << quantity << std::endl;
        }
        else if (choice == OPTION_PRINT_ALL)
        {
            readDataFile(INPUT_FILE, grocerMap);

            std::map<std::string, GroceryItem*>::iterator it;
            for (it = grocerMap.begin(); it != grocerMap.end(); ++it)
            {
                std::string name = it->second->getItemName();
                int qty = it->second->getItemQuantity();

                std::cout << name << " " << qty << std::endl;
            }
        }
        else if (choice == OPTION_HISTOGRAM)
        {
            readDataFile(INPUT_FILE, grocerMap);

            std::map<std::string, GroceryItem*>::iterator it;
            for (it = grocerMap.begin(); it != grocerMap.end(); ++it)
            {
                std::string name = it->second->getItemName();
                int qty = it->second->getItemQuantity();

                std::cout << name << " ";

                for (int i = 0; i < qty; ++i)
                {
                    std::cout << "*";
                }

                std::cout << std::endl;
            }
        }
        else if (choice == OPTION_EXIT)
        {
            std::cout << "Goodbye!" << std::endl;
        }
        else
        {
            std::cout << "Invalid choice. Please enter 1, 2, 3, or 4." << std::endl;
        }
    }

    freeMapMemory(grocerMap);

    return 0;
}