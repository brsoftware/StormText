/**
 * @brief BrStormTextLexerSQL.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERSQL_HPP
#define BRSTORMTEXTLEXERSQL_HPP


#include <Qsci/qscilexersql.h>


class BrStormTextLexerSQL : public QsciLexerSQL
{
    Q_OBJECT

public:

    BrStormTextLexerSQL(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERSQL_HPP

