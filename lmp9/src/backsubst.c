#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	/**
	 * Tutaj należy umieścić właściwą implemntację.
	 */

	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

	int i, j;
	if (mat->r!=mat->c)
		return 2;
	for (i = x->r - 1; i >= 0; i--)
	{
		x->data[i][0] = b->data[i][0];
		for (j = 0; j < x->r - 1 - i; j++)
			x->data[i][0] -= x->data[x->r - 1 - j][0] * mat->data[i][x->r - 1 - j];
		if (mat->data[i][i]==0)
			return 1;
		x->data[i][0] /= mat->data[i][i];
	}

	return 0;
}
