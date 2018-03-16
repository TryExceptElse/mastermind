#include <QString>
#include <QtTest>
// ugly but simple way to test class members (I hope there's a better way?)
#define private public
#include "../model.h"

static const QString WORDS_PATH = "../resources/4-letter-words.txt";

class TestModel : public QObject
{
    Q_OBJECT

public:
    TestModel();

private Q_SLOTS:
    void testMixedResultGuessIsHandledCorrectly();
    void testTotallyWrongGuessIsHandledCorrectly();
    void testCorrectGuessIsHandledCorrectly();
    void testEmptyGuessDoesNotBreakThingsAndReturnsFalse();
    void testGuessThatIsUnder4CharsCanBeHandled();
    void testGuessThatIsOver4CharsCanBeHandled();
    void testGuessIsCaseInsensitive();
    void testCorrectGuessWithDifferentCaseIsHandledCorrectly();
    void testWordsAreLoadedCorrectly();
    void testNewWordRetrievesVaryingSelectionOfWords();
};

TestModel::TestModel()
{
}

void TestModel::testMixedResultGuessIsHandledCorrectly()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "tabs";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
    QCOMPARE(feedback, QString("*-  "));
}

void TestModel::testGuessIsCaseInsensitive()
{
    mm::Model model;
    QString feedback;
    model.word = "TEST";
    const QString guess = "tabs";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
    QCOMPARE(feedback, QString("*-  "));
}

void TestModel::testTotallyWrongGuessIsHandledCorrectly()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "blah";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
}

void TestModel::testCorrectGuessIsHandledCorrectly()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "test";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, true);
}

void TestModel::testCorrectGuessWithDifferentCaseIsHandledCorrectly()
{
    mm::Model model;
    QString feedback;
    model.word = "TEST";
    const QString guess = "test";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, true);
}

void TestModel::testEmptyGuessDoesNotBreakThingsAndReturnsFalse()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
}

void TestModel::testGuessThatIsUnder4CharsCanBeHandled()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "tes";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
}

void TestModel::testGuessThatIsOver4CharsCanBeHandled()
{
    mm::Model model;
    QString feedback;
    model.word = "test";
    const QString guess = "testagasdafsdf";
    bool result = model.guess(feedback, guess);
    QCOMPARE(result, false);
}

void TestModel::testWordsAreLoadedCorrectly()
{
    mm::Model model;
    const QString path = WORDS_PATH;
    model.loadWords(path);
    QCOMPARE((ulong)5272, model.wordPool.size());
    QCOMPARE(model.wordPool[0], QString("AANI"));
    QCOMPARE(model.wordPool[1], QString("AARU"));
}

void TestModel::testNewWordRetrievesVaryingSelectionOfWords()
{
    mm::Model model;
    model.loadWords(WORDS_PATH);
    QString a = model.findNewWord();
    QString b = model.findNewWord();
    QString c = model.findNewWord();
    QString d = model.findNewWord();
    QVERIFY(!(a == b && b == c && c == d));

}

QTEST_APPLESS_MAIN(TestModel)

#include "test_model.moc"
