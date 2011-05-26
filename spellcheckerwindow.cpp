#include "spellcheckerwindow.h"
#include "ui_spellcheckerwindow.h"

#include <iostream>

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

void SpellCheckerWindow::on_spellButton_clicked()
{
    std::cout << "# spellButton clicked" << std::endl;
}

void SpellCheckerWindow::on_loadButton_clicked()
{
    std::cout << "# loadButton clicked" << std::endl;
}

void SpellCheckerWindow::on_clearButton_clicked()
{
    std::cout << "# clearButton clicked" << std::endl;
}
