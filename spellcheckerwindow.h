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

private:
    Ui::SpellCheckerWindow *ui;
};

#endif // SPELLCHECKERWINDOW_H
