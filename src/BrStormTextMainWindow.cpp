/**
 * @brief BrStormTextMainWindow.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 27 May 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextMainWindow.hpp"
#include "BrStormTextEditor.hpp"
#include "BrStormTextDialogs/BrStormTextOpenDialog.hpp"
#include "BrStormTextDialogs/BrStormTextSaveCopyToDialog.hpp"
#include "BrStormTextDialogs/BrStormTextSaveDialog.hpp"
#include "BrStormTextApplication.hpp"

#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileIconProvider>
#include <QHeaderView>
#include <QMessageBox>
#include <Qsci/qscilexer.h>
#include <QTextStream>
#include <QDebug>


BrStormTextMainWindow::BrStormTextMainWindow(QList<QString> argv, BrStormTextApplication *app, int u, bool o, QWidget *parent)
    : QMainWindow(parent)
{
    qSetMessagePattern("[%{type}] %{line} %{function} - %{message}");

    m_untitled = u;
    m_app = app;

    setUnifiedTitleAndToolBarOnMac(true);

#ifndef Q_OS_DARWIN
    setWindowIcon(QIcon(":/rsc/stormtext-icon.png"));
#endif

    initUi();

    if (o) openFile(true);

    for (const QString &str : argv)
    {
        openThroughArgs(str);
    }
}

QString BrStormTextMainWindow::getCurrentLexer()
{
    /**
     * @todo: Add more languages
     */

    if (m_actionFormatLanguageNone->isChecked()) return "None";
    else if (m_actionFormatLanguageAVS->isChecked()) return "AVS";
    else if (m_actionFormatLanguageBash->isChecked()) return "Bash";
    else if (m_actionFormatLanguageBatch->isChecked()) return "Batch";
    else if (m_actionFormatLanguageC->isChecked()) return "C";
    else if (m_actionFormatLanguageCMake->isChecked()) return "CMake";
    else if (m_actionFormatLanguageCoffeeScript->isChecked()) return "CoffeeScript";
    else if (m_actionFormatLanguageCPP->isChecked()) return "CPP";
    else if (m_actionFormatLanguageCSharp->isChecked()) return "CSharp";
    else if (m_actionFormatLanguageCSS->isChecked()) return "CSS";
    else if (m_actionFormatLanguageD->isChecked()) return "D";
    else if (m_actionFormatLanguageDiff->isChecked()) return "Diff";
    else if (m_actionFormatLanguageEDIFACT->isChecked()) return "EDIFACT";
    else if (m_actionFormatLanguageFortran->isChecked()) return "Fortran";
    else if (m_actionFormatLanguageFortran77->isChecked()) return "Fortran77";
    else if (m_actionFormatLanguageHTML->isChecked()) return "HTML";
    else if (m_actionFormatLanguageIDL->isChecked()) return "IDL";
    else if (m_actionFormatLanguageJava->isChecked()) return "Java";
    else if (m_actionFormatLanguageJavaScript->isChecked()) return "JavaScript";
    else if (m_actionFormatLanguageJSON->isChecked()) return "JSON";
    else if (m_actionFormatLanguageLua->isChecked()) return "Lua";
    else if (m_actionFormatLanguageMakefile->isChecked()) return "Makefile";
    else if (m_actionFormatLanguageMarkdown->isChecked()) return "Markdown";
    else if (m_actionFormatLanguageMatlab->isChecked()) return "Matlab";
    else if (m_actionFormatLanguageOctave->isChecked()) return "Octave";
    else if (m_actionFormatLanguagePascal->isChecked()) return "Pascal";
    else if (m_actionFormatLanguagePerl->isChecked()) return "Perl";
    else if (m_actionFormatLanguagePO->isChecked()) return "PO";
    else if (m_actionFormatLanguagePostScript->isChecked()) return "PostScript";
    else if (m_actionFormatLanguagePOV->isChecked()) return "POV";
    else if (m_actionFormatLanguageProperties->isChecked()) return "Properties";
    else if (m_actionFormatLanguagePython->isChecked()) return "Python";
    else if (m_actionFormatLanguagePython3->isChecked()) return "Python3";
    else if (m_actionFormatLanguageQSS->isChecked()) return "QSS";
    else if (m_actionFormatLanguageRuby->isChecked()) return "Ruby";
    else if (m_actionFormatLanguageSpice->isChecked()) return "Spice";
    else if (m_actionFormatLanguageSQL->isChecked()) return "SQL";
    else if (m_actionFormatLanguageTCL->isChecked()) return "TCL";
    else if (m_actionFormatLanguageTeX->isChecked()) return "TeX";
    else if (m_actionFormatLanguageVerilog->isChecked()) return "Verilog";
    else if (m_actionFormatLanguageVHDL->isChecked()) return "VHDL";
    else if (m_actionFormatLanguageXML->isChecked()) return "XML";
    else if (m_actionFormatLanguageYAML->isChecked()) return "YAML";
    else return "";
}

void BrStormTextMainWindow::openThroughArgs(QString path)
{
    QFile f(path);

    if (!m_tab) return;

    if (!f.exists())
    {
        QMessageBox msg = QMessageBox(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setWindowTitle(tr("FileNoutFoundError"));
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("Sorry, the file you have selected does not exists."));
        msg.setInformativeText(tr("Check if you have misspelt the file name,"
                                  "the file path or check your network connections. \n"
                                  "BR_STORMTEXT_0x00003855"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }

    if (f.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream ts(&f);
        QString c = ts.readAll();
        QFileInfo fi(f);
        QFileIconProvider fip;
        QIcon icns = fip.icon(fi);
        QString ce = fi.completeSuffix().toLower();

        bool cfnit = false;

        for (int ti = 0; ti < m_tab->count(); ti++)
        {
            if (m_tab->tabToolTip(ti) == fi.absoluteFilePath())
            {
                cfnit = true;
                break;
            }
        }

        if (cfnit) return;

        BrStormTextEditor *ed;
        ed = new BrStormTextEditor(this);
        ed->setText(c);

        connect(ed, &BrStormTextEditor::modificationChanged,
                this, [=](bool m){setWindowModified(m);});

        /**
         * @todo: Add more languages
         */

        if (ce == "avs")
        {
            ed->setLexerAVS(true);
        }

        else if (ce == "sh"
                 || ce == "bash")
        {
            ed->setLexerBash(true);
        }

        else if (ce == "bat"
                 || ce =="cmd"
                 || ce == "btm")
        {
            ed->setLexerBatch(true);
        }

        else if (ce == "c")
        {
            ed->setLexerC(true);
        }

        else if (ce == "cpp"
                 || ce == "cxx"
                 || ce == "cc"
                 || ce == "ii"
                 || ce == "hpp"
                 || ce == "hxx")
        {
            ed->setLexerCPP(true);
        }

        else if (ce == "h")
        {
            if (QString(c).contains("class"))
                ed->setLexerCPP(true);
            else
                ed->setLexerC(true);
        }

        else if (ce == "cmake"
                 || fi.fileName() == "CMakeLists.txt"
                 || fi.fileName() == "CMakeCache.txt")
        {
            ed->setLexerCMake(true);
        }

        else if (ce == "coffee"
                 || ce == "litcoffee")
        {
            ed->setLexerCoffeeScript(true);
        }

        else if (ce == "cs")
        {
            ed->setLexerCSharp(true);
        }

        else if (ce == "css")
        {
            ed->setLexerCSS(true);
        }

        else if (ce == "d")
        {
            ed->setLexerD(true);
        }

        else if (ce == "diff")
        {
            ed->setLexerDiff(true);
        }

        else if (ce == "edifact")
        {
            ed->setLexerEDIFACT(true);
        }

        else if (ce == "f90"
                 || ce == "f95"
                 || ce == "f03"
                 || ce == "f"
                 || ce == "for")
        {
            ed->setLexerFortran(true);
        }

        else if (ce == "f77")
        {
            ed->setLexerFortran77(true);
        }

        else if (ce == "html"
                 || ce == "htm"
                 || ce == "mhtml"
                 || ce == "shtml")
        {
            ed->setLexerHTML(true);
        }

        else if (ce == "idl")
        {
            ed->setLexerIDL(true);
        }

        else if (ce == "java")
        {
            ed->setLexerJava(true);
        }

        else if (ce == "js"
                 || ce == "javascript"
                 || fi.fileName() == "node.js")
        {
            ed->setLexerJavaScript(true);
        }

        else if (ce == "json")
        {
            ed->setLexerJSON(true);
        }

        else if (ce == "lua")
        {
            ed->setLexerLua(true);
        }

        else if (ce == "make"
                 || ce == "makefile"
                 || fi.fileName().toLower() == "makefile"
                 || fi.fileName().toLower() == "make")
        {
            ed->setLexerMakefile(true);
        }

        else if (ce == "md"
                 || ce == "markdown"
                 || ce == "commonmark")
        {
            ed->setLexerMarkdown(true);
        }

        else if (ce == "mex"
                 || ce == "mat"
                 || ce == "mlx"
                 || ce == "mlapp")
        {
            ed->setLexerMatlab(true);
        }

        else if (ce == "octave")
        {
            ed->setLexerOctave(true);
        }

        else if (ce == "pas"
                 || ce == "pp")
        {
            ed->setLexerPascal(true);
        }

        else if (ce == "plx"
                 || ce == "pl"
                 || ce == "pm")
        {
            ed->setLexerPerl(true);
        }

        else if (ce == "po")
        {
            ed->setLexerPO(true);
        }

        else if (ce == "ps")
        {
            ed->setLexerPostScript(true);
        }

        else if (ce == "pov"
                 || ce == "povray")
        {
            ed->setLexerPOV(true);
        }

        else if (ce == "psl")
        {
            ed->setLexerProperties(true);
        }

        else if (ce == "py"
                 || ce == "py3"
                 || ce == "pyw"
                 || ce == "pypy"
                 || ce == "egg"
                 || ce == "egg-info"
                 || ce == "spec"
                 || ce == "pyd"
                 || ce == "ipynb")
        {
            ed->setLexerPython3(true);
        }

        else if (ce == "py2"
                 || ce == "pyo")
        {
            ed->setLexerPython(true);
        }

        else if (ce == "qss")
        {
            ed->setLexerQSS(true);
        }

        else if (ce == "rb"
                 || ce == "ruby"
                 || ce == "gem")
        {
            ed->setLexerRuby(true);
        }

        else if (ce == "spice"
                 || ce == "pspice")
        {
            ed->setLexerSpice(true);
        }

        else if (ce == "sql"
                 || ce == "sql86"
                 || ce == "sql92"
                 || ce == "sql99"
                 || ce == "sql03"
                 || ce == "sql06"
                 || ce == "sql08"
                 || ce == "sql11"
                 || ce == "sql16"
                 || ce == "sqldata")
        {
            ed->setLexerSQL(true);
        }

        else if (ce == "tcl"
                 || ce == "tbc")
        {
            ed->setLexerTCL(true);
        }

        else if (ce == "tex")
        {
            ed->setLexerTeX(true);
        }

        else if (ce == "v"
                 || ce == "vh")
        {
            ed->setLexerVerilog(true);
        }

        else if (ce == "xml"
                 || ce == "svg"
                 || ce == "svgx"
                 || ce == "plist"
                 || ce == "string"
                 || ce == "qrc"
                 || ce == "rc"
                 || ce == "ui"
                 || c.startsWith("<?xml version="))
        {
            ed->setLexerXML(true);
        }

        else if (ce == "yml")
        {
            ed->setLexerYAML(true);
        }

        int i = m_tab->addTab(ed, icns, fi.fileName());
        m_tab->setTabToolTip(i, fi.absoluteFilePath());
        m_tab->setCurrentIndex(i);
        m_tab->currentTab()->setModified(false);
        setWindowModified(m_tab->currentTab()->isModified());
    }

    else
    {
        QMessageBox msg = QMessageBox(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setWindowTitle(tr("OSError"));
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("Sorry, the file you have selected cannot be opened."));
        msg.setInformativeText(tr("This might be caused by inconsistence file access,"
                                  "Or the disconnection of your current network "
                                  "condition. Try to contact your technical manager / "
                                  "system administrator for more information / solution. \n"
                                  "BR_STORMTEXT_0x00000094"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }

    f.close();
    return;
}

void BrStormTextMainWindow::closeEvent(QCloseEvent *event)
{
    if ((!m_tab->currentTab()) ||
        m_tab->count() == 0)
    {
        event->accept();
        return;
    }

    closeAllFile(true);

    if (m_tab->count() == 0) event->accept();
    else event->ignore();
}

void BrStormTextMainWindow::initUi()
{
    m_aAppD = new BrStormTextAboutApplicationDialog(this);
    m_aD = new BrStormTextAboutDialog(this);

    initMenus();
    initTabs();
    initStatusBar();
    initFileBrowser();
    initFindDock();

    m_gD = new BrStormTextGotoDialog(m_tab, this);

    initSignals();

    connect(m_app, SIGNAL(fileOpened(QString)),
            this, SLOT(openThroughArgs(QString)));
}

void BrStormTextMainWindow::initMenus()
{
    m_menuBar = menuBar();

    initFileMenu();
    initEditMenu();
    initViewMenu();
    initFormatMenu();
    initToolsMenu();
    initHelpMenu();

    initActionGroups();
}

void BrStormTextMainWindow::initFileMenu()
{
    m_menuFile = new QMenu(tr("&File"), this);
    m_menuBar->addMenu(m_menuFile);

#if QT_VERSION > QT_VERSION_CHECK(6, 3, 0)

    m_actionFileNew = m_menuFile->addAction(tr("&New"),
                                            QKeySequence::New);
    m_actionFileNewWindow = m_menuFile->addAction(tr("New &Window"),
                                                  QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    m_menuFile->addSeparator();
    m_actionFileOpen = m_menuFile->addAction(tr("&Open..."),
                                             QKeySequence::Open);
    m_actionFileOpenWindow = m_menuFile->addAction(tr("Open &in New Window..."),
                                                   QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));
    m_menuFile->addSeparator();
    m_actionFileSave = m_menuFile->addAction(tr("&Save..."),
                                             QKeySequence::Save);
    m_actionFileSaveAs = m_menuFile->addAction(tr("Save &As..."),
                                               QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_S));
    m_actionFileSaveCopyTo = m_menuFile->addAction(tr("Save &Copy To..."),
                                                   QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::ALT | Qt::Key_S));
    m_actionFileSaveAll = m_menuFile->addAction(tr("Save A&ll..."),
                                                QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    m_menuFile->addSeparator();
    m_actionFileClose = m_menuFile->addAction(tr("Clos&e..."),
                                              QKeySequence(Qt::CTRL | Qt::Key_W));
    m_actionFileCloseAll = m_menuFile->addAction(tr("Close All&..."),
                                                 QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_W));

#else

    m_actionFileNew = m_menuFile->addAction(tr("&New"));
    m_actionFileNew->setShortcut(QKeySequence::New);
    m_actionFileNewWindow = m_menuFile->addAction(tr("New &Window"));
    m_actionFileNewWindow->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));
    m_menuFile->addSeparator();
    m_actionFileOpen = m_menuFile->addAction(tr("&Open..."));
    m_actionFileOpen->setShortcut(QKeySequence::Open);
    m_actionFileOpenWindow = m_menuFile->addAction(tr("Open &in New Window..."));
    m_actionFileOpenWindow->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_O));
    m_menuFile->addSeparator();
    m_actionFileSave = m_menuFile->addAction(tr("&Save..."));
    m_actionFileSave->setShortcut(QKeySequence::Save);
    m_actionFileSaveAs = m_menuFile->addAction(tr("Save &As..."));
    m_actionFileSaveAs->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_S));
    m_actionFileSaveCopyTo = m_menuFile->addAction(tr("Save &Copy To..."));
    m_actionFileSaveCopyTo->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::ALT | Qt::Key_S));
    m_actionFileSaveAll = m_menuFile->addAction(tr("Save A&ll..."));
    m_actionFileSaveAll->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    m_menuFile->addSeparator();
    m_actionFileClose = m_menuFile->addAction(tr("Clos&e..."));
    m_actionFileClose->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_W));
    m_actionFileCloseAll = m_menuFile->addAction(tr("Close All&..."));
    m_actionFileCloseAll->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_W));

#endif

    m_actionFileCloseLeft = m_menuFile->addAction(tr("Close &to the Left..."));
    m_actionFileCloseRight = m_menuFile->addAction(tr("Close to the &Right..."));
    m_actionFileCloseUnchanged = m_menuFile->addAction(tr("Close All &Unchanged"));
}

