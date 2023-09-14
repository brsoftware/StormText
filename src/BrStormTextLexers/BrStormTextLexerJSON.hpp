/**
 * @brief BrStormTextLexerJSON.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERJSON_HPP
#define BRSTORMTEXTLEXERJSON_HPP


#include <Qsci/qscilexerjson.h>


class BrStormTextLexerJSON : public QsciLexerJSON
{
    Q_OBJECT

public:

    BrStormTextLexerJSON(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERJSON_HPP

