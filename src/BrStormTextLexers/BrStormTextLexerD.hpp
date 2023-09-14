/**
 * @brief BrStormTextLexerD.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERD_HPP
#define BRSTORMTEXTLEXERD_HPP


#include <Qsci/qscilexerd.h>


class BrStormTextLexerD : public QsciLexerD
{
    Q_OBJECT

public:

    BrStormTextLexerD(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERD_HPP