void BrStormTextMainWindow::initEditMenu()
{
    m_menuEdit = new QMenu(tr("&Edit"));
    m_menuBar->addMenu(m_menuEdit);

#if QT_VERSION > QT_VERSION_CHECK(6, 3, 0)

    m_actionEditUndo = m_menuEdit->addAction(tr("&Undo"),
                                             QKeySequence::Undo);
    m_actionEditRedo = m_menuEdit->addAction(tr("&Redo"),
                                             QKeySequence::Redo);
    m_menuEdit->addSeparator();
    m_actionEditCut = m_menuEdit->addAction(tr("&Cut"),
                                            QKeySequence::Cut);
    m_actionEditCopy = m_menuEdit->addAction(tr("C&opy"),
                                             QKeySequence::Copy);
    m_actionEditPaste = m_menuEdit->addAction(tr("&Paste"),
                                              QKeySequence::Paste);
    m_actionEditDelete = m_menuEdit->addAction(tr("&Delete"),
                                               QKeySequence::Delete);
    m_actionEditSelectAll = m_menuEdit->addAction(tr("Select &All"),
                                                  QKeySequence::SelectAll);
    m_menuEdit->addSeparator();
    m_menuEditIndentation = m_menuEdit->addMenu(tr("&Indentation"));
    m_actionEditIndentationIndent = m_menuEditIndentation->addAction(tr("Increase Indentation (&Indent)"));
    m_actionEditIndentationDedent = m_menuEditIndentation->addAction(tr("Decrease Indentation (&Dedent)"));
    m_menuEditFind = m_menuEdit->addMenu(tr("&Find"));
    m_actionEditFindFind = m_menuEditFind->addAction(tr("&Find..."),
                                                     QKeySequence::Find);
    m_actionEditFindNext = m_menuEditFind->addAction(tr("Find &Next"),
                                                     QKeySequence(Qt::Key_F3));
    m_actionEditFindPrevious = m_menuEditFind->addAction(tr("Find &Previous"),
                                                         QKeySequence(Qt::SHIFT | Qt::Key_F3));
    m_actionEditFindGoto = m_menuEditFind->addAction(tr("&Goto..."),
                                                     QKeySequence(Qt::CTRL | Qt::Key_G));
    m_menuEditReplace = m_menuEdit->addMenu("&Replace");
    m_actionEditReplaceFindNext = m_menuEditReplace->addAction(tr("Find &Next and Replace"),
                                                               QKeySequence(Qt::CTRL | Qt::Key_F3));
    m_actionEditReplaceFindPrevious = m_menuEditReplace->addAction(tr("Find &Previous and Replace"),
                                                                   QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_F3));
    m_actionEditReplaceAll = m_menuEditReplace->addAction(tr("Replace &All"),
                                                          QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::ALT | Qt::Key_H));

#else

    m_actionEditUndo = m_menuEdit->addAction(tr("&Undo"));
    m_actionEditUndo->setShortcut(QKeySequence::Undo);
    m_actionEditRedo = m_menuEdit->addAction(tr("&Redo"));
    m_actionEditRedo->setShortcut(QKeySequence::Redo);
    m_menuEdit->addSeparator();
    m_actionEditCut = m_menuEdit->addAction(tr("&Cut"));
    m_actionEditCut->setShortcut(QKeySequence::Cut);
    m_actionEditCopy = m_menuEdit->addAction(tr("C&opy"));
    m_actionEditCopy->setShortcut(QKeySequence::Copy);
    m_actionEditPaste = m_menuEdit->addAction(tr("&Paste"));
    m_actionEditPaste->setShortcut(QKeySequence::Paste);
    m_actionEditDelete = m_menuEdit->addAction(tr("&Delete"));
    m_actionEditDelete->setShortcut(QKeySequence::Delete);
    m_actionEditSelectAll = m_menuEdit->addAction(tr("Select &All"));
    m_actionEditSelectAll->setShortcut(QKeySequence::SelectAll);
    m_menuEdit->addSeparator();
    m_menuEditIndentation = m_menuEdit->addMenu(tr("&Indentation"));
    m_actionEditIndentationIndent = m_menuEditIndentation->addAction(tr("Increase Indentation (&Indent)"));
    m_actionEditIndentationDedent = m_menuEditIndentation->addAction(tr("Decrease Indentation (&Dedent)"));
    m_menuEditFind = m_menuEdit->addMenu(tr("&Find"));
    m_actionEditFindFind = m_menuEditFind->addAction(tr("&Find..."));
    m_actionEditFindFind->setShortcut(QKeySequence::Find);
    m_actionEditFindNext = m_menuEditFind->addAction(tr("Find &Next"));
    m_actionEditFindNext->setShortcut(QKeySequence(Qt::Key_F3));
    m_actionEditFindPrevious = m_menuEditFind->addAction(tr("Find &Previous"));
    m_actionEditFindPrevious->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_F3));
    m_actionEditFindGoto = m_menuEditFind->addAction(tr("&Goto..."));
    m_actionEditFindGoto->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_G));
    m_menuEditReplace = m_menuEdit->addMenu("&Replace");
    m_actionEditReplaceFindNext = m_menuEditReplace->addAction(tr("Find &Next and Replace"));
    m_actionEditReplaceFindNext->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F3));
    m_actionEditReplaceFindPrevious = m_menuEditReplace->addAction(tr("Find &Previous and Replace"));
    m_actionEditReplaceFindPrevious->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_F3));
    m_actionEditReplaceAll = m_menuEditReplace->addAction(tr("Replace &All"));
    m_actionEditReplaceAll->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::ALT | Qt::Key_H));

#endif
    m_actionEditUndo->setEnabled(false);
    m_actionEditRedo->setEnabled(false);
    m_actionEditCut->setEnabled(false);
    m_actionEditCopy->setEnabled(false);
    m_actionEditDelete->setEnabled(false);
}

void BrStormTextMainWindow::initViewMenu()
{
    m_menuView = new QMenu(tr("&View"));
    m_menuBar->addMenu(m_menuView);

#if QT_VERSION > QT_VERSION_CHECK(6, 3, 0)

    #ifndef Q_OS_MAC
    m_actionViewFullscreen = m_menuView->addAction(tr("&Fullscreen"),
                                                   QKeySequence(Qt::Key_F11));
    m_actionViewFullscreen->setCheckable(true);
    #endif
    m_menuViewSymbols = m_menuView->addMenu(tr("&Show Symbols"));
    m_actionViewSymbolsWhitespace = m_menuViewSymbols->addAction(tr("Show &Whitespace"));
    m_actionViewSymbolsEol = m_menuViewSymbols->addAction(tr("Show &EOLs (End-Of-Line)"));
    m_menuViewZoom = m_menuView->addMenu(tr("&Zoom"));
    m_actionViewZoomIn = m_menuViewZoom->addAction(tr("Zoom &In"),
                                                   QKeySequence::ZoomIn);
    m_actionViewZoomOut = m_menuViewZoom->addAction(tr("Zoom &Out"),
                                                    QKeySequence::ZoomOut);
    m_menuViewZoom->addSeparator();
    m_actionViewZoomDefault = m_menuViewZoom->addAction(tr("Zoom to &Default (100%)"),
                                                        QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_0));
    m_menuViewTab = m_menuView->addMenu(tr("&Tabs"));
    m_actionViewTab1 = m_menuViewTab->addAction(tr("Switch to Tab &1 (the First Tab)"),
                                             QKeySequence(Qt::CTRL | Qt::Key_1));
    m_actionViewTab2 = m_menuViewTab->addAction(tr("Switch to Tab &2"),
                                             QKeySequence(Qt::CTRL | Qt::Key_2));
    m_actionViewTab3 = m_menuViewTab->addAction(tr("Switch to Tab &3"),
                                             QKeySequence(Qt::CTRL | Qt::Key_3));
    m_actionViewTab4 = m_menuViewTab->addAction(tr("Switch to Tab &4"),
                                             QKeySequence(Qt::CTRL | Qt::Key_4));
    m_actionViewTab5 = m_menuViewTab->addAction(tr("Switch to Tab &5"),
                                             QKeySequence(Qt::CTRL | Qt::Key_5));
    m_actionViewTab6 = m_menuViewTab->addAction(tr("Switch to Tab &6"),
                                             QKeySequence(Qt::CTRL | Qt::Key_6));
    m_actionViewTab7 = m_menuViewTab->addAction(tr("Switch to Tab &7"),
                                             QKeySequence(Qt::CTRL | Qt::Key_7));
    m_actionViewTab8 = m_menuViewTab->addAction(tr("Switch to Tab &8"),
                                             QKeySequence(Qt::CTRL | Qt::Key_8));
    m_actionViewTab9 = m_menuViewTab->addAction(tr("Switch to Tab &9"),
                                             QKeySequence(Qt::CTRL | Qt::Key_9));
    m_actionViewTab10 = m_menuViewTab->addAction(tr("Switch to Tab 1&0"),
                                             QKeySequence(Qt::CTRL | Qt::Key_0));
    m_menuViewTab->addSeparator();
    m_actionViewTabLast = m_menuViewTab->addAction(tr("Switch to the &Last Tab"),
                                                   QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_9));
    m_actionViewTabPrevious = m_menuViewTab->addAction(tr("Switch to the &Previous Tab"),
                                                       QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Left));
    m_actionViewTabNext = m_menuViewTab->addAction(tr("Switch to the &Next Tab"),
                                                   QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Right));
    m_menuView->addSeparator();
    m_menuViewMarkers = m_menuView->addMenu(tr("Ma&rkers"));
    m_actionViewMarkersEnable = m_menuViewMarkers->addAction(tr("&Enable"));
    m_menuViewMarkers->addSeparator();
    m_actionViewMarkersNew = m_menuViewMarkers->addAction(tr("&New on the Current Line"));
    m_actionViewMarkersDelete = m_menuViewMarkers->addAction(tr("&Delete"));
    m_actionViewMarkersDeleteAll = m_menuViewMarkers->addAction(tr("Delete &All"));
    m_menuViewWrapMode = m_menuView->addMenu(tr("&Wrap Mode"));
    m_actionViewWrapNone = m_menuViewWrapMode->addAction(tr("&None"));
    m_menuViewWrapMode->addSeparator();
    m_actionViewWrapWord = m_menuViewWrapMode->addAction(tr("Wrap by &Word"));
    m_actionViewWrapCharacter = m_menuViewWrapMode->addAction(tr("Wrap by &Character"));
    m_actionViewWrapWhitespace = m_menuViewWrapMode->addAction(tr("Wrap by W&hitespace"));
    m_menuViewWrapVisualFlag = m_menuView->addMenu(tr("Wrap &Visual Flag"));
    m_actionViewWrapFlagNone = m_menuViewWrapVisualFlag->addAction(tr("&No Flag"));
    m_menuViewWrapVisualFlag->addSeparator();
    m_actionViewWrapFlagByText = m_menuViewWrapVisualFlag->addAction(tr("By &Text"));
    m_actionViewWrapFlagByBorder = m_menuViewWrapVisualFlag->addAction(tr("By &Border"));
    m_actionViewWrapFlagInMargin = m_menuViewWrapVisualFlag->addAction(tr("&In Margin"));
    m_menuViewFold = m_menuView->addMenu(tr("&Fold"));
    m_actionViewFoldAll = m_menuViewFold->addAction(tr("Fold &All"));
    m_actionViewFoldAllChildren = m_menuViewFold->addAction(tr("Fold All with Their &Children"));
    m_actionViewFoldCurrentLine = m_menuViewFold->addAction(tr("Fold Current &Line"));
    m_menuViewMove = m_menuView->addMenu(tr("M&ove"));
    m_menuViewMoveLine = m_menuViewMove->addMenu(tr("&Line"));
    m_actionViewMoveLineDown = m_menuViewMoveLine->addAction(tr("Line &Down"),
                                                             QKeySequence(Qt::Key_Down));
    m_actionViewMoveLineDownExtend = m_menuViewMoveLine->addAction(tr("Line Down and &Extend Selection"),
                                                                   QKeySequence(Qt::Key_Down | Qt::SHIFT));
    m_actionViewMoveLineDownRectExtend = m_menuViewMoveLine->addAction(tr("Line Down and Extend &Rectangular Selection"),
                                                                       QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Down));
    m_actionViewMoveLineScrollDown = m_menuViewMoveLine->addAction(tr("&Scroll the View One Line Down"),
                                                                   QKeySequence(Qt::Key_Down | Qt::CTRL));
    m_actionViewMoveLineUp = m_menuViewMoveLine->addAction(tr("Line &Up"),
                                                           QKeySequence(Qt::Key_Up));
    m_actionViewMoveLineUpExtend = m_menuViewMoveLine->addAction(tr("Line Up and E&xtend Selection"),
                                                                 QKeySequence(Qt::Key_Up | Qt::SHIFT));
    m_actionViewMoveLineUpRectExtend = m_menuViewMoveLine->addAction(tr("Line Up and Extend Re&ctangular Selection"),
                                                                     QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Up));
    m_actionViewMoveLineScrollUp = m_menuViewMoveLine->addAction(tr("Scr&oll the View One Line Up"),
                                                                 QKeySequence(Qt::CTRL | Qt::Key_Up));
    m_actionViewMoveLineEnd = m_menuViewMoveLine->addAction(tr("Line E&nd"),
                                                            QKeySequence(Qt::Key_End));
    m_actionViewMoveLineEndExtend = m_menuViewMoveLine->addAction(tr("Line End and Ex&tend Selection"),
                                                                  QKeySequence(Qt::SHIFT | Qt::Key_End));
    m_actionViewMoveLineEndRectExtend = m_menuViewMoveLine->addAction(tr("Line End and Extend Rectan&gular Selection"),
                                                                      QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_End));
    m_actionViewMoveLineEndDisplay = m_menuViewMoveLine->addAction(tr("Line End Dis&play"),
                                                                   QKeySequence(Qt::ALT | Qt::Key_End));
    m_actionViewMoveLineEndDisplayExtend = m_menuViewMoveLine->addAction(tr("Line End Displa&y Extend"));
    m_actionViewMoveLineEndWrap = m_menuViewMoveLine->addAction(tr("Line End &Wrap"));
    m_actionViewMoveLineEndWrapExtend = m_menuViewMoveLine->addAction(tr("Line End Wr&ap Extend"));
    m_actionViewMoveLineDelete = m_menuViewMoveLine->addAction(tr("&Line Delete"),
                                                               QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_L));
    m_actionViewMoveLineCut = m_menuViewMoveLine->addAction(tr("L&ine Cut"),
                                                            QKeySequence(Qt::CTRL | Qt::Key_L));
    m_actionViewMoveLineCopy = m_menuViewMoveLine->addAction(tr("Line& Copy"),
                                                             QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_T));
    m_actionViewMoveLineTranspose = m_menuViewMoveLine->addAction(tr("Line Transpose &(Swap Lines)"),
                                                                  QKeySequence(Qt::CTRL | Qt::Key_T));
    m_actionViewMoveLineDuplicate = m_menuViewMoveLine->addAction(tr("Line Duplicate (Insert a Same Line After This Line&)"));
    m_menuViewMoveScrollTo = m_menuViewMove->addMenu(tr("&Scroll To"));
    m_actionViewMoveScrollToStart = m_menuViewMoveScrollTo->addAction(tr("&Start"));
    m_actionViewMoveScrollToEnd = m_menuViewMoveScrollTo->addAction(tr("&End"));
    m_actionViewMoveVerticalCenterCaret = m_menuViewMoveScrollTo->addAction(tr("&Vertical Center Caret"));
    m_menuViewMoveParagraph = m_menuViewMove->addMenu(tr("&Paragraph"));
    m_actionViewMoveParaDown = m_menuViewMoveParagraph->addAction(tr("Paragraph &Down"),
                                                         QKeySequence(Qt::CTRL | Qt::Key_BracketRight));
    m_actionViewMoveParaDownExtend = m_menuViewMoveParagraph->addAction(tr("Paragrap Down and &Extend Selection"),
                                                                        QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_BracketRight));
    m_actionViewMoveParaUp = m_menuViewMoveParagraph->addAction(tr("Paragraph &Up"),
                                                                QKeySequence(Qt::CTRL | Qt::Key_BracketLeft));
    m_actionViewMoveParaUpExtend = m_menuViewMoveParagraph->addAction(tr("Paragraph Up and E&xtend Selection"),
                                                                      QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_BracketLeft));
    m_menuViewMoveCharacter = m_menuViewMove->addMenu(tr("&Character"));
    m_actionViewMoveCharLeft = m_menuViewMoveCharacter->addAction(tr("Character &Left"),
                                                                  QKeySequence(Qt::Key_Left));
    m_actionViewMoveCharLeftExtend = m_menuViewMoveCharacter->addAction(tr("Character Left and &Extend Selection"),
                                                                        QKeySequence(Qt::SHIFT | Qt::Key_Left));
    m_actionViewMoveCharLeftRectExtend = m_menuViewMoveCharacter->addAction(tr("Character Left and Extend Re&ctangular Selection"),
                                                                            QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_Left));
    m_actionViewMoveCharRight = m_menuViewMoveCharacter->addAction(tr("Character &Right"),
                                                                   QKeySequence(Qt::Key_Right));
    m_actionViewMoveCharRightExtend = m_menuViewMoveCharacter->addAction(tr("Character Right and E&xtend Selection"),
                                                                         QKeySequence(Qt::SHIFT | Qt::Key_Right));
    m_actionViewMoveCharRightRectExtend = m_menuViewMoveCharacter->addAction(tr("Character Right and Extend Rectangular &Selection"),
                                                                             QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_Right));
    m_menuViewMoveWord = m_menuViewMove->addMenu(tr("&Word"));
    m_actionViewMoveWordLeft = m_menuViewMoveWord->addAction(tr("Word &Left"),
                                                             QKeySequence(Qt::CTRL | Qt::Key_Left));
    m_actionViewMoveWordLeftExtend = m_menuViewMoveWord->addAction(tr("Word Left &Extend"),
                                                                   QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Left));
    m_actionViewMoveWordRight = m_menuViewMoveWord->addAction(tr("Word &Right"),
                                                                  QKeySequence(Qt::CTRL | Qt::Key_Right));
    m_actionViewMoveWordRightExtend = m_menuViewMoveWord->addAction(tr("Word Right E&xtend"),
                                                                    QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Right));
    m_actionViewMoveWordLeftEnd = m_menuViewMoveWord->addAction(tr("Word Left E&nd"));
    m_actionViewMoveWordLeftEndExtend = m_menuViewMoveWord->addAction(tr("Word Left End and Extend Sele&ction"));
    m_actionViewMoveWordRightEnd = m_menuViewMoveWord->addAction(tr("Word Right En&d"));
    m_actionViewMoveWordRightEndExtend = m_menuViewMoveWord->addAction(tr("Word Right and Ex&tend Selection"));
    m_actionViewMoveWordPartLeft = m_menuViewMoveWord->addAction(tr("Word &Part Left"),
                                                                 QKeySequence(Qt::CTRL | Qt::Key_Slash));
    m_actionViewMoveWordPartLeftExtend = m_menuViewMoveWord->addAction(tr("Word Part Le&ft and Extend Selection"),
                                                                       QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Slash));
    m_actionViewMoveWordPartRight = m_menuViewMoveWord->addAction(tr("&Word Part Right"),
                                                                  QKeySequence(Qt::CTRL | Qt::Key_Backslash));
    m_actionViewMoveWordPartRightExtend = m_menuViewMoveWord->addAction(tr("W&ord Part Right and Extend Selection"),
                                                                        QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Backslash));
    m_menuViewMoveHome = m_menuViewMove->addMenu(tr("&Home"));
    m_actionViewMoveHome = m_menuViewMoveHome->addAction(tr("&Home"));
    m_actionViewMoveHomeExtend = m_menuViewMoveHome->addAction(tr("Home and &Extend Selection"));
    m_actionViewMoveHomeRectExtend = m_menuViewMoveHome->addAction(tr("Home and Extend &Rectangular Selection"));
    m_actionViewMoveHomeDisplay = m_menuViewMoveHome->addAction(tr("Home &Display"),
                                                                QKeySequence(Qt::ALT | Qt::Key_Home));
    m_actionViewMoveHomeDisplayExtend = m_menuViewMoveHome->addAction(tr("Home Display and E&xtend Selection"));
    m_actionViewMoveHomeWrap = m_menuViewMoveHome->addAction(tr("Home &Wrap"));
    m_actionViewMoveHomeWrapExtend = m_menuViewMoveHome->addAction(tr("Home Wrap &and Extend Selection"));
    m_actionViewMoveVCHome = m_menuViewMoveHome->addAction(tr("&Visible Character Home"),
                                                           QKeySequence(Qt::Key_Home));
    m_actionViewMoveVCHomeExtend = m_menuViewMoveHome->addAction(tr("Visible &Character Home and Extend Selection"),
                                                                 QKeySequence(Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveVCHomeRectExtend = m_menuViewMoveHome->addAction(tr("Visible Character Home and Extend Rectan&gular Selection"),
                                                                     QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveVCHomeWrap = m_menuViewMoveHome->addAction(tr("Visible Character Wra&p"));
    m_actionViewMoveVCHomeWrapExtend = m_menuViewMoveHome->addAction(tr("Visible Character Wrap and Extend Select&ion"));
    m_menuViewMoveDocument = m_menuViewMove->addMenu(tr("&Document"));
    m_actionViewMoveDocumentStart = m_menuViewMoveDocument->addAction(tr("Document &Start"),
                                                                      QKeySequence(Qt::CTRL | Qt::Key_Home));
    m_actionViewMoveDocumentStartExtend = m_menuViewMoveDocument->addAction(tr("Document Start E&xtend"),
                                                                            QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveDocumentEnd = m_menuViewMoveDocument->addAction(tr("Document &End"),
                                                                    QKeySequence(Qt::CTRL | Qt::Key_End));
    m_actionViewMoveDocumentEndExtend = m_menuViewMoveDocument->addAction(tr("Document End Ex&tend"),
                                                                          QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_End));
    m_menuViewMovePage = m_menuViewMove->addMenu(tr("Pa&ge"));
    m_actionViewMovePageUp = m_menuViewMovePage->addAction(tr("Page &Up"),
                                                               QKeySequence(Qt::Key_PageUp));
    m_actionViewMovePageUpExtend = m_menuViewMovePage->addAction(tr("Page Up and &Extend Selection"),
                                                                     QKeySequence(Qt::SHIFT | Qt::Key_PageUp));
    m_actionViewMovePageUpRectExtend = m_menuViewMovePage->addAction(tr("Page Up and Extend &Rectangular Selection"),
                                                                         QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_PageUp));
    m_actionViewMovePageDown = m_menuViewMovePage->addAction(tr("Page &Down"),
                                                                 QKeySequence(Qt::Key_PageDown));
    m_actionViewMovePageDownExtend = m_menuViewMovePage->addAction(tr("Page Down and E&xtend Selection"),
                                                                       QKeySequence(Qt::SHIFT | Qt::Key_PageDown));
    m_actionViewMovePageDownRectExtend = m_menuViewMovePage->addAction(tr("Page Down and Extend Rectan&gular Selection"),
                                                                           QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_PageDown));
    m_actionViewMoveStutteredPageUp = m_menuViewMovePage->addAction(tr("&Stuttered Page Up"));
    m_actionViewMoveStutteredPageUpExtend = m_menuViewMovePage->addAction(tr("S&tuttered Page Up and Extend Selection"));
    m_actionViewMoveStutteredPageDown = m_menuViewMovePage->addAction(tr("Stuttered &Page Down"));
    m_actionViewMoveStutteredPageDownExtend = m_menuViewMovePage->addAction(tr("Stuttered Page Do&wn and Extend Selection"));
    m_menuViewMoveDelete = m_menuViewMove->addMenu(tr("D&elete"));
    m_actionViewMoveDeleteBack = m_menuViewMoveDelete->addAction(tr("Delete &Back"),
                                                                 QKeySequence(Qt::Key_Backspace));
    m_actionViewMoveDeleteBackNotLine = m_menuViewMoveDelete->addAction(tr("Delete Back &If Not at The Start Of Line"));
    m_actionViewMoveDeleteWordLeft = m_menuViewMoveDelete->addAction(tr("Delete Word &Left"),
                                                                     QKeySequence(Qt::CTRL | Qt::Key_Backspace));
    m_actionViewMoveDeleteWordRight = m_menuViewMoveDelete->addAction(tr("Delete Word &Right"),
                                                                      QKeySequence(Qt::CTRL | Qt::Key_Delete));
    m_actionViewMoveDeleteWordRightEnd = m_menuViewMoveDelete->addAction(tr("Delete &Word Right End"));
    m_actionViewMoveDeleteLineLeft = m_menuViewMoveDelete->addAction(tr("Delete &Line Left"),
                                                                     QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Backspace));
    m_actionViewMoveDeleteLineRight = m_menuViewMoveDelete->addAction(tr("Delete Line Ri&ght"),
                                                                      QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Delete));
    m_menuViewMoveSelection = m_menuViewMove->addMenu(tr("Selec&tion"));
    m_actionViewMoveMoveSelectedLinesUp = m_menuViewMoveSelection->addAction(tr("Move Selected Lines &Up"));
    m_actionViewMoveMoveSelectedLinesDown = m_menuViewMoveSelection->addAction(tr("Move Selected Lines &Down"));
    m_actionViewMoveSelectionDuplicate = m_menuViewMoveSelection->addAction(tr("D&uplicate Selection"),
                                                                            QKeySequence(Qt::CTRL | Qt::Key_D));

