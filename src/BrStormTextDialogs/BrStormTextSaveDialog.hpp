/**
 * @brief BrStormTextLexerSaveDialog.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 27 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTSAVEDIALOG_HPP
#define BRSTORMTEXTSAVEDIALOG_HPP


#include <QFileDialog>


class BrStormTextTab;


class BrStormTextSaveDialog : public QFileDialog
{
    Q_OBJECT

public:

    BrStormTextSaveDialog(QString fileName, QString currentLexer, BrStormTextTab *tab, QWidget *parent = nullptr);

public slots:

    void saveFile();

public:

    bool isSuccessfulSaving();
    QString currentText();

private:

    QList<QString> m_filters;
    BrStormTextTab *m_tab;
    QString m_curLex;
    bool m_success;
    QString m_text;
};

#endif // BRSTORMTEXTSAVEDIALOG_HPP

