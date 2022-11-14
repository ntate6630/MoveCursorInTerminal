/* Cursor control example */
#include <stdio.h><
#include <conio.h><
<
int main(void)<
{<
     char key;<
     int x = 0, y = 2;<
          <
     printf("\x1b[2J");               /* Clear screen */<

     printf("\x1b[%d;%df", x, y);       /* Move cursor to starting position */
<
     while(key != 'q' && key != 'Q')<
     {<
          printf("\x1b[8;1;37;44m"); /* Hide cursor; Bright;  White text; Blue Background */
          printf("\x1b[0;40f");          /* Cursor to top left */<
          printf("x = %3d,   y = %3d", x, y); /* Print coordinates */<
          printf("\x1b[%d;%df", y, x);      /* return to previous position */<
          printf("\x1b[0m");                 /* Show cursor */<
          while(1)<
          {
               key = getch();<
               if(key == 0x1b || key == '^' || key == '[' || key == '1' || key = '2' || key == '3'
|| key == '4' || key =='5' || key == '6' || key == '7' || key == '8' || key ==
'9' || key == '0')<
                    continue;<
               break;<
          }

          if(key == 'A')<
          {<
               printf("\x1b[A");        /* UP */<
               --y;<
               if(y < 2)<
                    y = 2;<
          }<
          if(key == 'B')<
          {<
               printf("\x1b[B");        /* DOWN */<
               ++y;<
               if(y > 40)<
                    y = 40;<
          }<
          if(key == 'D')<
          {
               printf("\x1b[D");        /* LEFT */<
               --x;<
               if(x < 0)<
                    x = 0;<
          }<
          if(key == 'C')<
          {<
               printf("\x1b[C");        /* RIGHT */<
               ++x;<
               if(x > 160)<
                    x = 160;<
          }<
     }<
     printf("\x1b[2J");            /* Clear screen */         <
}<
