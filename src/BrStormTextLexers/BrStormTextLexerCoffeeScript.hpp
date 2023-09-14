/**
 * @brief BrStormTextLexerCoffeeScript.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERCOFFEESCRIPT_HPP
#define BRSTORMTEXTLEXERCOFFEESCRIPT_HPP


#include <Qsci/qscilexercoffeescript.h>


class BrStormTextLexerCoffeeScript : public QsciLexerCoffeeScript
{
    Q_OBJECT

public:

    BrStormTextLexerCoffeeScript(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERCOFFEESCRIPT_HPP
