/**
 * @brief BrStormTextLexerVerilog.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERVERILOG_HPP
#define BRSTORMTEXTLEXERVERILOG_HPP


#include <Qsci/qscilexerverilog.h>


class BrStormTextLexerVerilog : public QsciLexerVerilog
{
    Q_OBJECT

public:

    BrStormTextLexerVerilog(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERVERILOG_HPP

