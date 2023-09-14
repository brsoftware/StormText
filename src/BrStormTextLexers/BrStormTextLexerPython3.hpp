/**
 * @brief BrStormTextLexerPython3.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPYTHON3_HPP
#define BRSTORMTEXTLEXERPYTHON3_HPP


#include <Qsci/qscilexerpython.h>


class BrStormTextLexerPython3 : public QsciLexerPython
{
    Q_OBJECT

public:

    BrStormTextLexerPython3(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *language() const {return "Python 3";}

    const char *keywords(int set) const
    {
        if (set == 1)
            return set1;

        if (set == 2)
            return set2;

        return 0;
    }

private:

    const char *set1 = "and as assert async await break case class continue def del "
                       "elif else except False finally for from global if import in "
                       "is lambda match None nonlocal not or pass raise return True "
                       "try while with yield";
    const char *set2 = "abs aiter all any anext ascii bin bool breakpoint bytearray "
                       "bytes callable chr classmethod compile complex delattr dict "
                       "dir divmod enumerate eval exec filter float format frozenset "
                       "getattr globals hasattr hash help hex id input int isinstance "
                       "issubclass iter len list locals map max memoryview min next "
                       "object oct open ord pow print property range repr reversed "
                       "round set setattr slice sorted staticmethod str sum super "
                       "tuple type vars zip __import__ "
                       "BaseException BaseExceptionGroup GeneratorExit KeyboardInterrupt "
                       "SystemExit Exception ArithmeticError FloatingPointError "
                       "OverflowError ZeroDivisionError AssertionError AttributeError "
                       "BufferError EOFError ExceptionGroup ImportError ModuleNotFoundError "
                       "LookupError IndexError KeyError MemoryError NameError "
                       "UnboundLocalError OSError BlockingIOError ChildProcessError "
                       "BrokenPipeError ConnectionAbortedError ConnectionRefusedError "
                       "ConnectionResetError FileExistsError FileNotFoundError InterruptedError "
                       "IsADirectoryError NotADirectoryError PermissionError ProcessLookupError "
                       "TimeoutError ReferenceError RuntimeError NotImplementedError "
                       "RecursionError StopAsyncIteration StopIteration SyntaxError "
                       "IndentationError TabError SystemError TypeError ValueError "
                       "UnicodeError UnicodeDecodeError UnicodeEncodeError UnicodeTranslateError "
                       "Warning BytesWarning DeprecationWarning EncodingWarning FutureWarning "
                       "ImportWarning PendingDeprecationWarning ResourcesWarning SyntaxWarning "
                       "UnicodeWarning UserWarning";
};

#endif // BRSTORMTEXTLEXERPYTHON3_HPP

