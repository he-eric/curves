#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char **argv ) {

  screen s;
  color c;
  c.red = 255;
  clear_screen( s );
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  //face
  add_edge( edges, 70, 290, 0, 105, 360, 0);
  add_circle( edges, 130, 300, 150, .01 );
  add_circle( edges, 170, 325, 15, .01 );
  add_circle( edges, 140, 275, 15, .01 );
  add_curve( edges, 83, 250, 150, 150, 145, 365, 10, 10, .01, 0 );
  add_curve( edges, 83, 250, 50, 50, 145, 365, 5, 5, .01, 0 );
  //face
  add_circle( edges, 350, 0, 150, .01 );
  add_circle( edges, 310, 50, 15, .01 );
  add_circle( edges, 370, 50, 15, .01 );
  add_curve( edges, 290, 0, 150, 150, 400, 0, 10, 10, .01, 0 );
  add_curve( edges, 290, 0, 50, 50, 400, 0, 5, 5, .01, 0 );
  
  int i = 0;
  for (i = 0; i < 35; i++) {
    add_curve( edges, i*10, i*20, 150, 50, 300, 250, 300, 250, .01, 1 );
    add_curve( edges, 200, 250, i*10, i*20, 300, 250, 300, 250, .01, 1 );
    add_curve( edges, 200, 250, 150, 50, i*10, i*20, 300, 250, .01, 1 );
    add_curve( edges, 200, 250, 150, 50, 300, 250, i*10, i*20, .01, 1 );
  }
  
  //add_curve( edges, 150, 150, 150, 50, 350, 150, 350, 300, .01, 0 );
  draw_lines( edges, s, c );
  display( s );
  save_extension(s, "line.png");

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  free_matrix( transform );
  free_matrix( edges );
}
