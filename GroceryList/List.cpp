#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <map>
#include "List.h"


using namespace std;

int countAllGroceries(string str) {
    vector<string> items({ "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Potatoes", "Cucumbers", "Peaches", "Beets", "Cantaloupe", "Cauliflower", "Zucchini", "Yams", "Apples", "Pears", "Garlic", "Onions", "Pumpkins", "Limes", "Celery" });
    vector<string> words;
    vector<int> counts;
    string temp = "";
    int count = 1;
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


        count = 1;
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