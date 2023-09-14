/**
 * @brief BrStormTextLexerTeX.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerTeX.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerTeX::BrStormTextLexerTeX(QFont font, QColor color, QObject *parent)
    : QsciLexerTeX(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerTeX::Default);
    setColor(QColor("#FF6D00"), QsciLexerTeX::Special);
    setColor(color, QsciLexerTeX::Group);
    setColor(QColor("#39FF00"), QsciLexerTeX::Symbol);
    setColor(QColor("#FF00FD"), QsciLexerTeX::Command);
    setColor(color, QsciLexerTeX::Text);

    setFont(font, QsciLexerTeX::Default);
    setFont(font, QsciLexerTeX::Special);
    setFont(font, QsciLexerTeX::Group);
    setFont(font, QsciLexerTeX::Symbol);
    setFont(font, QsciLexerTeX::Command);
    setFont(font, QsciLexerTeX::Text);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
