#include "model.h"

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

bool Model::guess(std::string &feedback, const std::string &guess)
{
    if (guess.length() != WORD_LEN) {
        feedback = "Guess was not 4 characters";
    }
    if (guess == word) {
        feedback = SUCCESS_STRING;
        return 1;
    }
    int placeMatches = 0;
    int charMatches = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        guessChar = guess.get())
    }
}
