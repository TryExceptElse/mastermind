#include "model.h"

namespace mm {


static const int WORD_LEN = 4;
static const std::string SUCCESS_STRING = "Success";

Model::Model()
{
    nGuesses = 0;
    inProgress = false;
}

void Model::newGame()
{
    inProgress = true;
    nGuesses = 0;
    findNewWord(word);
}

bool Model::guess(std::string &outFeedback, const std::string &guess)
{
    if (guess.length() != WORD_LEN) {
        outFeedback = "Guess was not 4 characters";
    }
    if (guess == word) {
        outFeedback = SUCCESS_STRING;
        return 1;
    }
    int placeMatches = 0;
    int charMatches = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        const char guessChar = guess[i];
    }
}

void Model::findNewWord(std::string &outWord) {

}



} // namespace mm
