/**
 * @brief BrStormTextLexerFortran77.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERHTML_HPP
#define BRSTORMTEXTLEXERHTML_HPP


#include <Qsci/qscilexerhtml.h>


class BrStormTextLexerHTML : public QsciLexerHTML
{
    Q_OBJECT

public:

    BrStormTextLexerHTML(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const
    {
        if (set == 1)
            return set1;

        if (set == 2)
            return set2;

        if (set == 3)
            return set3;

        if (set == 4)
            return set4;

        if (set == 5)
            return set5;

        if (set == 6)
            return set6;

        return 0;
    }

private:

    const char *set1 = "a abbr acronym address applet aside area article audio "
                       "b base basefont bdo big blockquote body br button "
                       "canvas caption center cite code col colgroup command "
                       "datalist dd del details dfn dir div dl dt "
                       "em embed "
                       "fieldset figure font footer form frame frameset "
                       "h1 h2 h3 h4 h5 h6 head header hgroup hr html "
                       "i iframe img input ins isindex "
                       "kbd keygen "
                       "label legend li link "
                       "map mark menu meta meter "
                       "nav noframes noscript "
                       "object ol optgroup option output "
                       "p param pre progress "
                       "q "
                       "ruby "
                       "s samp script section select small span strike strong style "
                       "sub sup "
                       "table tbody td textarea tfoot th thead time title tr tt "
                       "u ul "
                       "var video "
                       "wbr "
                       "xml xmlns "
                       "abbr accept-charset accept accesskey action align "
                       "alink alt archive autocomplete autofocus axis "
                       "background bgcolor border "
                       "cellpadding cellspacing char charoff charset checked "
                       "cite class classid clear codebase codetype color "
                       "cols colspan compact content coords "
                       "data datafld dataformatas datapagesize datasrc "
                       "datetime declare defer dir disabled "
                       "enctype event "
                       "face for form formaction formenctype frame frameborder "
                       "formmethod formnovalidate formtarget "
                       "headers height href hreflang hspace http-equiv "
                       "id ismap label lang language leftmargin link list "
                       "longdesc "
                       "marginwidth marginheight max maxlength media method "
                       "min multiple "
                       "name nohref noresize noshade novalidate nowrap "
                       "object "
                       "onafterprint onbeforeprint onbeforeunload onerror "
                       "onhashchange onload nomessage onoffline ononline "
                       "onpagehide onpageshow onpopstate onresize onstorage "
                       "onunload onblur onchange oncontextmenu onfocus oninput "
                       "oninvalid onreset onsearch onselect onsubmit onkeydown "
                       "onkeypress onkeyup onclick ondblclick onmousedown "
                       "onmousemove onmouseout onmouseover onmouseup onmousewheel "
                       "onwheel ondrag ondragend ondragenter ondragleave ondragover "
                       "ondragstart ondrop onscroll oncopy oncut onpaste onabort "
                       "oncanplay oncaplaythrough oncuechange ondurationchange "
                       "onemptied onended onloadeddata onloadedmetadata onloadstart "
                       "onpause onplay onplaying onprogress onratechange onseeked "
                       "onseeking onstalled onsuspend ontimeupdate onvolumechange "
                       "onwaiting ontoggle "
                       "pattern placeholder profile prompt "
                       "readonly rel required rev rows rowspan rules "
                       "scheme scope selected shape size span src standby "
                       "start step style summary "
                       "tabindex target text title topmargin type "
                       "usemap "
                       "valign value valuetype version vlink vspace "
                       "width "
                       "text password checkbox radio submit reset file "
                       "hidden image "
                       "public !doctype";
    const char *set2 = "abstract boolean break byte case catch char class const continue "
                       "debugger default delete do double else enum export extends final "
                       "finally float for function goto if implements import in instanceof "
                       "int interface long native new package private protected public "
                       "return short static super switch synchronized this throw throws "
                       "transient try typeof var void volatile while with";
    const char *set3 = "and begin case call continue do each else elseif end "
                       "erase error event exit false for function get gosub "
                       "goto if implement in load loop lset me mid new next "
                       "not nothing on or property raiseevent rem resume "
                       "return rset select set stop sub then to true unload "
                       "until wend while with withevents attribute alias as "
                       "boolean byref byte byval const compare currency date "
                       "declare dim double enum explicit friend global "
                       "integer let lib long module object option optional "
                       "preserve private property public redim single static "
                       "string type variant";
    const char *set4 = "and as assert async await break case class continue def del "
                       "elif else except False finally for from global if import in "
                       "is lambda match None nonlocal not or pass raise return True "
                       "try while with yield";
    const char *set5 = "and argv as argc break case cfunction class continue "
                       "declare default do die "
                       "echo else elseif empty enddeclare endfor endforeach "
                       "endif endswitch endwhile e_all e_parse e_error "
                       "e_warning eval exit extends "
                       "false for foreach function global "
                       "http_cookie_vars http_get_vars http_post_vars "
                       "http_post_files http_env_vars http_server_vars "
                       "if include include_once list new not null "
                       "old_function or "
                       "parent php_os php_self php_version print "
                       "require require_once return "
                       "static switch stdclass this true var xor virtual "
                       "while "
                       "__file__ __line__ __sleep __wakeup";
    const char *set6 = "ELEMENT DOCTYPE ATTLIST ENTITY NOTATION";
};

#endif // BRSTORMTEXTLEXERHTML_HPP

