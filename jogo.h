#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

    void jouer(SDL_Surface* ecran);
    void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction);
    void deplacerCaisse(int *premiereCase, int *secondeCase);


#endif // JOGO_H_INCLUDED
