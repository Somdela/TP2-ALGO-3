#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct elt {
    int priorite;
    char donnee;
} element;

typedef element Pile[MAX];
Pile p;

int sommet;

void initialisation() {
    sommet = -1;
}

int pile_vide() {
    return (sommet == -1);
}

int pile_pleine() {
    return (sommet >= MAX - 1);
}

// Ajouter dans un ordre quelconque
void ajouter_ordre_qlc(element x) {
    if (pile_pleine()) {
        printf("La pile est pleine\n");
    } else {
        sommet++;
        p[sommet] = x;
    }
}

// Chercher la position de l'élément le plus prioritaire
int chercher_elt_plusPrioritaire() {
    int Max = -1, pos = -1, indice = sommet;
    element x;
    while (indice >= 0) {
        x = p[indice];
        if (x.priorite > Max) {
            Max = x.priorite;
            pos = indice;
        }
        indice--;
    }
    return pos;
}

element retirer_ordre_qlc() {
    int j, i, indice;
    element t, x, tab[MAX];
    if (pile_vide()) {
        printf("La pile est vide\n");
        exit(1);
    } else {
        indice = chercher_elt_plusPrioritaire();
        i = -1;
        while (sommet != indice) {
            x = p[sommet];
            sommet--;
            i++;
            tab[i] = x;
        }
        t = p[sommet]; // Le sommet = indice de l'élément le plus prioritaire
        sommet--;
        for (j = i; j >= 0; j--) {
            ajouter_ordre_qlc(tab[j]); // Remettre les éléments retirés dans le même ordre
        }
        return t;
    }
}

// Ajouter les éléments par ordre de priorité croissante
void ajouter_ordre(element x) {
    element y;
    int i, j = -1, trouve = 1;
    element tab[MAX];
    if (pile_pleine()) {
        printf("Stack overflow : dépassement de la capacité\n");
    } else {
        if (pile_vide()) {
            sommet++;
            p[sommet] = x;
        } else {
            while ((!pile_vide()) && (trouve == 1)) {
                y = p[sommet];
                if (x.priorite < y.priorite) {
                    j++;
                    tab[j] = y;
                    sommet--;
                } else {
                    trouve = 0;
                }
            }
            sommet++;
            p[sommet] = x; // Ajouter l'élément x
            for (i = j; i >= 0; i--) {
                sommet++;
                p[sommet] = tab[i];
            }
        }
    }
}

void afficher() {
    int i;
    if (pile_vide()) {
        printf("La pile est vide\n");
    } else {
        for (i = 0; i <= sommet; i++) {
            printf("%d , %c\n", p[i].priorite, p[i].donnee);
        }
    }
}

int main() {
    element elt1, t;
    int N, i, d;
    initialisation();
    printf("Choisir N : ");
    scanf("%d", &N);
    printf("1.) Ajouter dans un ordre quelconque\n2.) Ajouter dans un ordre\n");
    scanf("%d", &d);
    if (d == 1) {
        printf("Ajouter les elements de la Pile dans un ordre quelconque:\n");
        for (i = 0; i < N; i++) {
            printf("Entrez la priorite de l'element %d : ", i + 1);
            scanf("%d", &elt1.priorite);
            printf("Entrez la donnee de l'element %d : ", i + 1);
            scanf(" %c", &elt1.donnee);
            ajouter_ordre_qlc(elt1);
        }
        printf("Retirer l'element le plus prioritaire\n");
        t = retirer_ordre_qlc();
        afficher();
        printf("L'element le plus prioritaire est : %d , %c\n", t.priorite, t.donnee);
    } else if (d == 2) {
        printf("Ajouter les elements de la Pile dans un ordre :\n");
        for (i = 0; i < N; i++) {
            printf("Entrez la priorite de l'element %d : ", i + 1);
            scanf("%d", &elt1.priorite);
            printf("Entrez la donnee de l'element %d : ", i + 1);
            scanf(" %c", &elt1.donnee);
            ajouter_ordre(elt1);
        }
        afficher();
    } else {
        printf("Le choix est errone\n");
    }
    return 0;
}

