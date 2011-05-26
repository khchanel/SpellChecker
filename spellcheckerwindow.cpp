#include "spellcheckerwindow.h"
#include "ui_spellcheckerwindow.h"

SpellCheckerWindow::SpellCheckerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpellCheckerWindow)
{
    ui->setupUi(this);
}

SpellCheckerWindow::~SpellCheckerWindow()
{
    delete ui;
}
