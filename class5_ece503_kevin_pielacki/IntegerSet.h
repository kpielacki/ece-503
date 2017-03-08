// IntegerSet.h
// Header file for class IntegerSet

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet {

	public:
		IntegerSet(); // constructor
		IntegerSet(int set[101]); // constructor

		/* Write a member funcion prototype for unionOfSets */
		// Sets value of set to union of current set and passed set_2.
		void unionOfSets(IntegerSet set_2);
		// Sets value of set to intersection of current set and passed set_2.
		void intersectionOfSets(IntegerSet set_2);

		void inputSet(); // read values from user
		void printSet() const;

	private:
		int set[101]; // range of 0 - 100

		// determines a valid entry to the set
		int validEntry(int x) const {
			return (x >= 0 and x <= 100);
		} // end function validEntry
};

#endif