#else

    #ifndef Q_OS_MAC
    m_actionViewFullscreen = m_menuView->addAction(tr("&Fullscreen"));
    m_actionViewFullscreen->setShortcut(QKeySequence(Qt::Key_F11));
    m_actionViewFullscreen->setCheckable(true);
    m_menuView->addSeparator();
    #endif
    m_menuViewSymbols = m_menuView->addMenu(tr("&Show Symbols"));
    m_actionViewSymbolsWhitespace = m_menuViewSymbols->addAction(tr("Show &Whitespace"));
    m_actionViewSymbolsEol = m_menuViewSymbols->addAction(tr("Show &EOLs (End-Of-Line)"));
    m_menuViewZoom = m_menuView->addMenu(tr("&Zoom"));
    m_actionViewZoomIn = m_menuViewZoom->addAction(tr("Zoom &In"));
    m_actionViewZoomIn->setShortcut(QKeySequence::ZoomIn);
    m_actionViewZoomOut = m_menuViewZoom->addAction(tr("Zoom &Out"));
    m_actionViewZoomOut->setShortcut(QKeySequence::ZoomOut);
    m_menuViewZoom->addSeparator();
    m_actionViewZoomDefault = m_menuViewZoom->addAction(tr("Zoom to &Default (100%)"));
    m_actionViewZoomDefault->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_0));
    m_menuViewTab = m_menuView->addMenu(tr("&Tabs"));
    m_actionViewTab1 = m_menuViewTab->addAction(tr("Switch to Tab &1 (the First Tab)"));
    m_actionViewTab1->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_1));
    m_actionViewTab2 = m_menuViewTab->addAction(tr("Switch to Tab &2"));
    m_actionViewTab2->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_2));
    m_actionViewTab3 = m_menuViewTab->addAction(tr("Switch to Tab &3"));
    m_actionViewTab3->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_3));
    m_actionViewTab4 = m_menuViewTab->addAction(tr("Switch to Tab &4"));
    m_actionViewTab4->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_4));
    m_actionViewTab5 = m_menuViewTab->addAction(tr("Switch to Tab &5"));
    m_actionViewTab5->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_5));
    m_actionViewTab6 = m_menuViewTab->addAction(tr("Switch to Tab &6"));
    m_actionViewTab6->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_6));
    m_actionViewTab7 = m_menuViewTab->addAction(tr("Switch to Tab &7"));
    m_actionViewTab7->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_7));
    m_actionViewTab8 = m_menuViewTab->addAction(tr("Switch to Tab &8"));
    m_actionViewTab8->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_8));
    m_actionViewTab9 = m_menuViewTab->addAction(tr("Switch to Tab &9"));
    m_actionViewTab9->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_9));
    m_actionViewTab10 = m_menuViewTab->addAction(tr("Switch to Tab 1&0"));
    m_actionViewTab10->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));
    m_menuViewTab->addSeparator();
    m_actionViewTabLast = m_menuViewTab->addAction(tr("Switch to the &Last Tab"));
    m_actionViewTabLast->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_9));
    m_actionViewTabPrevious = m_menuViewTab->addAction(tr("Switch to the &Previous Tab"));
    m_actionViewTabPrevious->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Left));
    m_actionViewTabNext = m_menuViewTab->addAction(tr("Switch to the &Next Tab"));
    m_actionViewTabNext->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Right));
    m_menuViewMarkers = m_menuView->addMenu(tr("Ma&rkers"));
    m_actionViewMarkersEnable = m_menuViewMarkers->addAction(tr("&Enable"));
    m_menuViewMarkers->addSeparator();
    m_actionViewMarkersNew = m_menuViewMarkers->addAction(tr("&New on the Current Line"));
    m_actionViewMarkersDelete = m_menuViewMarkers->addAction(tr("&Delete"));
    m_actionViewMarkersDeleteAll = m_menuViewMarkers->addAction(tr("Delete &All"));
    m_menuViewWrapMode = m_menuView->addMenu(tr("&Wrap Mode"));
    m_actionViewWrapNone = m_menuViewWrapMode->addAction(tr("&None"));
    m_menuViewWrapMode->addSeparator();
    m_actionViewWrapWord = m_menuViewWrapMode->addAction(tr("Wrap by &Word"));
    m_actionViewWrapCharacter = m_menuViewWrapMode->addAction(tr("Wrap by &Character"));
    m_actionViewWrapWhitespace = m_menuViewWrapMode->addAction(tr("Wrap by W&hitespace"));
    m_menuViewWrapVisualFlag = m_menuView->addMenu(tr("Wrap &Visual Flag"));
    m_actionViewWrapFlagNone = m_menuViewWrapVisualFlag->addAction(tr("&No Flag"));
    m_menuViewWrapVisualFlag->addSeparator();
    m_actionViewWrapFlagByText = m_menuViewWrapVisualFlag->addAction(tr("By &Text"));
    m_actionViewWrapFlagByBorder = m_menuViewWrapVisualFlag->addAction(tr("By &Border"));
    m_actionViewWrapFlagInMargin = m_menuViewWrapVisualFlag->addAction(tr("&In Margin"));
    m_menuViewFold = m_menuView->addMenu(tr("&Fold"));
    m_actionViewFoldAll = m_menuViewFold->addAction(tr("Fold &All"));
    m_actionViewFoldAllChildren = m_menuViewFold->addAction(tr("Fold All with Their &Children"));
    m_actionViewFoldCurrentLine = m_menuViewFold->addAction(tr("Fold Current &Line"));
    m_menuViewMove = m_menuView->addMenu(tr("M&ove"));
    m_menuViewMoveLine = m_menuViewMove->addMenu(tr("&Line"));
    m_actionViewMoveLineDown = m_menuViewMoveLine->addAction(tr("Line &Down"));
    m_actionViewMoveLineDown->setShortcut(QKeySequence(Qt::Key_Down));
    m_actionViewMoveLineDownExtend = m_menuViewMoveLine->addAction(tr("Line Down and &Extend Selection"));
    m_actionViewMoveLineDownExtend->setShortcut(QKeySequence(Qt::Key_Down | Qt::SHIFT));
    m_actionViewMoveLineDownRectExtend = m_menuViewMoveLine->addAction(tr("Line Down and Extend &Rectangular Selection"));
    m_actionViewMoveLineDownRectExtend->setShortcut(QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Down));
    m_actionViewMoveLineScrollDown = m_menuViewMoveLine->addAction(tr("&Scroll the View One Line Down"));
    m_actionViewMoveLineScrollDown->setShortcut(QKeySequence(Qt::Key_Down | Qt::CTRL));
    m_actionViewMoveLineUp = m_menuViewMoveLine->addAction(tr("Line &Up"));
    m_actionViewMoveLineUp->setShortcut(QKeySequence(Qt::Key_Up));
    m_actionViewMoveLineUpExtend = m_menuViewMoveLine->addAction(tr("Line Up and E&xtend Selection"));
    m_actionViewMoveLineUpExtend->setShortcut(QKeySequence(Qt::Key_Up | Qt::SHIFT));
    m_actionViewMoveLineUpRectExtend = m_menuViewMoveLine->addAction(tr("Line Up and Extend Re&ctangular Selection"));
    m_actionViewMoveLineUpRectExtend->setShortcut(QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Up));
    m_actionViewMoveLineScrollUp = m_menuViewMoveLine->addAction(tr("Scr&oll the View One Line Up"));
    m_actionViewMoveLineScrollUp->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Up));
    m_actionViewMoveLineEnd = m_menuViewMoveLine->addAction(tr("Line E&nd"));
    m_actionViewMoveLineEnd->setShortcut(QKeySequence(Qt::Key_End));
    m_actionViewMoveLineEndExtend = m_menuViewMoveLine->addAction(tr("Line End and Ex&tend Selection"));
    m_actionViewMoveLineEndExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_End));
    m_actionViewMoveLineEndRectExtend = m_menuViewMoveLine->addAction(tr("Line End and Extend Rectan&gular Selection"));
    m_actionViewMoveLineEndRectExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_End));
    m_actionViewMoveLineEndDisplay = m_menuViewMoveLine->addAction(tr("Line End Dis&play"));
    m_actionViewMoveLineEndDisplay->setShortcut(QKeySequence(Qt::ALT | Qt::Key_End));
    m_actionViewMoveLineEndDisplayExtend = m_menuViewMoveLine->addAction(tr("Line End Displa&y Extend"));
    m_actionViewMoveLineEndWrap = m_menuViewMoveLine->addAction(tr("Line End &Wrap"));
    m_actionViewMoveLineEndWrapExtend = m_menuViewMoveLine->addAction(tr("Line End Wr&ap Extend"));
    m_actionViewMoveLineDelete = m_menuViewMoveLine->addAction(tr("&Line Delete"));
    m_actionViewMoveLineDelete->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_L));
    m_actionViewMoveLineCut = m_menuViewMoveLine->addAction(tr("L&ine Cut"));
    m_actionViewMoveLineCut->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    m_actionViewMoveLineCopy = m_menuViewMoveLine->addAction(tr("Line& Copy"));
    m_actionViewMoveLineCopy->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_T));
    m_actionViewMoveLineTranspose = m_menuViewMoveLine->addAction(tr("Line Transpose &(Swap Lines)"));
    m_actionViewMoveLineTranspose->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_T));
    m_actionViewMoveLineDuplicate = m_menuViewMoveLine->addAction(tr("Line Duplicate (Insert a Same Line After This Line&)"));
    m_menuViewMoveScrollTo = m_menuViewMove->addMenu(tr("&Scroll To"));
    m_actionViewMoveScrollToStart = m_menuViewMoveScrollTo->addAction(tr("&Start"));
    m_actionViewMoveScrollToEnd = m_menuViewMoveScrollTo->addAction(tr("&End"));
    m_actionViewMoveVerticalCenterCaret = m_menuViewMoveScrollTo->addAction(tr("&Vertical Center Caret"));
    m_menuViewMoveParagraph = m_menuViewMove->addMenu(tr("&Paragraph"));
    m_actionViewMoveParaDown = m_menuViewMoveParagraph->addAction(tr("Paragraph &Down"));
    m_actionViewMoveParaDown->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_BracketRight));
    m_actionViewMoveParaDownExtend = m_menuViewMoveParagraph->addAction(tr("Paragrap Down and &Extend Selection"));
    m_actionViewMoveParaDownExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_BracketRight));
    m_actionViewMoveParaUp = m_menuViewMoveParagraph->addAction(tr("Paragraph &Up"));
    m_actionViewMoveParaUp->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_BracketLeft));
    m_actionViewMoveParaUpExtend = m_menuViewMoveParagraph->addAction(tr("Paragraph Up and E&xtend Selection"));
    m_actionViewMoveParaUpExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_BracketLeft));
    m_menuViewMoveCharacter = m_menuViewMove->addMenu(tr("&Character"));
    m_actionViewMoveCharLeft = m_menuViewMoveCharacter->addAction(tr("Character &Left"));
    m_actionViewMoveCharLeft->setShortcut(QKeySequence(Qt::Key_Left));
    m_actionViewMoveCharLeftExtend = m_menuViewMoveCharacter->addAction(tr("Character Left and &Extend Selection"));
    m_actionViewMoveCharLeftExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_Left));
    m_actionViewMoveCharLeftRectExtend = m_menuViewMoveCharacter->addAction(tr("Character Left and Extend Re&ctangular Selection"));
    m_actionViewMoveCharLeftRectExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_Left));
    m_actionViewMoveCharRight = m_menuViewMoveCharacter->addAction(tr("Character &Right"));
    m_actionViewMoveCharRight->setShortcut(QKeySequence(Qt::Key_Right));
    m_actionViewMoveCharRightExtend = m_menuViewMoveCharacter->addAction(tr("Character Right and E&xtend Selection"));
    m_actionViewMoveCharRightExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_Right));
    m_actionViewMoveCharRightRectExtend = m_menuViewMoveCharacter->addAction(tr("Character Right and Extend Rectangular &Selection"));
    m_actionViewMoveCharRightRectExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::ALT | Qt::Key_Right));
    m_menuViewMoveWord = m_menuViewMove->addMenu(tr("&Word"));
    m_actionViewMoveWordLeft = m_menuViewMoveWord->addAction(tr("Word &Left"));
    m_actionViewMoveWordLeft->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Left));
    m_actionViewMoveWordLeftExtend = m_menuViewMoveWord->addAction(tr("Word Left &Extend"));
    m_actionViewMoveWordLeftExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Left));
    m_actionViewMoveWordRight = m_menuViewMoveWord->addAction(tr("Word &Right"));
    m_actionViewMoveWordRight->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Right));
    m_actionViewMoveWordRightExtend = m_menuViewMoveWord->addAction(tr("Word Right E&xtend"));
    m_actionViewMoveWordRightExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Right));
    m_actionViewMoveWordLeftEnd = m_menuViewMoveWord->addAction(tr("Word Left E&nd"));
    m_actionViewMoveWordLeftEndExtend = m_menuViewMoveWord->addAction(tr("Word Left End and Extend Sele&ction"));
    m_actionViewMoveWordRightEnd = m_menuViewMoveWord->addAction(tr("Word Right En&d"));
    m_actionViewMoveWordRightEndExtend = m_menuViewMoveWord->addAction(tr("Word Right and Ex&tend Selection"));
    m_actionViewMoveWordPartLeft = m_menuViewMoveWord->addAction(tr("Word &Part Left"));
    m_actionViewMoveWordPartLeft->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Slash));
    m_actionViewMoveWordPartLeftExtend = m_menuViewMoveWord->addAction(tr("Word Part Le&ft and Extend Selection"));
    m_actionViewMoveWordPartLeftExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Slash));
    m_actionViewMoveWordPartRight = m_menuViewMoveWord->addAction(tr("&Word Part Right"));
    m_actionViewMoveWordPartRight->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Backslash));
    m_actionViewMoveWordPartRightExtend = m_menuViewMoveWord->addAction(tr("W&ord Part Right and Extend Selection"));
    m_actionViewMoveWordPartRightExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Backslash));
    m_menuViewMoveHome = m_menuViewMove->addMenu(tr("&Home"));
    m_actionViewMoveHome = m_menuViewMoveHome->addAction(tr("&Home"));
    m_actionViewMoveHomeExtend = m_menuViewMoveHome->addAction(tr("Home and &Extend Selection"));
    m_actionViewMoveHomeRectExtend = m_menuViewMoveHome->addAction(tr("Home and Extend &Rectangular Selection"));
    m_actionViewMoveHomeDisplay = m_menuViewMoveHome->addAction(tr("Home &Display"));
    m_actionViewMoveHomeDisplay->setShortcut(QKeySequence(Qt::ALT | Qt::Key_Home));
    m_actionViewMoveHomeDisplayExtend = m_menuViewMoveHome->addAction(tr("Home Display and E&xtend Selection"));
    m_actionViewMoveHomeWrap = m_menuViewMoveHome->addAction(tr("Home &Wrap"));
    m_actionViewMoveHomeWrapExtend = m_menuViewMoveHome->addAction(tr("Home Wrap &and Extend Selection"));
    m_actionViewMoveVCHome = m_menuViewMoveHome->addAction(tr("&Visible Character Home"));
    m_actionViewMoveVCHome->setShortcut(QKeySequence(Qt::Key_Home));
    m_actionViewMoveVCHomeExtend = m_menuViewMoveHome->addAction(tr("Visible &Character Home and Extend Selection"));
    m_actionViewMoveVCHomeExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveVCHomeRectExtend = m_menuViewMoveHome->addAction(tr("Visible Character Home and Extend Rectan&gular Selection"));
    m_actionViewMoveVCHomeRectExtend->setShortcut(QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveVCHomeWrap = m_menuViewMoveHome->addAction(tr("Visible Character Wra&p"));
    m_actionViewMoveVCHomeWrapExtend = m_menuViewMoveHome->addAction(tr("Visible Character Wrap and Extend Select&ion"));
    m_menuViewMoveDocument = m_menuViewMove->addMenu(tr("&Document"));
    m_actionViewMoveDocumentStart = m_menuViewMoveDocument->addAction(tr("Document &Start")),
    m_actionViewMoveDocumentStart->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Home));
    m_actionViewMoveDocumentStartExtend = m_menuViewMoveDocument->addAction(tr("Document Start E&xtend")),
    m_actionViewMoveDocumentStartExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Home));
    m_actionViewMoveDocumentEnd = m_menuViewMoveDocument->addAction(tr("Document &End")),
    m_actionViewMoveDocumentEnd->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_End));
    m_actionViewMoveDocumentEndExtend = m_menuViewMoveDocument->addAction(tr("Document End Ex&tend")),
    m_actionViewMoveDocumentEndExtend->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_End));
    m_menuViewMovePage = m_menuViewMove->addMenu(tr("Pa&ge"));
    m_actionViewMovePageUp = m_menuViewMovePage->addAction(tr("Page &Up"));
    m_actionViewMovePageUp->setShortcut(QKeySequence(Qt::Key_PageUp));
    m_actionViewMovePageUpExtend = m_menuViewMovePage->addAction(tr("Page Up and &Extend Selection"));
    m_actionViewMovePageUpExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_PageUp));
    m_actionViewMovePageUpRectExtend = m_menuViewMovePage->addAction(tr("Page Up and Extend &Rectangular Selection"));
    m_actionViewMovePageUpRectExtend->setShortcut(QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_PageUp));
    m_actionViewMovePageDown = m_menuViewMovePage->addAction(tr("Page &Down"));
    m_actionViewMovePageDown->setShortcut(QKeySequence(Qt::Key_PageDown));
    m_actionViewMovePageDownExtend = m_menuViewMovePage->addAction(tr("Page Down and E&xtend Selection"));
    m_actionViewMovePageDownExtend->setShortcut(QKeySequence(Qt::SHIFT | Qt::Key_PageDown));
    m_actionViewMovePageDownRectExtend = m_menuViewMovePage->addAction(tr("Page Down and Extend Rectan&gular Selection"));
    m_actionViewMovePageDownRectExtend->setShortcut(QKeySequence(Qt::ALT | Qt::SHIFT | Qt::Key_PageDown));
    m_actionViewMoveStutteredPageUp = m_menuViewMovePage->addAction(tr("&Stuttered Page Up"));
    m_actionViewMoveStutteredPageUpExtend = m_menuViewMovePage->addAction(tr("S&tuttered Page Up and Extend Selection"));
    m_actionViewMoveStutteredPageDown = m_menuViewMovePage->addAction(tr("Stuttered &Page Down"));
    m_actionViewMoveStutteredPageDownExtend = m_menuViewMovePage->addAction(tr("Stuttered Page Do&wn and Extend Selection"));
    m_menuViewMoveDelete = m_menuViewMove->addMenu(tr("D&elete"));
    m_actionViewMoveDeleteBack = m_menuViewMoveDelete->addAction(tr("Delete &Back"));
    m_actionViewMoveDeleteBack->setShortcut(QKeySequence(Qt::Key_Backspace));
    m_actionViewMoveDeleteBackNotLine = m_menuViewMoveDelete->addAction(tr("Delete Back &If Not at The Start Of Line"));
    m_actionViewMoveDeleteWordLeft = m_menuViewMoveDelete->addAction(tr("Delete Word &Left"));
    m_actionViewMoveDeleteWordLeft->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Backspace));
    m_actionViewMoveDeleteWordRight = m_menuViewMoveDelete->addAction(tr("Delete Word &Right"));
    m_actionViewMoveDeleteWordRight->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Delete));
    m_actionViewMoveDeleteWordRightEnd = m_menuViewMoveDelete->addAction(tr("Delete &Word Right End"));
    m_actionViewMoveDeleteLineLeft = m_menuViewMoveDelete->addAction(tr("Delete &Line Left"));
    m_actionViewMoveDeleteLineLeft->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Backspace));
    m_actionViewMoveDeleteLineRight = m_menuViewMoveDelete->addAction(tr("Delete Line Ri&ght"));
    m_actionViewMoveDeleteLineRight->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_Delete));
    m_menuViewMoveSelection = m_menuViewMove->addMenu(tr("Selec&tion"));
    m_actionViewMoveMoveSelectedLinesUp = m_menuViewMoveSelection->addAction(tr("Move Selected Lines &Up"));
    m_actionViewMoveMoveSelectedLinesDown = m_menuViewMoveSelection->addAction(tr("Move Selected Lines &Down"));
    m_actionViewMoveSelectionDuplicate = m_menuViewMoveSelection->addAction(tr("D&uplicate Selection"));
    m_actionViewMoveSelectionDuplicate->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_D));

