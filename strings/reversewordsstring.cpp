#include <iostream>
#include <string>

/** Reverse the words in a string, in-place. */

void swap(std::string& str, int a, int b) {
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}

std::string& reverseWords(std::string& str) {
	// reverse string
	for(int i=0; i < str.size()/2; i++)
		swap(str, i, str.size()-1-i);
	
	int j;
	// reverse words in string (in place)
	for(int i=0; i < str.size(); i++) {
		// find start of word
		while(isspace(str[i]) && i < str.size()) {
			i++;
		}
		// find end of word
		j = i;
		while(!isspace(str[j]) && j < str.size()) {
			j++;
		}
		
		int end = ((j - i) / 2) + i;
		// swap the word
		for(int n = i; n < end; n++) {
			int swapIndex = (j-1) - (n-i); 
			swap(str, n, swapIndex);
		}
		
		i = j;
	}
	
	return str;
}

int main() {
	std::string str1 = "My Name is Abraham";
	std::cout << reverseWords(str1) << std::endl;
	std::string str2 = "I am a really cool dude";
	std::cout << reverseWords(str2) << std::endl;
	std::string str3 = "I  am awesome";
	std::cout << reverseWords(str3) << std::endl;
	
	return 0;
}