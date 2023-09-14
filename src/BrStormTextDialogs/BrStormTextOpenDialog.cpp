/**
 * @brief BrStormTextLexerOpenDialog.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextOpenDialog.hpp"
#include "../BrStormTextTab.hpp"
#include "../BrStormTextEditor.hpp"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileIconProvider>
#include <QFileInfo>
#include <QIcon>
#include <QMessageBox>
#include <QStandardPaths>
#include <Qsci/qscilexer.h>


BrStormTextOpenDialog::BrStormTextOpenDialog(BrStormTextTab *tab, QWidget *parent)
    : QFileDialog(parent)
{
    m_tab = tab;
    m_w = {};

    /**
     * @todo: Add more languages
     */

    m_filters = {
        "All files (*.*)",
        "Normal text file (*.txt)",
        "AVS source file (*.avs)",
        "Bash shell commands (*.sh; *.bash)",
        "Bash shell (*.sh)",
        "Bash commands (*.bash)",
        "Batch commands (*.bat; *.cmd; *.btm)",
        "Typical Windows Batch command (*.bat)",
        "Windows NT and OS/2 Batch command (*.cmd)",
        "Old-styled Batch command (*.btm)",
        "CMake sources (CMakeLists.txt; CMakeCache.txt; *.cmake)",
        "CMake List (CMakeLists.txt)",
        "CMake Cache (CMakeCache.txt)",
        "CMake source (*.cmake)",
        "CoffeeScript sources (*.coffee; *.litcoffee)",
        "CoffeeScript source (*.coffee)",
        "CoffeeScript literal programming source (*.litcoffee)",
        "C files (*.c; *.h)",
        "C source (*.c)",
        "C header (*.h)",
        "C++ files (*.cpp; *.cxx; *.cc; *.ii; *.h; *.hpp; *.hxx)",
        "C++ sources (*.cpp; *.cxx; *cc; *.ii)",
        "C++ headers (*.h; *.hpp; *.hxx)",
        "C++ ARM-compiler source (*.ii)",
        "C++ source (*.cpp)",
        "C++ new source (*.cxx)",
        "C++ old C-like wrapper header (*.h)",
        "C++ header (*.hpp)",
        "C++ new header (*.hxx)",
        "C# source (*.cs)",
        "CSS source (*.css)",
        "D source (*.d)",
        "Diff file (*.diff)",
        "EDIFACT file (*.edifact)",
        "Fortran sources (*.f90; *.f95; *.f03; *.f; *.for)",
        "Fortran 90 source (*.f90)",
        "Fortran 95 source (*.f95)",
        "Fortran 2003 source (*.f03)",
        "Fortran source (*.f)",
        "Fortran new source (*.for)",
        "Fortran 77 source (*.f77)",
        "HTML sources (*.html; *.htm; *.mhtml; *.shtml)",
        "HTML file (*.html)",
        "HTML old file (*.htm)",
        "HTML bundled (*.mhtml)",
        "HTML source (*.shtml)",
        "IDL file (*.idl)",
        "Java source (*.java)",
        "JavaScript sources (*.js; node.js; *.javascript)",
        "JavaScript web-based sources (*.js; *.javascript)",
        "Node.js index file (node.js)",
        "JSON file (*.json)",
        "Lua source (*.lua)",
        "Makefile files (Makefile; Make; *.make; *.makefile)",
        "Unix Makefile files (Makefile; Make)",
        "Windows Makefile files (*.make; *.makefile)",
        "Markdown files (*.md; *.markdown; *.commonmark)",
        "GitHub dialect markdown file (*.md)",
        "CommonMark dialect markdown files (*.markdown; *.commonmark)",
        "Matlab sources (*.mex; *.mat; *.mlx; *.mlapp)",
        "Matlab source (*.mex; *.mat)",
        "Matlab app (*.mlx; *.mlapp)",
        "Octave source (*.octave)",
        "Pascal sources (*.pas; *.pp)",
        "Pascal old source (*.pp)",
        "Pascal source (*.pas)",
        "Perl sources (*.plx; *.pl; *.pm)",
        "Perl source (*.pl)",
        "GNU/gettext project-object language file (*.po)",
        "PostScript source (*.ps)",
        "POV files (*.pov; *.povray)",
        "POV sources (*.pov)",
        "POV-Ray sources (*.povray)",
        "Property Specification Language (*.psl)",
        "Python files (*.py; *.py2; *.py3; *.pyw; *.pyo; *.pypy; "
                       "*.egg; *.egg-info; *.spec; *.pyd; *.ipynb)",
        "Python sources (*.py; *.py2; *.py3; *.pyw; *.pypy; *.ipynb)",
        "Python script (*.py)",
        "Python 2 specified script (*.py2)",
        "Python 3 specified script (*.py3)",
        "Python no-console script (*.pyw)",
        "Python object file (*.pyo)",
        "Python PyPy interpreter script (*.pypy)",
        "Python pip installation file (*.egg)",
        "Python pip installation information file (*.egg-info)",
        "Python PyInstaller specificational file (*.spec)",
        "Python binary module file (*.pyd)",
        "Python-Jupyter notebook file (*.ipynb)",
        "Qt StyleSheet (*.qss)",
        "Ruby files (*.rb; *.ruby; *.gem)",
        "Ruby script (*.rb)",
        "Ruby file (*.ruby)",
        "Ruby gem installation file (*.gem)",
        "Spice sources (*.spice; *.pspice)",
        "Spice source (*.spice)",
        "Spice-p source (*.pspice)",
        "SQL files (*.sql; *.sql86; *.sql92; *.sql99; *.sql03; *.sql06; "
                   "*.sql08; *.sql11; *.sql16; *.sqldata)",
        "SQL script (*.sql)",
        "SQL 86 script (*.sql86)",
        "SQL 92 script (*.sql92)",
        "SQL 1999 script (*.sql99)",
        "SQL 2003 script (*.sql03)",
        "SQL 2006 script (*.sql06)",
        "SQL 2008 script (*.sql08)",
        "SQL 2011 script (*.sql11)",
        "SQL 2016 script (*.sql16)",
        "SQL database management kit file (*.sqldata)",
        "TCL files (*.tcl; *.tbc)",
        "TCL source (*.tcl)",
        "TCL compiler kit file (*.tbc)",
        "TeX file (*.tex)",
        "Verilog files (*.v; *.vh)",
        "Verilog source (*.v)",
        "Verilog header (*.vh)",
        "VHDL file (*.vhd)",
        "XML files (*.xml; *.svg; *.svgx; *.plist; *.string; *.qrc; *.rc; *.ui)",
        "XML file (*.xml)",
        "SVG graphics file - XML notational (*.svg)",
        "SVG new graphics file (*.svgx)",
        "Apple macOS information file (*.plist)",
        "XML-notational dictational string file (*.string)",
        "Qt resources file (*.qrc)",
        "Resources file (*.rc)",
        "Qt Creator UI design file (*.ui)",
        "YAML file (*.yml)"
    };

    setAcceptMode(QFileDialog::AcceptOpen);
    setDirectory(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    setFileMode(QFileDialog::ExistingFiles);
    setNameFilter(m_filters.join(";;"));
    setWindowModality(Qt::WindowModal);
    selectNameFilter("All files (*.*)");

    connect(this, SIGNAL(accepted()),
            this, SLOT(openSelectedFiles()));
}

void BrStormTextOpenDialog::openSelectedFiles()
{
    for (const QString &path : selectedFiles())
    {
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
            continue;
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

            if (cfnit) continue;

            BrStormTextEditor *ed;
            ed = new BrStormTextEditor();
            ed->setText(c);

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
            qobject_cast<QWidget*>(parent())->setWindowModified(m_tab->currentTab()->isModified());

            m_w.push_back(ed);
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
            continue;
        }

        f.close();
    }
}

QList<BrStormTextEditor*> BrStormTextOpenDialog::getWidgets()
{
    return m_w;
}