#endif

    m_menuView->addSeparator();
    m_actionViewVirtualSelection = m_menuView->addAction(tr("Virt&ual Selection"));
    m_actionViewReadOnly = m_menuView->addAction(tr("Document is Read&-only"));
    m_menuView->addSeparator();
    m_actionViewShowFileBrowser = m_menuView->addAction(tr("Show File &Browser"));
    m_actionViewShowIndentationGuides = m_menuView->addAction(tr("Show &Indentation Guides"));
    m_actionViewShowCaretBackground = m_menuView->addAction(tr("Show &Caret Line Background"));
    m_actionViewShowBraceMatching = m_menuView->addAction(tr("Show Brace-&matching Indicators"));
    m_actionViewShowAutocomplete = m_menuView->addAction(tr("Show &Autocompleter"));
    m_actionViewShowLineNumbers = m_menuView->addAction(tr("Show Line &Number"));
    #ifdef Q_OS_MAC
    m_menuView->addSeparator();
    #endif
    m_actionViewSymbolsEol->setCheckable(true);
    m_actionViewSymbolsWhitespace->setCheckable(true);
    m_actionViewMarkersEnable->setCheckable(true);
    m_actionViewMarkersEnable->setChecked(true);
    m_actionViewWrapNone->setCheckable(true);
    m_actionViewWrapWord->setCheckable(true);
    m_actionViewWrapWord->setChecked(true);
    m_actionViewWrapCharacter->setCheckable(true);
    m_actionViewWrapWhitespace->setCheckable(true);
    m_actionViewWrapFlagNone->setCheckable(true);
    m_actionViewWrapFlagNone->setChecked(true);
    m_actionViewWrapFlagByText->setCheckable(true);
    m_actionViewWrapFlagByBorder->setCheckable(true);
    m_actionViewWrapFlagInMargin->setCheckable(true);
    m_actionViewVirtualSelection->setCheckable(true);
    m_actionViewReadOnly->setCheckable(true);
    m_actionViewShowFileBrowser->setCheckable(true);
    m_actionViewShowIndentationGuides->setCheckable(true);
    m_actionViewShowCaretBackground->setCheckable(true);
    m_actionViewShowBraceMatching->setCheckable(true);
    m_actionViewShowAutocomplete->setCheckable(true);
    m_actionViewShowLineNumbers->setCheckable(true);
    m_actionViewShowIndentationGuides->setChecked(true);
    m_actionViewShowCaretBackground->setChecked(true);
    m_actionViewShowBraceMatching->setChecked(true);
    m_actionViewShowAutocomplete->setChecked(true);
    m_actionViewShowLineNumbers->setChecked(true);
}

