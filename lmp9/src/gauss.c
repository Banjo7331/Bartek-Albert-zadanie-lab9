#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
	int l= mat->r;
	/*zmiany w funkcji eliminacji*/
	for( int k= 0; k < l-1; k++ ) {
		int najw = k;
		for( int w = k+1; w < l; w++ )
			if( fabs(mat->data[w][k]) > fabs(mat->data[najw][k]) )
				najw = w;
		if( najw != k ) {
			double *tmp = mat->data[k];
      mat->data[k] = mat->data[najw];
			mat->data[najw] = tmp;
      double tmp2 = b->data[k][0];
      b->data[k][0] = b->data[najw][0];
      b->data[najw][0] = tmp2;
		}
		for( int w= k+1; w < l; w++ ) {
       if( mat->data[k][k] == 0 )
          return 1;
       double m = mat->data[w][k] / mat->data[k][k];
       for( int i= k; i < l; i++ )
				 mat->data[w][i] -= m * mat->data[k][i];
       b->data[w][0] -= m * b->data[k][0];
		}
	}

		return 0;
}

