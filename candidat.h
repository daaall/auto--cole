#include <stdbool.h>
struct examen {
	char nom [10];
	float frais;
	bool statut;
};
typedef struct examen examen;

struct candidat {
	char nom [10];
	int num_doss;
	int age;
	float mont_p;
	float mont_r;
	int nb_seances;
	struct examen tab[3];
};
typedef struct candidat candidat; 

