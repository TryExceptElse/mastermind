#ifndef MODEL_H
#define MODEL_H

#include <string>

namespace mm {


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

    void findNewWord(std::string &outWord);
};


} // namespace mm

#endif // MODEL_H
