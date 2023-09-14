/**
 * @brief BrStormTextLexerDiff.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERDIFF_HPP
#define BRSTORMTEXTLEXERDIFF_HPP


#include <Qsci/qscilexerdiff.h>


class BrStormTextLexerDiff : public QsciLexerDiff
{
    Q_OBJECT

public:

    BrStormTextLexerDiff(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERDIFF_HPP

