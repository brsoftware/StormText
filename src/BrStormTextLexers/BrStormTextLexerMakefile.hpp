/**
 * @brief BrStormTextLexerMakefile.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERMAKEFILE_HPP
#define BRSTORMTEXTLEXERMAKEFILE_HPP


#include <Qsci/qscilexermakefile.h>


class BrStormTextLexerMakefile : public QsciLexerMakefile
{
    Q_OBJECT

public:

    BrStormTextLexerMakefile(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERMAKEFILE_HPP

