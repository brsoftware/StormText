/**
 * @brief BrStormTextLexerC.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERC_HPP
#define BRSTORMTEXTLEXERC_HPP


#include <Qsci/qscilexercpp.h>


class BrStormTextLexerC : public QsciLexerCPP
{
    Q_OBJECT

public:

    BrStormTextLexerC(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const;
    const char *language() const {return "C";}

private:
    
    const char *m_keywordSet1 = "auto break case char const continue default "
                                "do double else enum extern float for goto "
                                "if int long register return short signed sizeof "
                                "static struct switch typedef union unsigned void "
                                "volatile while";
    const char *m_keywordSet3 = "a abstract addindex addtogroup anchor annotatedlist "
                                "arg attention author authors b badcode basename "
                                "bold brief bug c callergraph callgraph caption category "
                                "chapter cite class code codeline compat cond "
                                "contentspace copybrief copydetails copydoc copyright "
                                "corelib date def default defgroup deprecated details "
                                "diafile dir div docbookonly dontinclude dot dotfile "
                                "dots e else elseif em endabstract endchapter "
                                "endcode endcond enddocbookonly enddot endfootnote "
                                "endhtmlonly endif endinternal endlatexonly endlegalese "
                                "endlink endlist endmanonly endmsc endomit endparblock "
                                "endpart endquotation endraw endrtfonly endsecreflist "
                                "endsection1 endsection2 endsection3 endsection4 "
                                "endsidebar endtable enduml endverbatim endxmlonly "
                                "enum example exception exceptions expire extends "
                                "externalpage file fn footnote generatelist granularity "
                                "group gui header headerfile hidecallergraph hidecallgraph "
                                "hideinitializer htmlinclude htmlonly i idleexcept if "
                                "ifnot image implements include includelineno index indexpage "
                                "ingroup inheaderfile inherits inlineimage inmodule "
                                "inpublicgroup inqmlmodule instantiates interface internal "
                                "invariant keyword l latexinclude latexonly legalese li "
                                "line link list macro mainclass mainpage manonly memberof "
                                "meta module msc mscfile n name namespace network newcode "
                                "nextpage noautolist noreentrant nosubgrouping note o "
                                "obsolete oldcode omit omitvalue only opengl overload "
                                "p package page par paragraph param parblock part "
                                "post pre preliminary previouspage printline printto "
                                "printuntil private privatesection property protected "
                                "protectedsection protocol public publicsection pure "
                                "qmlabstract qmlattachedproperty qmlattachedsignal "
                                "qmlbasictype qmlclass qmlmethod qmlmodule qmlproperty "
                                "qmlsignal qmltype qt3dsupport qteestlib quotation "
                                "quotefile quotefromfile quotefunction raw reentrant "
                                "ref refitem refimp related relates relatesalso remark "
                                "remarks result return returns retval row row rtfonly "
                                "sa secreflist section section1 section2 section3 section4 "
                                "see service short showinitializer sidebar skip skipline "
                                "skipto skipuntil snippet span sql startpage startuml "
                                "struct sub subpage subsection subsubsection subtitle sup "
                                "svg table tableofcontents target test threadsafe throw "
                                "throws title todo tparam tt typedef uitools underline "
                                "unicode union until value var variable verbatim "
                                "verbinclude version vhdlflow warnings weakgroup webkit "
                                "xml xmlonly xrefitem $ @ \\ & < > # { }";
};

#endif // BRSTORMTEXTLEXERC_HPP

