#ifndef _HAVE_WIKI_TEXT_HEADER
#define _HAVE_WIKI_TEXT_HEADER

#define EDITHEADER                                                       \
                                                                         \
"<div id='header'>\n"                                                    \
"<form method='get' action='Search'>\n"                                 \
"<table border='0' width='100%%'>\n"                                      \
"<tr>\n"                                                                 \
"<td align='left' ><strong>%s</strong>" \
" ( <a href=%s?edit title='Edit this wiki page contents. [alt-j]' accesskey='j'>Edit</a> | " \
"<a href=%s?delete title='Delete page. [alt-d]' accesskey='d'>Delete</a> ) </td>" \
"<td align='right' >\n"                                    \
"<a href='WikiHome' title='Visit Wiki home page. [alt-z]' accesskey='z'>Home</a> |\n"  \
"<a href='Index' title='List all pages in the wiki. [alt-i]' accesskey='i' >Index</a> | \n"  \
"<a href='Changes' title='List recent changes in the wiki. [alt-r]' accesskey='r' >Changes</a> | \n"  \
"<a href='Create' title='Create a new wiki page by title. [alt-c]' accesskey='c'>New</a> | \n"    \
"<a href='WikiHelp' title='Get help on wiki usage and formatting.'>Help</a>  \n"    \
"<input type='text' name='expr' size='15' title='Enter text to search for and press return.' /> </td>\n"  \
"</tr>\n"                                                                \
"</table>\n"                                                             \
"</form>\n"                                                              \
"</div>\n"                                                               \
"<div id='wikidata'>\n"

#define PAGEHEADER                                                       \
                                                                         \
"<div id='header'>\n"                                                    \
"<form method='get' action='Search'>\n"                                 \
"<table border='0' width='100%%'>\n"                                      \
"<tr>\n"                                                                 \
"<td align='left' ><strong>%s</strong> %s</td>\n"         \
"<td align='right' >\n"                                    \
"<a href='WikiHome' title='Visit Wiki home page. [alt-z]' accesskey='z'>Home</a> |\n"  \
"<a href='Index' title='List all pages in the wiki. [alt-i]' accesskey='i' >Index</a> | \n"  \
"<a href='Changes' title='List recent changes in the wiki. [alt-r]' accesskey='r' >Changes</a> | \n"                                    \
"<a href='Create' title='Create a new wiki page by title. [alt-c]' accesskey='c'>New</a> | \n"                                         \
"<a href='WikiHelp' title='Get help on wiki usage and formatting.'>Help</a>  \n"                                       \
"<input type='text' name='expr' size='15' title='Enter text to search for and press return.' /> </td>\n"                               \
"</tr>\n"                                                                \
"</table>\n"                                                             \
"</form>\n"                                                              \
"</div>\n"                                                               \
"<div id='wikidata'>\n"


#define PAGEFOOTER                                                       \
                                                                         \
"</div><div id='footer'>PortableWiki Version: " VERSION "</div>\n"


#define SHORTHELP                                                    \
                                                                         \
"<div id='header'>\n"                                                    \
"<table border='0' width='100%%'>\n"                                      \
"<tr>\n"                                                                 \
"<td align='left' > =H1 ==H2 ===H3 | *bold* | /italic/ | _underscore_ | -strikethrough- | +highlight+ | 'quote | "\
"[link] | * list | ** sublist | # ordered | ---- | {{toc}}</td>\n"\
"</tr>\n"                                                           \
"</table>\n"                                                             \
"</div>\n"                                                               \
"<div id='wikidata'>\n"


#define CREATEFORM                                                       \
                                                                        \
"<form method=POST action='Create'>\n"                                  \
"<input type='text' name='title' />\n"                                   \
"<p><input type='submit' value='Create' /></p>\n"                        \
"</form>\n"


#define EDITFORM                                                         \
                                                                         \
"<form method=POST action='%s?edit' name='editform'>\n"                        \
"<textarea name='wikitext' rows='20' cols='80' wrap='virtual'>%s</textarea>\n" \
"<p><input type='submit' name='save' value='Save' title='[alt-k]' accesskey='k'>" \
"<input type='submit' name='preview' value='Preview' title='[alt-p]' accesskey='p'>" \
"<input type='submit' name='cancel' value='Cancel' title='[alt-c]' accesskey='c'></p>\n"                            \
"</form>\n"             \
"<script language='JavaScript'>\n"   \
"<!--\n"                             \
"/* Give the textarea focus ...less mouse usage but may annoy people ?*/ \n" \
"document.editform.wikitext.focus()\n" \
"document.editform.wikitext.scrollTop = document.editform.wikitext.scrollHeight;\n"          \
"//-->\n"                            \
"</script>\n"


