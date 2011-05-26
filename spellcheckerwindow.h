#ifndef SPELLCHECKERWINDOW_H
#define SPELLCHECKERWINDOW_H

#include <QWidget>

namespace Ui {
    class SpellCheckerWindow;
}

class SpellCheckerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SpellCheckerWindow(QWidget *parent = 0);
    ~SpellCheckerWindow();

private slots:
    void on_spellButton_clicked();

    void on_loadButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::SpellCheckerWindow *ui;
};

#endif // SPELLCHECKERWINDOW_H