void BrStormTextMainWindow::initFormatMenu()
{
    m_menuFormat = new QMenu(tr("F&ormat"));
    m_menuBar->addMenu(m_menuFormat);

    /**
     * @todo: Add more languages
     */

    m_menuFormatLanguage = m_menuFormat->addMenu(tr("&Languages"));
    m_actionFormatLanguageNone = m_menuFormatLanguage->addAction(tr("None &(No Lexer Applied)"));
    m_menuFormatLanguage->addSeparator();
    m_menuFormatLanguageA = m_menuFormatLanguage->addMenu(tr("&A"));
    m_actionFormatLanguageAVS = m_menuFormatLanguageA->addAction(tr("&AVS (Application Visualizing Script)"));
    m_menuFormatLanguageB = m_menuFormatLanguage->addMenu(tr("&B"));
    m_actionFormatLanguageBash = m_menuFormatLanguageB->addAction(tr("&Bash (UNIX-like OS Bash-Shell script)"));
    m_actionFormatLanguageBatch = m_menuFormatLanguageB->addAction(tr("B&atch (Windows PowerShell script)"));
    m_menuFormatLanguageC = m_menuFormatLanguage->addMenu(tr("&C"));
    m_actionFormatLanguageC = m_menuFormatLanguageC->addAction(tr("C &(the C language)"));
    m_actionFormatLanguageCMake = m_menuFormatLanguageC->addAction(tr("&CMake (C-Make)"));
    m_actionFormatLanguageCPP = m_menuFormatLanguageC->addAction(tr("C&++ (C-Plus-Plus)"));
    m_actionFormatLanguageCSharp = m_menuFormatLanguageC->addAction(tr("C&# (C-Sharp)"));
    m_actionFormatLanguageCoffeeScript = m_menuFormatLanguageC->addAction(tr("C&offeeScript"));
    m_actionFormatLanguageCSS = m_menuFormatLanguageC->addAction(tr("C&SS (Cascading StyleSheet)"));
    m_menuFormatLanguageD = m_menuFormatLanguage->addMenu(tr("&D"));
    m_actionFormatLanguageD = m_menuFormatLanguageD->addAction(tr("&D"));
    m_actionFormatLanguageDiff = m_menuFormatLanguageD->addAction(tr("D&iff (Diff Marker Language)"));
    m_menuFormatLanguageE = m_menuFormatLanguage->addMenu(tr("&E"));
    m_actionFormatLanguageEDIFACT = m_menuFormatLanguageE->addAction(tr("&EDIFACT (Electronic Data Interchange FACT)"));
    m_menuFormatLanguageF = m_menuFormatLanguage->addMenu(tr("&F"));
    m_actionFormatLanguageFortran = m_menuFormatLanguageF->addAction(tr("&Fortran"));
    m_actionFormatLanguageFortran77 = m_menuFormatLanguageF->addAction(tr("Fortran&77 (Fortran Versioned 77)"));
    m_menuFormatLanguageH = m_menuFormatLanguage->addMenu(tr("&H"));
    m_actionFormatLanguageHTML = m_menuFormatLanguageH->addAction(tr("&HTML (HyperText Markup Language)"));
    m_menuFormatLanguageI = m_menuFormatLanguage->addMenu(tr("&I"));
    m_actionFormatLanguageIDL = m_menuFormatLanguageI->addAction(tr("&IDL (Interface Description Language)"));
    m_menuFormatLanguageJ = m_menuFormatLanguage->addMenu(tr("&J"));
    m_actionFormatLanguageJava = m_menuFormatLanguageJ->addAction(tr("&Java"));
    m_actionFormatLanguageJavaScript = m_menuFormatLanguageJ->addAction(tr("J&avaScript"));
    m_actionFormatLanguageJSON = m_menuFormatLanguageJ->addAction(tr("J&SON (JavaScript Object Notation)"));
    m_menuFormatLanguageL = m_menuFormatLanguage->addMenu(tr("&L"));
    m_actionFormatLanguageLua = m_menuFormatLanguageL->addAction(tr("&Lua (the Lua language)"));
    m_menuFormatLanguageM = m_menuFormatLanguage->addMenu(tr("&M"));
    m_actionFormatLanguageMakefile = m_menuFormatLanguageM->addAction(tr("&Makefile (for make/nmake)"));
    m_actionFormatLanguageMarkdown = m_menuFormatLanguageM->addAction(tr("M&arkdown (for both CommonMarks and GitHub markdown)"));
    m_actionFormatLanguageMatlab = m_menuFormatLanguageM->addAction(tr("Ma&tlab"));
    m_menuFormatLanguageO = m_menuFormatLanguage->addMenu(tr("&O"));
    m_actionFormatLanguageOctave = m_menuFormatLanguageO->addAction(tr("&Octave (the Octave language)"));
    m_menuFormatLanguageP = m_menuFormatLanguage->addMenu(tr("&P"));
    m_actionFormatLanguagePascal = m_menuFormatLanguageP->addAction(tr("&Pascal"));
    m_actionFormatLanguagePerl = m_menuFormatLanguageP->addAction(tr("P&erl"));
    m_actionFormatLanguagePO = m_menuFormatLanguageP->addAction(tr("P&O (GNU gettext utilities)"));
    m_actionFormatLanguagePostScript = m_menuFormatLanguageP->addAction(tr("Post&Script (for desktop publishing)"));
    m_actionFormatLanguagePOV = m_menuFormatLanguageP->addAction(tr("PO&V (the POV-Ray language)"));
    m_actionFormatLanguageProperties = m_menuFormatLanguageP->addAction(tr("P&roperties"));
    m_actionFormatLanguagePython = m_menuFormatLanguageP->addAction(tr("P&ython (Python Versioned 2)"));
    m_actionFormatLanguagePython3 = m_menuFormatLanguageP->addAction(tr("Python &3 (Python Versioned 3)"));
    m_menuFormatLanguageQ = m_menuFormatLanguage->addMenu(tr("&Q"));
    m_actionFormatLanguageQSS = m_menuFormatLanguageQ->addAction(tr("&QSS (Qt StyleSheet)"));
    m_menuFormatLanguageR = m_menuFormatLanguage->addMenu(tr("&R"));
    m_actionFormatLanguageRuby = m_menuFormatLanguageR->addAction(tr("&Ruby (the Ruby language)"));
    m_menuFormatLanguageS = m_menuFormatLanguage->addMenu(tr("&S"));
    m_actionFormatLanguageSpice = m_menuFormatLanguageS->addAction(tr("&Spice (the Simulation Program with Integrated Circuit Emphasis)"));
    m_actionFormatLanguageSQL = m_menuFormatLanguageS->addAction(tr("S&QL (Structured Query Language)"));
    m_menuFormatLanguageT = m_menuFormatLanguage->addMenu(tr("&T"));
    m_actionFormatLanguageTCL = m_menuFormatLanguageT->addAction(tr("&TCL"));
    m_actionFormatLanguageTeX = m_menuFormatLanguageT->addAction(tr("Te&X (for text and document markup)"));
    m_menuFormatLanguageV = m_menuFormatLanguage->addMenu(tr("&V"));
    m_actionFormatLanguageVerilog = m_menuFormatLanguageV->addAction(tr("&Verilog"));
    m_actionFormatLanguageVHDL = m_menuFormatLanguageV->addAction(tr("V&HDL (The VHSIC Hardware Description Language)"));
    m_menuFormatLanguageX = m_menuFormatLanguage->addMenu(tr("&X"));
    m_actionFormatLanguageXML = m_menuFormatLanguageX->addAction(tr("&XML (eXtensible Markup Language)"));
    m_menuFormatLanguageY = m_menuFormatLanguage->addMenu(tr("&Y"));
    m_actionFormatLanguageYAML = m_menuFormatLanguageY->addAction(tr("&YAML (Yet Another Markup Language)"));
    m_menuFormatEol = m_menuFormat->addMenu(tr("&EOL"));
    m_actionFormatEolUnix = m_menuFormatEol->addAction(tr("EOL &Unix (LF)"));
    m_actionFormatEolMac = m_menuFormatEol->addAction(tr("EOL Classical &Mac (CR)"));
    m_actionFormatEolWindows = m_menuFormatEol->addAction(tr("EOL &Windows (CRLF)"));
    m_menuFormat->addSeparator();
    m_actionFormatIndentationUseTab = m_menuFormat->addAction(tr("&Use Tabs for Indentation (Instead of Spaces)"));

    m_actionFormatLanguageNone->setCheckable(true);
    m_actionFormatLanguageNone->setChecked(true);
    m_actionFormatLanguageAVS->setCheckable(true);
    m_actionFormatLanguageBash->setCheckable(true);
    m_actionFormatLanguageBatch->setCheckable(true);
    m_actionFormatLanguageC->setCheckable(true);
    m_actionFormatLanguageCMake->setCheckable(true);
    m_actionFormatLanguageCPP->setCheckable(true);
    m_actionFormatLanguageCSharp->setCheckable(true);
    m_actionFormatLanguageCoffeeScript->setCheckable(true);
    m_actionFormatLanguageCSS->setCheckable(true);
    m_actionFormatLanguageD->setCheckable(true);
    m_actionFormatLanguageDiff->setCheckable(true);
    m_actionFormatLanguageEDIFACT->setCheckable(true);
    m_actionFormatLanguageFortran->setCheckable(true);
    m_actionFormatLanguageFortran77->setCheckable(true);
    m_actionFormatLanguageHTML->setCheckable(true);
    m_actionFormatLanguageIDL->setCheckable(true);
    m_actionFormatLanguageJava->setCheckable(true);
    m_actionFormatLanguageJavaScript->setCheckable(true);
    m_actionFormatLanguageJSON->setCheckable(true);
    m_actionFormatLanguageLua->setCheckable(true);
    m_actionFormatLanguageMakefile->setCheckable(true);
    m_actionFormatLanguageMarkdown->setCheckable(true);
    m_actionFormatLanguageMatlab->setCheckable(true);
    m_actionFormatLanguageOctave->setCheckable(true);
    m_actionFormatLanguagePascal->setCheckable(true);
    m_actionFormatLanguagePerl->setCheckable(true);
    m_actionFormatLanguagePO->setCheckable(true);
    m_actionFormatLanguagePostScript->setCheckable(true);
    m_actionFormatLanguagePOV->setCheckable(true);
    m_actionFormatLanguageProperties->setCheckable(true);
    m_actionFormatLanguagePython->setCheckable(true);
    m_actionFormatLanguagePython3->setCheckable(true);
    m_actionFormatLanguageQSS->setCheckable(true);
    m_actionFormatLanguageRuby->setCheckable(true);
    m_actionFormatLanguageSpice->setCheckable(true);
    m_actionFormatLanguageSQL->setCheckable(true);
    m_actionFormatLanguageTCL->setCheckable(true);
    m_actionFormatLanguageTeX->setCheckable(true);
    m_actionFormatLanguageVerilog->setCheckable(true);
    m_actionFormatLanguageVHDL->setCheckable(true);
    m_actionFormatLanguageXML->setCheckable(true);
    m_actionFormatLanguageYAML->setCheckable(true);
    m_actionFormatEolUnix->setCheckable(true);
    m_actionFormatEolMac->setCheckable(true);
    m_actionFormatEolWindows->setCheckable(true);
    m_actionFormatEolUnix->setChecked(true);
    m_actionFormatIndentationUseTab->setCheckable(true);
}

void BrStormTextMainWindow::initToolsMenu()
{
    m_menuTools = new QMenu(tr("&Tools"));
    m_menuBar->addMenu(m_menuTools);

    m_menuToolsAutoCompletion = m_menuTools->addMenu(tr("&Auto-completion"));
    m_actionToolsAutoCompletionCaseSensitivity =
        m_menuToolsAutoCompletion->addAction(tr("Auto-completion &Case Sensitive"));
    m_actionToolsAutoCompletionReplaceWord =
        m_menuToolsAutoCompletion->addAction(tr("Auto-completion &Replace Word"));
    m_actionToolsAutoCompletionShowSingle =
        m_menuToolsAutoCompletion->addAction(tr("Auto-completion &Show Single"));
    m_menuToolsAutoCompletion->addSeparator();
    m_menuToolsAutoCompletionSource = m_menuToolsAutoCompletion->addMenu(tr("&Auto-completion Sources"));
    m_actionToolsAutoCompletionSourceAll = m_menuToolsAutoCompletionSource->addAction(tr("&All"));
    m_actionToolsAutoCompletionSourceDocument = m_menuToolsAutoCompletionSource->addAction(tr("&Document"));
    m_actionToolsAutoCompletionSourceAPIs = m_menuToolsAutoCompletionSource->addAction(tr("A&PIs"));
    m_menuToolsBraceMatching = m_menuTools->addMenu(tr("&Brace-matching"));
    m_actionToolsStrictBraceMatch = m_menuToolsBraceMatching->addAction(tr("&Strict Brace-match"));
    m_actionToolsSloppyBraceMatch = m_menuToolsBraceMatching->addAction(tr("S&loppy Brace-match"));
    m_menuTools->addSeparator();
    m_actionToolsAutoIndent = m_menuTools->addAction(tr("Auto-&Indent"));

    m_actionToolsAutoCompletionCaseSensitivity->setCheckable(true);
    m_actionToolsAutoCompletionReplaceWord->setCheckable(true);
    m_actionToolsAutoCompletionReplaceWord->setChecked(true);
    m_actionToolsAutoCompletionShowSingle->setCheckable(true);
    m_actionToolsAutoCompletionShowSingle->setChecked(true);
    m_actionToolsAutoCompletionSourceAll->setCheckable(true);
    m_actionToolsAutoCompletionSourceAll->setChecked(true);
    m_actionToolsAutoCompletionSourceDocument->setCheckable(true);
    m_actionToolsAutoCompletionSourceAPIs->setCheckable(true);
    m_actionToolsStrictBraceMatch->setCheckable(true);
    m_actionToolsStrictBraceMatch->setChecked(true);
    m_actionToolsSloppyBraceMatch->setCheckable(true);
    m_actionToolsAutoIndent->setCheckable(true);
    m_actionToolsAutoIndent->setChecked(true);
}

void BrStormTextMainWindow::initHelpMenu()
{
    m_menuHelp = new QMenu(tr("&Help"));
    m_menuBar->addMenu(m_menuHelp);

    m_actionAbout = m_menuHelp->addAction(tr("&About..."));
    m_actionAbout->setMenuRole(QAction::TextHeuristicRole);
    m_actionHelpAboutApp = m_menuHelp->addAction(tr("About &App..."));
    m_actionHelpAboutApp->setMenuRole(QAction::NoRole);
}

void BrStormTextMainWindow::initActionGroups()
{
    m_actionGroupViewWrapMode = new QActionGroup(this);

    m_actionGroupViewWrapMode->addAction(m_actionViewWrapNone);
    m_actionGroupViewWrapMode->addAction(m_actionViewWrapWord);
    m_actionGroupViewWrapMode->addAction(m_actionViewWrapCharacter);
    m_actionGroupViewWrapMode->addAction(m_actionViewWrapWhitespace);

    m_actionGroupViewWrapVisualFlag = new QActionGroup(this);

    m_actionGroupViewWrapVisualFlag->addAction(m_actionViewWrapFlagNone);
    m_actionGroupViewWrapVisualFlag->addAction(m_actionViewWrapFlagByText);
    m_actionGroupViewWrapVisualFlag->addAction(m_actionViewWrapFlagByBorder);
    m_actionGroupViewWrapVisualFlag->addAction(m_actionViewWrapFlagInMargin);

    /**
     * @todo: Add more languages
     */

    m_actionGroupFormatLanguage = new QActionGroup(this);

    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageNone);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageAVS);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageBash);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageBatch);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageC);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageCMake);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageCPP);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageCSharp);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageCoffeeScript);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageCSS);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageD);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageDiff);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageEDIFACT);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageFortran);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageFortran77);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageHTML);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageIDL);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageJava);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageJavaScript);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageJSON);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageLua);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageMakefile);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageMarkdown);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageMatlab);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageOctave);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePascal);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePerl);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePO);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePostScript);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePOV);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageProperties);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePython);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguagePython3);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageQSS);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageRuby);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageSpice);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageSQL);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageTCL);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageTeX);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageVerilog);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageVHDL);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageXML);
    m_actionGroupFormatLanguage->addAction(m_actionFormatLanguageYAML);

    m_actionGroupFormatEol = new QActionGroup(this);

    m_actionGroupFormatEol->addAction(m_actionFormatEolUnix);
    m_actionGroupFormatEol->addAction(m_actionFormatEolMac);
    m_actionGroupFormatEol->addAction(m_actionFormatEolWindows);

    m_actionGroupToolsAutoCompletionSource = new QActionGroup(this);

    m_actionGroupToolsAutoCompletionSource->addAction(m_actionToolsAutoCompletionSourceAll);
    m_actionGroupToolsAutoCompletionSource->addAction(m_actionToolsAutoCompletionSourceDocument);
    m_actionGroupToolsAutoCompletionSource->addAction(m_actionToolsAutoCompletionSourceAPIs);

    m_actionGroupToolsBraceMatching = new QActionGroup(this);

    m_actionGroupToolsBraceMatching->addAction(m_actionToolsStrictBraceMatch);
    m_actionGroupToolsBraceMatching->addAction(m_actionToolsSloppyBraceMatch);
}

void BrStormTextMainWindow::initTabs()
{
    QFileIconProvider fic;
    QIcon ficns = fic.icon(QFileIconProvider::File);

    BrStormTextEditor *ed;
    ed = new BrStormTextEditor(this);

    connect(ed, &BrStormTextEditor::cursorPositionChanged,
            this, [=](){m_actionEditUndo->setEnabled(true);m_actionEditRedo->setEnabled(true);});
    connect(ed, &BrStormTextEditor::copyAvailable,
            this, [=](bool c){m_actionEditCut->setEnabled(c);m_actionEditCopy->setEnabled(c);m_actionEditDelete->setEnabled(c);});
    connect(ed, &BrStormTextEditor::modificationChanged,
            this, [=](bool c){setWindowModified(c);});

    m_tab = new BrStormTextTab(this);
    int i = m_tab->addTab(ed, ficns, tr("Untitled"));
    m_tab->setCurrentIndex(i);
    m_tab->setUsesScrollButtons(true);
    setCentralWidget(m_tab);

    setWindowFilePath("Untitled");
    setWindowOpacity(0.95);

    m_untitled += 1;
}

void BrStormTextMainWindow::initStatusBar()
{
    m_sb = new BrStormTextStatusBar();

    m_lexerButton = new QToolButton();
    m_lexerButton->setAcceptDrops(false);
    m_lexerButton->setPopupMode(QToolButton::InstantPopup);
    m_lexerButton->setDefaultAction(m_actionFormatLanguageNone);
    m_lexerButton->setMenu(m_menuFormatLanguage);
    m_lexerButton->setPalette(m_sb->palette());
    connect(m_lexerButton, &QToolButton::triggered,
            this, [=](QAction *a){m_lexerButton->setDefaultAction(a);});
    m_sb->addWidget(m_lexerButton);

    setStatusBar(m_sb);
}

void BrStormTextMainWindow::initFileBrowser()
{
    m_fbw = new BrStormTextFileTreeview();
    m_fbm = new BrStormTextFileModel();
    m_fbw->setModel(m_fbm);

    m_fb = new BrStormTextFileDock();
    m_fb->setWidget(m_fbw);

    addDockWidget(Qt::LeftDockWidgetArea, m_fb);
}

void BrStormTextMainWindow::initFindDock()
{
    m_findDock = new BrStormTextFindDock(m_tab);
    addDockWidget(Qt::RightDockWidgetArea, m_findDock);
}

void BrStormTextMainWindow::initSignals()
{
    /**
     * @todo: Add more languages
     */

    connect(m_tab, SIGNAL(currentChanged(int)),
            this, SLOT(handleTabChanged(int)));
    connect(m_tab, SIGNAL(tabCloseRequested(int)),
            this, SLOT(handleTabCloseRequest(int)));
    connect(m_fbw, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(handleFileBrowserDoubleClicked(QModelIndex)));
    connect(m_fb, &QDockWidget::visibilityChanged,
            this, [=](bool c){m_actionViewShowFileBrowser->setChecked(c);});
    connect(m_actionFileNew, SIGNAL(triggered(bool)),
            this, SLOT(newFile(bool)));
    connect(m_actionFileNewWindow, SIGNAL(triggered(bool)),
            this, SLOT(wNewFile(bool)));
    connect(m_actionFileOpen, SIGNAL(triggered(bool)),
            this, SLOT(openFile(bool)));
    connect(m_actionFileOpenWindow, SIGNAL(triggered(bool)),
            this, SLOT(wOpenFile(bool)));
    connect(m_actionFileSave, SIGNAL(triggered(bool)),
            this, SLOT(saveFile(bool)));
    connect(m_actionFileSaveAs, SIGNAL(triggered(bool)),
            this, SLOT(saveAsFile(bool)));
    connect(m_actionFileSaveCopyTo, SIGNAL(triggered(bool)),
            this, SLOT(saveCopyToFile(bool)));
    connect(m_actionFileSaveAll, SIGNAL(triggered(bool)),
            this, SLOT(saveAllFile(bool)));
    connect(m_actionFileClose, SIGNAL(triggered(bool)),
            this, SLOT(closeFile(bool)));
    connect(m_actionFileCloseAll, SIGNAL(triggered(bool)),
            this, SLOT(closeAllFile(bool)));
    connect(m_actionFileCloseLeft, SIGNAL(triggered(bool)),
            this, SLOT(closeFileLeft(bool)));
    connect(m_actionFileCloseRight, SIGNAL(triggered(bool)),
            this, SLOT(closeFileRight(bool)));
    connect(m_actionFileCloseUnchanged, SIGNAL(triggered(bool)),
            this, SLOT(closeFileUnchanged(bool)));
    connect(m_actionEditUndo, SIGNAL(triggered(bool)),
            this, SLOT(editUndo(bool)));
    connect(m_actionEditRedo, SIGNAL(triggered(bool)),
            this, SLOT(editRedo(bool)));
    connect(m_actionEditCut, SIGNAL(triggered(bool)),
            this, SLOT(editCut(bool)));
    connect(m_actionEditCopy, SIGNAL(triggered(bool)),
            this, SLOT(editCopy(bool)));
    connect(m_actionEditPaste, SIGNAL(triggered(bool)),
            this, SLOT(editPaste(bool)));
    connect(m_actionEditDelete, SIGNAL(triggered(bool)),
            this, SLOT(editDelete(bool)));
    connect(m_actionEditSelectAll, SIGNAL(triggered(bool)),
            this, SLOT(editSelectAll(bool)));
    connect(m_actionEditIndentationIndent, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->indent(m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_GETLINE)+1);});
    connect(m_actionEditIndentationDedent, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->unindent(m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_GETLINE)+1);});
    connect(m_actionEditFindFind, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_findDock->setVisible(!m_findDock->isVisible());});
    connect(m_actionEditFindNext, &QAction::triggered,
            m_findDock, &BrStormTextFindDock::findNext);
    connect(m_actionEditFindPrevious, &QAction::triggered,
            m_findDock, &BrStormTextFindDock::findPrevious);
    connect(m_actionEditFindGoto, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_gD->setVisible(!m_gD->isVisible());});
    connect(m_actionEditReplaceFindNext, &QAction::triggered,
            m_findDock, &BrStormTextFindDock::replaceNext);
    connect(m_actionEditReplaceFindPrevious, &QAction::triggered,
            m_findDock, &BrStormTextFindDock::replacePrevious);
    connect(m_actionEditReplaceAll, &QAction::triggered,
            m_findDock, &BrStormTextFindDock::replaceAll);
