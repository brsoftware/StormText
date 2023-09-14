/**
 * @brief BrStormTextLexerBash.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 30 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERBASH_HPP
#define BRSTORMTEXTLEXERBASH_HPP


#include <Qsci/qscilexerbash.h>


class BrStormTextLexerBash : public QsciLexerBash
{
    Q_OBJECT

public:

    BrStormTextLexerBash(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERBASH_HPP


