#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iterator>


// Returns true if value greater than 6.
bool greater_than_6(int i) {
	return i > 6 ? true: false;
}

// Returns true if value is 6.
bool is_6(int i) {
	return i == 6 ? true: false;
}

// Prints integer half of input i.
void print_half(int i) {
	std::cout << i / 2 << ", ";
}


// Prints all values in int deque.
void print_deque(const std::deque <int> &values) {
	// Print current contents of deque.
	for (int i = 0; i < values.size(); i++) {
		std::cout << values[i];
		if (i < values.size() -1 ) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}


int main() {

	/* Problem 1 */
	std::cout << "---Problem 1---" << std::endl;
	// Define array to hold values to be inserted in order.
	int order_array[10] = {3, 4, 6, 2, 9, 1, 5, 0, 7, 8};
	std::deque <int> values;

	// Interate through order array and push new element back to insert at end of deque.
	for (int i = 0; i < sizeof(order_array) / sizeof(int); i++) {
		values.push_back(order_array[i]);
	}
	print_deque(values);
	

	/* Problem 2 */
	std::cout << "---Problem 2---" << std::endl;
	std::deque <int> :: const_iterator removal_loc;
	// int* removal_loc = values + values.size(); // ^ 
	removal_loc = std::remove(values.begin(), values.end(), 7);
	// values.erase(&removal_loc);

	for (int i = 0; i < values.size(); i++) {
		// Erase any elements in deque with value of 7.
		if (values[i] == 7) {
			values.erase(values.begin() + i);
			// Decrement i to accomedate new size of values.
			i--;
		}
	}
	print_deque(values);


	/* Problem 3 */
	std::cout << "---Problem 3---" << std::endl;
	// Relace all values greater than 6 with 10.
	std::replace_if(values.begin(), values.end(), greater_than_6, 10);
	print_deque(values);


	/* Problem 4 */
	std::cout << "---Problem 4---" << std::endl;
	int sum;
	// Sum all elements in values
	sum = std::accumulate(values.begin(), values.end(), 0);
	std::cout << "The sum of the deque is: " << sum << std::endl;
	
	// Print current contents of deque.
	values.push_front(sum);
	print_deque(values);


	/* Problem 5 */
	std::cout << "---Problem 5---" << std::endl;
	int count;
	// Sum all elements in values
	count = std::count_if(values.begin(), values.end(), greater_than_6);
	std::cout << "The count of elements greater than 6 is: " << count << std::endl;
	

	/* Problem 6 */
	std::cout << "---Problem 6---" << std::endl;
	// Prints integer half for all elements in deque.
	std::for_each(values.begin(), values.end(), print_half);
	std::cout << std::endl;


	/* Problem 7 */
	std::cout << "---Problem 7---" << std::endl;
	// Sort all elements in deque.
	std::sort(values.begin(), values.end());
	print_deque(values);


	/* Problem 8 */
	std::cout << "---Problem 8---" << std::endl;
	std::deque <int> :: const_iterator location;
	// Find  all elements in deque with value of 6.
	location = std::find_if(values.begin(), values.end(), is_6);

	if (location != values.end()) {
		std::cout << "Found 6 at location: " << (location - values.begin()) << std::endl;
	} else {
		std::cout << "Value 6 not found" << std::endl;
	}


	/* Problem 9 */
	std::deque <int> values_cp;
	std::ostream_iterator<int> output(std::cout, ", ");
	std::cout << "ostream_iterator output is: " << std::endl;
	std::copy(values.begin(), values.end(), output);

	return 0;
}
