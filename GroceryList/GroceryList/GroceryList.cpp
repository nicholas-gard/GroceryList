// GroceryList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <map>



using namespace std;

class MyGroceries {//class that holds required methods and variables
public:
    int countUserGroceries(string str);

    int countAllGroceries(string str);

    int groceriesHistogram(string str);

    int exportAllGroceries(string str);

private:
    int count;

};



int MyGroceries::countUserGroceries(string str) {//counts groceries based on user input

    string userInput;

    cin >> userInput;

    vector<string> words;
    string temp = "";
    for (int i = 0; i < str.size(); i++) {//stores the string in a vector
        if (str[i] == '\n') { //skips newline
            words.push_back(temp);
            temp = "";
        }
        else {//stores the string
            temp += str[i];
        }
    }

    int count = 0;

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == userInput) {//if the element matches the users input, adds 1 to count
            count++;
        }
    }

    // Prints number of items
    cout << userInput << " " << count << endl;

    return 0;
}


int MyGroceries::countAllGroceries(string str) {//counts all groceries in list
    //vector items holds all possible grecery items
    vector<string> items({ "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Potatoes", "Cucumbers", "Peaches", "Beets", "Cantaloupe", "Cauliflower", "Zucchini", "Yams", "Apples", "Pears", "Garlic", "Onions", "Pumpkins", "Limes", "Celery" });
    vector<string> words;

    string temp = "";

    int count = 0;

    for (int i = 0; i < str.size(); i++) {//stores the string in a vector
        if (str[i] == '\n') { //skips newline
            words.push_back(temp);
            temp = "";
        }
        else {//stores the string
            temp += str[i];
        }
    }

    map<string, int>mp;
    
   for (int q = 0; q < items.size(); q++) {//for loop iterates items vector
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == items[q]) {//if the element matches the users input, adds 1 to count
            count++;
        }
    }

            mp.insert({ items[q], count});//creates new map pair for each item
            

            count = 0;
}

    // gets an iterator pointing to the first element in the map
    map<string, int>::iterator it = mp.begin();

    // Iterate through the map and print the elements
    while (it != mp.end()) {
        cout << it->first
            << " " << it->second << endl;
        ++it;
    }

    return 0;


}

int MyGroceries::exportAllGroceries(string str) {//counts all groceries in list
    //vector items holds all possible grecery items
    vector<string> items({ "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Potatoes", "Cucumbers", "Peaches", "Beets", "Cantaloupe", "Cauliflower", "Zucchini", "Yams", "Apples", "Pears", "Garlic", "Onions", "Pumpkins", "Limes", "Celery" });
    vector<string> words;

    string temp = "";

    int count = 0;

    for (int i = 0; i < str.size(); i++) {//stores the string in a vector
        if (str[i] == '\n') { //skips newline
            words.push_back(temp);
            temp = "";
        }
        else {//stores the string
            temp += str[i];
        }
    }

    map<string, int>mp;

    for (int q = 0; q < items.size(); q++) {//for loop iterates items vector
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == items[q]) {//if the element matches the users input, adds 1 to count
                count++;
            }
        }

        mp.insert({ items[q], count });//creates new map pair for each item


        count = 0;
    }

    // gets an iterator pointing to the first element in the map
    map<string, int>::iterator it = mp.begin();

    // Iterate through the map and print the elements
    cout << endl << "Exporting to file GroceryCount.txt\n\n";

    ofstream MyFile("GroceryCount.txt"); //creates new file

    while (it != mp.end()) {//exports the map of all grovery items and values to the file
        MyFile << it->first
            << " " << it->second << endl;
        ++it;
    }

    MyFile.close();
    cout << "Export successful, file closed." << endl;

    return 0;


}


int MyGroceries::groceriesHistogram(string str) {//prints a histogram of items and numbers

    vector<string> items({ "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Potatoes", "Cucumbers", "Peaches", "Beets", "Cantaloupe", "Cauliflower", "Zucchini", "Yams", "Apples", "Pears", "Garlic", "Onions", "Pumpkins", "Limes", "Celery" });
    vector<string> words;

    string temp = "";

    int count = 1;
    int length = 0;
    int size = 0;
    int spaces = 0;

    for (int i = 0; i < str.size(); i++) {//stores the string in a vector
        if (str[i] == '\n') { //skips newline
            words.push_back(temp);
            temp = "";
        }
        else {//stores the string
            temp += str[i];
        }
    }

    map<string, int>mp;

    for (int q = 0; q < items.size(); q++) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == items[q]) {//if the element matches the users input, adds 1 to count
                count++;
            }
        }

        mp.insert({ items[q], count });


        count = 0;
    }

    map<string, int>::iterator it = mp.begin();

        for (int q = 0; q < items.size(); q++) {//gets words length, adds number of spaces to make them all aligned
            cout << endl;
            length = 0;
            length = mp[items[q]];

            size = items[q].length();
            if (size < 15) {
                spaces = 14 - items[q].length();
            }
            for (int h = 0; h < spaces; h++) {
                cout << " ";
            }
            cout << items[q] << " | ";

            for (int x = 0; x < length; x++) {
                cout << "*";
            }
        }

        cout << endl;

    return 0;

    }





int main()
{
    int menuOption = 0;
    char c;
    string s;
    MyGroceries myCount;

    ifstream rfile;
    rfile.open("CS210_Project_Three_Input_File.txt");//grocery list file
    if (rfile.is_open()) {
        
        rfile >> noskipws;           // needed to prevent loss of spaces
        while (rfile >> c) s += c; // iterates all characters into string s

        rfile.close(); //closes file
        cout << "File opened and data is stored.\n\n";
    }

    else if (!rfile.is_open()) {
    
        cout << "Error: File could not be opened.\n"; // shows error if file was unable to be opened
    
    }



    //while loop for MAIN MENU
    while (menuOption != 4) {

        cout << "***MAIN MENU***\n" << "1. Search for individual Item and Frequency\n" << "2. Display list of Items and Frequencies\n";
        cout << "3. Display list of Items and Frequencies as histogram\n" << "4. Close program and save all data to file\n";

        cin >> menuOption;

        if (menuOption == 1) {
            cout << "Input desired item: ";

            myCount.countUserGroceries(s);

            
        }
        
        if (menuOption == 2) {

            myCount.countAllGroceries(s);
        }

        if (menuOption == 3) {

            myCount.groceriesHistogram(s);
        }

        if (menuOption == 4) {
            cout << "Exporting\n";

            myCount.exportAllGroceries(s);

            break;
        }

        if (cin.fail()) {
            cout << " \nPlease input a valid option.\n\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
