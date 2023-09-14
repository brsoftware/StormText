/**
 * @brief BrStormTextEditor.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextEditor.hpp"

#include "BrStormTextLexers/BrStormTextLexerAVS.hpp"
#include "BrStormTextLexers/BrStormTextLexerBash.hpp"
#include "BrStormTextLexers/BrStormTextLexerBatch.hpp"
#include "BrStormTextLexers/BrStormTextLexerC.hpp"
#include "BrStormTextLexers/BrStormTextLexerCMake.hpp"
#include "BrStormTextLexers/BrStormTextLexerCPP.hpp"
#include "BrStormTextLexers/BrStormTextLexerCSharp.hpp"
#include "BrStormTextLexers/BrStormTextLexerCoffeeScript.hpp"
#include "BrStormTextLexers/BrStormTextLexerCSS.hpp"
#include "BrStormTextLexers/BrStormTextLexerD.hpp"
#include "BrStormTextLexers/BrStormTextLexerDiff.hpp"
#include "BrStormTextLexers/BrStormTextLexerEDIFACT.hpp"
#include "BrStormTextLexers/BrStormTextLexerFortran.hpp"
#include "BrStormTextLexers/BrStormTextLexerFortran77.hpp"
#include "BrStormTextLexers/BrStormTextLexerHTML.hpp"
#include "BrStormTextLexers/BrStormTextLexerIDL.hpp"
#include "BrStormTextLexers/BrStormTextLexerJava.hpp"
#include "BrStormTextLexers/BrStormTextLexerJavaScript.hpp"
#include "BrStormTextLexers/BrStormTextLexerJSON.hpp"
#include "BrStormTextLexers/BrStormTextLexerLua.hpp"
#include "BrStormTextLexers/BrStormTextLexerMakefile.hpp"
#include "BrStormTextLexers/BrStormTextLexerMarkdown.hpp"
#include "BrStormTextLexers/BrStormTextLexerMatlab.hpp"
#include "BrStormTextLexers/BrStormTextLexerOctave.hpp"
#include "BrStormTextLexers/BrStormTextLexerPascal.hpp"
#include "BrStormTextLexers/BrStormTextLexerPerl.hpp"
#include "BrStormTextLexers/BrStormTextLexerPO.hpp"
#include "BrStormTextLexers/BrStormTextLexerPostScript.hpp"
#include "BrStormTextLexers/BrStormTextLexerPOV.hpp"
#include "BrStormTextLexers/BrStormTextLexerProperties.hpp"
#include "BrStormTextLexers/BrStormTextLexerPython.hpp"
#include "BrStormTextLexers/BrStormTextLexerPython3.hpp"
#include "BrStormTextLexers/BrStormTextLexerQSS.hpp"
#include "BrStormTextLexers/BrStormTextLexerRuby.hpp"
#include "BrStormTextLexers/BrStormTextLexerSpice.hpp"
#include "BrStormTextLexers/BrStormTextLexerSQL.hpp"
#include "BrStormTextLexers/BrStormTextLexerTCL.hpp"
#include "BrStormTextLexers/BrStormTextLexerTeX.hpp"
#include "BrStormTextLexers/BrStormTextLexerVerilog.hpp"
#include "BrStormTextLexers/BrStormTextLexerVHDL.hpp"
#include "BrStormTextLexers/BrStormTextLexerXML.hpp"
#include "BrStormTextLexers/BrStormTextLexerYAML.hpp"

#include <QApplication>
#include <QDebug>
#include <QKeyEvent>
#include <QRgb>


BrStormTextEditor::BrStormTextEditor(QWidget *parent)
    : QsciScintilla(parent)
{
    markerNum = 8;
    m_enableMarkers = true;

    m_caretLineBg = QColor();
    m_caretLineBg.setBlue(0xff);
    m_caretLineBg.setGreen(0xff);
    m_caretLineBg.setRed(0xe9);
    m_caretLineBg.setAlpha(50);

    m_indentationGuideColor = QColor();
    m_indentationGuideColor = QApplication::palette().color(QPalette::ToolTipText);

    /*QColor marginBg = QColor();
    marginBg.setBlue(0x00);
    marginBg.setGreen(0x00);
    marginBg.setRed(0x00);
    caretLineBg.setAlpha(50);*/
    m_marginBg = QColor();
    m_marginBg = QApplication::palette().color(QPalette::Window);

    m_marginFg = QColor();
    /*7f, 7f, 7f*/
    m_marginFg = QApplication::palette().color(QPalette::WindowText);

    m_font = QFont();
    m_font.setStyleHint(QFont::Monospace);
    m_font.setFamily(m_font.defaultFamily());
    m_font.setPointSize(QApplication::font().pointSize() * 2);

    setAutoCompletionCaseSensitivity(false);
    setAutoCompletionReplaceWord(true);
    setAutoCompletionShowSingle(true);
    setAutoCompletionSource(QsciScintilla::AcsAll);
    setAutoCompletionThreshold(1);
    setAutoCompletionFillupsEnabled(true);
    setAutoIndent(true);
    setBraceMatching(QsciScintilla::SloppyBraceMatch);
    setBackspaceUnindents(true);
    setCaretForegroundColor(QColor("#8B00FF"));
    setCaretLineBackgroundColor(m_caretLineBg);
    setCaretLineVisible(true);
    setCaretWidth(3);
    setEolMode(QsciScintilla::EolUnix);
    setEolVisibility(false);
    setFolding(QsciScintilla::PlainFoldStyle);
    setFoldMarginColors(m_marginBg, m_marginBg);
    setFont(m_font);
    setIndentationGuides(true);
    setIndentationGuidesBackgroundColor(m_indentationGuideColor);
    setIndentationGuidesForegroundColor(m_indentationGuideColor);
    setIndentationsUseTabs(false);
    setIndentationWidth(4);
    setLexer();
    setMatchedBraceBackgroundColor(QApplication::palette().color(QPalette::Button));
    setMatchedBraceForegroundColor(QColor("#0000FF"));
    setMarginsBackgroundColor(m_marginBg);
    setMarginsFont(m_font);
    setMarginsForegroundColor(m_marginFg);
    setMarginLineNumbers(0, true);
    setMarginMarkerMask(1, ~QsciScintilla::SC_MASK_FOLDERS);
    setMarginSensitivity(1, true);
    setMarginType(1, QsciScintilla::SymbolMargin);
    markerDefine(QsciScintilla::Bookmark, markerNum);
    setMarkerBackgroundColor(QApplication::palette().color(QPalette::Text), markerNum);
    setMarkerForegroundColor(QApplication::palette().color(QPalette::Text), markerNum);
    setReadOnly(false);
    setSelectionBackgroundColor(QApplication::palette().color(QPalette::Button));
    setSelectionForegroundColor(QApplication::palette().color(QPalette::ButtonText));
    setTabIndents(4);
    setTabWidth(4);
    setUnmatchedBraceBackgroundColor(QApplication::palette().color(QPalette::Button));
    setUnmatchedBraceForegroundColor(QColor("#AA0000"));
    setUtf8(true);
    setWrapMode(QsciScintilla::WrapWord);

    SendScintilla(QsciScintilla::SCI_SETADDITIONALSELECTIONTYPING, true);
    SendScintilla(QsciScintilla::SCI_SETMULTIPLESELECTION, true);

    registerImage(1, QImage(":/rsc/icon-lang-clip-property.png"));
    registerImage(2, QImage(":/rsc/icon-lang-filter.png"));
    registerImage(3, QImage(":/rsc/icon-lang-function.png"));
    registerImage(4, QImage(":/rsc/icon-lang-keyword.png"));
    registerImage(5, QImage(":/rsc/icon-lang-plugin.png"));
    registerImage(6, QImage(":/rsc/icon-lang-preprocessor.png"));
    registerImage(7, QImage(":/rsc/icon-lang-property.png"));
    registerImage(8, QImage(":/rsc/icon-lang-pseudo-class.png"));
    registerImage(9, QImage(":/rsc/icon-lang-pseudo-element.png"));
    registerImage(10, QImage(":/rsc/icon-lang-tag.png"));

    connect(this, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(positionChanged(int,int)));
    connect(this, SIGNAL(selectionChanged()), this, SLOT(selectionChanged_()));
    // connect(this, SIGNAL(marginClicked(int,int,QFlags<Qt::KeyboardModifier>)),
    //         this, SLOT(marginClicked_(int,int,QFlags<Qt::KeyboardModifier>)));
    connect(this, &BrStormTextEditor::marginClicked,
            this, &BrStormTextEditor::marginClicked_);
}

