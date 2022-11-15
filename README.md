# MoveCursorInTerminal
Move the cursor in a terminal example


Cursor2.c is my initial version. Generic non CPU specific 'C' code needs a CPU running at 36MHz or more otherwise errors on the display happen because the printf() functions are too slow.

Cursor3.c is my improved version. It replaces some of the printf() functions with calls to a low level serial transmit routine and now the code runs without issues at 18MHz but only on a Z180 CPU. 
