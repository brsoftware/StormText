/**
 * @brief BrStormTextLexerDiff.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerDiff.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerDiff::BrStormTextLexerDiff(QFont font, QColor color, QObject *parent)
    : QsciLexerDiff(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerDiff::Default);
    setColor(QColor("#EA0000"), QsciLexerDiff::Comment);
    setColor(QColor("#3900FF"), QsciLexerDiff::Comment);
    setColor(color, QsciLexerDiff::Header);
    setColor(color, QsciLexerDiff::Position);
    setColor(QColor("#FF00FD"), QsciLexerDiff::LineRemoved);
    setColor(QColor("#39FF00"), QsciLexerDiff::LineAdded);
    setColor(QColor("#FF6D00"), QsciLexerDiff::LineChanged);
    setColor(QColor("#FF00FD"), QsciLexerDiff::AddingPatchRemoved);
    setColor(QColor("#FF00FD"), QsciLexerDiff::RemovingPatchRemoved);
    setColor(QColor("#39FF00"), QsciLexerDiff::AddingPatchAdded);
    setColor(QColor("#39FF00"), QsciLexerDiff::RemovingPatchAdded);

    setFont(font, QsciLexerDiff::Default);
    setFont(font, QsciLexerDiff::Comment);
    setFont(font, QsciLexerDiff::Comment);
    setFont(font, QsciLexerDiff::Header);
    setFont(font, QsciLexerDiff::Position);
    setFont(font, QsciLexerDiff::LineRemoved);
    setFont(font, QsciLexerDiff::LineAdded);
    setFont(font, QsciLexerDiff::LineChanged);
    setFont(font, QsciLexerDiff::AddingPatchRemoved);
    setFont(font, QsciLexerDiff::RemovingPatchRemoved);
    setFont(font, QsciLexerDiff::AddingPatchAdded);
    setFont(font, QsciLexerDiff::RemovingPatchAdded);

    setPaper(QsciLexer::defaultPaper());
}
