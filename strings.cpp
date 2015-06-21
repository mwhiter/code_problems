#include <iostream>
#include <cstring>

/** Some C-String stuff. */

// reverse a string
const char* reverse(const char* str) {
	char* reversed = new char[strlen(str)];
	for(int i=0; i<strlen(str);i++)
		reversed[i] = str[strlen(str)-1-i];
	
	return str;
}

// remove whitespace from a string (in place)
void stripWhiteSpace(char* str) {
	// implement
}

int main() {
	std::cout << reverse("Hello!") << std::endl;
	return 0;
}