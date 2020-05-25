#include <glib.h>
#include <ncurses.h>
#include "print_matrix.h"

#define WIDTH 7
#define HEIGHT 5

bool *get_matrix(char c);

void print_matrix_char(char c, int x_offset, int y_offset)
{
  bool *matrix = get_matrix(c);
  for (int y = 0; y < HEIGHT; y++)
  {
    for (int x = 0; x < WIDTH; x++)
    {
      wbkgdset(stdscr, COLOR_PAIR(matrix[x + (y * WIDTH)] + 2));
      mvwaddch(stdscr, y + y_offset, x + x_offset, ' ');
    }
  }
  wrefresh(stdscr);
}

void print_matrix(char *s)
{
  int x_offset = 1;
  static int y_offset = 1;
  for (int i = 0; i < strlen(s); i++)
  {
    print_matrix_char(s[i], x_offset, y_offset);
    x_offset += 8;
  }
  y_offset += 6;
}

bool *get_matrix(char c)
{
  static bool num[WIDTH * HEIGHT];
  switch (c)
  {
  case '-':
    num[0] = 0, num[1] = 0, num[2] = 0, num[3] = 0, num[4] = 0, num[5] = 0, num[6] = 0, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 0, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 0, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 0, num[34] = 0;
    return num;
  case ' ':
    num[0] = 0, num[1] = 0, num[2] = 0, num[3] = 0, num[4] = 0, num[5] = 0, num[6] = 0, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 0, num[15] = 0, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 0, num[20] = 0, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 0, num[34] = 0;
    return num;
  case 'D':
    num[0] = 0, num[1] = 0, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 0, num[6] = 0, num[7] = 0, num[8] = 0, num[9] = 1, num[10] = 0, num[11] = 1, num[12] = 0, num[13] = 0, num[14] = 0, num[15] = 0, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 0, num[20] = 0, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 0, num[34] = 0;
    return num;
  case 'f':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 0, num[20] = 0, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 0, num[34] = 0;
    return num;
  case 's':
    num[0] = 0, num[1] = 0, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 1, num[10] = 1, num[11] = 1, num[12] = 0, num[13] = 0, num[14] = 0, num[15] = 0, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 0, num[20] = 0, num[21] = 0, num[22] = 0, num[23] = 1, num[24] = 1, num[25] = 1, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 0, num[34] = 0;
    return num;
  case 'o':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case 'l':
    num[0] = 1, num[1] = 1, num[2] = 0, num[3] = 0, num[4] = 0, num[5] = 0, num[6] = 0, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 1, num[15] = 1, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 0, num[20] = 0, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case 't':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 1, num[10] = 1, num[11] = 1, num[12] = 0, num[13] = 0, num[14] = 0, num[15] = 0, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 0, num[20] = 0, num[21] = 0, num[22] = 0, num[23] = 1, num[24] = 1, num[25] = 1, num[26] = 0, num[27] = 0, num[28] = 0, num[29] = 0, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 0, num[34] = 0;
    return num;
  case 'e':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 0, num[20] = 0, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case 'm':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 1, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 0, num[17] = 1, num[18] = 0, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 1, num[34] = 1;
    return num;
  case 'p':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 0, num[34] = 0;
    return num;
  case '0':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '1':
    num[0] = 0, num[1] = 0, num[2] = 0, num[3] = 0, num[4] = 0, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 0, num[15] = 0, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 1, num[34] = 1;
    return num;
  case '2':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 0, num[27] = 0, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '3':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '4':
    num[0] = 1, num[1] = 1, num[2] = 0, num[3] = 0, num[4] = 0, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 1, num[34] = 1;
    return num;
  case '5':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '6':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 0, num[13] = 0, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '7':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 0, num[8] = 0, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 0, num[15] = 0, num[16] = 0, num[17] = 0, num[18] = 0, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 1, num[34] = 1;
    return num;
  case '8':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 1, num[22] = 1, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 1, num[29] = 1, num[30] = 1, num[31] = 1, num[32] = 1, num[33] = 1, num[34] = 1;
    return num;
  case '9':
    num[0] = 1, num[1] = 1, num[2] = 1, num[3] = 1, num[4] = 1, num[5] = 1, num[6] = 1, num[7] = 1, num[8] = 1, num[9] = 0, num[10] = 0, num[11] = 0, num[12] = 1, num[13] = 1, num[14] = 1, num[15] = 1, num[16] = 1, num[17] = 1, num[18] = 1, num[19] = 1, num[20] = 1, num[21] = 0, num[22] = 0, num[23] = 0, num[24] = 0, num[25] = 0, num[26] = 1, num[27] = 1, num[28] = 0, num[29] = 0, num[30] = 0, num[31] = 0, num[32] = 0, num[33] = 1, num[34] = 1;
    return num;
  default:
    printf("unknown character %c", c);
    exit(1);
  }
}