void BrStormTextEditor::setLexerNone()
{
    setLexer();

    adjustColors();

    QString text_ = text();

    beginUndoAction();
    clear();
    insert(text_);

    endUndoAction();
}

void BrStormTextEditor::adjustColors()
{
    setFont(m_font);
    setMarginsFont(m_font);
    setMarginsBackgroundColor(m_marginBg);
    setMarginsForegroundColor(m_marginFg);
    setIndentationGuidesBackgroundColor(m_indentationGuideColor);
    setIndentationGuidesForegroundColor(m_indentationGuideColor);
    setMatchedBraceForegroundColor(QColor("#0000FF"));
    setMatchedBraceBackgroundColor(QApplication::palette().color(QPalette::Button));
    setUnmatchedBraceForegroundColor(QColor("#AA0000"));
    setUnmatchedBraceBackgroundColor(QApplication::palette().color(QPalette::Button));
    setMarkerBackgroundColor(QApplication::palette().color(QPalette::Text), markerNum);
    setMarkerForegroundColor(QApplication::palette().color(QPalette::Text), markerNum);
}

void BrStormTextEditor::setWrapVisualFlags(QsciScintilla::WrapVisualFlag endFlag,
                                           QsciScintilla::WrapVisualFlag startFlag, int indent)
{
    m_wrapVisualFlag = endFlag;

    QsciScintilla::setWrapVisualFlags(endFlag, startFlag, indent);
}

