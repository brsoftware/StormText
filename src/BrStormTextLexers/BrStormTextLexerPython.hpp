/**
 * @brief BrStormTextLexerPython.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPYTHON_HPP
#define BRSTORMTEXTLEXERPYTHON_HPP


#include <Qsci/qscilexerpython.h>


class BrStormTextLexerPython : public QsciLexerPython
{
    Q_OBJECT

public:

    BrStormTextLexerPython(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const
    {
        if (set == 1)
            return set1;

        if (set == 2)
            return set2;

        return 0;
    }

private:

    const char *set1 = "and as assert break class continue def del elif else except exec "
                       "finally for from global if import in is lambda None not or pass "
                       "print raise return try while with yield";
    const char *set2 = "abs all any basestring bin bool bytearray "
                       "callable chr classmethod cmp compile complex "
                       "delattr dict dir divmod enumerate eval execfile "
                       "file filter float format frozenset getattr globals "
                       "hasattr hash help hex id input int isinstance "
                       "issubclass iter len list locals long map max "
                       "memoryview min next object oct open ord pow "
                       "property range raw_input reduce reload repr "
                       "reserved round set setattr slice sorted staticmethod "
                       "str sum super tuple type unichr unicode vars xrange "
                       "zip __import__ apply buffer coerce intern quit "
                       "exit copyright license credits "
                       "BaseException Exception StandardError ArithmeticError "
                       "BufferError LookupError EnvironmentError AssertionError "
                       "AttributeError EOFError FloatingPointError GeneratorExit "
                       "IOError ImportError IndexError KeyError KeyboardInterrupt "
                       "MemoryError NameError NotImplementedError OSError "
                       "OverflowError ReferenceError RuntimeError StopIteration "
                       "SyntaxError IndentationError TabError SystemError "
                       "SytemExit TypeError UnboundLocalError UnicodeError "
                       "UnicodeEncodeError UnicodeDecodeError UnicodeTranslateError "
                       "ValueError VMSError WindowsError ZeroDivisionError Warning "
                       "UserWarning DeprecationWarning PendingDeprecationWarning "
                       "SyntaxWarning RuntimeWarning FutureWarning ImportWarning "
                       "UnicodeWarning";
};

#endif // BRSTORMTEXTLEXERPYTHON_HPP

