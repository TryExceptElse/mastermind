#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

namespace mm {


/**
 * Model for the mastermind game. Interacted with from the UI.
 */
class Model
{
public:
    Model();

    void loadWords(const std::string &path);
    void newGame();
    bool guess(std::string &feedback, const std::string &guess);
    int getNGuesses() const;
    const std::string &getWord() const;
private:
    int nGuesses;
    bool inProgress;
    std::string word;
    std::vector<std::string> wordPool;

    const std::string &findNewWord();
};


} // namespace mm

#endif // MODEL_H
