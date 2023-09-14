/**
 * @brief BrStormTextLexerPOV.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPOV_HPP
#define BRSTORMTEXTLEXERPOV_HPP


#include <Qsci/qscilexerpov.h>


class BrStormTextLexerPOV : public QsciLexerPOV
{
    Q_OBJECT

public:

    BrStormTextLexerPOV(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPOV_HPP

