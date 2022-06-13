#ifndef __colors__
#define __colors__

#ifdef _WIN32
#include <windows.h>

#else
#define TNRM  "\x1B[0m"
#define TGRY  "\x1B[30;1m"
#define TRED  "\x1B[31m"
#define TBRED  "\x1B[31;1m"
#define TGRN  "\x1B[32m"
#define TBGRN  "\x1B[32;1m"
#define TYEL  "\x1B[33m"
#define TBYEL  "\x1B[33;1m"
#define TBLU  "\x1B[34m"
#define TBBLU  "\x1B[34;1m"
#define TMAG  "\x1B[35m"
#define TBMAG  "\x1B[35;1m"
#define TCYN  "\x1B[36m"
#define TBCYN  "\x1B[36;1m"
#define TWHT  "\x1B[37m"
#define TBWHT  "\x1B[37;1m"

#define SGRY  "\x1B[30;1;100m"
#define SRED  "\x1B[31;41m"
#define SBRED  "\x1B[31;1;101m"
#define SGRN  "\x1B[32;42m"
#define SBGRN  "\x1B[32;1;102m"
#define SYEL  "\x1B[33;43m"
#define SBYEL  "\x1B[33;1;103m"
#define SBLU  "\x1B[34m;44"
#define SBBLU  "\x1B[34;1;104m"
#define SMAG  "\x1B[35;45m"
#define SBMAG  "\x1B[35;1;105m"
#define SCYN  "\x1B[36;46m"
#define SBCYN  "\x1B[36;1;106m"
#define SWHT  "\x1B[37;47m"
#define SBWHT  "\x1B[37;1;107m"

#endif

enum systemColors
{
    RED = 1,
    GREEN,
    BLUE,
    MAGENTA,
    YELLOW,
    BLACK,
    WHITE
};

#endif