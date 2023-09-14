/**
 * @brief BrStormTextMainWindow.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 27 May 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTMAINWINDOW_HPP
#define BRSTORMTEXTMAINWINDOW_HPP


#include <QAction>
#include <QActionGroup>
#include <QDockWidget>
#include <QFileSystemModel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolButton>
#include <QTreeView>

#include "BrStormTextTab.hpp"
#include "BrStormTextStatusBar.hpp"
#include "BrStormTextDialogs/BrStormTextAboutApplicationDialog.hpp"
#include "BrStormTextDialogs/BrStormTextAboutDialog.hpp"
#include "BrStormTextDialogs/BrStormTextGotoDialog.hpp"
#include "BrStormTextFileBrowsers/BrStormTextFileDock.hpp"
#include "BrStormTextFileBrowsers/BrStormTextFileModel.hpp"
#include "BrStormTextFileBrowsers/BrStormTextFileTreeview.hpp"
#include "BrStormTextFindDock.hpp"


class BrStormTextApplication;


class BrStormTextMainWindow : public QMainWindow
{
    Q_OBJECT

public:

    BrStormTextMainWindow(QList<QString> argv, BrStormTextApplication *app, int u = 0, bool o = false, QWidget *parent = nullptr);

public:

    QString getCurrentLexer();

public:

    void closeEvent(QCloseEvent *event);

public slots:

    void openThroughArgs(QString path);

private:

    void initUi();
    void initMenus();
    void initFileMenu();
    void initEditMenu();
    void initViewMenu();
    void initFormatMenu();
    void initToolsMenu();
    void initHelpMenu();
    void initActionGroups();
    void initTabs();
    void initStatusBar();
    void initFileBrowser();
    void initFindDock();
    void initSignals();

private:

    int saves();

/**
 * @todo: Add more languages
 */

private slots:

    void handleTabChanged(int idx);
    void handleTabCloseRequest(int idx);

    void handleFileBrowserDoubleClicked(QModelIndex idx);

    void newFile(bool);
    void wNewFile(bool);
    void openFile(bool);
    void wOpenFile(bool);
    bool saveFile(bool);
    bool saveAsFile(bool);
    void saveCopyToFile(bool);
    void saveAllFile(bool);
    int closeFile(bool);
    void closeAllFile(bool);
    void closeFileLeft(bool);
    void closeFileRight(bool);
    void closeFileUnchanged(bool);

    void editUndo(bool);
    void editRedo(bool);
    void editCut(bool);
    void editCopy(bool);
    void editPaste(bool);
    void editDelete(bool);
    void editSelectAll(bool);

    void setShowEol(bool isChecked);
    void setShowWhitespace(bool isChecked);

    void setLexerNone(bool);
    void setLexerAVS(bool);
    void setLexerBash(bool);
    void setLexerBatch(bool);
    void setLexerCMake(bool);
    void setLexerC(bool);
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

    void setEolUnix(bool);
    void setEolMac(bool);
    void setEolWindows(bool);