void BrStormTextEditor::marginClicked_(int margin, int line, QFlags<Qt::KeyboardModifier> state)
{
    Q_UNUSED(state)

    if (margin == 1)
    {
        // marker one
        
        if (m_enableMarkers)
        {
            if (markersAtLine(line) == 0)
            {
                markerAdd(line, markerNum);
            }

            else
            {
                markerDelete(line);
            }
        }
    }
}

void BrStormTextEditor::positionChanged(int line, int index)
{
    Q_UNUSED(line)
    Q_UNUSED(index)

    adjustMargins();
}

void BrStormTextEditor::selectionChanged_()
{
    adjustMargins();
}

void BrStormTextEditor::adjustMargins()
{
    int margin = text().split("\n").count();
    setMarginWidth(0, QFontMetrics(font()).horizontalAdvance(QString::number(margin)) + 30);
}

void BrStormTextEditor::setEnableMarkers(bool e)
{
    if (m_enableMarkers != e)
        m_enableMarkers = e;
}

void BrStormTextEditor::addMarker(bool isChecked)
{
    Q_UNUSED(isChecked)
    
    markerAdd(SendScintilla(SCI_LINEFROMPOSITION, SendScintilla(SCI_GETCURRENTPOS)), markerNum);
}

void BrStormTextEditor::delMarker(bool isChecked)
{
    Q_UNUSED(isChecked)
    
    markerDelete(SendScintilla(SCI_LINEFROMPOSITION, SendScintilla(SCI_GETCURRENTPOS)), markerNum);
}

void BrStormTextEditor::delAllMarkers(bool isChecked)
{
    Q_UNUSED(isChecked)
    
    markerDeleteAll(markerNum);
}

void BrStormTextEditor::increaseIndent(bool isChecked)
{
    Q_UNUSED(isChecked)

    int line = SendScintilla(SCI_LINEFROMPOSITION, SendScintilla(SCI_GETCURRENTPOS));
    indent(line);
}

void BrStormTextEditor::decreaseIndent(bool isChecked)
{
    Q_UNUSED(isChecked)

    int line = SendScintilla(SCI_LINEFROMPOSITION, SendScintilla(SCI_GETCURRENTPOS));
    unindent(line);
}

/**
 * @todo: Add more languages
 */

