/**
 * @brief BrStormTextFindDock.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 27 May 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTFINDDOCK_HPP
#define BRSTORMTEXTFINDDOCK_HPP


#include <QDockWidget>
#include <QLineEdit>
#include <QCheckBox>


class BrStormTextTab;


class BrStormTextFindDock : public QDockWidget
{
    Q_OBJECT

public:

    BrStormTextFindDock(BrStormTextTab *tab, QWidget *parent = nullptr);

public slots:

    void findNext(bool);
    void findPrevious(bool);
    void replaceNext(bool);
    void replacePrevious(bool);
    void replaceAll(bool);

private:

    BrStormTextTab *m_tab;
    QLineEdit *m_lef;
    QLineEdit *m_ler;
    QCheckBox *m_checkRegex;
    QCheckBox *m_checkCaseSensitive;
    QCheckBox *m_checkWholeWord;
};

#endif // BRSTORMTEXTFINDDOCK_HPP

