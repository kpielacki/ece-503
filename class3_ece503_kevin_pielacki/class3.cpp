#include <iostream>

using namespace std;

int main() {
	// Intialize all candidates votes to be zero.
	int vote_array[5] = {0, 0, 0, 0, 0};
	const int polled_users = 20;
	const string candidate_array[5] = {
		"Trishna Thakrar",
	 	"Natalie Hughes",
	 	"Grainne McCoy",
	 	"Courtney Wood",
	 	"Sofiane Khelfa"
	 };
	int user_vote;
	bool user_selecting;
	string user_confirm;
	int current_max = 0;
	int winner_count = 0;
	int winner_array[2];

	// Print candidate vote menu.
	 cout << "--------------------------------------------------------" << endl;
	 cout << "Select the number to vote for the candidate." << endl;
	 for ( int i = 0; i < 5; i++ ) {
	 	cout << i + 1 << ". " << candidate_array[i] << endl;
	 }
	 cout << "--------------------------------------------------------" << endl << endl;

	 // Iterate through each voter.
	 for ( int i = 0; i < polled_users; i++ ) {
	 	user_selecting = true;
	 	// Don't let next user vote until user confirms.
	 	while ( user_selecting ) {
		 	cout << "User " << i + 1 << " selection: ";
		 	cin >> user_vote;

		 	// Clear for prompting again in case of bad selection.
		 	cin.clear();
			cin.ignore();

		 	// Restrict user vote to menue selection.
		 	if ( user_vote > 5 || user_vote < 1 ) {
		 		cout << "Invalid candidate selection, try again." << endl;
		 	} else {
		 		// Ask user to confirm if proper candidate.
		 		cout << "You have selected \"" << candidate_array[user_vote - 1] << "\". Enter \"y\" if this is correct: ";
		 		cin >> user_confirm;
		 		if ( user_confirm == "y" ) {
		 			user_selecting = false;
		 			// Add vote to candidate.
		 			vote_array[user_vote - 1]++;
		 			cout << "Vote added for \"" << candidate_array[user_vote - 1] << "\"" << endl;
		 		}
		 	}
	 		
	 	}
	 }

	 // Iterate through vote count.
	 for ( int i = 0; i < 5; i++ ) {
		if ( vote_array[i] > current_max ) {
			current_max = vote_array[i];
			winner_count = 1;
			winner_array[winner_count - 1] = i;
		} else if ( vote_array[i] == current_max ) {
			// Instructions ask for "more" than 2 people with the same vote
			// count to declare no winner. I don't know if it's intentional
			// so I'm interpretting this literally.
			// If there are more than 2 people who have the same vote counts, print there is no winner
			winner_count++;
			if ( winner_count <= 2 ) {
				winner_array[winner_count - 1] = i;
			}
		}
	 }

	cout << endl << "--------------------------------------------------------" << endl;
	if ( winner_count <= 2 ) {
	 	for (int i = 0; i < winner_count; i++) {
	 		cout << "Winner: " << candidate_array[winner_array[i]] << endl;
	 	}
	} else {
 		cout << "No winner, more than two people have the same max vote." << endl;
	}
	cout << "--------------------------------------------------------" << endl << endl;

	cout << "Instructions ask for \"more\" than 2 people with the same vote count to declare no winner. I don't know if it's intentional so I'm interpretting this literally." << endl;
	return 0;
}