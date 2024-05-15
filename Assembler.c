#include "PhaseZero.h"
#include "PhaseSecond.h"


/* According to the lecturer, it can be assumed that all the received files have an 'as' extension  */
int main(int argc, char **argv) {
    /* each cell of the markValues array represent a flag (5 cell - ICcounter, DCcounter, EX, EN, ERROR ) */
    int markValues[FLAGS] = {NON, NON, NON, NON, NON};
    GeneralList symbolList = NULL;
    int i;
    if (argc < 2) {
        printf("Error - Invalid number of arguments\n");
        return FALSE;
    }
    for (i = 1; i < argc; i++) {
        if (!SearchAndAddMcr(argv[i]))/* layout of all existing macros */
            continue;
        symbolList = firstPass(argv[i],
                               markValues); /* checking the validation of the file and create a symbolList*/
        if (markValues[ERROR] == EXIST)
            continue;
        encodingSecondPass(argv[i], &symbolList,
                           markValues);
        /* when the file is valid, encoding it in spacial binary */
        freelist(symbolList);
    }
    return FALSE;
}

