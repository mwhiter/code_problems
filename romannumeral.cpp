#include <iostream>
#include <string>

/** Given a roman numeral (e.g. VIII), convert it into an integer (e.g. VIII = 8) */

// get value of roman digit
int getValue(const char& c) {
	switch(c) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;
	}
}

// Converts a roman number into an integer
int convertRomanNumeral(const std::string& str) {
	if(str.empty()) return 0;
	int index = 0;
	int largestIndex = 0;
	int value = 0;
	
	while(index < str.size()) {
		// Find the largest index in front of us
		for(int i = index; i < str.size(); i++) {
			if(getValue(str[i]) > getValue(str[largestIndex])) {
				largestIndex = i;
				break;
			}
		}
		
		value += getValue(str[largestIndex]);
		
		// Loop behind us (to index) and subtract their values
		for(int i = largestIndex-1; i >= index; i--) {
			value -= getValue(str[i]);
		}
		
		index = largestIndex+1;
		largestIndex = index;
	}
	
	return value;
}

int main() {
	std::cout << "III = " << convertRomanNumeral("III") << std::endl; 				// 3
	std::cout << "VIII = " << convertRomanNumeral("VIII") << std::endl;				// 8
	std::cout << "XLVII = " << convertRomanNumeral("XLVII") << std::endl; 			// 47
	std::cout << "LXXII = " << convertRomanNumeral("LXXII") << std::endl; 			// 72
	std::cout << "C = " << convertRomanNumeral("C") << std::endl; 					// 100
	std::cout << "MMMMCMXCIX = " << convertRomanNumeral("MMMMCMXCIX") << std::endl; // 4999
	
	return 0;
}