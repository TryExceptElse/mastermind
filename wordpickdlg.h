#ifndef WORDPICKDLG_H
#define WORDPICKDLG_H

#include <QDialog>

namespace Ui {
class WordPickDlg;
}

class WordPickDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WordPickDlg(QWidget *parent = 0);
    ~WordPickDlg();

private:
    Ui::WordPickDlg *ui;
};

#endif // WORDPICKDLG_H
