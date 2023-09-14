/**
 * @brief BrStormTextLexerOctave.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXEROCTAVE_HPP
#define BRSTORMTEXTLEXEROCTAVE_HPP


#include <Qsci/qscilexeroctave.h>


class BrStormTextLexerOctave : public QsciLexerOctave
{
    Q_OBJECT

public:

    BrStormTextLexerOctave(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXEROCTAVE_HPP