#ifndef Q_OS_DARWIN
    connect(m_actionViewFullscreen, &QAction::triggered,
            this, [=](bool c){c ? showFullScreen() : showMaximized();});
#endif
    connect(m_actionViewSymbolsEol, SIGNAL(triggered(bool)),
            this, SLOT(setShowEol(bool)));
    connect(m_actionViewSymbolsWhitespace, SIGNAL(triggered(bool)),
            this, SLOT(setShowWhitespace(bool)));
    connect(m_actionViewZoomIn, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->zoomIn(1);});
    connect(m_actionViewZoomOut, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->zoomOut(1);});
    connect(m_actionViewZoomDefault, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->zoomTo(0);});
    connect(m_actionViewTab1, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(0);});
    connect(m_actionViewTab2, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(1);});
    connect(m_actionViewTab3, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(2);});
    connect(m_actionViewTab4, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(3);});
    connect(m_actionViewTab5, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(4);});
    connect(m_actionViewTab6, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(5);});
    connect(m_actionViewTab7, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(6);});
    connect(m_actionViewTab8, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(7);});
    connect(m_actionViewTab9, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(8);});
    connect(m_actionViewTab10, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(9);});
    connect(m_actionViewTabLast, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(m_tab->count()-1);});
    connect(m_actionViewTabPrevious, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(m_tab->currentIndex()-1);});
    connect(m_actionViewTabNext, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->setCurrentIndex(m_tab->currentIndex()+1);});
    connect(m_actionViewMarkersEnable, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setEnableMarkers(c);
                              m_actionViewMarkersNew->setEnabled(c);m_actionViewMarkersDelete->setEnabled(c);
                              m_actionViewMarkersDeleteAll->setEnabled(c);});
    connect(m_actionViewMarkersNew, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->addMarker(c);});
    connect(m_actionViewMarkersDelete, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->delMarker(c);});
    connect(m_actionViewMarkersDeleteAll, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->delAllMarkers(c);});
    connect(m_actionViewWrapNone, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->setWrapMode(QsciScintilla::WrapNone);});
    connect(m_actionViewWrapWord, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapMode(c?QsciScintilla::WrapWord:QsciScintilla::WrapNone);});
    connect(m_actionViewWrapCharacter, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapMode(c?QsciScintilla::WrapCharacter:QsciScintilla::WrapNone);});
    connect(m_actionViewWrapWhitespace, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapMode(c?QsciScintilla::WrapWhitespace:QsciScintilla::WrapNone);});
    connect(m_actionViewWrapFlagNone, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->setWrapVisualFlags(QsciScintilla::WrapFlagNone);});
    connect(m_actionViewWrapFlagByText, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapVisualFlags(c?QsciScintilla::WrapFlagByText:QsciScintilla::WrapFlagNone);});
    connect(m_actionViewWrapFlagByBorder, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapVisualFlags(c?QsciScintilla::WrapFlagByBorder:QsciScintilla::WrapFlagNone);});
    connect(m_actionViewWrapFlagInMargin, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setWrapVisualFlags(c?QsciScintilla::WrapFlagInMargin:QsciScintilla::WrapFlagNone);});
    connect(m_actionViewFoldAll, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->foldAll();});
    connect(m_actionViewFoldAllChildren, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->foldAll(true);});
    connect(m_actionViewFoldCurrentLine, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->foldLine(
                                              m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_GETCURLINE)
                                          );});
    connect(m_actionViewMoveLineDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEDOWN);});
    connect(m_actionViewMoveLineDownExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEDOWNEXTEND);});
    connect(m_actionViewMoveLineDownRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEDOWNRECTEXTEND);});
    connect(m_actionViewMoveLineScrollDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINESCROLLDOWN);});
    connect(m_actionViewMoveLineUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEUP);});
    connect(m_actionViewMoveLineUpExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEUPEXTEND);});
    connect(m_actionViewMoveLineUpRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEUPRECTEXTEND);});
    connect(m_actionViewMoveLineScrollUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINESCROLLUP);});
    connect(m_actionViewMoveLineEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEEND);});
    connect(m_actionViewMoveLineEndExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDEXTEND);});
    connect(m_actionViewMoveLineEndRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDRECTEXTEND);});
    connect(m_actionViewMoveLineEndDisplay, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDDISPLAY);});
    connect(m_actionViewMoveLineEndDisplayExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDDISPLAYEXTEND);});
    connect(m_actionViewMoveLineEndWrap, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDWRAP);});
    connect(m_actionViewMoveLineEndWrapExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEENDWRAPEXTEND);});
    connect(m_actionViewMoveLineDelete, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEDELETE);});
    connect(m_actionViewMoveLineCut, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINECUT);});
    connect(m_actionViewMoveLineCopy, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINECOPY);});
    connect(m_actionViewMoveLineTranspose, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINETRANSPOSE);});
    connect(m_actionViewMoveLineDuplicate, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_LINEDUPLICATE);});
    connect(m_actionViewMoveScrollToStart, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_SCROLLTOSTART);});
    connect(m_actionViewMoveScrollToEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_SCROLLTOEND);});
    connect(m_actionViewMoveVerticalCenterCaret, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VERTICALCENTRECARET);});
    connect(m_actionViewMoveParaDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PARADOWN);});
    connect(m_actionViewMoveParaDownExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PARADOWNEXTEND);});
    connect(m_actionViewMoveParaUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PARAUP);});
    connect(m_actionViewMoveParaUpExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PARAUPEXTEND);});
    connect(m_actionViewMoveCharLeft, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARLEFT);});
    connect(m_actionViewMoveCharLeftExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARLEFTEXTEND);});
    connect(m_actionViewMoveCharLeftRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARLEFTRECTEXTEND);});
    connect(m_actionViewMoveCharRight, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARRIGHT);});
    connect(m_actionViewMoveCharRightExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARRIGHTEXTEND);});
    connect(m_actionViewMoveCharRightRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_CHARRIGHTRECTEXTEND);});
    connect(m_actionViewMoveWordLeft, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDLEFT);});
    connect(m_actionViewMoveWordLeftExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDLEFTEXTEND);});
    connect(m_actionViewMoveWordRight, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDRIGHT);});
    connect(m_actionViewMoveWordRightExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDRIGHTEXTEND);});
    connect(m_actionViewMoveWordLeftEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDLEFTEND);});
    connect(m_actionViewMoveWordLeftEndExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDLEFTENDEXTEND);});
    connect(m_actionViewMoveWordRightEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDRIGHTEND);});
    connect(m_actionViewMoveWordRightEndExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDRIGHTENDEXTEND);});
    connect(m_actionViewMoveWordPartLeft, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDPARTLEFT);});
    connect(m_actionViewMoveWordPartLeftExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDPARTLEFTEXTEND);});
    connect(m_actionViewMoveWordPartRight, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDPARTRIGHT);});
    connect(m_actionViewMoveWordPartRightExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_WORDPARTRIGHTEXTEND);});
    connect(m_actionViewMoveHome, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOME);});
    connect(m_actionViewMoveHomeExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMEEXTEND);});
    connect(m_actionViewMoveHomeRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMERECTEXTEND);});
    connect(m_actionViewMoveHomeDisplay, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMEDISPLAY);});
    connect(m_actionViewMoveHomeDisplayExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMEDISPLAYEXTEND);});
    connect(m_actionViewMoveHomeWrap, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMEWRAP);});
    connect(m_actionViewMoveHomeWrapExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_HOMEWRAPEXTEND);});
    connect(m_actionViewMoveVCHome, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VCHOME);});
    connect(m_actionViewMoveVCHomeExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VCHOMEEXTEND);});
    connect(m_actionViewMoveVCHomeRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VCHOMERECTEXTEND);});
    connect(m_actionViewMoveVCHomeWrap, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VCHOMEWRAP);});
    connect(m_actionViewMoveVCHomeWrapExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_VCHOMEWRAPEXTEND);});
    connect(m_actionViewMoveDocumentStart, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DOCUMENTSTART);});
    connect(m_actionViewMoveDocumentStartExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DOCUMENTSTARTEXTEND);});
    connect(m_actionViewMoveDocumentEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DOCUMENTEND);});
    connect(m_actionViewMoveDocumentEndExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DOCUMENTENDEXTEND);});
    connect(m_actionViewMovePageUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEUP);});
    connect(m_actionViewMovePageUpExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEUPEXTEND);});
    connect(m_actionViewMovePageUpRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEUPRECTEXTEND);});
    connect(m_actionViewMovePageDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEDOWN);});
    connect(m_actionViewMovePageDownExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEDOWNEXTEND);});
    connect(m_actionViewMovePageDownRectExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_PAGEDOWNRECTEXTEND);});
    connect(m_actionViewMoveStutteredPageUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_STUTTEREDPAGEUP);});
    connect(m_actionViewMoveStutteredPageUpExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_STUTTEREDPAGEUPEXTEND);});
    connect(m_actionViewMoveStutteredPageDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_STUTTEREDPAGEDOWN);});
    connect(m_actionViewMoveStutteredPageDownExtend, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_STUTTEREDPAGEDOWNEXTEND);});
    connect(m_actionViewMoveDeleteBack, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELETEBACK);});
    connect(m_actionViewMoveDeleteBackNotLine, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELETEBACKNOTLINE);});
    connect(m_actionViewMoveDeleteWordLeft, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELWORDLEFT);});
    connect(m_actionViewMoveDeleteWordRight, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELWORDRIGHT);});
    connect(m_actionViewMoveDeleteWordRightEnd, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELWORDRIGHTEND);});
    connect(m_actionViewMoveDeleteLineLeft, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELLINELEFT);});
    connect(m_actionViewMoveDeleteLineRight, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_DELLINERIGHT);});
    connect(m_actionViewMoveMoveSelectedLinesUp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_MOVESELECTEDLINESUP);});
    connect(m_actionViewMoveMoveSelectedLinesDown, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_MOVESELECTEDLINESDOWN);});
    connect(m_actionViewMoveSelectionDuplicate, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_SELECTIONDUPLICATE);});
    connect(m_actionViewVirtualSelection, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setSelectionToEol(c);});
    connect(m_actionViewReadOnly, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setReadOnly(c);});
    connect(m_actionViewShowFileBrowser, &QAction::triggered,
            this, [=](bool c){m_fb->setVisible(c);});
    connect(m_actionViewShowAutocomplete, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionSource(c?QsciScintilla::AcsAll:QsciScintilla::AcsNone);
                              m_actionGroupToolsAutoCompletionSource->setEnabled(c);});
    connect(m_actionViewShowBraceMatching, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setBraceMatching(c?QsciScintilla::StrictBraceMatch:QsciScintilla::NoBraceMatch);});
    connect(m_actionViewShowCaretBackground, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setCaretLineVisible(c);});
    connect(m_actionViewShowIndentationGuides, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setIndentationGuides(c);});
    connect(m_actionViewShowLineNumbers, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setMarginLineNumbers(0,c);});
    connect(m_actionFormatLanguageNone, SIGNAL(triggered(bool)),
            this, SLOT(setLexerNone(bool)));
    connect(m_actionFormatLanguageAVS, SIGNAL(triggered(bool)),
            this, SLOT(setLexerAVS(bool)));
    connect(m_actionFormatLanguageBash, SIGNAL(triggered(bool)),
            this, SLOT(setLexerBash(bool)));
    connect(m_actionFormatLanguageBatch, SIGNAL(triggered(bool)),
            this, SLOT(setLexerBatch(bool)));
    connect(m_actionFormatLanguageC, SIGNAL(triggered(bool)),
            this, SLOT(setLexerC(bool)));
    connect(m_actionFormatLanguageCMake, SIGNAL(triggered(bool)),
            this, SLOT(setLexerCMake(bool)));
    connect(m_actionFormatLanguageCPP, SIGNAL(triggered(bool)),
            this, SLOT(setLexerCPP(bool)));
    connect(m_actionFormatLanguageCSharp, SIGNAL(triggered(bool)),
            this, SLOT(setLexerCSharp(bool)));
    connect(m_actionFormatLanguageCoffeeScript, SIGNAL(triggered(bool)),
            this, SLOT(setLexerCoffeeScript(bool)));
    connect(m_actionFormatLanguageCSS, SIGNAL(triggered(bool)),
            this, SLOT(setLexerCSS(bool)));
    connect(m_actionFormatLanguageD, SIGNAL(triggered(bool)),
            this, SLOT(setLexerD(bool)));
    connect(m_actionFormatLanguageDiff, SIGNAL(triggered(bool)),
            this, SLOT(setLexerDiff(bool)));
    connect(m_actionFormatLanguageEDIFACT, SIGNAL(triggered(bool)),
            this, SLOT(setLexerEDIFACT(bool)));
    connect(m_actionFormatLanguageFortran, SIGNAL(triggered(bool)),
            this, SLOT(setLexerFortran(bool)));
    connect(m_actionFormatLanguageFortran77, SIGNAL(triggered(bool)),
            this, SLOT(setLexerFortran77(bool)));
    connect(m_actionFormatLanguageHTML, SIGNAL(triggered(bool)),
            this, SLOT(setLexerHTML(bool)));
    connect(m_actionFormatLanguageIDL, SIGNAL(triggered(bool)),
            this, SLOT(setLexerIDL(bool)));
    connect(m_actionFormatLanguageJava, SIGNAL(triggered(bool)),
            this, SLOT(setLexerJava(bool)));
    connect(m_actionFormatLanguageJavaScript, SIGNAL(triggered(bool)),
            this, SLOT(setLexerJavaScript(bool)));
    connect(m_actionFormatLanguageJSON, SIGNAL(triggered(bool)),
            this, SLOT(setLexerJSON(bool)));
    connect(m_actionFormatLanguageLua, SIGNAL(triggered(bool)),
            this, SLOT(setLexerLua(bool)));
    connect(m_actionFormatLanguageMakefile, SIGNAL(triggered(bool)),
            this, SLOT(setLexerMakefile(bool)));
    connect(m_actionFormatLanguageMarkdown, SIGNAL(triggered(bool)),
            this, SLOT(setLexerMarkdown(bool)));
    connect(m_actionFormatLanguageMatlab, SIGNAL(triggered(bool)),
            this, SLOT(setLexerMatlab(bool)));
    connect(m_actionFormatLanguageOctave, SIGNAL(triggered(bool)),
            this, SLOT(setLexerOctave(bool)));
    connect(m_actionFormatLanguagePascal, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPascal(bool)));
    connect(m_actionFormatLanguagePerl, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPerl(bool)));
    connect(m_actionFormatLanguagePO, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPO(bool)));
    connect(m_actionFormatLanguagePostScript, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPostScript(bool)));
    connect(m_actionFormatLanguagePOV, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPOV(bool)));
    connect(m_actionFormatLanguageProperties, SIGNAL(triggered(bool)),
            this, SLOT(setLexerProperties(bool)));
    connect(m_actionFormatLanguagePython, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPython(bool)));
    connect(m_actionFormatLanguagePython3, SIGNAL(triggered(bool)),
            this, SLOT(setLexerPython3(bool)));
    connect(m_actionFormatLanguageQSS, SIGNAL(triggered(bool)),
            this, SLOT(setLexerQSS(bool)));
    connect(m_actionFormatLanguageRuby, SIGNAL(triggered(bool)),
            this, SLOT(setLexerRuby(bool)));
    connect(m_actionFormatLanguageSpice, SIGNAL(triggered(bool)),
            this, SLOT(setLexerSpice(bool)));
    connect(m_actionFormatLanguageSQL, SIGNAL(triggered(bool)),
            this, SLOT(setLexerSQL(bool)));
    connect(m_actionFormatLanguageTCL, SIGNAL(triggered(bool)),
            this, SLOT(setLexerTCL(bool)));
    connect(m_actionFormatLanguageTeX, SIGNAL(triggered(bool)),
            this, SLOT(setLexerTeX(bool)));
    connect(m_actionFormatLanguageVerilog, SIGNAL(triggered(bool)),
            this, SLOT(setLexerVerilog(bool)));
    connect(m_actionFormatLanguageVHDL, SIGNAL(triggered(bool)),
            this, SLOT(setLexerVHDL(bool)));
    connect(m_actionFormatLanguageXML, SIGNAL(triggered(bool)),
            this, SLOT(setLexerXML(bool)));
    connect(m_actionFormatLanguageYAML, SIGNAL(triggered(bool)),
            this, SLOT(setLexerYAML(bool)));
    connect(m_actionFormatEolUnix, SIGNAL(triggered(bool)),
            this, SLOT(setEolUnix(bool)));
    connect(m_actionFormatEolMac, SIGNAL(triggered(bool)),
            this, SLOT(setEolMac(bool)));
    connect(m_actionFormatEolWindows, SIGNAL(triggered(bool)),
            this, SLOT(setEolWindows(bool)));
    connect(m_actionFormatIndentationUseTab, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setIndentationsUseTabs(c);});
    connect(m_actionToolsAutoCompletionCaseSensitivity, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionCaseSensitivity(c);});
    connect(m_actionToolsAutoCompletionReplaceWord, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionReplaceWord(c);});
    connect(m_actionToolsAutoCompletionShowSingle, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionShowSingle(c);});
    connect(m_actionToolsAutoCompletionSourceAll, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionSource(c?QsciScintilla::AcsAll:QsciScintilla::AcsNone);});
    connect(m_actionToolsAutoCompletionSourceDocument, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionSource(c?QsciScintilla::AcsDocument:QsciScintilla::AcsNone);});
    connect(m_actionToolsAutoCompletionSourceAPIs, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoCompletionSource(c?QsciScintilla::AcsAPIs:QsciScintilla::AcsNone);});
    connect(m_actionToolsStrictBraceMatch, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setBraceMatching(c?QsciScintilla::StrictBraceMatch:QsciScintilla::NoBraceMatch);});
    connect(m_actionToolsSloppyBraceMatch, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setBraceMatching(c?QsciScintilla::SloppyBraceMatch:QsciScintilla::NoBraceMatch);});
    connect(m_actionToolsAutoIndent, &QAction::triggered,
            this, [=](bool c){m_tab->currentTab()->setAutoIndent(c);});
    connect(m_actionAbout, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_aD->show();});
    connect(m_actionHelpAboutApp, &QAction::triggered,
            this, [=](bool c){Q_UNUSED(c);m_aAppD->show();});
}

