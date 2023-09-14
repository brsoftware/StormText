/**
 * @brief BrStormTextLexerEDIFACT.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerEDIFACT.hpp"


BrStormTextLexerEDIFACT::BrStormTextLexerEDIFACT(QFont font, QColor color, QObject *parent)
    : QsciLexerEDIFACT(parent)
{
    setColor(color, QsciLexerEDIFACT::Default);
    setColor(QColor("#FF6D00"), QsciLexerEDIFACT::SegmentStart);
    setColor(QColor("#FF6D00"), QsciLexerEDIFACT::SegmentEnd);
    setColor(color, QsciLexerEDIFACT::ElementSeparator);
    setColor(color, QsciLexerEDIFACT::CompositeSeparator);
    setColor(color, QsciLexerEDIFACT::ReleaseSeparator);
    setColor(QColor("#FF00FD"), QsciLexerEDIFACT::UNASegmentHeader);
    setColor(QColor("#FF00FD"), QsciLexerEDIFACT::UNHSegmentHeader);
    setColor(QColor("#EA0000"), QsciLexerEDIFACT::BadSegment);

    setFont(font, QsciLexerEDIFACT::Default);
    setFont(font, QsciLexerEDIFACT::SegmentStart);
    setFont(font, QsciLexerEDIFACT::SegmentEnd);
    setFont(font, QsciLexerEDIFACT::ElementSeparator);
    setFont(font, QsciLexerEDIFACT::CompositeSeparator);
    setFont(font, QsciLexerEDIFACT::ReleaseSeparator);
    setFont(font, QsciLexerEDIFACT::UNASegmentHeader);
    setFont(font, QsciLexerEDIFACT::UNHSegmentHeader);
    setFont(font, QsciLexerEDIFACT::BadSegment);

    setPaper(QsciLexer::defaultPaper());
}