void BrStormTextEditor::setLexerAVS(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerAVS *lexer;
    lexer = new BrStormTextLexerAVS(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerBash(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerBash *lexer;
    lexer = new BrStormTextLexerBash(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerBatch(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerBatch *lexer;
    lexer = new BrStormTextLexerBatch(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerC(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerC *lexer;
    lexer = new BrStormTextLexerC(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerCMake(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerCMake *lexer;
    lexer = new BrStormTextLexerCMake(color(), font());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerCPP(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerCPP *lexer;
    lexer = new BrStormTextLexerCPP(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerCSharp(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerCSharp *lexer;
    lexer = new BrStormTextLexerCSharp(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerCoffeeScript(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerCoffeeScript *lexer;
    lexer = new BrStormTextLexerCoffeeScript(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerCSS(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerCSS *lexer;
    lexer = new BrStormTextLexerCSS(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerD(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerD *lexer;
    lexer = new BrStormTextLexerD(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerDiff(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerDiff *lexer;
    lexer = new BrStormTextLexerDiff(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerEDIFACT(bool isChecked)
{
    Q_UNUSED(isChecked)

    append("\n");

    BrStormTextLexerEDIFACT *lexer;
    lexer = new BrStormTextLexerEDIFACT(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerFortran(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerFortran *lexer;
    lexer = new BrStormTextLexerFortran(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerFortran77(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerFortran77 *lexer;
    lexer = new BrStormTextLexerFortran77(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerHTML(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerHTML *lexer;
    lexer = new BrStormTextLexerHTML(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerIDL(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerIDL *lexer;
    lexer = new BrStormTextLexerIDL(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerJava(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerJava *lexer;
    lexer = new BrStormTextLexerJava(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerJavaScript(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerJavaScript *lexer;
    lexer = new BrStormTextLexerJavaScript(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerJSON(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerJSON *lexer;
    lexer = new BrStormTextLexerJSON(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerLua(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerLua *lexer;
    lexer = new BrStormTextLexerLua(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerMakefile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerMakefile *lexer;
    lexer = new BrStormTextLexerMakefile(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerMarkdown(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerMarkdown *lexer;
    lexer = new BrStormTextLexerMarkdown(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerMatlab(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerMatlab *lexer;
    lexer = new BrStormTextLexerMatlab(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerOctave(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerOctave *lexer;
    lexer = new BrStormTextLexerOctave(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPascal(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPascal *lexer;
    lexer = new BrStormTextLexerPascal(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPerl(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPerl *lexer;
    lexer = new BrStormTextLexerPerl(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPO(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPO *lexer;
    lexer = new BrStormTextLexerPO(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPostScript(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPostScript *lexer;
    lexer = new BrStormTextLexerPostScript(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPOV(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPOV *lexer;
    lexer = new BrStormTextLexerPOV(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerProperties(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerProperties *lexer;
    lexer = new BrStormTextLexerProperties(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPython(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPython *lexer;
    lexer = new BrStormTextLexerPython(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerPython3(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerPython3 *lexer;
    lexer = new BrStormTextLexerPython3(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerQSS(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerQSS *lexer;
    lexer = new BrStormTextLexerQSS(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerRuby(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerRuby *lexer;
    lexer = new BrStormTextLexerRuby(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerSpice(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerSpice *lexer;
    lexer = new BrStormTextLexerSpice(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerSQL(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerSQL *lexer;
    lexer = new BrStormTextLexerSQL(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerTCL(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerTCL *lexer;
    lexer = new BrStormTextLexerTCL(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerTeX(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerTeX *lexer;
    lexer = new BrStormTextLexerTeX(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerVerilog(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerVerilog *lexer;
    lexer = new BrStormTextLexerVerilog(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerVHDL(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerVHDL *lexer;
    lexer = new BrStormTextLexerVHDL(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerXML(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerXML *lexer;
    lexer = new BrStormTextLexerXML(font(), color());

    setLexer(lexer);
    adjustColors();
}

void BrStormTextEditor::setLexerYAML(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextLexerYAML *lexer;
    lexer = new BrStormTextLexerYAML(font(), color());

    setLexer(lexer);
    adjustColors();
}