int BrStormTextMainWindow::saves()
{
    if (m_unchanged) return -1;

    QMessageBox msg;
    msg.setWindowTitle(tr("StormText"));
    msg.setIcon(QMessageBox::Question);
    msg.setText(QString("Do you want to save your changes to ") + windowFilePath() + QString("?"));
    msg.setInformativeText(tr("If no, your information will be deleted permanently "
                              "and cannot be retrieved anymore, forever."));
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    int e = msg.exec();

    if (e == QMessageBox::Save) return 1;
    else if (e == QMessageBox::Discard) return 0;
    else if (e == QMessageBox::Cancel) return -1;
    else return -2;
}

void BrStormTextMainWindow::handleTabChanged(int idx)
{
    if (m_tab->count() > 0)
    {
        m_actionGroupFormatLanguage->setEnabled(true);
        m_actionGroupFormatEol->setEnabled(true);

        QFile f(m_tab->tabToolTip(idx));
        QFileInfo fi(f);

        if (fi.exists())
        {
            setWindowFilePath(fi.absoluteFilePath());
            m_fbw->setCurrentIndex(m_fbm->index(fi.absoluteFilePath()));
        }

        else
        {
            setWindowFilePath(m_tab->tabText(idx));
        }

        setWindowModified(m_tab->currentTab()->isModified());

        m_actionEditUndo->setEnabled(m_tab->currentTab()->isUndoAvailable());
        m_actionEditRedo->setEnabled(m_tab->currentTab()->isRedoAvailable());
        m_actionEditCut->setEnabled(m_tab->currentTab()->hasSelectedText());
        m_actionEditCopy->setEnabled(m_tab->currentTab()->hasSelectedText());
        m_actionEditDelete->setEnabled(m_tab->currentTab()->hasSelectedText());

        m_actionViewMarkersEnable->setChecked(m_tab->currentTab()->markerEnable());
        m_actionViewWrapNone->setChecked(m_tab->currentTab()->wrapMode() == QsciScintilla::WrapNone);
        m_actionViewWrapCharacter->setChecked(m_tab->currentTab()->wrapMode() == QsciScintilla::WrapCharacter);
        m_actionViewWrapWhitespace->setChecked(m_tab->currentTab()->wrapMode() == QsciScintilla::WrapWhitespace);
        m_actionViewWrapWord->setChecked(m_tab->currentTab()->wrapMode() == QsciScintilla::WrapWord);
        m_actionViewWrapFlagNone->setChecked(m_tab->currentTab()->wrapVisualFlag() == QsciScintilla::WrapFlagNone);
        m_actionViewWrapFlagByBorder->setChecked(m_tab->currentTab()->wrapVisualFlag() == QsciScintilla::WrapFlagByBorder);
        m_actionViewWrapFlagByText->setChecked(m_tab->currentTab()->wrapVisualFlag() == QsciScintilla::WrapFlagByText);
        m_actionViewWrapFlagInMargin->setChecked(m_tab->currentTab()->wrapVisualFlag() == QsciScintilla::WrapFlagInMargin);
        m_actionViewVirtualSelection->setChecked(m_tab->currentTab()->selectionToEol());
        m_actionViewShowAutocomplete->setChecked(m_tab->currentTab()->autoCompletionSource() != QsciScintilla::AcsNone);
        m_actionViewShowBraceMatching->setChecked(m_tab->currentTab()->braceMatching() != QsciScintilla::NoBraceMatch);
        m_actionViewShowCaretBackground->setChecked(m_tab->currentTab()->SendScintilla(QsciScintilla::SCI_GETCARETLINEVISIBLE));
        m_actionViewShowIndentationGuides->setChecked(m_tab->currentTab()->indentationGuides());
        m_actionViewShowLineNumbers->setChecked(m_tab->currentTab()->marginLineNumbers(0));
        m_actionViewSymbolsEol->setChecked(m_tab->currentTab()->eolVisibility());
        m_actionViewReadOnly->setChecked(m_tab->currentTab()->isReadOnly());

        m_actionFormatIndentationUseTab->setChecked(m_tab->currentTab()->indentationsUseTabs());

        m_actionViewSymbolsWhitespace->setChecked(m_tab->currentTab()->whitespaceVisibility() != QsciScintilla::WsInvisible);
        m_actionToolsAutoCompletionCaseSensitivity->setChecked(m_tab->currentTab()->autoCompletionCaseSensitivity());
        m_actionToolsAutoCompletionReplaceWord->setChecked(m_tab->currentTab()->autoCompletionReplaceWord());
        m_actionToolsAutoCompletionShowSingle->setChecked(m_tab->currentTab()->autoCompletionShowSingle());
        m_actionToolsAutoCompletionSourceAPIs->setChecked(m_tab->currentTab()->autoCompletionSource() == QsciScintilla::AcsAPIs);
        m_actionToolsAutoCompletionSourceAll->setChecked(m_tab->currentTab()->autoCompletionSource() == QsciScintilla::AcsAll);
        m_actionToolsAutoCompletionSourceDocument->setChecked(m_tab->currentTab()->autoCompletionSource() == QsciScintilla::AcsDocument);
        m_actionToolsSloppyBraceMatch->setChecked(m_tab->currentTab()->braceMatching() == QsciScintilla::SloppyBraceMatch);
        m_actionToolsStrictBraceMatch->setChecked(m_tab->currentTab()->braceMatching() == QsciScintilla::StrictBraceMatch);
        m_actionToolsAutoIndent->setChecked(m_tab->currentTab()->autoIndent());

        if (m_tab->currentTab()->lexer())
        {
            QString l = QString(m_tab->currentTab()->lexer()->language());

            /**
             * @todo: Add more languages
             */

            m_actionFormatLanguageAVS->setChecked(l == "AVS");
            m_actionFormatLanguageBash->setChecked(l == "Bash");
            m_actionFormatLanguageBatch->setChecked(l == "Batch");
            m_actionFormatLanguageCMake->setChecked(l == "CMake");
            m_actionFormatLanguageCoffeeScript->setChecked(l == "CoffeeScript");
            m_actionFormatLanguageC->setChecked(l == "C");
            m_actionFormatLanguageCPP->setChecked(l == "C++");
            m_actionFormatLanguageCSharp->setChecked(l == "C#");
            m_actionFormatLanguageCSS->setChecked(l == "CSS");
            m_actionFormatLanguageD->setChecked(l == "D");
            m_actionFormatLanguageDiff->setChecked(l == "Diff");
            m_actionFormatLanguageEDIFACT->setChecked(l == "EDIFACT");
            m_actionFormatLanguageFortran->setChecked(l == "Fortran");
            m_actionFormatLanguageFortran77->setChecked(l == "Fortran77");
            m_actionFormatLanguageHTML->setChecked(l == "HTML");
            m_actionFormatLanguageIDL->setChecked(l == "IDL");
            m_actionFormatLanguageJava->setChecked(l == "Java");
            m_actionFormatLanguageJavaScript->setChecked(l == "JavaScript");
            m_actionFormatLanguageJSON->setChecked(l == "JSON");
            m_actionFormatLanguageLua->setChecked(l == "Lua");
            m_actionFormatLanguageMakefile->setChecked(l == "Makefile");
            m_actionFormatLanguageMarkdown->setChecked(l == "Markdown");
            m_actionFormatLanguageMatlab->setChecked(l == "Matlab");
            m_actionFormatLanguageOctave->setChecked(l == "Octave");
            m_actionFormatLanguagePascal->setChecked(l == "Pascal");
            m_actionFormatLanguagePerl->setChecked(l == "Perl");
            m_actionFormatLanguagePO->setChecked(l == "PO");
            m_actionFormatLanguagePostScript->setChecked(l == "PostScript");
            m_actionFormatLanguagePOV->setChecked(l == "POV");
            m_actionFormatLanguageProperties->setChecked(l == "Properties");
            m_actionFormatLanguagePython->setChecked(l == "Python");
            m_actionFormatLanguagePython3->setChecked(l == "Python 3");
            m_actionFormatLanguageQSS->setChecked(l == "QSS");
            m_actionFormatLanguageRuby->setChecked(l == "Ruby");
            m_actionFormatLanguageSpice->setChecked(l == "Spice");
            m_actionFormatLanguageSQL->setChecked(l == "SQL");
            m_actionFormatLanguageTCL->setChecked(l == "TCL");
            m_actionFormatLanguageTeX->setChecked(l == "TeX");
            m_actionFormatLanguageVerilog->setChecked(l == "Verilog");
            m_actionFormatLanguageVHDL->setChecked(l == "VHDL");
            m_actionFormatLanguageXML->setChecked(l == "XML");
            m_actionFormatLanguageYAML->setChecked(l == "YAML");
        }

        else
        {
            m_actionFormatLanguageNone->setChecked(true);
        }

        m_actionFormatEolUnix->setChecked(m_tab->currentTab()->eolMode() == QsciScintilla::EolUnix);
        m_actionFormatEolMac->setChecked(m_tab->currentTab()->eolMode() == QsciScintilla::EolMac);
        m_actionFormatEolWindows->setChecked(m_tab->currentTab()->eolMode() == QsciScintilla::EolWindows);

        m_actionGroupToolsAutoCompletionSource->setEnabled(m_actionViewShowAutocomplete->isChecked());
        m_actionGroupToolsBraceMatching->setEnabled(m_actionViewShowBraceMatching->isChecked());
    }

    else
    {
        m_actionGroupFormatLanguage->setEnabled(false);
        m_actionGroupFormatEol->setEnabled(false);
        m_actionViewZoomIn->setEnabled(false);
        m_actionViewZoomOut->setEnabled(false);
        m_actionViewZoomDefault->setEnabled(false);
        m_actionViewShowIndentationGuides->setEnabled(false);
        m_actionViewShowCaretBackground->setEnabled(false);
        m_actionViewShowBraceMatching->setEnabled(false);
        m_actionViewShowAutocomplete->setEnabled(false);
        m_actionViewShowLineNumbers->setEnabled(false);
    }
}

void BrStormTextMainWindow::handleTabCloseRequest(int idx)
{
    m_tab->setCurrentIndex(idx);

    closeFile(true);
}

void BrStormTextMainWindow::handleFileBrowserDoubleClicked(QModelIndex idx)
{
    QString path = m_fbm->fileInfo(idx).absoluteFilePath();

    if (QFileInfo(QFile(path)).isDir()) return;
    if (idx.column() != 0) return;

    QFile f(path);

    if (!f.exists())
    {
        QMessageBox msg = QMessageBox(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setWindowTitle(tr("FileNoutFoundError"));
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("Sorry, the file you have selected does not exists."));
        msg.setInformativeText(tr("Check if you have misspelt the file name,"
                                  "the file path or check your network connections. \n"
                                  "BR_STORMTEXT_0x00003855"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }

    if (f.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream ts(&f);
        QString c = ts.readAll();
        QFileInfo fi(f);
        QFileIconProvider fip;
        QIcon icns = fip.icon(fi);
        QString ce = fi.completeSuffix().toLower();

        for (int ti = 0; ti < m_tab->count(); ti++)
        {
            if (m_tab->tabToolTip(ti) == fi.absoluteFilePath())
            {
                return;
            }
        }

        BrStormTextEditor *ed;
        ed = new BrStormTextEditor(this);
        ed->setText(c);

        connect(ed, &QsciScintilla::modificationChanged,
                this, [=](bool c){setWindowModified(c);});

        /**
         * @todo: Add more languages
         */

        if (ce == "avs")
        {
            ed->setLexerAVS(true);
        }

        else if (ce == "sh"
                 || ce == "bash")
        {
            ed->setLexerBash(true);
        }

        else if (ce == "bat"
                 || ce =="cmd"
                 || ce == "btm")
        {
            ed->setLexerBatch(true);
        }

        else if (ce == "c")
        {
            ed->setLexerC(true);
        }

        else if (ce == "cpp"
                 || ce == "cxx"
                 || ce == "cc"
                 || ce == "ii"
                 || ce == "hpp"
                 || ce == "hxx")
        {
            ed->setLexerCPP(true);
        }

        else if (ce == "h")
        {
            if (QString(c).contains("class"))
                ed->setLexerCPP(true);
            else
                ed->setLexerC(true);
        }

        else if (ce == "cmake"
                 || fi.fileName() == "CMakeLists.txt"
                 || fi.fileName() == "CMakeCache.txt")
        {
            ed->setLexerCMake(true);
        }

        else if (ce == "coffee"
                 || ce == "litcoffee")
        {
            ed->setLexerCoffeeScript(true);
        }

        else if (ce == "cs")
        {
            ed->setLexerCSharp(true);
        }

        else if (ce == "css")
        {
            ed->setLexerCSS(true);
        }

        else if (ce == "d")
        {
            ed->setLexerD(true);
        }

        else if (ce == "diff")
        {
            ed->setLexerDiff(true);
        }

        else if (ce == "edifact")
        {
            ed->setLexerEDIFACT(true);
        }

        else if (ce == "f90"
                 || ce == "f95"
                 || ce == "f03"
                 || ce == "f"
                 || ce == "for")
        {
            ed->setLexerFortran(true);
        }

        else if (ce == "f77")
        {
            ed->setLexerFortran77(true);
        }

        else if (ce == "html"
                 || ce == "htm"
                 || ce == "mhtml"
                 || ce == "shtml")
        {
            ed->setLexerHTML(true);
        }

        else if (ce == "idl")
        {
            ed->setLexerIDL(true);
        }

        else if (ce == "java")
        {
            ed->setLexerJava(true);
        }

        else if (ce == "js"
                 || ce == "javascript"
                 || fi.fileName() == "node.js")
        {
            ed->setLexerJavaScript(true);
        }

        else if (ce == "json")
        {
            ed->setLexerJSON(true);
        }

        else if (ce == "lua")
        {
            ed->setLexerLua(true);
        }

        else if (ce == "make"
                 || ce == "makefile"
                 || fi.fileName().toLower() == "makefile"
                 || fi.fileName().toLower() == "make")
        {
            ed->setLexerMakefile(true);
        }

        else if (ce == "md"
                 || ce == "markdown"
                 || ce == "commonmark")
        {
            ed->setLexerMarkdown(true);
        }

        else if (ce == "mex"
                 || ce == "mat"
                 || ce == "mlx"
                 || ce == "mlapp")
        {
            ed->setLexerMatlab(true);
        }

        else if (ce == "octave")
        {
            ed->setLexerOctave(true);
        }

        else if (ce == "pas"
                 || ce == "pp")
        {
            ed->setLexerPascal(true);
        }

        else if (ce == "plx"
                 || ce == "pl"
                 || ce == "pm")
        {
            ed->setLexerPerl(true);
        }

        else if (ce == "po")
        {
            ed->setLexerPO(true);
        }

        else if (ce == "ps")
        {
            ed->setLexerPostScript(true);
        }

        else if (ce == "pov"
                 || ce == "povray")
        {
            ed->setLexerPOV(true);
        }

        else if (ce == "psl")
        {
            ed->setLexerProperties(true);
        }

        else if (ce == "py"
                 || ce == "py3"
                 || ce == "pyw"
                 || ce == "pypy"
                 || ce == "egg"
                 || ce == "egg-info"
                 || ce == "spec"
                 || ce == "pyd"
                 || ce == "ipynb")
        {
            ed->setLexerPython3(true);
        }

        else if (ce == "py2"
                 || ce == "pyo")
        {
            ed->setLexerPython(true);
        }

        else if (ce == "qss")
        {
            ed->setLexerQSS(true);
        }

        else if (ce == "rb"
                 || ce == "ruby"
                 || ce == "gem")
        {
            ed->setLexerRuby(true);
        }

        else if (ce == "spice"
                 || ce == "pspice")
        {
            ed->setLexerSpice(true);
        }

        else if (ce == "sql"
                 || ce == "sql86"
                 || ce == "sql92"
                 || ce == "sql99"
                 || ce == "sql03"
                 || ce == "sql06"
                 || ce == "sql08"
                 || ce == "sql11"
                 || ce == "sql16"
                 || ce == "sqldata")
        {
            ed->setLexerSQL(true);
        }

        else if (ce == "tcl"
                 || ce == "tbc")
        {
            ed->setLexerTCL(true);
        }

        else if (ce == "tex")
        {
            ed->setLexerTeX(true);
        }

        else if (ce == "v"
                 || ce == "vh")
        {
            ed->setLexerVerilog(true);
        }

        else if (ce == "xml"
                 || ce == "svg"
                 || ce == "svgx"
                 || ce == "plist"
                 || ce == "string"
                 || ce == "qrc"
                 || ce == "rc"
                 || ce == "ui"
                 || c.startsWith("<?xml version="))
        {
            ed->setLexerXML(true);
        }

        else if (ce == "yml")
        {
            ed->setLexerYAML(true);
        }

        int i = m_tab->addTab(ed, icns, fi.fileName());
        m_tab->setTabToolTip(i, fi.absoluteFilePath());
        m_tab->setCurrentIndex(i);
        m_tab->currentTab()->setModified(false);
        setWindowModified(m_tab->currentTab()->isModified());
    }

    else
    {
        QMessageBox msg = QMessageBox(this);
        msg.setWindowModality(Qt::WindowModal);
        msg.setWindowTitle(tr("OSError"));
        msg.setIcon(QMessageBox::Critical);
        msg.setText(tr("Sorry, the file you have selected cannot be opened."));
        msg.setInformativeText(tr("This might be caused by inconsistence file access,"
                                  "Or the disconnection of your current network "
                                  "condition. Try to contact your technical manager / "
                                  "system administrator for more information / solution. \n"
                                  "BR_STORMTEXT_0x00000094"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }

    f.close();
}

void BrStormTextMainWindow::newFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    QFileIconProvider fic;
    QIcon ficns = fic.icon(QFileIconProvider::File);

    BrStormTextEditor *ed;
    ed = new BrStormTextEditor(this);
    ed->setModified(false);

    connect(ed, &BrStormTextEditor::cursorPositionChanged,
            this, [=](){m_actionEditUndo->setEnabled(true);m_actionEditRedo->setEnabled(true);});
    connect(ed, &BrStormTextEditor::copyAvailable,
            this, [=](bool c){m_actionEditCut->setEnabled(c);m_actionEditCopy->setEnabled(c);m_actionEditDelete->setEnabled(c);});
    connect(ed, &BrStormTextEditor::modificationChanged,
            this, [=](bool c){setWindowModified(c);});

    if (m_untitled == 0)
    {
        int i = m_tab->addTab(ed, ficns, tr("Untitled"));
        m_tab->setCurrentIndex(i);
    }

    else
    {
        QString un = "Untitled ";
        QString rst = un + QString::number(m_untitled);
        int i = m_tab->addTab(ed, ficns, rst);
        m_tab->setTabToolTip(i, rst);
        m_tab->setCurrentIndex(i);
    }

    handleTabChanged(m_tab->currentIndex());

    m_untitled += 1;
}

void BrStormTextMainWindow::wNewFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextMainWindow *mw;
    mw = new BrStormTextMainWindow({}, m_app, m_untitled, false);
    mw->showMaximized();
}

void BrStormTextMainWindow::openFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextOpenDialog *dlg;
    dlg = new BrStormTextOpenDialog(m_tab, this);
    dlg->exec();

    for (BrStormTextEditor *ed : dlg->getWidgets())
    {
        ed->setModified(false);
        setWindowModified(false);

        connect(ed, &BrStormTextEditor::modificationChanged,
                this, [=](bool m){setWindowModified(m);});
    }
}

void BrStormTextMainWindow::wOpenFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextMainWindow *mw;
    mw = new BrStormTextMainWindow({}, m_app, m_untitled, true);
    mw->showMaximized();
}

