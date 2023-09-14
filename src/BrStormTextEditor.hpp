/**
 * @brief BrStormTextEditor.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 28 May 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTEDITOR_HPP
#define BRSTORMTEXTEDITOR_HPP


#include <QColor>
#include <QFlags>
#include <QFont>
#include <Qsci/qsciscintilla.h>


class BrStormTextEditor : public QsciScintilla
{
    Q_OBJECT

public:

    BrStormTextEditor(QWidget *parent = nullptr);

public:

    void setLexerNone();
    void adjustColors();
    bool markerEnable() {return m_enableMarkers;}
    QsciScintilla::WrapVisualFlag wrapVisualFlag() {return m_wrapVisualFlag;}

public:

    void setWrapVisualFlags(WrapVisualFlag endFlag, WrapVisualFlag startFlag = WrapFlagNone, int indent = 0);

/**
 * @todo: Add more languages
 */
public slots:
    
    void setEnableMarkers(bool e);
    void addMarker(bool);
    void delMarker(bool);
    void delAllMarkers(bool);
    void increaseIndent(bool);
    void decreaseIndent(bool);

    void setLexerAVS(bool);
    void setLexerBash(bool);
    void setLexerBatch(bool);
    void setLexerC(bool);
    void setLexerCMake(bool);
    void setLexerCPP(bool);
    void setLexerCSharp(bool);
    void setLexerCoffeeScript(bool);
    void setLexerCSS(bool);
    void setLexerD(bool);
    void setLexerDiff(bool);
    void setLexerEDIFACT(bool);
    void setLexerFortran(bool);
    void setLexerFortran77(bool);
    void setLexerHTML(bool);
    void setLexerIDL(bool);
    void setLexerJava(bool);
    void setLexerJavaScript(bool);
    void setLexerJSON(bool);
    void setLexerLua(bool);
    void setLexerMakefile(bool);
    void setLexerMarkdown(bool);
    void setLexerMatlab(bool);
    void setLexerOctave(bool);
    void setLexerPascal(bool);
    void setLexerPerl(bool);
    void setLexerPO(bool);
    void setLexerPostScript(bool);
    void setLexerPOV(bool);
    void setLexerProperties(bool);
    void setLexerPython(bool);
    void setLexerPython3(bool);
    void setLexerQSS(bool);
    void setLexerRuby(bool);
    void setLexerSpice(bool);
    void setLexerSQL(bool);
    void setLexerTCL(bool);
    void setLexerTeX(bool);
    void setLexerVerilog(bool);
    void setLexerVHDL(bool);
    void setLexerXML(bool);
    void setLexerYAML(bool);

private slots:

    void marginClicked_(int, int, QFlags<Qt::KeyboardModifier>);
    void positionChanged(int, int);
    void selectionChanged_();
    void adjustMargins();

private:
    
    bool m_enableMarkers;
    int markerNum;
    QColor m_marginBg;
    QColor m_marginFg;
    QColor m_caretLineBg;
    QColor m_indentationGuideColor;
    QFont m_font;
    QsciScintilla::WrapVisualFlag m_wrapVisualFlag;
};

#endif // BRSTORMTEXTEDITOR_HPP


