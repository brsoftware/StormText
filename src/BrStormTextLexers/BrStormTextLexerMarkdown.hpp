/**
 * @brief BrStormTextLexerMarkdown.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERMARKDOWN_HPP
#define BRSTORMTEXTLEXERMARKDOWN_HPP


#include <Qsci/qscilexermarkdown.h>


class BrStormTextLexerMarkdown : public QsciLexerMarkdown
{
    Q_OBJECT

public:

    BrStormTextLexerMarkdown(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERMAKEFILE_HPP

