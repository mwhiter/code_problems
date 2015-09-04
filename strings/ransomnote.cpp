#include <iostream>

/* Ransom note problem:
	Return a boolean function that determines whether or not you can write a ransom note.
	The key to understanding this problem is that we'd have a larger text that we can pull characters from, and a smaller text that we need to write.
	1) Check if we have a text to draw from.
	2) Check if we have a text to write.
	3) Count the number of each individual character in the big text.
	4) Decrement from that count for each character in the target text. If we don't have it, we fail.
*/

#define NUM_CHARS 256

// Can we write target text by pulling characters from big text?
bool canWrite(std::string big, std::string target) {
	if(big == "") return false;
	if(target == "") return false;
	
	int charcount[NUM_CHARS];
	for(int i=0;i<NUM_CHARS;i++) {
		charcount[i] = 0;
	}
	
	// Increment the character count for each character we find.
	for(int i=0; i<big.size(); i++) {
		charcount[big[i]] = ++charcount[big[i]];
	} 
	
	for(int i=0; i<target.size(); i++) {
		if(charcount[target[i]] == 0) return false;
		charcount[target[i]] = --charcount[target[i]];
	}
	
	return true;
}

int main() {
	std::cout << "1st (true): " << canWrite("This is my article.", "hi.") << std::endl;
	std::cout << "2nd (false): " << canWrite("How are you doing?", "Very well.") << std::endl;
	std::cout << "3rd (true): " << canWrite("A long, long, time ago... in a galaxy far away...", "Aoooaaaa") << std::endl;
	return 0;
}