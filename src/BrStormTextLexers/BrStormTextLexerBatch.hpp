/**
 * @brief BrStormTextLexerBatch.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 4 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERBATCH_HPP
#define BRSTORMTEXTLEXERBATCH_HPP


#include <Qsci/qscilexerbatch.h>


class BrStormTextLexerBatch : public QsciLexerBatch
{
    Q_OBJECT

public:

    BrStormTextLexerBatch(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERBATCH_HPP


