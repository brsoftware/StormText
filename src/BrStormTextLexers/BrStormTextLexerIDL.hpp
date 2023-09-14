/**
 * @brief BrStormTextLexerIDL.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERIDL_HPP
#define BRSTORMTEXTLEXERIDL_HPP


#include <Qsci/qscilexeridl.h>


class BrStormTextLexerIDL : public QsciLexerIDL
{
    Q_OBJECT

public:

    BrStormTextLexerIDL(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const;
    
private:
    
    const char *m_keywordSet1 = "aggregatable allocate appobject arrays async async_uuid "
                                "auto_handle bindable boolean broadcast byte byte_count "
                                "call_as callback char coclass code comm_status const "
                                "context_handle context_handle_noserialize "
                                "context_handle_serialize control cpp_quote custom decode "
                                "default defaultbind defaultcollelem defaultvalue "
                                "defaultvtable dispinterface displaybind dllname double dual "
                                "enable_allocate encode endpoint entry enum error_status_t "
                                "explicit_handle fault_status first_is float handle_t heap "
                                "helpcontext helpfile helpstring helpstringcontext "
                                "helpstringdll hidden hyper id idempotent ignore iid_as iid_is "
                                "immediatebind implicit_handle import importlib in include "
                                "in_line int __int64 __int3264 interface last_is lcid "
                                "length_is library licensed local long max_is maybe message "
                                "methods midl_pragma midl_user_allocate midl_user_free min_is "
                                "module ms_union ncacn_at_dsp ncacn_dnet_nsp ncacn_http "
                                "ncacn_ip_tcp ncacn_nb_ipx ncacn_nb_nb ncacn_nb_tcp ncacn_np "
                                "ncacn_spx ncacn_vns_spp ncadg_ip_udp ncadg_ipx ncadg_mq "
                                "ncalrpc nocode nonbrowsable noncreatable nonextensible notify "
                                "object odl oleautomation optimize optional out out_of_line "
                                "pipe pointer_default pragma properties propget propput "
                                "propputref ptr public range readonly ref represent_as "
                                "requestedit restricted retval shape short signed size_is "
                                "small source strict_context_handle string struct switch "
                                "switch_is switch_type transmit_as typedef uidefault union "
                                "unique unsigned user_marshal usesgetlasterror uuid v1_enum "
                                "vararg version void wchar_t wire_marshal";
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

#endif // BRSTORMTEXTLEXERIDL_HPP

