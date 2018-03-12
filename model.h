#ifndef MODEL_H
#define MODEL_H

#include <string>

/**
 * Model for the mastermind game. Interacted with from the UI.
 */
class Model
{
public:
    Model();

    void newGame();
    bool guess(std::string &feedback, const std::string &guess);
    int getNGuesses() const;
private:
    int nGuesses;
    bool inProgress;
    std::string word;

    void findNewWord(std::string &outString);
};

#endif // MODEL_H
