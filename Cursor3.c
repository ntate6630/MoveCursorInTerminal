/* Cursor3 for Z180 */
#include <stdio.h><
#include <conio.h><
#include <sys.h><
#define TSR0 0xC8 /* Receive data register */<
#define TDR0 0xC6  /* Transmit data register */<
#define STAT0 0xC4 /* Status register */<
#define RDRF 7     /* Receive data reg full bit */<
#define TDRE 1     /* Transmit data reg empty */<
void serialTX(char);<
int main(void)<
{<
     char key;<
     int x = 0, y = 2;<
          <
     printf("\x1b[2J");               /* Clear screen */<

     printf("\x1b[%d;%df", x, y);       /* Move cursor to starting position */
<
     while(key != 'q' && key != 'Q')<
     {
         /*      printf("\x1b[0;40f");    */   /* Cursor the top */<
               serialTX(0x1B);<
               serialTX('[');<
               serialTX('0');<
               serialTX(';');<
               serialTX('4');<
               serialTX('0');<
               serialTX('f');<
<
         /*      printf("\x1b[1;37;44m"); */   /* Bright;  White text; Blue BG *
               serialTX(0x1B);<
               serialTX('[');<
               serialTX('1');<
               serialTX(';');<
               serialTX('3');<
               serialTX('7');<
               serialTX(';');<
               serialTX('4');<
               serialTX('4');<
               serialTX('m');<

               printf("x = %3d,   y = %3d", x, y); /* Print coordinates */<
               printf("\x1b[%d;%df", y, x);      /* return to previous position
          /*     printf("\x1b[0m");     */       /* Reset and Show curso[Cr */<
               serialTX(0x1B);<
               serialTX('[');<
               serialTX('0');<
               serialTX('m');<
          while(1)<
          {
               key = getch();<
               if(key == 0x1b || key == '^' || key == '[' || key == '1' || key == '2' || key == '3'
|| key == '4' || key =='5' || key == '6' || key == '7' || key == '8' || key ==
'9' || key == '0')<
                    continue;<
               break;<
          }

          if(key == 'A')<
          {<
       /*       printf("\x1b[A");  */      /* UP */<
               --y;<
               if(y < 2)<
                    y = 2;<
          }<
          if(key == 'B')<
          {<
       /*        printf("\x1b[B");  */      /* DOWN */<
               ++y;<
               if(y > 40)<
                    y = 40;<
          }<
          if(key == 'D')<
          {
        /*       printf("\x1b[D");  */      /* LEFT */<
               --x;<
               if(x < 0)<
                    x = 0;<
          }<
          if(key == 'C')<
          {<
       /*       printf("\x1b[C");   */     /* RIGHT */<
               ++x;<
               if(x > 160)<
                    x = 160;<
          }<
     }<
     printf("\x1b[2J");            /* Clear screen */<
}<
<
void serialTX(char data)<
{<
#asm<
empty:<
          in0       a,(0C4h)<
          bit       1,a<
          jr        z,empty<
#endasm<
          outp(TDR0, data);<
}<
