#include <iostream>
#include <cstring>

/** Some C-String stuff. */

// reverse a string
const char* reverse(const char* str) {
	char* reversed = new char[strlen(str)];
	for(int i=0; i<strlen(str);i++)
		reversed[i] = str[strlen(str)-1-i];
	
	return reversed;
}

// remove whitespace from a string (in place)
void stripWhiteSpace(char* str) {
	int j;
	for(int i=0; str[i] != '\0'; i++) {
		str[j] = str[i];
		
		// increment j if it is not on a space
		if(!isspace(str[j]))
			j++;
	}
	
	str[j] = '\0';
}

void removeChar(char* str, int index) {
	int size = strlen(str);
	if(index < 0 || index >= size) return;
	
	for(int i = index; i < size-1; i++) {
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
	char str2[] = "Henry has  a little dog  ";
	stripWhiteSpace(str2);
	std::cout << "(Reverse) Hello: " << reverse("Hello!") << std::endl;
	std::cout << "(Remove Duplicates) AABcCCDDeEeFAa: " << removeDuplicates(str1) << std::endl;
	std::cout << "(Find first unique) AbcDceF: " << findFirstUnique("AbcDceF") << std::endl;
	std::cout << "(Remove whitespace) Henry has  a little dog: " << str2 << std::endl;
	return 0;
}