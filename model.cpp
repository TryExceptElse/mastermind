#include <cstdlib>
#include <fstream>
#include <iostream>
#include <climits>
#include "model.h"

namespace mm {


static const int WORD_LEN = 4;
static const std::string SUCCESS_STRING = "Success";

Model::Model()
{
    nGuesses = 0;
    inProgress = false;
}

void Model::loadWords(const std::string &path) {
    std::ifstream wordFile;
    wordFile.open(path);
    if (wordFile.fail()) {
        throw std::runtime_error("Could not read from path: " + path);
    }
    std::string word;
    while (wordFile >> word) { // While lines are able to be retrieved...
        // Check that length is correct.
        if (word.length() != WORD_LEN) {
            std::cerr << "Loaded word had incorrect length: " << word << '\n';
            continue;
        }
        wordPool.push_back(word);
    }
}

void Model::newGame()
{
    inProgress = true;
    nGuesses = 0;
    word = findNewWord();
}

bool Model::guess(std::string &outFeedback, const std::string &guess)
{
    if (guess.length() != WORD_LEN) {
        outFeedback = "Guess was not 4 characters";
    }
    if (guess == word) {
        outFeedback = SUCCESS_STRING;
        inProgress = false; // game is over.
        return true;
    }
    // otherwise, set string to 4 chars length and give feedback
    outFeedback = "    ";
    int placeMatches = 0;
    int charMatches = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        const char guessChar = guess[i];
        // go to next char if char is not in word
        if (word.find(guessChar) == word.npos) {
            continue;
        }
        ++charMatches;
        if (word[i] == guessChar) {
            ++placeMatches;
        }
    }
    // populate feedback string
    for (int i = 0; i < WORD_LEN; ++i) {
        if (i < placeMatches) {
            outFeedback[i] = '*';
        } else if (i < charMatches) {
            outFeedback[i] = '-';
        } else {
            outFeedback[i] = ' ';
        }
    }
    return false;
}

// getters


int Model::getNGuesses() const {
    return nGuesses;
}

const std::string &Model::getWord() const {
    return word;
}


// private helpers

const std::string& Model::findNewWord() {
    if (wordPool.size() == 0) {
        throw std::runtime_error(
            "Model::findNewWord() : No words in wordPool");
    }
    if (wordPool.size() > INT_MAX) {
        std::cerr << "WARN : Model::findNewWord() : "
                  << "wordPool was too large to select from effectively";
    }
    // If perfectly even distribution is desired, the modulo method
    // of selection should be replaced.
    return wordPool[std::rand() % wordPool.size()];
}


} // namespace mm
