//repo.cpp
#include <iostream>
#include <vector>
#include "../inc/repo.h"

int words(const char* str)
{
   int numWords = 0;
	bool inSpaces = true;
  
   while (*str != '\0')
   {
      if (std::isspace(*str))
      {
         inSpaces = true;
      }
      else if (inSpaces)
      {
         numWords++;
         inSpaces = false;
      }

      ++str;
   }

   return numWords;
}



int ReadInt(int low, int high) {
	std::cout << "\nEnter in range " << low << " - " << high << ": ";
	int value;

	std::cin >> value;

	if (low <= value && value <= high)
		return value;

	std::cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}

int ShowReadMenu(const std::vector<std::string> &choices) {
	system("CLS");
	std::cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		std::cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}


 