#define EDITPREVIEW                                                      \
                                                                         \
"<div id=\"header\"><strong>Preview:</strong></div>\n"


#define DELETEFORM                                                       \
                                                                         \
"<form method=POST action='%s?delete' name='deleteform'>\n"              \
"Are you really sure you want to delete the page <strong>%s</strong>?\n" \
"<p><input type='submit' name='confirm' Value='OK'>\n"                   \
"<input type='submit' name='cancel' value='Cancel'></form>"


#define HOMETEXT ""                                                      \
                                                                         \
"==Welcome to !PortableWiki\n"                                 \
"PortableWiki is a small and simple [http://en.wikipedia.org/wiki/Wiki WikiWikiWeb] implementation\n" \
"Ideal for personal note-taking, \"to do\" lists, and any other uses you can think of.\n" \
"It is fast and does not require webserver, database mng and php interpreter.\n\n\n"  \
"For an example of how a !PortableWiki entry looks in text form you can [?edit edit] this page. Also see WikiHelp for infomation on usage and formatting rules. Use The WikiSandbox to experiment.\n" \


#define HELPTEXT ""                                                      \
                                                                         \
"=Quick Guide \n"                                                    \
"Top toolbar usage\n"                                                    \
"* [?edit Edit] Allows you to edit pages ( see below for rules )\n"       \
"* [?delete Delete] Allows you to delete pages\n"                        \
"* [WikiHome Home] Takes you to the wiki front page\n"                \
"* [Index Index] List all the pages in the wiki\n"                \
"* [Changes Changes] Lists the pages changed by date\n"                  \
"* [Create New] Creates a new wiki page by title\n"                      \
"* [WikiHelp Help] Takes you to this help page\n"                            \
"\n"                                                                     \
"Use the text entry box to perform a very simple keyword search on the\n" \
"Wiki contents. Hit return to activate the search.\n"                    \
"\n"                                                                     \
"Use the WikiSandbox to practice formatting.\n"                         \
"\n"                                                                     \
"----\n"                                                                 \
"=Formatting rules\n"                                                    \
"\n"                                                                     \
"=Top Level Heading\n"                                                   \
"  =Top Level Heading (H1)\n"                                            \
"==Second Level Heading\n"                                               \
"  ==Second Level Heading (H2)\n"                                        \
"More levels \n"                                                         \
"  === (H3), ==== (H4) etc\n"                                            \
"----\n"                                                                 \
"The horizontal lines in this page are made with 4 or more dashes:\n"     \
" ---- Horizonal line\n"                                                 \
"----\n"                                                                 \
"\n"                                                                     \
"Paragraphs are separated by an empty line\n"                            \
"\n"                                                                     \
"Like this. Another paragraph.\n"                                        \
"\n"                                                                     \
" Paragraphs are separated by a blank line.\n"                           \
"\n"                                                                     \
" Like this. Another paragraph.\n"                                       \
"----\n"                                                                 \
"*Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n"    \
"  *Bold text*, /italic text/, _underscore text_ and -strikethrough-.\n"  \
"/*Combination of bold and italics*/\n"                                  \
"  /*Combination of bold and italics*/\n"                                \
"----\n"                                                                 \
"\n"                                                                     \
"{B}Text color{B}\n"                                                     \
" {B}Text color{B}\n"                                                    \
"(Y)Background color(Y)\n"                                               \
" (Y)Background color(Y)\n"                                             \
"\n"                                                                    \
"Colors: {B}B blue{B}  {C}C cyan{C}  {G}G green{G}  {P}P pink{P}  {R}R red{R}  {Y}Y yellow{Y}\n" \
"\n"                                                                    \
"Colors: (B)B blue(B)  (C)C cyan(C)  (G)G green(G)  (P)P pink(P)  (R)R red(R)  (Y)Y yellow(Y)\n" \
"----\n"                                                                 \
"\n"                                                                  \
"+Highlight+\n"                                                       \
" +Highlight+\n"                                                      \
"-----\n"                                                              \
"\n"                                                                   \
"WikiLinks are formed by two or more words in /camelcase/.\n"           \
" WikiLinks are formed by two or more words in /camelcase/.\n"          \
"External links begin with http://, like http://www.freepan.org\n"       \
" External links begin with http://, like http://www.freepan.org\n"      \
"Forced wiki [links] are a alphanumeric string surrounded by square brackets.\n" \
" Forced wiki [links] are a alphanumeric string surrounded by square brackets.\n" \
"Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]\n" \
" Named http links have text with an !http:// link inside, like [http://www.freepan.org FreePAN]\n" \
"Sometimes !WordsShouldNotMakeAWikiLink so put a '! ' beforehand.\n"      \
" Sometimes !WordsShouldNotMakeAWikiLink so put a '! ' beforehand.\n"     \
"Same thing with !http://foobar.com\n"                                   \
" Same thing with !http://foobar.com\n"                                  \
"Open external links in new tags:\n"                                     \
" {{wwwlink=new_tag}} opens external link in a new tag\n"                \
" {{wwwlink=current_tag}} opens external link in a current tag\n"        \
"----\n"                                                                 \
"\n"                                                                     \
"Links to images display the image:\n"                                   \
"\n"                                                                     \
" Pictures size and border: {{width=100 height=50 border=2}}\n"          \
" Return to the default width, height and border: {{picture=default}}\n"  \
"\n"                                                                     \
"{{width=100 height=50 border=1}}\n"                                     \
"http://www.google.com/images/logo.gif\n"                                \
" http://www.google.com/images/logo.gif\n"                               \
"Picture http links have picture with an !http:// link inside, like [http://www.google.com/images/logo.gif http://www.google.com]\n" \
" Picture http links have picture with an !http:// link inside, like [http://www.google.com/images/logo.gif http://www.google.com]\n" \
"----\n"                                                                 \
"\n"                                                                     \
" Video youtube, videomotion, veoh, vimeo, flash... embedded:\n"         \
" youtube=http://www.youtube.com/v/---adress--- \n"                       \
" dailymotion=http://www.dailymotion.com/swf/---adress--- \n"             \
" vimeo=http://..... veoh=http://..... flash=http://.....\n"             \
" line starts with youtube... and terminate the adress with a space\n"   \
"----\n"                                                                 \
"\n"                                                                     \
"Unordered lists begin with a '* '. The number of asterisks determines the level:\n" \
"* foo\n"                                                                \
"* bar\n"                                                                \
"** boom\n"                                                              \
"** bam\n"                                                               \
"* baz\n"                                                                \
"\n"                                                                     \
"  * foo\n"                                                              \
"  * bar\n"                                                              \
"  ** boom\n"                                                            \
"  ** bam\n"                                                             \
"  * baz\n"                                                              \
"\n"                                                                     \
"Ordered lists work the same, but use a '#'\n"                           \
"----\n"                                                                 \
"Tables begin the line with a '|' and before every new column after.\n"  \
"\n"                                                                     \
"| row:1,col:1 | row:1,col:2\n"                                          \
"| row:2,col:1 | row:2,col:2\n"                                          \
" | row:1,col:1 | row:1,col:2\n"                                         \
" | row:2,col:1 | row:2,col:2\n"                                         \
"---\n"                                                                  \
"Quotation begins with ' \n"                                             \
"\n"                                                                     \
" 'I had a monumental idea this morning, but I didn't like it\n"         \
"'I had a monumental idea this morning, but I didn't like it\n"          \
"----\n"                                                                 \
"Expand text\n"                                                          \
"\n"                                                                     \
" {{expand}}  or  {{expand=your label here}}\n"                          \
" text, links, images\n"                                                 \
" {{-expand}}\n"                                                         \
"\n"                                                                     \
"{{expand}}\n"                                                           \
"text, links: http://www.google.com\n"                                  \
"{{-expand}}\n"                                                         \
"\nImbricated\n"                                                        \
" {{expand}}\n"                                                         \
" Some text\n"                                                          \
" {{expand}}\n"                                                         \
" More text\n"                                                           \
" {{-expand}}\n"                                                         \
" {{-expand}}\n"                                                         \
"{{expand}}\n"                                                         \
"Some text\n"                                                          \
"{{expand}}\n"                                                         \
"More text\n"                                                           \
"{{-expand}}\n"                                                         \
"{{-expand}}\n"                                                         \
"----\n"                                                                 \
"Collapse text, can be imbricated too.\n"                                    \
"\n"                                                                     \
" {{collapse}}  or  {{collapse=your label here}}\n"                       \
" text, links, images\n"                                                 \
" {{-collapse}}\n"                                                        \
"\n"                                                                     \
"{{collapse}}\n"                                                          \
"text, links: http://www.google.com\n"                                  \
"{{-collapse}}\n"                                                        \
"----\n"                                                                 \
"Simple form: ToDo list\n"                                               \
" {{entry}} or {{entry tiny/small/medium/large/huge date}}\n"            \
" !{{data}}   (remove ! before this tag)\n"                              \
" Entries are added in the page after the tag data\n"                    \
" {{delete}} deletes the selected field\n"                               \
" {{save}} saves the checked fields\n"                                   \
"{{entry}}\n"                                                            \
"{{data}}\n"                                                            \
"{{delete}}{{save}}\n"                                                  \
"----\n"                                                                 \
" Table of contents {{toc}} can be between collapse or expand\n"           \
"{{collapse=Table of contents}}{{toc}}{{-collapse}}\n"                   \
"----\n"                                                                 \
"<Inline> <html> <is> <escaped>.\n"                                      \
"\n"                                                                     \
"----\n"                                                                 \
"Lines prefixed with a space are unformatted ( Like examples on this page )\n" \
"\n"                                                                     \
"----\n"                                                                 \
" There is a `keyword` in this line.\n"                                  \
"There is a `keyword` in this line.\n"                                   \
"\n"                                                                     \
"----\n"                                                                 \

