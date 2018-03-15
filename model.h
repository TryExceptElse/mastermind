#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <vector>

namespace mm {


/**
 * Model for the mastermind game. Interacted with from the UI.
 * The Model stores game state information in a form that is
 * independant of its representation.
 */
class Model
{
public:
    Model();

    /**
     * Loads words from file, so that they can be used during gameplay.
     */
    void loadWords(const QString &path);

    /**
     * (Re)sets model to that of a new game.
     */
    void newGame();

    /**
     * Checks passed guess made by user and compares it to
     * current word.
     *
     * If word matches, the user has won the game, and game ends.
     * A success message is then returned via the feedback string.
     *
     * Otherwise, feedback is combination of '*' chars, indicating
     * guessed characters in correct position, and '-' chars,
     * indicating a character that is present in the word, but at
     * the wrong location.
     *
     * @param outFeedback std::string feedback to user guess
     * @param guess std::string
     * @return bool true if guess matched target word, otherwise false.
     */
    bool guess(QString &feedback, const QString &guess);

    int getNGuesses() const;
    const QString &getWord() const;
private:
    int nGuesses;
    bool inProgress;
    QString word;
    std::vector<QString> wordPool;

    /**
     * Finds new word from pool by random selection and returns it.
     * Selection distribution is not perfectly even, but close enough for
     * game purposes.
     * @return std::string word
     */
    const QString& findNewWord();
};


} // namespace mm

#endif // MODEL_H
