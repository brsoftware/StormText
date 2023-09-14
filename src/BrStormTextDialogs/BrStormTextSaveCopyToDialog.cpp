/**
 * @brief BrStormTextLexerSaveCopyToDialog.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 27 2023
 *
 * See the project QMake file for details.
 */


#include "../BrStormTextTab.hpp"
#include "BrStormTextSaveCopyToDialog.hpp"

#include <QFile>
#include <QTextStream>
#include <Qsci/qscilexer.h>
#include <QStandardPaths>
#include <QDebug>


BrStormTextSaveCopyToDialog::BrStormTextSaveCopyToDialog(QString fileName, QString currentLexer, BrStormTextTab *tab, QWidget *parent)
    : QFileDialog(parent)
{
    m_tab = tab;
    m_curLex = currentLexer;

    /**
     * @todo: Add more languages
     */

    m_filters = {
        "Any files (*.*)",
        "Normal text file (*.txt)",
        "AVS source file (*.avs)",
        "Bash shell (*.sh)",
        "Bash commands (*.bash)",
        "Typical Windows Batch command (*.bat)",
        "Windows NT and OS/2 Batch command (*.cmd)",
        "Old-styled Batch command (*.btm)",
        "CMake source (*.cmake)",
        "CoffeeScript source (*.coffee)",
        "CoffeeScript literal programming source (*.litcoffee)",
        "C source (*.c)",
        "C header (*.h)",
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
        "Fortran 90 source (*.f90)",
        "Fortran 95 source (*.f95)",
        "Fortran 2003 source (*.f03)",
        "Fortran source (*.f)",
        "Fortran new source (*.for)",
        "Fortran 77 source (*.f77)",
        "HTML file (*.html)",
        "HTML old file (*.htm)",
        "HTML bundled (*.mhtml)",
        "HTML source (*.shtml)",
        "IDL file (*.idl)",
        "Java source (*.java)",
        "JavaScript web-based sources (*.js)",
        "JavaScript files (*.javascript)",
        "Node.js index file (node.js)",
        "JSON file (*.json)",
        "Lua source (*.lua)",
        "Unix Makefile file (Makefile)",
        "Unix Make file (make)",
        "Windows Makefile files (*.make; *.makefile)",
        "GitHub dialect markdown file (*.md)",
        "Markdown file (*.markdown)",
        "CommonMark dialect markdown files (*.commonmark)",
        "Matlab source (*.mat)",
        "Matlab mex source (*.mex)",
        "Matlab mlx app (*.mlx)",
        "Matlab app (*.mlapp)",
        "Octave source (*.octave)",
        "Pascal old source (*.pp)",
        "Pascal source (*.pas)",
        "Perl source (*.pl)",
        "GNU/gettext project-object language file (*.po)",
        "PostScript source (*.ps)",
        "POV sources (*.pov)",
        "POV-Ray sources (*.povray)",
        "Property Specification Language (*.psl)",
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
        "Qt StyleSheet file (*.qss)",
        "Ruby script (*.rb)",
        "Ruby file (*.ruby)",
        "Ruby gem installation file (*.gem)",
        "Spice source (*.spice)",
        "Spice-p source (*.pspice)",
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
        "TCL source (*.tcl)",
        "TCL compiler kit file (*.tbc)",
        "TeX file (*.tex)",
        "Verilog source (*.v)",
        "Verilog header (*.vh)",
        "VHDL file (*.vhd)",
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

    setAcceptMode(QFileDialog::AcceptSave);
    setDirectory(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0));
    setFileMode(QFileDialog::ExistingFiles);
    setNameFilter(m_filters.join(";;"));
    setWindowModality(Qt::WindowModal);
    selectFile(fileName);

    /**
     * @todo: Add more languages
     */

    QString l = m_curLex;

    if (l == "AVS")                selectNameFilter("AVS source file (*.avs)");
    else if (l == "Bash")          selectNameFilter("Bash shell (*.sh)");
    else if (l == "Batch")         selectNameFilter("Typical Windows Batch command (*.bat)");
    else if (l == "C")             selectNameFilter("C source (*.c)");
    else if (l == "CMake")         selectNameFilter("CMake List (CMakeLists.txt)");
    else if (l == "CoffeeScript")  selectNameFilter("CoffeeScript source (*.coffee)");
    else if (l == "CPP")           selectNameFilter("C++ source (*.cpp)");
    else if (l == "CSharp")        selectNameFilter("C# source (*.cs)");
    else if (l == "CSS")           selectNameFilter("CSS source (*.css)");
    else if (l == "D")             selectNameFilter("D source (*.d)");
    else if (l == "Diff")          selectNameFilter("Diff file (*.diff)");
    else if (l == "EDIFACT")       selectNameFilter("EDIFACT file (*.edifact)");
    else if (l == "Fortran")       selectNameFilter("Fortran source (*.f)");
    else if (l == "Fortran77")     selectNameFilter("Fortran 77 source (*.f77)");
    else if (l == "HTML")          selectNameFilter("HTML file (*.html)");
    else if (l == "IDL")           selectNameFilter("IDL file (*.idl)");
    else if (l == "Java")          selectNameFilter("Java source (*.java)");
    else if (l == "JavaScript")    selectNameFilter("JavaScript web-based sources (*.js)");
    else if (l == "JSON")          selectNameFilter("JSON file (*.json)");
    else if (l == "Lua")           selectNameFilter("Lua source (*.lua)");
    else if (l == "Makefile")      selectNameFilter("Unix Makefile file (Makefile)");
    else if (l == "Markdown")      selectNameFilter("GitHub dialect markdown file (*.md)");
    else if (l == "Matlab")        selectNameFilter("Matlab source (*.mat)");
    else if (l == "Octave")        selectNameFilter("Octave source (*.octave)");
    else if (l == "Pascal")        selectNameFilter("Pascal source (*.pas)");
    else if (l == "Perl")          selectNameFilter("Perl source (*.pl)");
    else if (l == "PO")            selectNameFilter("GNU/gettext project-object language file (*.po)");
    else if (l == "PostScript")    selectNameFilter("PostScript source (*.ps)");
    else if (l == "POV")           selectNameFilter("POV sources (*.pov)");
    else if (l == "Properties")    selectNameFilter("Property Specification Language (*.psl)");
    else if (l == "Python"
             || l == "Python3")    selectNameFilter("Python script (*.py)");
    else if (l == "QSS")           selectNameFilter("Qt StyleSheet file (*.qss)");
    else if (l == "Ruby")          selectNameFilter("Ruby script (*.rb)");
    else if (l == "Spice")         selectNameFilter("Spice source (*.spice)");
    else if (l == "SQL")           selectNameFilter("SQL script (*.sql)");
    else if (l == "TCL")           selectNameFilter("TCL source (*.tcl)");
    else if (l == "TeX")           selectNameFilter("TeX file (*.tex)");
    else if (l == "Verilog")       selectNameFilter("Verilog source (*.v)");
    else if (l == "VHDL")          selectNameFilter("VHDL file (*.vhd)");
    else if (l == "XML")           selectNameFilter("XML file (*.xml)");
    else if (l == "YAML")          selectNameFilter("YAML file (*.yml)");
    else                           selectNameFilter("Normal text file (*.txt)");

    connect(this, SIGNAL(accepted()),
            this, SLOT(saveFile()));
}

void BrStormTextSaveCopyToDialog::saveFile()
{
    QFile f(selectedFiles().at(0));

    if (f.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream o(&f);
        o << m_tab->currentTab()->text();
    }

    f.close();
}
