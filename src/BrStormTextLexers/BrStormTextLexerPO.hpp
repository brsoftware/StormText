/**
 * @brief BrStormTextLexerPO.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPO_HPP
#define BRSTORMTEXTLEXERPO_HPP


#include <Qsci/qscilexerpo.h>


class BrStormTextLexerPO : public QsciLexerPO
{
    Q_OBJECT

public:

    BrStormTextLexerPO(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPO_HPP