bool BrStormTextMainWindow::saveFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    QFile f(m_tab->tabToolTip(m_tab->currentIndex()));

    if (!f.exists())
    {
        return saveAsFile(true);
    }

    else
    {
        if (f.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream o(&f);
            o << m_tab->currentTab()->text();
            m_tab->currentTab()->setModified(false);
        }

        f.close();

        m_tab->currentTab()->setModified(false);
        setWindowModified(false);

        return true;
    }
}

bool BrStormTextMainWindow::saveAsFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextSaveDialog *dlg;
    dlg = new BrStormTextSaveDialog(m_tab->tabText(m_tab->currentIndex()), getCurrentLexer(), m_tab, this);
    dlg->exec();

    if (QFile(dlg->currentText()).exists())
    {
        handleTabChanged(m_tab->currentIndex());
        return true;
    }

    return false;
}

void BrStormTextMainWindow::saveCopyToFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    BrStormTextSaveCopyToDialog *dlg;
    dlg = new BrStormTextSaveCopyToDialog(m_tab->tabText(m_tab->currentIndex()), getCurrentLexer(), m_tab, this);
    dlg->exec();
}

void BrStormTextMainWindow::saveAllFile(bool isChecked)
{
    if (m_tab->count() == 0)
    {
        close();

        return;
    }

    int c = m_tab->count();
    m_tab->setCurrentIndex(0);

    int item = c - 1;

    while (item >= 0)
    {
        saveFile(isChecked);

        m_tab->setCurrentIndex(item);

        item -= 1;
    }
}

int BrStormTextMainWindow::closeFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 1)
    {
        if (!m_tab->currentTab()) {close(); return 0;}

        if (m_tab->currentTab()->isModified())
        {
            int rst = saves();

            if (rst == 1)
            {
                bool s = saveFile(true);

                return (s ? 1 : -1);
            }

            else if (rst == 0)
            {
                QWidget *w = m_tab->widget(m_tab->currentIndex());
                m_tab->removeTab(m_tab->currentIndex());
                delete w;

                return 0;
            }

            else
            {
                return -1;
            }
        }

        else
        {
            QWidget *w = m_tab->widget(m_tab->currentIndex());
            m_tab->removeTab(m_tab->currentIndex());
            delete w;
        }
    }

    else if (m_tab->count() == 1)
    {
        if (m_tab->currentTab()->isModified())
        {
            int rst = saves();

            if (rst == 1)
            {
                bool s = saveFile(true);

                return (s ? 1 : -1);
            }

            else if (rst == 0)
            {
                QWidget *w = m_tab->widget(m_tab->currentIndex());
                m_tab->removeTab(m_tab->currentIndex());
                delete w;

                close();

                return 0;
            }

            else
            {
                return -1;
            }
        }

        else
        {
            QWidget *w = m_tab->widget(m_tab->currentIndex());
            m_tab->removeTab(m_tab->currentIndex());
            delete w;

            close();

            return 0;
        }
    }

    else
    {
        close();

        return 0;
    }

    return 0;
}

void BrStormTextMainWindow::closeAllFile(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() == 0)
    {
        close();

        return;
    }

    int c = m_tab->count();
    m_tab->setCurrentIndex(0);

    int item = c - 1;

    while (item >= 0)
    {
        closeFile(true);

        m_tab->setCurrentIndex(item);

        item -= 1;
    }

    if (m_tab->count() == 0)
        close();
}

void BrStormTextMainWindow::closeFileLeft(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() == 0)
    {
        close();

        return;
    }

    int c = m_tab->currentIndex();
    if (c < 0)
        return;

    int item = c - 1;

    while (item >= 0)
    {
        m_tab->setCurrentIndex(item);

        closeFile(true);

        item -= 1;
    }
}

void BrStormTextMainWindow::closeFileRight(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() == 0)
    {
        close();

        return;
    }

    int c = m_tab->currentIndex();
    if (c < 0)
        return;

    int item = m_tab->count() - 1;

    while (item > c)
    {
        m_tab->setCurrentIndex(item);

        closeFile(true);

        item -= 1;
    }
}

void BrStormTextMainWindow::closeFileUnchanged(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() == 0)
    {
        close();

        return;
    }

    int c = m_tab->currentIndex();
    if (c < 0)
        return;

    int item = c - 1;
    m_unchanged = true;

    while (item >= 0)
    {
        m_tab->setCurrentIndex(item);

        if (!(m_tab->currentTab()->isWindowModified()))
            closeFile(true);

        item -= 1;
    }

    m_unchanged = false;
}

void BrStormTextMainWindow::editUndo(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->undo();

    m_actionEditUndo->setEnabled(m_tab->currentTab()->isUndoAvailable());
    m_actionEditRedo->setEnabled(m_tab->currentTab()->isRedoAvailable());
}

void BrStormTextMainWindow::editRedo(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->redo();

    m_actionEditUndo->setEnabled(m_tab->currentTab()->isUndoAvailable());
    m_actionEditRedo->setEnabled(m_tab->currentTab()->isRedoAvailable());
}

void BrStormTextMainWindow::editCut(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->cut();

    m_actionEditCut->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditCopy->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditDelete->setEnabled(m_tab->currentTab()->hasSelectedText());
}

void BrStormTextMainWindow::editCopy(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->copy();

    m_actionEditCut->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditCopy->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditDelete->setEnabled(m_tab->currentTab()->hasSelectedText());
}

void BrStormTextMainWindow::editPaste(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->paste();
}

void BrStormTextMainWindow::editSelectAll(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->selectAll();
}

void BrStormTextMainWindow::editDelete(bool isChecked)
{
    Q_UNUSED(isChecked)

    if (m_tab->count() > 0) m_tab->currentTab()->removeSelectedText();

    m_actionEditCut->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditCopy->setEnabled(m_tab->currentTab()->hasSelectedText());
    m_actionEditDelete->setEnabled(m_tab->currentTab()->hasSelectedText());
}

void BrStormTextMainWindow::setShowEol(bool isChecked)
{
    if (m_tab->count() > 0) m_tab->currentTab()->setEolVisibility(isChecked);
}

void BrStormTextMainWindow::setShowWhitespace(bool isChecked)
{
    if (m_tab->count() > 0) m_tab->currentTab()->setWhitespaceVisibility(isChecked
                                                         ? QsciScintilla::WsVisible
                                                         : QsciScintilla::WsInvisible);
}

/**
 * @todo: Add more languages
 */

void BrStormTextMainWindow::setLexerNone(bool isChecked)
{
    Q_UNUSED(isChecked)

    m_tab->currentTab()->setLexerNone();
}

void BrStormTextMainWindow::setLexerAVS(bool isChecked)
{
    m_tab->currentTab()->setLexerAVS(isChecked);
}

void BrStormTextMainWindow::setLexerBash(bool isChecked)
{
    m_tab->currentTab()->setLexerBash(isChecked);
}

void BrStormTextMainWindow::setLexerBatch(bool isChecked)
{
    m_tab->currentTab()->setLexerBatch(isChecked);
}

void BrStormTextMainWindow::setLexerC(bool isChecked)
{
    m_tab->currentTab()->setLexerC(isChecked);
}

void BrStormTextMainWindow::setLexerCMake(bool isChecked)
{
    m_tab->currentTab()->setLexerCMake(isChecked);
}

void BrStormTextMainWindow::setLexerCPP(bool isChecked)
{
    m_tab->currentTab()->setLexerCPP(isChecked);
}

void BrStormTextMainWindow::setLexerCSharp(bool isChecked)
{
    m_tab->currentTab()->setLexerCSharp(isChecked);
}

void BrStormTextMainWindow::setLexerCoffeeScript(bool isChecked)
{
    m_tab->currentTab()->setLexerCoffeeScript(isChecked);
}

void BrStormTextMainWindow::setLexerCSS(bool isChecked)
{
    m_tab->currentTab()->setLexerCSS(isChecked);
}

void BrStormTextMainWindow::setLexerD(bool isChecked)
{
    m_tab->currentTab()->setLexerD(isChecked);
}

void BrStormTextMainWindow::setLexerDiff(bool isChecked)
{
    m_tab->currentTab()->setLexerDiff(isChecked);
}

void BrStormTextMainWindow::setLexerEDIFACT(bool isChecked)
{
    m_tab->currentTab()->setLexerEDIFACT(isChecked);
}

void BrStormTextMainWindow::setLexerFortran(bool isChecked)
{
    m_tab->currentTab()->setLexerFortran(isChecked);
}

void BrStormTextMainWindow::setLexerFortran77(bool isChecked)
{
    m_tab->currentTab()->setLexerFortran77(isChecked);
}

void BrStormTextMainWindow::setLexerHTML(bool isChecked)
{
    m_tab->currentTab()->setLexerHTML(isChecked);
}

void BrStormTextMainWindow::setLexerIDL(bool isChecked)
{
    m_tab->currentTab()->setLexerIDL(isChecked);
}

void BrStormTextMainWindow::setLexerJava(bool isChecked)
{
    m_tab->currentTab()->setLexerJava(isChecked);
}

void BrStormTextMainWindow::setLexerJavaScript(bool isChecked)
{
    m_tab->currentTab()->setLexerJavaScript(isChecked);
}

void BrStormTextMainWindow::setLexerJSON(bool isChecked)
{
    m_tab->currentTab()->setLexerJSON(isChecked);
}

void BrStormTextMainWindow::setLexerLua(bool isChecked)
{
    m_tab->currentTab()->setLexerLua(isChecked);
}

void BrStormTextMainWindow::setLexerMakefile(bool isChecked)
{
    m_tab->currentTab()->setLexerMakefile(isChecked);
}

void BrStormTextMainWindow::setLexerMarkdown(bool isChecked)
{
    m_tab->currentTab()->setLexerMarkdown(isChecked);
}

void BrStormTextMainWindow::setLexerMatlab(bool isChecked)
{
    m_tab->currentTab()->setLexerMatlab(isChecked);
}

void BrStormTextMainWindow::setLexerOctave(bool isChecked)
{
    m_tab->currentTab()->setLexerOctave(isChecked);
}

void BrStormTextMainWindow::setLexerPascal(bool isChecked)
{
    m_tab->currentTab()->setLexerPascal(isChecked);
}

void BrStormTextMainWindow::setLexerPerl(bool isChecked)
{
    m_tab->currentTab()->setLexerPerl(isChecked);
}

void BrStormTextMainWindow::setLexerPO(bool isChecked)
{
    m_tab->currentTab()->setLexerPO(isChecked);
}

void BrStormTextMainWindow::setLexerPostScript(bool isChecked)
{
    m_tab->currentTab()->setLexerPostScript(isChecked);
}

void BrStormTextMainWindow::setLexerPOV(bool isChecked)
{
    m_tab->currentTab()->setLexerPOV(isChecked);
}

void BrStormTextMainWindow::setLexerProperties(bool isChecked)
{
    m_tab->currentTab()->setLexerProperties(isChecked);
}

void BrStormTextMainWindow::setLexerPython(bool isChecked)
{
    m_tab->currentTab()->setLexerPython(isChecked);
}

void BrStormTextMainWindow::setLexerPython3(bool isChecked)
{
    m_tab->currentTab()->setLexerPython3(isChecked);
}

void BrStormTextMainWindow::setLexerQSS(bool isChecked)
{
    m_tab->currentTab()->setLexerQSS(isChecked);
}

void BrStormTextMainWindow::setLexerRuby(bool isChecked)
{
    m_tab->currentTab()->setLexerRuby(isChecked);
}

void BrStormTextMainWindow::setLexerSpice(bool isChecked)
{
    m_tab->currentTab()->setLexerSpice(isChecked);
}

void BrStormTextMainWindow::setLexerSQL(bool isChecked)
{
    m_tab->currentTab()->setLexerSQL(isChecked);
}

void BrStormTextMainWindow::setLexerTCL(bool isChecked)
{
    m_tab->currentTab()->setLexerTCL(isChecked);
}

void BrStormTextMainWindow::setLexerTeX(bool isChecked)
{
    m_tab->currentTab()->setLexerTeX(isChecked);
}

void BrStormTextMainWindow::setLexerVerilog(bool isChecked)
{
    m_tab->currentTab()->setLexerVerilog(isChecked);
}

void BrStormTextMainWindow::setLexerVHDL(bool isChecked)
{
    m_tab->currentTab()->setLexerVHDL(isChecked);
}

void BrStormTextMainWindow::setLexerXML(bool isChecked)
{
    m_tab->currentTab()->setLexerXML(isChecked);
}

void BrStormTextMainWindow::setLexerYAML(bool isChecked)
{
    m_tab->currentTab()->setLexerYAML(isChecked);
}

void BrStormTextMainWindow::setEolUnix(bool isChecked)
{
    Q_UNUSED(isChecked)

    m_tab->currentTab()->setEolMode(QsciScintilla::EolUnix);
}

void BrStormTextMainWindow::setEolMac(bool isChecked)
{
    Q_UNUSED(isChecked)

    m_tab->currentTab()->setEolMode(QsciScintilla::EolMac);
}

void BrStormTextMainWindow::setEolWindows(bool isChecked)
{
    Q_UNUSED(isChecked)

    m_tab->currentTab()->setEolMode(QsciScintilla::EolWindows);
}
