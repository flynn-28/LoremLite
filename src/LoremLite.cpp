#include "LoremLite.h" // Library header
#include <vector> // used to store words
#include <random> // used to select words
#include <ctime> // used for seed
#include <cctype> // used for charecter manipulation

void capitalize(std::string &sentence) { // capitilize first letter of sentence
    if (!sentence.empty()) { // make sure sentence isnt empty
        sentence[0] = std::toupper(sentence[0]); // capitilize first charecter
    }
}

namespace LoremLite {
    // main function to generate text
    std::string generate(int wordCount) {
        // lorem ipsum word dictionary
        std::vector<std::string> wordBank = {
            "lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit",
            "sed", "do", "eiusmod", "tempor", "incididunt", "ut", "labore", "et", "dolore",
            "magna", "aliqua", "ut", "enim", "ad", "minim", "veniam", "quis", "nostrud",
            "exercitation", "ullamco", "laboris", "nisi", "ut", "aliquip", "ex", "ea",
            "commodo", "consequat", "duis", "aute", "irure", "dolor", "in", "reprehenderit",
            "in", "voluptate", "velit", "esse", "cillum", "dolore", "eu", "fugiat", "nulla",
            "pariatur", "excepteur", "sint", "occaecat", "cupidatat", "non", "proident",
            "sunt", "in", "culpa", "qui", "officia", "deserunt", "mollit", "anim", "id",
            "est", "laborum"
        };

        std::mt19937 rng(static_cast<unsigned>(time(0))); // initilize number genrater using time as seed
        std::uniform_int_distribution<int> sentenceRange(10, 17); // set sentence length to 10-17 words
        std::uniform_int_distribution<int> wordRange(0, wordBank.size() - 1); // range for selecting words

        std::string result; // store final text
        int remainingWords = wordCount; // words left

        while (remainingWords > 0) {
            int sentenceLength = (remainingWords < 10) ? remainingWords : sentenceRange(rng); // calculate length of next sntence
            sentenceLength = std::min(sentenceLength, remainingWords); // make sure sentence doesnt go past remaining words

            std::string sentence; // stores current sentence
            // generate sentence
            for (int i = 0; i < sentenceLength; ++i) {
                sentence += wordBank[wordRange(rng)]; // add word
                if (i < sentenceLength - 1) { // add space unless end of sentence
                    sentence += " ";
                }
            }

            sentence += ". "; // add puncuation to sentence
            capitalize(sentence); // capilitize first letter 
            result += sentence; // add sentecnce to final

            remainingWords -= sentenceLength; // count words left
        }

        return result; // return text
    }
}
