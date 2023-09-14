/**
 * @brief BrStormTextLexerCPP.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERCPP_HPP
#define BRSTORMTEXTLEXERCPP_HPP


#include <Qsci/qscilexercpp.h>


class BrStormTextLexerCPP : public QsciLexerCPP
{
    Q_OBJECT

public:

    BrStormTextLexerCPP(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const;

private:

    const char *m_keywordSet1 = "alignas alignof and and_eq asm atomic_cancel "
                                "atomic_commit atomic_noexcept auto bitand bitor "
                                "bool break case catch char char8_t char16_6 "
                                "char32_t class compl concept const consteval"
                                "constexpr constinit const_cast continue co_await "
                                "co_return co_yield decltype default delete do "
                                "double dynamic_cast else enum explicit export "
                                "extern false float for friend goto if inline int "
                                "long mutable namespace new noexcept not not_eq "
                                "nullptr operator or or_eq private protected public "
                                "reflexpr register reinterpret_cast requires return "
                                "short signed sizeof static static_assert static_cast "
                                "struct switch synchronized template this thread_local "
                                "throw true try typedef typeid typename union unsigned "
                                "using virtual void volatile wchar_t while xor xor_eq "
                                "final override transcation_safe "
                                "transaction_safe_dynamic import module";
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

#endif // BRSTORMTEXTLEXERCPP_HPP

