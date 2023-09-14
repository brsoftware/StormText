/**
 * @brief BrStormTextLexerGotoDialog.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Aug 3 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTGOTODIALOG_HPP
#define BRSTORMTEXTGOTODIALOG_HPP


#include <QDialog>
#include <QSpinBox>


class BrStormTextTab;


class BrStormTextGotoDialog : public QDialog
{
    Q_OBJECT

public:

    BrStormTextGotoDialog(BrStormTextTab *tab, QWidget *parent = nullptr);

public slots:

    void goto_(bool);

private:

    QSpinBox *m_leg;
    BrStormTextTab *m_tab;
};

#endif // BRSTORMTEXTGOTODIALOG_HPP

