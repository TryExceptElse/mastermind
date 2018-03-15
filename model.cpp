#include <cstdlib>
#include <iostream>
#include <climits>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QIODevice>
#include "model.h"
#include "exception.h"

namespace mm {


static const int WORD_LEN = 4;
static const QString SUCCESS_STRING = "Success";

Model::Model()
{
    nGuesses = 0;
    inProgress = false;
}

void Model::loadWords(const QString &path) {
    QFile wordFile(path);
    if (!wordFile.open(QIODevice::ReadOnly)) {
        throw GameException(QString("Could not open file: ") + path);
    }
    QTextStream outStream(&wordFile);
    QString word;
     // While lines are able to be retrieved...
    while ((outStream >> word).status() == 0) {
        // Check that length is correct.
        if (word.length() != WORD_LEN) {
            std::cerr << "Loaded word had incorrect length: "
                      << word.data() << '\n';
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

bool Model::guess(QString &outFeedback, const QString &guess)
{
    if (guess.length() != WORD_LEN) {
        outFeedback = "Guess was not 4 characters";
        return false;
    }
    // convert guess and word to lower case versions
    const QString wordLower(word.toLower());
    const QString guessLower(guess.toLower());

    // check if guess was correct. If so, method can return early.
    if (guessLower == wordLower) {
        outFeedback = SUCCESS_STRING;
        inProgress = false; // game is over.
        return true;
    }

    // otherwise, set string to 4 chars length and give feedback
    outFeedback = "    ";
    int placeMatches = 0;
    int charMatches = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        const QChar guessChar = guessLower[i];
        // go to next char if char is not in word
        if (!wordLower.contains(guessChar)) {
            continue;
        }
        ++charMatches;
        if (wordLower[i] == guessChar) {
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

const QString &Model::getWord() const {
    return word;
}


// private helpers

const QString& Model::findNewWord() {
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
