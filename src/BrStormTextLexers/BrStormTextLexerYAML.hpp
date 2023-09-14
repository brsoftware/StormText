/**
 * @brief BrStormTextLexerYAML.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERYAML_HPP
#define BRSTORMTEXTLEXERYAML_HPP


#include <Qsci/qscilexeryaml.h>


class BrStormTextLexerYAML : public QsciLexerYAML
{
    Q_OBJECT

public:

    BrStormTextLexerYAML(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERYAML_HPP

