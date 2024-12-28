#include "LoremLite.h" // include loremlite library
#include <iostream> // for io

int main() { // main function
    int wordCount; // declare number of words to gnerate
    
    std::cout << "Enter the number of words to generate: "; // prompt for words to generate
    std::cin >> wordCount;  // get word count from prompt

    std::string loremText = LoremLite::generate(wordCount); // generate lorem ipsum text based on input
    std::cout << "\nGenerated Lorem Ipsum Text:\n" << loremText << "\n";  // print output

    return 0;
}
