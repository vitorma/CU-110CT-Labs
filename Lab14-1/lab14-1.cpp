/*
 * lab14-1.cpp
 *
 *  Created on: 16 May 2014
 *      Author: vitorma
 *
 *      First of all, you need to implement a class named Bag, with integer attributes for number of
 * lemons, chickens and loaves of bread. For C++, these should be private attributes accessible
 * only through the class’s methods.

 * In addition, the class should have the following constructors/methods:

 * ● A constructor which produces an empty bag
 * ● Three methods named insertChicken, insertLemon and insertBread, which increment the
 * number of Chickens, Lemons or Bread accordingly, subject to the following constraints
 * ○ A bag may not contain more than 3 - (number of lemons / 5) chickens.
 * ○ A bag may not contain more than 17 - (number of chickens * 5) - (number of
 * loaves * 3) lemons
 * ○ A bag may not contain both chickens and bread as this scares the chickens
 * ○ The maximum loaf count is 5 - (number of lemons / 3)
 * ● The insert methods should return true or false to indicate whether or not the item was
 * successfully added to the Bag.
 * ● There should also be remove methods for Chickens, Lemons and Bread
 * ● There should be methods named getChickens, getLemons and getBread, which return
 * the number of each.
 *
 *
 */

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

int main(int argc, char **argv) {

}

