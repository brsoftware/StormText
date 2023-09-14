/**
 * @brief BrStormTextLexerHTML.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerHTML.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerHTML::BrStormTextLexerHTML(QFont font, QColor color, QObject *parent)
    : QsciLexerHTML(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldCompact(true);
    setFoldPreprocessor(true);
    setFoldScriptComments(true);
    setFoldScriptHeredocs(true);

    setColor(color, QsciLexerHTML::Default);
    setColor(QColor("#FF6D00"), QsciLexerHTML::Tag);
    setColor(QColor("#FF3333"), QsciLexerHTML::UnknownTag);
    setColor(QColor("#3966FF"), QsciLexerHTML::Attribute);
    setColor(QColor("#FF3333"), QsciLexerHTML::UnknownAttribute);
    setColor(QColor("#39FF00"), QsciLexerHTML::HTMLDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::HTMLSingleQuotedString);
    setColor(color, QsciLexerHTML::OtherInTag);
    setColor(QColor("#EA0000"), QsciLexerHTML::HTMLComment);
    setColor(color, QsciLexerHTML::Entity);
    setColor(QColor("#3900FF"), QsciLexerHTML::XMLTagEnd);
    setColor(QColor("#3900FF"), QsciLexerHTML::XMLStart);
    setColor(QColor("#3900FF"), QsciLexerHTML::XMLEnd);
    setColor(color, QsciLexerHTML::Script);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPAtStart);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPStart);
    setColor(QColor("#3900FF"), QsciLexerHTML::CDATA);
    setColor(QColor("#3900FF"), QsciLexerHTML::PHPStart);
    setColor(QColor("#0066FF"), QsciLexerHTML::HTMLValue);
    setColor(QColor("#EA0000"), QsciLexerHTML::ASPXCComment);
    setColor(color, QsciLexerHTML::SGMLDefault);
    setColor(QColor("#FF6D00"), QsciLexerHTML::SGMLCommand);
    setColor(QColor("#3900FF"), QsciLexerHTML::SGMLParameter);
    setColor(QColor("#39FF00"), QsciLexerHTML::SGMLDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::SGMLSingleQuotedString);
    setColor(QColor("#FF7777"), QsciLexerHTML::SGMLError);
    setColor(color, QsciLexerHTML::SGMLSpecial);
    setColor(color, QsciLexerHTML::SGMLEntity);
    setColor(QColor("#EA0000"), QsciLexerHTML::SGMLComment);
    setColor(QColor("#EA0000"), QsciLexerHTML::SGMLParameterComment);
    setColor(color, QsciLexerHTML::SGMLBlockDefault);
    setColor(QColor("#3900FF"), QsciLexerHTML::JavaScriptStart);
    setColor(color, QsciLexerHTML::JavaScriptDefault);
    setColor(QColor("#EA0000"), QsciLexerHTML::JavaScriptComment);
    setColor(QColor("#EA0000"), QsciLexerHTML::JavaScriptCommentLine);
    setColor(QColor("#EA0000"), QsciLexerHTML::JavaScriptCommentDoc);
    setColor(color, QsciLexerHTML::JavaScriptWord);
    setColor(QColor("#FF6D00"), QsciLexerHTML::JavaScriptKeyword);
    setColor(QColor("#39FF00"), QsciLexerHTML::JavaScriptDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::JavaScriptSingleQuotedString);
    setColor(color, QsciLexerHTML::JavaScriptSymbol);
    setColor(QColor("#06DD00"), QsciLexerHTML::JavaScriptUnclosedString);
    setColor(color, QsciLexerHTML::JavaScriptRegex);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPJavaScriptStart);
    setColor(color, QsciLexerHTML::ASPJavaScriptDefault);
    setColor(QColor("#EA0000"), QsciLexerHTML::ASPJavaScriptComment);
    setColor(QColor("#EA0000"), QsciLexerHTML::ASPJavaScriptCommentLine);
    setColor(QColor("#EA0000"), QsciLexerHTML::ASPJavaScriptCommentDoc);
    setColor(color, QsciLexerHTML::ASPJavaScriptWord);
    setColor(QColor("#FF6D00"), QsciLexerHTML::ASPJavaScriptKeyword);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPJavaScriptDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPJavaScriptSingleQuotedString);
    setColor(color, QsciLexerHTML::ASPJavaScriptSymbol);
    setColor(QColor("#06DD00"), QsciLexerHTML::ASPJavaScriptUnclosedString);
    setColor(color, QsciLexerHTML::ASPJavaScriptRegex);
    setColor(QColor("#3900FF"), QsciLexerHTML::PythonStart);
    setColor(color, QsciLexerHTML::PythonDefault);
    setColor(QColor("#EA0000"), QsciLexerHTML::PythonComment);
    setColor(QColor("#39FF00"), QsciLexerHTML::PythonSingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::PythonDoubleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerHTML::PythonKeyword);
    setColor(QColor("#39FF00"), QsciLexerHTML::PythonTripleSingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::PythonTripleDoubleQuotedString);
    setColor(QColor("#3900FF"), QsciLexerHTML::PythonClassName);
    setColor(QColor("#3900FF"), QsciLexerHTML::PythonFunctionMethodName);
    setColor(color, QsciLexerHTML::PythonOperator);
    setColor(color, QsciLexerHTML::PythonIdentifier);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPPythonStart);
    setColor(color, QsciLexerHTML::ASPPythonDefault);
    setColor(QColor("#EA0000"), QsciLexerHTML::ASPPythonComment);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPPythonSingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPPythonDoubleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerHTML::ASPPythonKeyword);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPPythonTripleSingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::ASPPythonTripleDoubleQuotedString);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPPythonClassName);
    setColor(QColor("#3900FF"), QsciLexerHTML::ASPPythonFunctionMethodName);
    setColor(color, QsciLexerHTML::ASPPythonOperator);
    setColor(color, QsciLexerHTML::ASPPythonIdentifier);
    setColor(color, QsciLexerHTML::PHPDefault);
    setColor(QColor("#39FF00"), QsciLexerHTML::PHPDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerHTML::PHPSingleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerHTML::PHPKeyword);
    setColor(QColor("#3900FF"), QsciLexerHTML::PHPVariable);
    setColor(QColor("#EA0000"), QsciLexerHTML::PHPComment);
    setColor(QColor("#EA0000"), QsciLexerHTML::PHPCommentLine);
    setColor(color, QsciLexerHTML::PHPDoubleQuotedVariable);
    setColor(color, QsciLexerHTML::PHPOperator);

    setFont(font, QsciLexerHTML::Default);
    setFont(font, QsciLexerHTML::Tag);
    setFont(font, QsciLexerHTML::UnknownTag);
    setFont(font, QsciLexerHTML::Attribute);
    setFont(font, QsciLexerHTML::UnknownAttribute);
    setFont(font, QsciLexerHTML::HTMLDoubleQuotedString);
    setFont(font, QsciLexerHTML::HTMLSingleQuotedString);
    setFont(font, QsciLexerHTML::OtherInTag);
    setFont(font, QsciLexerHTML::HTMLComment);
    setFont(font, QsciLexerHTML::Entity);
    setFont(font, QsciLexerHTML::XMLTagEnd);
    setFont(font, QsciLexerHTML::XMLStart);
    setFont(font, QsciLexerHTML::XMLEnd);
    setFont(font, QsciLexerHTML::Script);
    setFont(font, QsciLexerHTML::ASPAtStart);
    setFont(font, QsciLexerHTML::ASPStart);
    setFont(font, QsciLexerHTML::CDATA);
    setFont(font, QsciLexerHTML::PHPStart);
    setFont(font, QsciLexerHTML::HTMLValue);
    setFont(font, QsciLexerHTML::ASPXCComment);
    setFont(font, QsciLexerHTML::SGMLDefault);
    setFont(font, QsciLexerHTML::SGMLCommand);
    setFont(font, QsciLexerHTML::SGMLParameter);
    setFont(font, QsciLexerHTML::SGMLDoubleQuotedString);
    setFont(font, QsciLexerHTML::SGMLSingleQuotedString);
    setFont(font, QsciLexerHTML::SGMLError);
    setFont(font, QsciLexerHTML::SGMLSpecial);
    setFont(font, QsciLexerHTML::SGMLEntity);
    setFont(font, QsciLexerHTML::SGMLComment);
    setFont(font, QsciLexerHTML::SGMLParameterComment);
    setFont(font, QsciLexerHTML::SGMLBlockDefault);
    setFont(font, QsciLexerHTML::JavaScriptStart);
    setFont(font, QsciLexerHTML::JavaScriptDefault);
    setFont(font, QsciLexerHTML::JavaScriptComment);
    setFont(font, QsciLexerHTML::JavaScriptCommentLine);
    setFont(font, QsciLexerHTML::JavaScriptCommentDoc);
    setFont(font, QsciLexerHTML::JavaScriptWord);
    setFont(font, QsciLexerHTML::JavaScriptKeyword);
    setFont(font, QsciLexerHTML::JavaScriptDoubleQuotedString);
    setFont(font, QsciLexerHTML::JavaScriptSingleQuotedString);
    setFont(font, QsciLexerHTML::JavaScriptSymbol);
    setFont(font, QsciLexerHTML::JavaScriptUnclosedString);
    setFont(font, QsciLexerHTML::JavaScriptRegex);
    setFont(font, QsciLexerHTML::ASPJavaScriptStart);
    setFont(font, QsciLexerHTML::ASPJavaScriptDefault);
    setFont(font, QsciLexerHTML::ASPJavaScriptComment);
    setFont(font, QsciLexerHTML::ASPJavaScriptCommentLine);
    setFont(font, QsciLexerHTML::ASPJavaScriptCommentDoc);
    setFont(font, QsciLexerHTML::ASPJavaScriptWord);
    setFont(font, QsciLexerHTML::ASPJavaScriptKeyword);
    setFont(font, QsciLexerHTML::ASPJavaScriptDoubleQuotedString);
    setFont(font, QsciLexerHTML::ASPJavaScriptSingleQuotedString);
    setFont(font, QsciLexerHTML::ASPJavaScriptSymbol);
    setFont(font, QsciLexerHTML::ASPJavaScriptUnclosedString);
    setFont(font, QsciLexerHTML::ASPJavaScriptRegex);
    setFont(font, QsciLexerHTML::PythonStart);
    setFont(font, QsciLexerHTML::PythonDefault);
    setFont(font, QsciLexerHTML::PythonComment);
    setFont(font, QsciLexerHTML::PythonSingleQuotedString);
    setFont(font, QsciLexerHTML::PythonDoubleQuotedString);
    setFont(font, QsciLexerHTML::PythonKeyword);
    setFont(font, QsciLexerHTML::PythonTripleSingleQuotedString);
    setFont(font, QsciLexerHTML::PythonTripleDoubleQuotedString);
    setFont(font, QsciLexerHTML::PythonClassName);
    setFont(font, QsciLexerHTML::PythonFunctionMethodName);
    setFont(font, QsciLexerHTML::PythonOperator);
    setFont(font, QsciLexerHTML::PythonIdentifier);
    setFont(font, QsciLexerHTML::ASPPythonStart);
    setFont(font, QsciLexerHTML::ASPPythonDefault);
    setFont(font, QsciLexerHTML::ASPPythonComment);
    setFont(font, QsciLexerHTML::ASPPythonSingleQuotedString);
    setFont(font, QsciLexerHTML::ASPPythonDoubleQuotedString);
    setFont(font, QsciLexerHTML::ASPPythonKeyword);
    setFont(font, QsciLexerHTML::ASPPythonTripleSingleQuotedString);
    setFont(font, QsciLexerHTML::ASPPythonTripleDoubleQuotedString);
    setFont(font, QsciLexerHTML::ASPPythonClassName);
    setFont(font, QsciLexerHTML::ASPPythonFunctionMethodName);
    setFont(font, QsciLexerHTML::ASPPythonOperator);
    setFont(font, QsciLexerHTML::ASPPythonIdentifier);
    setFont(font, QsciLexerHTML::PHPDefault);
    setFont(font, QsciLexerHTML::PHPDoubleQuotedString);
    setFont(font, QsciLexerHTML::PHPSingleQuotedString);
    setFont(font, QsciLexerHTML::PHPKeyword);
    setFont(font, QsciLexerHTML::PHPVariable);
    setFont(font, QsciLexerHTML::PHPComment);
    setFont(font, QsciLexerHTML::PHPCommentLine);
    setFont(font, QsciLexerHTML::PHPDoubleQuotedVariable);
    setFont(font, QsciLexerHTML::PHPOperator);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(set1).split(" "))
    {
        api->add(str + "?10");
    }

    for (const QString &str : QString(set2).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(set3).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(set4).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(set5).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(set6).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
