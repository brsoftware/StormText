/**
 * @brief BrStormTextLexerLua.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERLUA_HPP
#define BRSTORMTEXTLEXERLUA_HPP


#include <Qsci/qscilexerlua.h>


class BrStormTextLexerLua : public QsciLexerLua
{
    Q_OBJECT

public:

    BrStormTextLexerLua(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERLUA_HPP

