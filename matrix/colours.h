/* Thanks to gon1332 http://stackoverflow.com/users/1814987/gon1332 */

/* This header define a terminal escape codes for text colors */

#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m" 
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
/* Edit by DAMI */
#define FG_DARK_GRAY  "\x1B[90m"
#define FG_LIGHT_RED  "\x1B[91m"
#define FG_LIGHT_GREEN  "\x1B[92m"
#define FG_LIGHT_YELLOW  "\x1B[93m"
#define FG_LIGHT_BLUE  "\x1B[94m"
#define FG_LIGHT_MAGENTA  "\x1B[95m"
#define FG_LIGHT_CYAN  "\x1B[96m"
#define FG_WHITE  "\x1B[97m"
/* end of edit by DAMI */
#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif 