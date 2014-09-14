#include "spellcheckerwindow.h"
#include "ui_spellcheckerwindow.h"
#include "spellchecker.h"

#include <iostream>
#include <QtGui>

#define CHECKER_READY "SpellChecker Ready"


SpellCheckerWindow::SpellCheckerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpellCheckerWindow)
{
    ui->setupUi(this);
    checker = new SpellChecker;
    ui->textEdit->setText ("Hello\nDo you know how to spell asdfasdf?");
}

SpellCheckerWindow::~SpellCheckerWindow()
{
    delete ui;
    delete checker;
}

void SpellCheckerWindow::on_spellButton_clicked()
{
    std::cerr << "# spellButton clicked" << std::endl;

    QTextCursor cur(ui->textEdit->document());
    QTextCharFormat normalFormat;
    QTextCharFormat errorFormat;

    errorFormat.setUnderlineColor(QColor(Qt::red));
    errorFormat.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);

    /* clear format */
    cur.movePosition (QTextCursor::End, QTextCursor::KeepAnchor);
    cur.setCharFormat (normalFormat);

    cur.movePosition (QTextCursor::Start, QTextCursor::MoveAnchor);
    while (!cur.atEnd ())
    {
        cur.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
        std::string word = cur.selectedText ().toStdString ();

        if (checker->spell (word.data ())) {
            cur.setCharFormat (normalFormat);
            std::cerr << "#selected: '" << word << "' ok"<< std::endl;
        } else {
            cur.setCharFormat (errorFormat);
            std::cerr << "#selected: '" << word << "' bad" << std::endl;
        }

        cur.clearSelection ();
        cur.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);
    }

    cur.movePosition (QTextCursor::End, QTextCursor::KeepAnchor);
    cur.setCharFormat (normalFormat);
}

void SpellCheckerWindow::on_loadButton_clicked()
{
    std::cerr << "# loadButton clicked" << std::endl;
    QString affpath = QFileDialog::getOpenFileName(this, "Load aff file",
                                                   "",
                                                   "Affix (*.aff)");
    if (affpath.isEmpty())
        return;
    std::cerr << "# affpath='" << affpath.toStdString().data () << "'"<< std::endl;

    QString dicpath = QFileDialog::getOpenFileName (this, "Load dic file",
                                                    "",
                                                    "Dictionary (*.dic)");
    if (dicpath.isEmpty())
        return;
    std::cerr << "# dicpath='" << dicpath.toStdString().data () << "'"<< std::endl;


    checker->load_dict(affpath.toStdString ().data (),dicpath.toStdString ().data ());
    switch (checker->ready ())
    {
        case SpellChecker::Ok:
            ui->spellButton->setEnabled (true);
            ui->status->setText ("<font color='green'>SpellChecker Ready!</font>");
            break;
        case SpellChecker::Bad:
            ui->spellButton->setEnabled (true);
            ui->status->setText ("<font color='orange'>Dictionary loaded doesnt seem good</font>");
            break;
        case SpellChecker::Null:
            ui->spellButton->setEnabled (false);
            ui->status->setText ("<font color='red'>Dictionary not loaded.</font>");
    }
}

void SpellCheckerWindow::on_clearButton_clicked()
{
    std::cerr << "# clearButton clicked" << std::endl;

    QTextCursor cur (ui->textEdit->document ());
    cur.movePosition (QTextCursor::End, QTextCursor::KeepAnchor);
    cur.setCharFormat (QTextCharFormat());
}