#define STYLESHEET                                                       \
                                                                         \
"body {\n" \
"  font-family: Verdana, Arial, Helvetica, sans-serif;\n" \
"  font-size: 90%;  \n" \
"  color: #333333;\n" \
"  margin: 2px;\n" \
"  padding: 2px;\n" \
"}\n" \
"\n" \
"#header {\n" \
"    font-size: 90%;\n" \
"    background-color: #eef;\n" \
"    border: 1px solid #aaa;\n" \
"    font-family: Verdana, Arial, Helvetica, sans-serif;\n" \
"    padding: 5px;\n" \
"    margin-bottom:20px;\n" \
"}\n" \
"#header input {\n" \
"    margin:0px;\n" \
"    padding: 0;\n" \
"    background-color: White;\n" \
"    border: 1px solid #aaaaaa;\n" \
"    font-size: 90%;\n" \
"}\n" \
"\n" \
"#footer {\n" \
"    font-size: 10px;\n" \
"    color: #ddd;\n" \
"    margin-top:40px;\n" \
"    width: 100%;\n" \
"    text-align: center;\n" \
"}\n" \
"table.wikitable { background-color: #fff; border: 1px solid #aaa; }\n" \
"table.wikitable td { background-color: #fff; border: 1px solid #aaa; }\n" \
"\n" \
"pre {\n" \
"    font-family: monospace;\n" \
"    background-color: #eee;\n" \
"    padding: 2px;\n" \
"    padding-left: 10px;\n" \
"    margin-left: 20px;\n" \
"    margin-right: 20px;\n" \
"}\n" \
"\n" \
"hr {\n" \
" height: 1px;\n" \
" color: #aaaaaa;\n" \
" background-color: #aaaaaa;\n" \
" border: 0;\n" \
" margin: 0.2em 5px 0.2em 5px;\n" \
"}\n" \
"\n" \
"form {\n" \
"    border: none;\n" \
"    margin: 0;\n" \
"}\n" \
"\n" \
"textarea {\n" \
"    border: 1px solid #aaaaaa;\n" \
"    color: Black;\n" \
"    background-color: white;\n" \
"    width: 100%;\n" \
"    padding: 0.1em;\n" \
"    overflow: auto;\n" \
"}\n" \
"\n" \
"input {\n" \
"    margin-top:1px;\n" \
"    padding: 0 0.4em !important;\n" \
"    background-color: White;\n" \
"    border: 1px solid #aaaaaa;\n" \
"}\n" \
"\n" \
"a, ulink{\n" \
"   color: #333;\n" \
"   text-decoration:none;\n" \
"   border-bottom: 1px #333 dotted;\n" \
"   display: inline;\n" \
" }\n" \
"\n" \
"a:hover {\n" \
"   color: #333;\n" \
"   text-decoration: None;\n" \
"   border-bottom: 1px #000 solid;\n" \
"   }\n" \
"\n" \
"a:visited {\n" \
"   color: #333;\n" \
"}\n" \
"\n" \

/* use xdd -i favicon.ico to generate */

unsigned char FaviconData[] = {
	0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x10, 0x10, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xee, 0x00, 0xff, 0xff,
	0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xba, 0xab, 0x00, 0x00, 0x92, 0xab,
	0x00, 0x00, 0xaa, 0x9b, 0x00, 0x00, 0xbb, 0xaf, 0x00, 0x00, 0xba, 0xab,
	0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x8d, 0x1b,
	0x00, 0x00, 0xb5, 0x6b, 0x00, 0x00, 0xb5, 0x6b, 0x00, 0x00, 0xb7, 0x6f,
	0x00, 0x00, 0x8d, 0x1b, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

unsigned int FaviconDataLen = 198;

#endif
