/**
 * @brief BrStormTextLexerOpenDialog.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTOPENDIALOG_HPP
#define BRSTORMTEXTOPENDIALOG_HPP


#include <QFileDialog>
#include <QList>


class BrStormTextTab;
class BrStormTextEditor;


class BrStormTextOpenDialog : public QFileDialog
{
    Q_OBJECT

public:

    BrStormTextOpenDialog(BrStormTextTab *tab, QWidget *parent = nullptr);

public slots:

    void openSelectedFiles();

public:

    QList<BrStormTextEditor*> getWidgets();

private:

    QList<QString> m_filters;
    BrStormTextTab *m_tab;
    QList<BrStormTextEditor*> m_w;
};

#endif // BRSTORMTEXTOPENDIALOG_HPP

