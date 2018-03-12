#include <QString>
#include <QtTest>
// ugly but simple way to test class members (I hope there's a better way?)
#define private public
#include "../model.h"

class TestModel : public QObject
{
    Q_OBJECT

public:
    TestModel();

private Q_SLOTS:
    void testMixedResultGuessIsHandledCorrectly();
    void testWordsAreLoadedCorrectly();
    void testNewWordRetrievesVaryingSelectionOfWords();
};

TestModel::TestModel()
{
}

void TestModel::testMixedResultGuessIsHandledCorrectly()
{
    mm::Model model;
    std::string feedback;
    model.word = "test";
    const std::string guess = "tabs";
    bool result = model.guess(feedback, guess);
    QCOMPARE(false, result);
    QCOMPARE("*-  ", feedback.data());
}

void TestModel::testWordsAreLoadedCorrectly()
{
    mm::Model model;
    const std::string path = "../4-letter-words.txt";
    model.loadWords(path);
    QCOMPARE((ulong)5272, model.wordPool.size());
    QCOMPARE("AANI", model.wordPool[0].data());
    QCOMPARE("AARU", model.wordPool[1].data());
}

void TestModel::testNewWordRetrievesVaryingSelectionOfWords()
{
    mm::Model model;
    const std::string path = "../4-letter-words.txt";
    model.loadWords(path);
    std::string a = model.findNewWord();
    std::string b = model.findNewWord();
    std::string c = model.findNewWord();
    std::string d = model.findNewWord();
    QVERIFY(!(a == b && b == c && c == d));

}

QTEST_APPLESS_MAIN(TestModel)

#include "test_model.moc"
