/**
 * @brief BrStormTextLexerCSS.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERQSS_HPP
#define BRSTORMTEXTLEXERQSS_HPP


#include <Qsci/qscilexercss.h>


class BrStormTextLexerQSS : public QsciLexerCSS
{
    Q_OBJECT

public:

    BrStormTextLexerQSS(QFont font, QColor color, QObject *parent = nullptr);

public:

    const char *keywords(int set) const override {
        if (set == 1) return css1Properties;
        if (set == 2) return cssPseudoClasses;
        if (set == 3) return css2Properties;
        if (set == 4) return css3Properties;
        if (set == 5) return cssPseudoElement;
        if (set == 6) return cssExtendedProperties;
        if (set == 7) return cssExtendedPseudoClass;
        if (set == 8) return cssExtendedPseudoElement;
        return 0;
    }

    const char *language() const override {
        return "QSS";
    }

private:

    const char *css1Properties = "color background-color background-image "
                                 "background-repeat background-attachment "
                                 "background-position background font-family "
                                 "font-style font-variant font-weight font-size font "
                                 "word-spacing letter-spacing text-decoration "
                                 "vertical-align text-transform text-align "
                                 "text-indent line-height margin-top margin-right "
                                 "margin-bottom margin-left margin padding-top "
                                 "padding-right padding-bottom padding-left padding "
                                 "border-top-width border-right-width "
                                 "border-bottom-width border-left-width border-width "
                                 "border-top border-right border-bottom border-left "
                                 "border border-color border-style width height float "
                                 "clear display white-space list-style-type "
                                 "list-style-image list-style-position list-style";
    const char *css2Properties = "border-top-color border-right-color "
                                 "border-bottom-color border-left-color border-color "
                                 "border-top-style border-right-style "
                                 "border-bottom-style border-left-style border-style "
                                 "top right bottom left position z-index direction "
                                 "unicode-bidi min-width max-width min-height "
                                 "max-height overflow clip visibility content quotes "
                                 "counter-reset counter-increment marker-offset size "
                                 "marks page-break-before page-break-after "
                                 "page-break-inside page orphans widows font-stretch "
                                 "font-size-adjust unicode-range units-per-em src "
                                 "panose-1 stemv stemh slope cap-height x-height "
                                 "ascent descent widths bbox definition-src baseline "
                                 "centerline mathline topline text-shadow "
                                 "caption-side table-layout border-collapse "
                                 "border-spacing empty-cells speak-header cursor "
                                 "outline outline-width outline-style outline-color "
                                 "volume speak pause-before pause-after pause "
                                 "cue-before cue-after cue play-during azimuth "
                                 "elevation speech-rate voice-family pitch "
                                 "pitch-range stress richness speak-punctuation "
                                 "speak-numeral";
    const char *css3Properties = "grid-area grid-auto-columns grid-auto-flow "
                                 "grid-column-end grid-column-gap grid-column-start "
                                 "grid-column grid-gap grid-row-end grid-row-gap "
                                 "grid-row-start grid-row grid-template-areas "
                                 "grid-template-columns grid-template-rows "
                                 "grid-template grid align-content align-items "
                                 "align-self flex flex-basis flex-direction "
                                 "flex-flow flex-grow flex-shrink flex-wrap "
                                 "justify-content order keyframes animation "
                                 "animation-delay animation-direction "
                                 "animation-duration animation-fill-mode "
                                 "animation-iteration-count animation-name "
                                 "animation-play-state animation-timing-function "
                                 "font-feature-settings font-kerning "
                                 "font-language-override font-synthesis "
                                 "font-variant-alternates font-variant-caps "
                                 "font-variant-east-asian font-variant-ligatures "
                                 "font-variant-numeric font-variant-position "
                                 "transition transition-delay transition-duration "
                                 "transition-property transition-timing-function "
                                 "backface-visibility perspective perspective-origin "
                                 "transform transform-box transform-origin "
                                 "transform-style break-after break-before break-inside "
                                 "columns column-count column-fill column-rule "
                                 "column-rule-color column-rule-style column-span "
                                 "column-width border-radius border-top-left-radius "
                                 "border-top-right-radius border-bottom-left-radius "
                                 "border-bottom-right-radius border-image "
                                 "border-image-outset border-image-repeat "
                                 "border-image-source border-image-slice border-image-width "
                                 "caret-color box-shadow filter image-rendering isolation "
                                 "mix-blend-mode object-fit object-position opacity "
                                 "linear-gradient repeating-linear-gradient radial-gradient "
                                 "repeating-radial-gradient text-decoration-line "
                                 "text-decoration-style text-decoration-color "
                                 "text-decoration-skip text-underline-position "
                                 "background-blend-mode background-clip background-origin "
                                 "background-size nav-up nav-down nav-left nav-right "
                                 "overflow-wrap overflow-x overflow-y resize text-overflow "
                                 "hyphens line-break word-break word-wrap rest-after "
                                 "rest-before rest speak-as voice-balance voice-duration "
                                 "voice-range voice-rate voice-stress voice-volume column-gap "
                                 "justify-items align-self justify-self place-content "
                                 "place-self row-gap hanging-punctuation tab-size tab-align-all "
                                 "text-align-all text-align-last text-justify all bleed "
                                 "box-sizing box-decoration-break color-interpolation-filters "
                                 "flood-color flood-opacity lighting-color outline-offset "
                                 "text-combine-upright text-orientation will-change writing-mode "
                                 "file-icon dialogbuttonbox-buttons-have-icons dialog-ok-icon "
                                 "dialog-cancel-icon border etch-disabled-text image subcontrol-origin "
                                 "subcontrol-position selection-background-color titlebar-close-icon "
                                 "titlebar-normal-icon lineedit-password-character alternate-background-color "
                                 "show-decoration-selected bottom button-layout gridline-color "
                                 "icon icon-size image-position lineedit-password-mask-delay "
                                 "messagebox-text-interaction-flags outline outline-color outline-offset "
                                 "outline-style outline-radius outline-bottom-left-radius "
                                 "outline-bottom-right-radius outline-top-left-radius outline-top-right-radius "
                                 "paint-alternating-row-colors-for-empty-area placeholder-text-color "
                                 "selection-color show-decoration-selected spacing titlebar-show-tooltips-on-buttons "
                                 "widget-animation-duration -qt-background-role -qt-style-features";
    const char *cssPseudoClasses = "active any-link autofill blank checked current default "
                                   "defined dir disabled empty enabled first first-child "
                                   "first-of-type fullscreen future focus focus-visible "
                                   "focus-within has host host-context hover indeterminate "
                                   "in-range invalid is lang last-child last-of-type left link "
                                   "local-link modal not nth-child nth-col nth-last-child "
                                   "nth-last-of-type nth-of-type only-child only-of-type optional "
                                   "out-of-range past picture-in-picture placeholder-shown paused "
                                   "playing read-only read-write required right root scope state "
                                   "target target-within user-invalid valid visited where "
                                   "adjoins-item alternate bottom checked closable default "
                                   "disabled editable edit-focus enabled exclusive flat "
                                   "floatable has-children has-siblings horizontal last left "
                                   "maximized middle minimized movable no-frame non-exclusive "
                                   "off on only-one open next-selected pressed previous-selected "
                                   "read-only right selected top unchecked vertical window";
    const char *cssPseudoElement = "after backdrop before cue cue-region first-letter first-line "
                                   "file-selector-button grammar-error marker part placeholder "
                                   "selection slotted spelling-error target-text add-line add-page "
                                   "branch chunk close-button corner down-arrow down-button "
                                   "drop-down float-button groove indicator handle icon item "
                                   "left-arrow left-corner menu-arrow menu-button menu-indicator "
                                   "right-arrow pane right-corner scroller section separator "
                                   "sub-line sub-page tab tab-bar tear tearoff text title up-arrow "
                                   "up-button";
    const char *cssExtendedProperties = "-webkit-animation-trigger -webkit-app-region "
                                        "-webkit-aspect-ratio -webkit-backdrop-filter "
                                        "-webkit-border-after -webkit-border-after-color "
                                        "-webkit-border-after-style -webkit-border-after-width "
                                        "-webkit-border-before -webkit-border-before-color "
                                        "-webkit-border-before-style -webkit-border-before-width "
                                        "-webkit-border-end -webkit-border-end-color "
                                        "-webkit-border-end-style -webkit-border-end-width "
                                        "-webkit-border-horizontal-spacing -webkit-border-start "
                                        "-webkit-border-start-color -webkit-border-start-style "
                                        "-webkit-border-start-width -webkit-border-vertical-spacing "
                                        "-webkit-box-align -webkit-box-direction -webkit-box-flex-group "
                                        "-webkit-box-flex -webkit-box-lines -webkit-box-ordinal-group "
                                        "-webkit-box-orient -webkit-box-pack -webkit-box-reflect "
                                        "-webkit-column-axis -webkit-column-break-after "
                                        "-webkit-column-break-before -webkit-column-break-inside "
                                        "-webkit-column-progression -webkit-cursor-visibility "
                                        "-webkit-dashboard-region -webkit-font-size-delta "
                                        "-webkit-font-smoothing -webkit-highlight "
                                        "-webkit-hyphenate-character -webkit-hyphenate-limit-after "
                                        "-webkit-hyphenate-limit-before -webkit-hyphenate-limit-lines "
                                        "-webkit-initial-letter -webkit-line-align -webkit-line-clamp "
                                        "-webkit-line-grid -webkit-line-snap -webkit-locale "
                                        "-webkit-logical-height -webkit-logical-width "
                                        "-webkit-margin-after -webkit-margin-before -webkit-margin-end "
                                        "-webkit-margin-start -webkit-marquee-direction "
                                        "-webkit-marquee-increment -webkit-marquee-repetition "
                                        "-webkit-marquee-speed -webkit-marquee-style -webkit-marquee "
                                        "-webkit-mask-box-image-outset -webkit-mask-box-image-repeat "
                                        "-webkit-mask-box-image-slice -webkit-mask-box-image-source "
                                        "-webkit-mask-box-image-width -webkit-mask-box-image "
                                        "-webkit-mask-repeat-x -webkit-mask-repeat-y "
                                        "-webkit-mask-source-type -webkit-mask-position-x "
                                        "-webkit-mask-position-y "
                                        "-webkit-max-logical-height -webkit-max-logical-width "
                                        "-webkit-min-logical-height -webkit-min-logical-width "
                                        "-webkit-nbsp-mode -webkit-padding-after -webkit-padding-before "
                                        "-webkit-padding-end -webkit-padding-start "
                                        "-webkit-perspective-origin-x -webkit-perspective-origin-y "
                                        "-webkit-rtl-ordering -webkit-svg-shadow "
                                        "-webkit-tap-highlight-color -webkit-text-decoration-skip "
                                        "-webkit-text-decorations-in-effect -webkit-text-fill-color "
                                        "-webkit-text-security -webkit-text-stroke-color "
                                        "-webkit-text-stroke-width -webkit-text-stroke -webkit-text-zoom "
                                        "-webkit-transform-origin-x -webkit-transform-origin-y "
                                        "-webkit-transform-origin-z -webkit-user-drag -webkit-user-modify "
                                        "-webkit-align-content -webkit-align-items -webkit-align-self "
                                        "-webkit-animation -webkit-animation-delay -webkit-animation-direction "
                                        "-webkit-animation-fill-mode -webkit-animation-iteration-count "
                                        "-webkit-animation-name -webkit-animation-play-state "
                                        "-webkit-animation-timing-function -webkit-appearance "
                                        "-webkit-backface-visibility -webkit-background-clip "
                                        "-webkit-background-origin -webkit-background-size "
                                        "-webkit-border-bottom-left-radius -webkit-border-bottom-right-radius "
                                        "-webkit-border-image -webkit-border-radius -webkit-border-top-left-radius "
                                        "-webkit-border-top-right-radius -webkit-box-decoration-break "
                                        "-webkit-box-shadow -webkit-box-sizing -webkit-clip-path -webkit-column-count "
                                        "-webkit-column-fill -webkit-column-gap -webkit-column-rule "
                                        "-webkit-column-rule-color -webkit-column-rule-style -webkit-column-rule-width "
                                        "-webkit-column-span -webkit-column-width -webkit-columns -webkit-filter "
                                        "-webkit-flex -webkit-flex-basis -webkit-flex-direction -webkit-flex-flow "
                                        "-webkit-flex-grow -webkit-flex-shrink -webkit-flex-wrap "
                                        "-webkit-font-feature-settings -webkit-font-kerning "
                                        "-webkit-font-variant-ligatures -webkit-grid -webkit-grid-area "
                                        "-webkit-grid-auto-columns -webkit-grid-auto-flow -webkit-grid-auto-rows "
                                        "-webkit-grid-column -webkit-grid-column-end -webkit-grid-column-gap "
                                        "-webkit-grid-column-start -webkit-grid-gap -webkit-grid-row "
                                        "-webkit-grid-row-end -webkit-grid-row-gap -webkit-grid-row-start "
                                        "-webkit-grid-template -webkit-grid-template-areas -webkit-grid-template-columns "
                                        "-webkit-grid-template-rows -webkit-hyphens -webkit-justify-content "
                                        "-webkit-justify-items -webkit-justify-self -webkit-line-break "
                                        "-webkit-mask -webkit-mask-clip -webkit-mask-composite -webkit-mask-image "
                                        "-webkit-mask-origin -webkit-mask-position -webkit-mask-repeat -webkit-mask-size "
                                        "-webkit-mask-repeat -webkit-mask-size -webkit-opacity -webkit-order "
                                        "-webkit-perspective -webkit-perspective-origin -webkit-print-color-adjust "
                                        "-webkit-ruby-position -webkit-scroll-snap-type -webkit-shape-image-threshold "
                                        "-webkit-shape-margin -webkit-shape-outside -webkit-text-combine "
                                        "-epub-text-decoration -webkit-text-color-decoration -webkit-text-decoration-line "
                                        "-epub-text-emphasis -webkit-text-emphasis -epub-text-emphasis-color "
                                        "-webkit-text-emphasis-color -webkit-text-emphasis-position -epub-text-emphasis-style "
                                        "-webkit-text-emphasis-style -webkit-text-justify -webkit-text-orientation "
                                        "-webkit-text-size-adjust -webkit-text-underline-position -webkit-transform "
                                        "-webkit-transform-origin -webkit-transform-style -webkit-transition "
                                        "-webkit-transition-delay -webkit-transition-property "
                                        "-webkit-transition-timing-function -webkit-user-select -epub-word-break "
                                        "-epub-writing-mode -webkit-mask-position-x -webkit-mask-position-y "
                                        "-moz-animation -moz-animation-delay -moz-animation-direction "
                                        "-moz-animation-duration -moz-animation-fill-mode -moz-animation-iteration-count "
                                        "-moz-animation-name -moz-animation-play-state -moz-animation-timing-function "
                                        "-moz-appearance -moz-backface-visibility -moz-background-origin "
                                        "-moz-background-inline-policy -moz-background-size -moz-border-end "
                                        "-moz-border-end-color -moz-border-end-style -moz-border-end-width "
                                        "-moz-border-image -moz-border-start -moz-border-start-color "
                                        "-moz-border-start-style -moz-border-start-width -moz-box-sizing "
                                        "-moz-column-count -moz-column-fill -moz-column-gap -moz-column-width "
                                        "-moz-column-rule -moz-column-rule-width -moz-column-rule-style "
                                        "-moz-column-rule-color -moz-font-feature-settings -moz-font-language-override "
                                        "-moz-hyphens -moz-margin-end -moz-margin-start -moz-opacity -moz-outline "
                                        "-moz-outline-color -moz-outline-offset -moz-outline-style -moz-outline-width "
                                        "-moz-padding-end -moz-padding-start -moz-perspective -moz-perspective-origin "
                                        "-moz-tab-size -moz-text-align-last -moz-text-decoration-color "
                                        "-moz-text-decoration-style -moz-text-size-adjust -moz-transform "
                                        "-moz-transform-origin -moz-transform-style -moz-transition "
                                        "-moz-transition-delay -moz-transition-duration -moz-transition-property "
                                        "-moz-transition-timing-function -moz-user-select "
                                        "-ms-background-position-x -ms-background-position-y "
                                        "-ms-behavior -ms-interpolation-mode -ms-text-align-last "
                                        "-ms-text-autospace -ms-text-underline-position -ms-transform "
                                        "-ms-transform-origin -ms-word-wrap -ms-writing-mode -ms-zoom"
                                        "";
    const char *cssExtendedPseudoClass = "-webkit-animating-full-screen-transition -webkit-any -webkit-any-link "
                                         "-webkit-autofill -webkit-autofill-strong-password -webkit-drag "
                                         "-webkit-full-page-media -webkit-full-screen -webkit-full-screen-ancestor "
                                         "-webkit-full-screen-document -webkit-full-screen-controls-hidden "
                                         "-moz-any -moz-any-link- moz-broken -moz-drag-over -moz-first-node "
                                         "-moz-focusring -moz-full-screen -moz-full-screen-ancestor "
                                         "-moz-handler-blocked -moz-handler-crashed -moz-handler-disabled "
                                         "-moz-last-node -moz-list-bullet -moz-list-number -moz-loading "
                                         "-moz-locale-dir -moz-lwtheme -moz-lwtheme-brighttext "
                                         "-moz-lwtheme-darktext -moz-native-anonymous -moz-only-whitespace "
                                         "-moz-placeholder -moz-read-only -moz-read-write -moz-submit-invalid "
                                         "-moz-suppressed -moz-ui-invalid -moz-ui-valid -moz-user-disabled "
                                         "-moz-window-inactive";
    const char *cssExtendedPseudoElement = "-webkit-file-upload-button -webkit-inner-spin-button -webkit-input-placeholder "
                                           "-webkit-media-controls -webkit-media-controls-current-time-display "
                                           "-webkit-media-controls-enclosure -webkit-controls-fullscreen-button "
                                           "-webkit-media-controls-mute-button -webkit-media-controls-overlay-enclosure "
                                           "-webkit-media-controls-panel -webkit-media-controls-play-button "
                                           "-webkit-media-controls-timeline -webkit-media-controls-time-remaining-display "
                                           "-webkit-media-controls-toggle-closed-captions-button "
                                           "-webkit-media-controls-volume-control-container "
                                           "-webkit-media-controls-volume-control-hover-background "
                                           "-webkit-media-controls-volume-slider -webkit-meter-bar "
                                           "-webkit-meter-even-less-good-value -webkit-meter-inner-element "
                                           "-webkit-meter-optimum-value -webkit-meter-suboptimum-value "
                                           "-webkit-media-text-track-container -webkit-outer-spin-button "
                                           "-webkit-progress-bar -webkit-progress-inner-element "
                                           "-webkit-progress-value -webkit-search-cancel-button "
                                           "-webkit-search-results-button -webkit-slider-runnable-track "
                                           "-webkit-slider-thumb -moz-anonymous-block -moz-anonymous-positioned-block "
                                           "-moz-canvas -moz-cell-content -moz-focus-inner -moz-focus-outer "
                                           "-moz-full-screen-ancestor -moz-inline-table -moz-pagebreak "
                                           "-moz-pagecontent -moz-placeholder -moz-progress-bar "
                                           "-moz-range-progress -moz-range-thumb -moz-range-track "
                                           "-moz-scrolled-canvas -moz-scrolled-content -moz-scrolled-page-sequence "
                                           "-moz-selection -moz-svg-foreign-content -moz-table "
                                           "-moz-table-cell -moz-table-column -moz-table-column-group "
                                           "-moz-table-outer -moz-table-row -moz-table-row-group -moz-viewport "
                                           "-moz-viewport-scroll";
};

#endif // BRSTORMTEXTLEXERQSS_HPP

