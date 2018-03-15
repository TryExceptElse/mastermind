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
