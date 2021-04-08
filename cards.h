// cards.h
// Author: Benjamin Fogiel
#include<iostream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

class cards
{
public:
    cards();  // constructor
    cards(const cards &other); // copy constructor
    ~cards(); // destructor


    void append(char s, char v); // adds a new Card to the list
    void print() const; // prints the list
    void play(cards &l1, cards &l2, int pos, int posp2, int player); // plays the game
    void deleteCard(int pos); // deletes node

    // overloaded << operator print the cards

    cards &operator=(const cards &other); // copy assignment
    friend std::ostream& operator<<(std::ostream &os, const cards &l);


    friend bool operator==(const cards &l1, const cards &l2); //equality operator

    bool operator!=(const cards &other) const; // not equal overloaded operator

private:
    // definition of Card
    struct Card
    {
        char suit;
        char value;

        Card *next;
    };
    Card *head; // pointer to first Card
    Card *tail; // pointer to the last Card
};

std::ostream& operator<<(std::ostream &os, const cards &l);

bool operator==(const cards &l1, const cards &l2);


#endif