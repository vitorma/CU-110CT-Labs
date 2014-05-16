/*
 * lab14-2.cpp
 *
 *  Created on: 16 May 2014
 *      Author: vitorma
 *
 *      Create an instances of a Bag, and an interactive menu-based program which enables you to go
 * shopping with it
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class bag {
private:
	int lemons;
	int chickens;
	int breads;

	bool isAValidChickenInsertion() {
		return !((chickens + 1) > (3 - (lemons / 5))) && breads == 0;
	}

	bool isAValidLemonInsertion() {
		return !((lemons + 1) > (17 - (chickens * 5) - (breads * 3)));
	}

	bool isAValidBreadInsertion() {
		return !((breads + 1) > (5 - (lemons / 3))) && chickens == 0;
	}

public:
	bag() {
		lemons = 0;
		chickens = 0;
		breads = 0;
	}

	bool insertChicken() {
		if (isAValidChickenInsertion()) {
			chickens++;
			return true;
		}
		return false;
	}

	bool insertLemon() {
		if (isAValidLemonInsertion()) {
			lemons++;
			return true;
		}
		return false;
	}
	bool insertBread() {
		if (isAValidBreadInsertion()) {
			breads++;
			return true;
		}
		return false;
	}

	bool removeChicken() {
		if (chickens > 0) {
			chickens--;
			return true;
		}
		return false;
	}

	bool removeLemon() {
		if (lemons > 0) {
			lemons--;
			return true;
		}
		return false;
	}

	bool removeBread() {
		if (breads > 0) {
			breads--;
			return true;
		}
		return false;
	}

	int getChickens() {
		return chickens;
	}

	int getLemons() {
		return lemons;
	}

	int getBreads() {
		return breads;
	}

};

void addProduct(bag& bag) {
	char userInput;
	cout << "------------------------------" << endl;
	cout << "Select an option below" << endl;
	cout << "c. to add a chicken" << endl;
	cout << "l. to add a lemon" << endl;
	cout << "b. to add a bread" << endl;
	cout << "q. to go to previous menu" << endl;
	cout << "Type the option: " << endl;
	cin >> userInput;
	cout << "------------------------------" << endl;
	switch (userInput) {
	case 'b':
		if (bag.insertBread())
			cout << "bread inserted successfully!" << endl;
		else
			cout << "sorry you cannot add more bread" << endl;
		addProduct(bag);
		break;
	case 'c':
		if (bag.insertChicken())
			cout << "chicken inserted successfully!" << endl;
		else
			cout << "sorry you cannot add more chicken" << endl;
		addProduct(bag);
		break;
	case 'l':
		if (bag.insertLemon())
			cout << "lemon inserted successfully!" << endl;
		else
			cout << "sorry you cannot add more lemon" << endl;
		addProduct(bag);
		break;
	case 'q':
		break;
	default:
		cout << "Invalid option!" << endl;
		addProduct(bag);
		break;
	}
}

void removeProduct(bag& bag) {
	char userInput;
	cout << "------------------------------" << endl;
	cout << "Select an option below" << endl;
	cout << "c. to remove a chicken" << endl;
	cout << "l. to remove a lemon" << endl;
	cout << "b. to remove a bread" << endl;
	cout << "q. to go to previous menu" << endl;
	cout << "Type the option: " << endl;
	cin >> userInput;
	cout << "------------------------------" << endl;
	switch (userInput) {
	case 'b':
		if (bag.removeBread())
			cout << "bread removed successfully!" << endl;
		else
			cout << "sorry, there is no more bread to remove" << endl;
		removeProduct(bag);
		break;
	case 'c':
		if (bag.removeChicken())
			cout << "chicken removed successfully!" << endl;
		else
			cout << "there is no more chicken to remove" << endl;
		removeProduct(bag);
		break;
	case 'l':
		if (bag.removeLemon())
			cout << "lemon removed successfully!" << endl;
		else
			cout << "there is no more lemon to remove" << endl;
		removeProduct(bag);
		break;
	case 'q':
		break;
	default:
		cout << "Invalid option!" << endl;
		removeProduct(bag);
		break;
	}
}

void listProducts(bag& bag) {
	cout << "------------------------------" << endl;
	cout << "this is the status of your bag:" << endl;
	cout << "Chickens: " << bag.getChickens() << endl;
	cout << "Lemons: " <<  bag.getLemons() << endl;
	cout << "Breads: " << bag.getBreads() << endl;
	cout << "------------------------------" << endl;
}

void mainMenu(bag& bag) {
	char userInput;
	while (userInput != 'q') {
		cout << "------------------------------" << endl;
		cout << "Select an option below" << endl;
		cout << "a. add a product to the bag" << endl;
		cout << "l. list bag content" << endl;
		cout << "r. remove a product from" << endl;
		cout << "q. quit" << endl;
		cout << "Type the option: " << endl;
		cin >> userInput;
		cout << "------------------------------" << endl;
		switch (userInput) {
		case 'a':
			addProduct(bag);
			break;
		case 'l':
			listProducts(bag);
			break;
		case 'r':
			removeProduct(bag);
			break;
		case 'q':
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	}
}

int main(int argc, char **argv) {
	bag bag;
	mainMenu(bag);
}

