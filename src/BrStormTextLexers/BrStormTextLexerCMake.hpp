/**
 * @brief BrStormTextLexerCMake.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERCMAKE_HPP
#define BRSTORMTEXTLEXERCMAKE_HPP


#include <Qsci/qscilexercmake.h>


class BrStormTextLexerCMake : public QsciLexerCMake
{
    Q_OBJECT

public:

    BrStormTextLexerCMake(QColor color, QFont font, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERCMAKE_HPP

