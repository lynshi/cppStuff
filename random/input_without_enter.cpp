#include <termios.h>
#include <cstdio>
#include <unistd.h>

static struct termios old, new_var;

/* Initialize new_var terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new_var = old; /* make new_var settings same as old settings */
    new_var.c_lflag &= ~ICANON; /* disable buffered i/o */
    new_var.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new_var); /* use these new_var terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void)
{
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
    return getch_(1);
}

int main()
{
    char c;
    printf("(getche example) please type a letter: ");
    c = getche();
    printf("\nYou typed: %c\n", c);
    printf("(getch example) please type a letter...");
    c = getch();
    printf("\nYou typed: %c\n", c);
    return 0;
}