private:

    QMenuBar *m_menuBar;
        QMenu *m_menuFile;
            QAction *m_actionFileNew;
            QAction *m_actionFileNewWindow;
            QAction *m_actionFileOpen;
            QAction *m_actionFileOpenWindow;
            QAction *m_actionFileSave;
            QAction *m_actionFileSaveAs;
            QAction *m_actionFileSaveCopyTo;
            QAction *m_actionFileSaveAll;
            QAction *m_actionFileClose;
            QAction *m_actionFileCloseAll;
            QAction *m_actionFileCloseLeft;
            QAction *m_actionFileCloseRight;
            QAction *m_actionFileCloseUnchanged;
        QMenu *m_menuEdit;
            QAction *m_actionEditUndo;
            QAction *m_actionEditRedo;
            QAction *m_actionEditCut;
            QAction *m_actionEditCopy;
            QAction *m_actionEditPaste;
            QAction *m_actionEditDelete;
            QAction *m_actionEditSelectAll;
            QMenu *m_menuEditIndentation;
                QAction *m_actionEditIndentationIndent;
                QAction *m_actionEditIndentationDedent;
            QMenu *m_menuEditFind;
                QAction *m_actionEditFindFind;
                QAction *m_actionEditFindNext;
                QAction *m_actionEditFindPrevious;
                QAction *m_actionEditFindGoto;
            QMenu *m_menuEditReplace;
                QAction *m_actionEditReplaceFindNext;
                QAction *m_actionEditReplaceFindPrevious;
                QAction *m_actionEditReplaceAll;
        QMenu *m_menuView;
            #ifndef Q_OS_DARWIN
            QAction *m_actionViewFullscreen;
            #endif
            QMenu *m_menuViewSymbols;
                QAction *m_actionViewSymbolsWhitespace;
                QAction *m_actionViewSymbolsEol;
            QMenu *m_menuViewZoom;
                QAction *m_actionViewZoomIn;
                QAction *m_actionViewZoomOut;
                QAction *m_actionViewZoomDefault;
            QMenu *m_menuViewTab;
                QAction *m_actionViewTab1;
                QAction *m_actionViewTab2;
                QAction *m_actionViewTab3;
                QAction *m_actionViewTab4;
                QAction *m_actionViewTab5;
                QAction *m_actionViewTab6;
                QAction *m_actionViewTab7;
                QAction *m_actionViewTab8;
                QAction *m_actionViewTab9;
                QAction *m_actionViewTab10;
                QAction *m_actionViewTabLast;
                QAction *m_actionViewTabPrevious;
                QAction *m_actionViewTabNext;
            QMenu *m_menuViewMarkers;
                QAction *m_actionViewMarkersEnable;
                QAction *m_actionViewMarkersNew;
                QAction *m_actionViewMarkersDelete;
                QAction *m_actionViewMarkersDeleteAll;
            QMenu *m_menuViewWrapMode;
                QAction *m_actionViewWrapNone;
                QAction *m_actionViewWrapWord;
                QAction *m_actionViewWrapCharacter;
                QAction *m_actionViewWrapWhitespace;
            QMenu *m_menuViewWrapVisualFlag;
                QAction *m_actionViewWrapFlagNone;
                QAction *m_actionViewWrapFlagByText;
                QAction *m_actionViewWrapFlagByBorder;
                QAction *m_actionViewWrapFlagInMargin;
            QMenu *m_menuViewFold;
                QAction *m_actionViewFoldAll;
                QAction *m_actionViewFoldAllChildren;
                QAction *m_actionViewFoldCurrentLine;
            QMenu *m_menuViewMove;
                QMenu *m_menuViewMoveLine;
                    QAction *m_actionViewMoveLineDown;
                    QAction *m_actionViewMoveLineDownExtend;
                    QAction *m_actionViewMoveLineDownRectExtend;
                    QAction *m_actionViewMoveLineScrollDown;
                    QAction *m_actionViewMoveLineUp;
                    QAction *m_actionViewMoveLineUpExtend;
                    QAction *m_actionViewMoveLineUpRectExtend;
                    QAction *m_actionViewMoveLineScrollUp;
                    QAction *m_actionViewMoveLineEnd;
                    QAction *m_actionViewMoveLineEndExtend;
                    QAction *m_actionViewMoveLineEndRectExtend;
                    QAction *m_actionViewMoveLineEndDisplay;
                    QAction *m_actionViewMoveLineEndDisplayExtend;
                    QAction *m_actionViewMoveLineEndWrap;
                    QAction *m_actionViewMoveLineEndWrapExtend;
                    QAction *m_actionViewMoveLineDelete;
                    QAction *m_actionViewMoveLineCut;
                    QAction *m_actionViewMoveLineCopy;
                    QAction *m_actionViewMoveLineTranspose;
                    QAction *m_actionViewMoveLineDuplicate;
                QMenu *m_menuViewMoveScrollTo;
                    QAction *m_actionViewMoveScrollToStart;
                    QAction *m_actionViewMoveScrollToEnd;
                    QAction *m_actionViewMoveVerticalCenterCaret;
                QMenu *m_menuViewMoveParagraph;
                    QAction *m_actionViewMoveParaDown;
                    QAction *m_actionViewMoveParaDownExtend;
                    QAction *m_actionViewMoveParaUp;
                    QAction *m_actionViewMoveParaUpExtend;
                QMenu *m_menuViewMoveCharacter;
                    QAction *m_actionViewMoveCharLeft;
                    QAction *m_actionViewMoveCharLeftExtend;
                    QAction *m_actionViewMoveCharLeftRectExtend;
                    QAction *m_actionViewMoveCharRight;
                    QAction *m_actionViewMoveCharRightExtend;
                    QAction *m_actionViewMoveCharRightRectExtend;
                QMenu *m_menuViewMoveWord;
                    QAction *m_actionViewMoveWordLeft;
                    QAction *m_actionViewMoveWordLeftExtend;
                    QAction *m_actionViewMoveWordRight;
                    QAction *m_actionViewMoveWordRightExtend;
                    QAction *m_actionViewMoveWordLeftEnd;
                    QAction *m_actionViewMoveWordLeftEndExtend;
                    QAction *m_actionViewMoveWordRightEnd;
                    QAction *m_actionViewMoveWordRightEndExtend;
                    QAction *m_actionViewMoveWordPartLeft;
                    QAction *m_actionViewMoveWordPartLeftExtend;
                    QAction *m_actionViewMoveWordPartRight;
                    QAction *m_actionViewMoveWordPartRightExtend;
                QMenu *m_menuViewMoveHome;
                    QAction *m_actionViewMoveHome;
                    QAction *m_actionViewMoveHomeExtend;
                    QAction *m_actionViewMoveHomeRectExtend;
                    QAction *m_actionViewMoveHomeDisplay;
                    QAction *m_actionViewMoveHomeDisplayExtend;
                    QAction *m_actionViewMoveHomeWrap;
                    QAction *m_actionViewMoveHomeWrapExtend;
                    QAction *m_actionViewMoveVCHome;
                    QAction *m_actionViewMoveVCHomeExtend;
                    QAction *m_actionViewMoveVCHomeRectExtend;
                    QAction *m_actionViewMoveVCHomeWrap;
                    QAction *m_actionViewMoveVCHomeWrapExtend;
                QMenu *m_menuViewMoveDocument;
                    QAction *m_actionViewMoveDocumentStart;
                    QAction *m_actionViewMoveDocumentStartExtend;
                    QAction *m_actionViewMoveDocumentEnd;
                    QAction *m_actionViewMoveDocumentEndExtend;
                QMenu *m_menuViewMovePage;
                    QAction *m_actionViewMovePageUp;
                    QAction *m_actionViewMovePageUpExtend;
                    QAction *m_actionViewMovePageUpRectExtend;
                    QAction *m_actionViewMovePageDown;
                    QAction *m_actionViewMovePageDownExtend;
                    QAction *m_actionViewMovePageDownRectExtend;
                    QAction *m_actionViewMoveStutteredPageUp;
                    QAction *m_actionViewMoveStutteredPageUpExtend;
                    QAction *m_actionViewMoveStutteredPageDown;
                    QAction *m_actionViewMoveStutteredPageDownExtend;
                QMenu *m_menuViewMoveDelete;
                    QAction *m_actionViewMoveDeleteBack;
                    QAction *m_actionViewMoveDeleteBackNotLine;
                    QAction *m_actionViewMoveDeleteWordLeft;
                    QAction *m_actionViewMoveDeleteWordRight;
                    QAction *m_actionViewMoveDeleteWordRightEnd;
                    QAction *m_actionViewMoveDeleteLineLeft;
                    QAction *m_actionViewMoveDeleteLineRight;
                QMenu *m_menuViewMoveSelection;
                    QAction *m_actionViewMoveMoveSelectedLinesUp;
                    QAction *m_actionViewMoveMoveSelectedLinesDown;
                    QAction *m_actionViewMoveSelectionDuplicate;
            QAction *m_actionViewVirtualSelection;
            QAction *m_actionViewShowFileBrowser;
            QAction *m_actionViewShowIndentationGuides;
            QAction *m_actionViewShowCaretBackground;
            QAction *m_actionViewShowBraceMatching;
            QAction *m_actionViewShowAutocomplete;
            QAction *m_actionViewShowLineNumbers;
            QAction *m_actionViewReadOnly;
        QMenu *m_menuFormat;
            QMenu *m_menuFormatLanguage;
                QAction *m_actionFormatLanguageNone;
                QMenu *m_menuFormatLanguageA;
                    QAction *m_actionFormatLanguageAVS;
                QMenu *m_menuFormatLanguageB;
                    QAction *m_actionFormatLanguageBash;
                    QAction *m_actionFormatLanguageBatch;
                QMenu *m_menuFormatLanguageC;
                    QAction *m_actionFormatLanguageC;
                    QAction *m_actionFormatLanguageCMake;
                    QAction *m_actionFormatLanguageCoffeeScript;
                    QAction *m_actionFormatLanguageCPP;
                    QAction *m_actionFormatLanguageCSharp;
                    QAction *m_actionFormatLanguageCSS;
                QMenu *m_menuFormatLanguageD;
                    QAction *m_actionFormatLanguageD;
                    QAction *m_actionFormatLanguageDiff;
                QMenu *m_menuFormatLanguageE;
                    QAction *m_actionFormatLanguageEDIFACT;
                QMenu *m_menuFormatLanguageF;
                    QAction *m_actionFormatLanguageFortran;
                    QAction *m_actionFormatLanguageFortran77;
                QMenu *m_menuFormatLanguageH;
                    QAction *m_actionFormatLanguageHTML;
                QMenu *m_menuFormatLanguageI;
                    QAction *m_actionFormatLanguageIDL;
                QMenu *m_menuFormatLanguageJ;
                    QAction *m_actionFormatLanguageJava;
                    QAction *m_actionFormatLanguageJavaScript;
                    QAction *m_actionFormatLanguageJSON;
                QMenu *m_menuFormatLanguageL;
                    QAction *m_actionFormatLanguageLua;
                QMenu *m_menuFormatLanguageM;
                    QAction *m_actionFormatLanguageMakefile;
                    QAction *m_actionFormatLanguageMarkdown;
                    QAction *m_actionFormatLanguageMatlab;
                QMenu *m_menuFormatLanguageO;
                    QAction *m_actionFormatLanguageOctave;
                QMenu *m_menuFormatLanguageP;
                    QAction *m_actionFormatLanguagePascal;
                    QAction *m_actionFormatLanguagePerl;
                    QAction *m_actionFormatLanguagePO;
                    QAction *m_actionFormatLanguagePostScript;
                    QAction *m_actionFormatLanguagePOV;
                    QAction *m_actionFormatLanguageProperties;
                    QAction *m_actionFormatLanguagePython;
                    QAction *m_actionFormatLanguagePython3;
                QMenu *m_menuFormatLanguageQ;
                    QAction *m_actionFormatLanguageQSS;
                QMenu *m_menuFormatLanguageR;
                    QAction *m_actionFormatLanguageRuby;
                QMenu *m_menuFormatLanguageS;
                    QAction *m_actionFormatLanguageSpice;
                    QAction *m_actionFormatLanguageSQL;
                QMenu *m_menuFormatLanguageT;
                    QAction *m_actionFormatLanguageTCL;
                    QAction *m_actionFormatLanguageTeX;
                QMenu *m_menuFormatLanguageV;
                    QAction *m_actionFormatLanguageVerilog;
                    QAction *m_actionFormatLanguageVHDL;
                QMenu *m_menuFormatLanguageX;
                    QAction *m_actionFormatLanguageXML;
                QMenu *m_menuFormatLanguageY;
                    QAction *m_actionFormatLanguageYAML;
            QMenu *m_menuFormatEol;
                QAction *m_actionFormatEolUnix;
                QAction *m_actionFormatEolMac;
                QAction *m_actionFormatEolWindows;
            QAction *m_actionFormatIndentationUseTab;
        QMenu *m_menuTools;
            QMenu *m_menuToolsAutoCompletion;
                QAction *m_actionToolsAutoCompletionCaseSensitivity;
                QAction *m_actionToolsAutoCompletionReplaceWord;
                QAction *m_actionToolsAutoCompletionShowSingle;
                QMenu *m_menuToolsAutoCompletionSource;
                    QAction *m_actionToolsAutoCompletionSourceAll;
                    QAction *m_actionToolsAutoCompletionSourceDocument;
                    QAction *m_actionToolsAutoCompletionSourceAPIs;
                QMenu *m_menuToolsBraceMatching;
                    QAction *m_actionToolsStrictBraceMatch;
                    QAction *m_actionToolsSloppyBraceMatch;
                QAction *m_actionToolsAutoIndent;
        QMenu *m_menuHelp;
            QAction *m_actionAbout;
            QAction *m_actionHelpAboutApp;

    QActionGroup *m_actionGroupViewWrapMode;
    QActionGroup *m_actionGroupViewWrapVisualFlag;
    QActionGroup *m_actionGroupFormatLanguage;
    QActionGroup *m_actionGroupFormatEol;
    QActionGroup *m_actionGroupToolsAutoCompletionSource;
    QActionGroup *m_actionGroupToolsBraceMatching;

    BrStormTextStatusBar *m_sb;
    QToolButton *m_lexerButton;
    BrStormTextFileDock *m_fb;
    BrStormTextFileModel *m_fbm;
    BrStormTextFileTreeview *m_fbw;
    BrStormTextAboutApplicationDialog *m_aAppD;
    BrStormTextAboutDialog *m_aD;
    BrStormTextGotoDialog *m_gD;
    BrStormTextFindDock *m_findDock;
    BrStormTextTab *m_tab;

private:

    bool m_unchanged = false;
    int m_untitled;
    BrStormTextApplication *m_app;
};

#endif // BRSTORMTEXTMAINWINDOW_HPP

