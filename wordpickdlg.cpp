#include "wordpickdlg.h"
#include "ui_wordpickdlg.h"

WordPickDlg::WordPickDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WordPickDlg)
{
    ui->setupUi(this);
}

WordPickDlg::~WordPickDlg()
{
    delete ui;
}
