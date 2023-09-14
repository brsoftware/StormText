/**
 * @brief BrStormTextLexerMarkdown.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerMarkdown.hpp"


BrStormTextLexerMarkdown::BrStormTextLexerMarkdown(QFont font, QColor color, QObject *parent)
    : QsciLexerMarkdown(parent)
{
    QFont defaultFont = QFont(font);

    QFont boldFont = QFont(defaultFont);
    boldFont.setBold(true);

    QFont italicFont = QFont(defaultFont);
    italicFont.setItalic(true);

    QFont strikeOutFont = QFont(defaultFont);
    strikeOutFont.setStrikeOut(true);

    QFont linkFont = QFont(defaultFont);
    linkFont.setUnderline(true);

    setColor(color, QsciLexerMarkdown::Default);
    setColor(QColor("#39FF00"), QsciLexerMarkdown::Special);
    setColor(color, QsciLexerMarkdown::StrongEmphasisAsterisks);
    setColor(color, QsciLexerMarkdown::StrongEmphasisUnderscores);
    setColor(color, QsciLexerMarkdown::EmphasisAsterisks);
    setColor(color, QsciLexerMarkdown::EmphasisUnderscores);
    setColor(QColor("#FF6D00"), QsciLexerMarkdown::Header1);
    setColor(QColor("#DD4B00"), QsciLexerMarkdown::Header2);
    setColor(QColor("#BB2900"), QsciLexerMarkdown::Header3);
    setColor(QColor("#990700"), QsciLexerMarkdown::Header4);
    setColor(QColor("#770000"), QsciLexerMarkdown::Header5);
    setColor(QColor("#550000"), QsciLexerMarkdown::Header6);
    setColor(color, QsciLexerMarkdown::Prechar);
    setColor(QColor("#FF00FD"), QsciLexerMarkdown::UnorderedListItem);
    setColor(QColor("#DD00DB"), QsciLexerMarkdown::OrderedListItem);
    setColor(QColor("#7D7D7D"), QsciLexerMarkdown::BlockQuote);
    setColor(color, QsciLexerMarkdown::StrikeOut);
    setColor(color, QsciLexerMarkdown::HorizontalRule);
    setColor(QColor("#3900FF"), QsciLexerMarkdown::Link);
    setColor(color, QsciLexerMarkdown::CodeBackticks);
    setColor(color, QsciLexerMarkdown::CodeDoubleBackticks);
    setColor(color, QsciLexerMarkdown::CodeBlock);

    setFont(defaultFont, QsciLexerMarkdown::Default);
    setFont(defaultFont, QsciLexerMarkdown::Special);
    setFont(boldFont, QsciLexerMarkdown::StrongEmphasisAsterisks);
    setFont(boldFont, QsciLexerMarkdown::StrongEmphasisUnderscores);
    setFont(italicFont, QsciLexerMarkdown::EmphasisAsterisks);
    setFont(italicFont, QsciLexerMarkdown::EmphasisUnderscores);
    setFont(boldFont, QsciLexerMarkdown::Header1);
    setFont(boldFont, QsciLexerMarkdown::Header2);
    setFont(boldFont, QsciLexerMarkdown::Header3);
    setFont(boldFont, QsciLexerMarkdown::Header4);
    setFont(boldFont, QsciLexerMarkdown::Header5);
    setFont(boldFont, QsciLexerMarkdown::Header6);
    setFont(font, QsciLexerMarkdown::Prechar);
    setFont(defaultFont, QsciLexerMarkdown::UnorderedListItem);
    setFont(defaultFont, QsciLexerMarkdown::OrderedListItem);
    setFont(defaultFont, QsciLexerMarkdown::BlockQuote);
    setFont(strikeOutFont, QsciLexerMarkdown::StrikeOut);
    setFont(font, QsciLexerMarkdown::HorizontalRule);
    setFont(defaultFont, QsciLexerMarkdown::Link);
    setFont(font, QsciLexerMarkdown::CodeBackticks);
    setFont(font, QsciLexerMarkdown::CodeDoubleBackticks);
    setFont(font, QsciLexerMarkdown::CodeBlock);

    setPaper(QsciLexer::defaultPaper());
}
