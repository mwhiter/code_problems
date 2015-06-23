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

void removeChar(char* str, int index) {
	int size = strlen(str);
	if(index < 0 || index >= size) return;
	
	for(int i = index; i < size-2; i++) {
		char temp = str[i];
		str[i] = str[i+1];
		str[i+1] = temp;
	}
	
	str[size-1] = '\0';
}

// remove duplicates from a string
char* removeDuplicates(char* str) {
	const int NUM_CHARS = 256;
	bool chars[NUM_CHARS];
	for(int i=0;i<NUM_CHARS;i++) chars[i] = false;
	
	for(int i=0; i < strlen(str); i++) {
		bool duplicate = chars[(int)str[i]];
		if(duplicate) {
			removeChar(str, i);
			i--;
		}
		else {
			chars[(int)str[i]] = true;
		}
	}
	
	return str;
}

int findFirstUnique(char* str) {
	int size = strlen(str);
	const int NUM_CHARS = 256;
	bool chars[NUM_CHARS];
	for(int i = 0; i < NUM_CHARS; i++)
		chars[i] = false;
	for(int i = 0; i < size; i++) {
		if(chars[str[i]])
			return i;
		else
			chars[str[i]] = true;
	}
	return -1;
}

int main() {
	char str1[] = "AABcCCDDeEeFAa";
	std::cout << "(Reverse) Hello: " << reverse("Hello!") << std::endl;
	std::cout << "(Remove Duplicates) AABcCCDDeEeFAa: " << removeDuplicates(str1) << std::endl;
	std::cout << "(Find first unique) AbcDceF: " << findFirstUnique("AbcDceF") << std::endl;
	return 0;
}