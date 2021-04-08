// cards.cpp
// Author: Benjamin Fogiel
// Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>

using namespace std;

// creates empty list
cards::cards() : head(nullptr), tail(nullptr) {}

// destructor
cards::~cards() {
	Card* current = head;
	while (current != nullptr){
		Card* next = current -> next;
		delete current;
		current = next;
	}
}

// << operator to print cards
std::ostream& operator<<(std::ostream &os, const cards &l) {
	cards::Card *c = l.head;
	while (c != nullptr){
		os << c->suit << " " << c->value << endl;
		c = c -> next;
	}
	return os;
}

// equality operator
bool operator==(const cards &l1, const cards &l2) {
	cards::Card *c1 = l1.head;
	cards::Card *c2 = l2.head;
	while (c1 != nullptr && c2 != nullptr){
		if (c1->suit != c2->suit || c1->value != c2->value)
			return false;
		c1 = c1 -> next;
		c2 = c2 -> next;
	}
	return true;
}

//adds a card to the list
void cards::append(char s, char v){
	Card *c = new Card;
	c->suit = s;
	c->value = v;
	c->next = nullptr;

	if (head == nullptr && tail == nullptr) {
		head = c;
		tail = c;
	} else {
		tail->next = c;
		tail = c;
	}
}

//plays the game. l1 is the first player, l2 is the secoond
// pos is the position in the list where the first player left off
// posp2 is the position in the list where the second player left off
// player variable keeps track of who is playing in respect to l1 and l2 
// this is needed because this function is running recusively and l1 and l2 switch
// with each iteration
void cards::play(cards &l1, cards &l2, int pos, int posp2, int player){

	Card *p1 = l1.head;
	Card *p2 = l2.head;

	bool match = false;

	int pos1 = pos;
	int pos2 = 0;

	for(int i=0;i<pos;i++) {
      p1 = p1->next;
    }

    if (p1 == nullptr || p2 == nullptr)
		return;

	while (p1 != nullptr){
		p2 = l2.head;
		pos2 = 0;
		while (p2 != nullptr){
			if ((p1->value == p2->value) && (p1->suit == p2->suit)) {
				if (player%2==0){
					cout << "Alice picked matching card " << p1->suit << " " << p1->value << endl;
				} else{
					cout << "Bob picked matching card " << p1->suit << " " << p1->value << endl;
				}
				l2.deleteCard(pos2);
				match = true;
				break;
			}
			pos2++;
			p2 = p2->next;
		}
		if (match){
			l1.deleteCard(pos1);
			break;
		}
		pos1++;
		p1 = p1->next;
	}
	player++; // indicates that it is the next players turn
	l1.play(l2,l1,posp2,pos1,player);
}


// deletes the card given its position pos within the list
void cards::deleteCard(int pos) {
	if (pos == 0){ //if first Card
		Card *temp=new Card;
    	temp=head;
    	head=head->next;
    	delete temp;
	}else{ // if either middle or last card
		Card *current=new Card;
    	Card *previous=new Card;
    	current=head;
    	for(int i=0;i<pos;i++){
      		previous=current;
      		current=current->next;
    	}
    	if (current == tail){ // if last Card
    		tail=previous;
    		previous->next=NULL;
    		delete current;
    		return;
    	}
    	previous->next=current->next;
    	delete current;
  	}

}
