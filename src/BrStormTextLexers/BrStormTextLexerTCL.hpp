/**
 * @brief BrStormTextLexerTCL.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERTCL_HPP
#define BRSTORMTEXTLEXERTCL_HPP


#include <Qsci/qscilexertcl.h>


class BrStormTextLexerTCL : public QsciLexerTCL
{
    Q_OBJECT

public:

    BrStormTextLexerTCL(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERTCL_HPP

