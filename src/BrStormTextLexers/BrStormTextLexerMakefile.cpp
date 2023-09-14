/**
 * @brief BrStormTextLexerMakefile.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerMakefile.hpp"


BrStormTextLexerMakefile::BrStormTextLexerMakefile(QFont font, QColor color, QObject *parent)
    : QsciLexerMakefile(parent)
{
    setColor(color, QsciLexerMakefile::Default);
    setColor(QColor("#EA0000"), QsciLexerMakefile::Comment);
    setColor(QColor("#FF00FD"), QsciLexerMakefile::Preprocessor);
    setColor(color, QsciLexerMakefile::Variable);
    setColor(color, QsciLexerMakefile::Operator);
    setColor(QColor("#FF6D00"), QsciLexerMakefile::Target);
    setColor(QColor("#FF7777"), QsciLexerMakefile::Error);

    setFont(font, QsciLexerMakefile::Default);
    setFont(font, QsciLexerMakefile::Comment);
    setFont(font, QsciLexerMakefile::Preprocessor);
    setFont(font, QsciLexerMakefile::Variable);
    setFont(font, QsciLexerMakefile::Operator);
    setFont(font, QsciLexerMakefile::Target);
    setFont(font, QsciLexerMakefile::Error);

    setPaper(QsciLexer::defaultPaper());
}
