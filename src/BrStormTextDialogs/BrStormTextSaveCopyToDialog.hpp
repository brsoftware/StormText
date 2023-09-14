/**
 * @brief BrStormTextLexerSaveCopyToDialog.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTSAVECOPYTODIALOG_HPP
#define BRSTORMTEXTSAVECOPYTODIALOG_HPP


#include <QFileDialog>


class BrStormTextTab;


class BrStormTextSaveCopyToDialog : public QFileDialog
{
    Q_OBJECT

public:

    BrStormTextSaveCopyToDialog(QString fileName, QString currentLexer, BrStormTextTab *tab, QWidget *parent = nullptr);

public slots:

    void saveFile();

private:

    QList<QString> m_filters;
    BrStormTextTab *m_tab;
    QString m_curLex;
};

#endif // BRSTORMTEXTSAVECOPYTODIALOG_HPP

