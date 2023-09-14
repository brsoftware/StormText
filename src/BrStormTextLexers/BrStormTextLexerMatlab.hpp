/**
 * @brief BrStormTextLexerMatlab.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERMATLAB_HPP
#define BRSTORMTEXTLEXERMATLAB_HPP


#include <Qsci/qscilexermatlab.h>


class BrStormTextLexerMatlab : public QsciLexerMatlab
{
    Q_OBJECT

public:

    BrStormTextLexerMatlab(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERMATLAB_HPP

