#include "../lib/base_struct.h"
#include "../lib/fonc.h"


/**
 * @struct heroText_s
 * @brief Structure représentant la texture et la position d'un héros.
 */
typedef struct heroText_s {
	SDL_Texture *texture; /**< La texture du héros. */
	SDL_Rect rectHero;    /**< La position et la taille du héros. */
} heroText_t;

/**
 * @brief Affiche le montant d'argent et une texture donnée à l'écran.
 * 
 * @param renderer Le renderer SDL.
 * @param hauteur La hauteur de l'écran.
 * @param largeur La largeur de l'écran.
 * @param texte La texture à afficher.
 */
void affiche_argent(SDL_Renderer *renderer,int hauteur,int largeur,SDL_Texture *texte){
	SDL_Texture *argent;
	SDL_Rect position;
	argent=loadImage("../img/euro.png",renderer);

	position.x = largeur-20;
	position.y = 10;
	SDL_QueryTexture(argent, NULL, NULL,&(position.w),&(position.h));
	position.w/=25;
	position.h/=25;
	SDL_RenderCopy(renderer, argent,NULL, &position);


	SDL_QueryTexture(texte, NULL, NULL,&(position.w),&(position.h));
	position.x = position.x-position.w;
	position.y = 0;
	SDL_RenderCopy(renderer, texte,NULL, &position);



	SDL_DestroyTexture(argent);
}

ennemie_t * avancerEnnemie(ennemie_t ** ennemie , int nbEnnemie,int indice){
		if(indice == 0){
			ennemie[indice]->imgDestRectEnnemie.x += 1;
		}
		else if(indice > 0){
			ennemie[indice]->imgDestRectEnnemie.x = ennemie[indice-1]->imgDestRectEnnemie.x - ennemie[indice]->imgDestRectEnnemie.w;
		}
	return ennemie[indice];
}

int detruireLesHeros(ennemie_t ** ennemie , int indice , int nbMax){
		ennemie_t * temp;

		temp = ennemie[indice];

		
		ennemie[nbMax-1] = temp;

		for(int i = 0 ; i < nbMax-1 ; i++){
			ennemie[i] = ennemie[i+1];
		}
		detruireEnem(&ennemie[nbMax-1]);
		ennemie[nbMax-1] = NULL;

		return nbMax;
}



void afficherText(SDL_Renderer * renderer ,SDL_Texture *background,SDL_Texture *hud,SDL_Texture *texte,SDL_Texture *case1,SDL_Texture *case2,SDL_Texture *case3,SDL_Texture *pause,SDL_Texture *textHero1,SDL_Texture *textHero2
				,SDL_Rect txtDestRect,SDL_Rect imgDestRect,SDL_Rect imgDestRect2,SDL_Rect imgDestRectCase1,SDL_Rect imgDestRectCase2,SDL_Rect imgDestRectCase3,SDL_Rect imgDestRectpause,heroText_t **lesHeros, int nbCaseUse ){

		SDL_RenderClear(renderer);
		//image de fond
		imgDestRect.x = 0;
		imgDestRect.y = 0;
		SDL_QueryTexture(background, NULL, NULL,&(imgDestRect.w),&(imgDestRect.h));
		SDL_RenderCopy(renderer, background, NULL, NULL);
		//HUD tout moche
		imgDestRect2.x = 0;
		imgDestRect2.y = HEIGHTSCREEN-200;
		SDL_QueryTexture(hud, NULL, NULL,&(imgDestRect2.w),&(imgDestRect2.h));
		SDL_SetTextureBlendMode(hud,SDL_BLENDMODE_ADD);
		SDL_RenderCopy(renderer, hud,NULL, &imgDestRect2);
		//Case1
		imgDestRectCase1.x = 50;
		imgDestRectCase1.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case1,NULL, NULL,&(imgDestRectCase1.w),&(imgDestRectCase1.h));
		SDL_RenderCopy(renderer, case1,NULL, &imgDestRectCase1);
		//Case2
		imgDestRectCase2.x = 300;
		imgDestRectCase2.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case2,NULL, NULL,&(imgDestRectCase2.w),&(imgDestRectCase2.h));
		SDL_RenderCopy(renderer, case2,NULL, &imgDestRectCase2);
		//Case3
		imgDestRectCase3.x = 550;
		imgDestRectCase3.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case3,NULL, NULL,&(imgDestRectCase3.w),&(imgDestRectCase3.h));
		SDL_RenderCopy(renderer, case3,NULL, &imgDestRectCase3);
		//bouton pause
		imgDestRectpause.x = 5;
		imgDestRectpause.y = 5;
		imgDestRectpause.w = 30;
		imgDestRectpause.h = 30;
		SDL_RenderCopy(renderer, pause,NULL, &imgDestRectpause);

		if(nbCaseUse - 1 >= 0){
		SDL_QueryTexture(lesHeros[nbCaseUse-1]->texture,NULL, NULL,&(lesHeros[nbCaseUse-1]->rectHero.w),&(lesHeros[nbCaseUse-1]->rectHero.h));
				int parcoursTab = 0;
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
				if(nbCaseUse >= 2){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 3){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 4){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 5){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 6){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 7){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 8){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 9){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 10){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				
		}
}

int appelTextEnnemie(SDL_Renderer * renderer, SDL_Texture *texture , SDL_Rect * drect , int *w,int * h,SDL_Texture *background,SDL_Texture *hud,SDL_Texture *texte,SDL_Texture *case1,SDL_Texture *case2,SDL_Texture *case3,SDL_Texture *pause,SDL_Texture *textHero1,SDL_Texture *textHero2
				,SDL_Rect txtDestRect,SDL_Rect imgDestRect,SDL_Rect imgDestRect2,SDL_Rect imgDestRectCase1,SDL_Rect imgDestRectCase2,SDL_Rect imgDestRectCase3,SDL_Rect imgDestRectpause,heroText_t **lesHeros, int nbCaseUse ){
	SDL_QueryTexture(texture,NULL, NULL,w,h);
	SDL_RenderCopy(renderer, texture,NULL, drect);
}

ennemie_t * avancerHorizontal(ennemie_t ** ennemie , int nbEnnemie,int indice,int indiceChemin,coord_t * coord){
		if(indice == 0){
			
			if(((WIDTHSCREEN/ABS)*coord[indiceChemin+1].x + (WIDTHSCREEN/ABS)/4) < ennemie[indice]->imgDestRectEnnemie.x){
				ennemie[indice]->imgDestRectEnnemie.x -= 1;
			}
			else if(((WIDTHSCREEN/ABS)*coord[indiceChemin+1].x + (WIDTHSCREEN/ABS)/4) > ennemie[indice]->imgDestRectEnnemie.x){
				ennemie[indice]->imgDestRectEnnemie.x += 1;
			}
		else if(indice > 0){
			ennemie[indice]->imgDestRectEnnemie.x = ennemie[indice-1]->imgDestRectEnnemie.x - ennemie[indice]->imgDestRectEnnemie.w;
		}
	return ennemie[indice];
}
}

ennemie_t * avancerVertical(ennemie_t ** ennemie , int nbEnnemie,int indice,int indiceChemin,coord_t * coord){
		if(indice == 0){
			if(((HEIGHTSCREEN-200)/ORD)*coord[indiceChemin+1].y + ((HEIGHTSCREEN-200)/ORD)/4 < ennemie[indice]->imgDestRectEnnemie.y){
				ennemie[indice]->imgDestRectEnnemie.y -= 1;
			}
			else if(((HEIGHTSCREEN-200)/ORD)*coord[indiceChemin+1].y + ((HEIGHTSCREEN-200)/ORD)/4 > ennemie[indice]->imgDestRectEnnemie.y){
				ennemie[indice]->imgDestRectEnnemie.y += 1;
			}
		else if(indice > 0){
			ennemie[indice]->imgDestRectEnnemie.y = ennemie[indice-1]->imgDestRectEnnemie.y - ennemie[indice]->imgDestRectEnnemie.h;
		}
	return ennemie[indice];
}
}

int detruireLesHeros(ennemie_t ** ennemie , int indice , int nbMax){
		ennemie_t * temp;

		temp = ennemie[indice];

		
		ennemie[nbMax-1] = temp;

		for(int i = 0 ; i < nbMax-1 ; i++){
			ennemie[i] = ennemie[i+1];
		}
		detruireEnem(&ennemie[nbMax-1]);
		ennemie[nbMax-1] = NULL;

		return nbMax;
}


int appelTextEnnemie(SDL_Renderer * renderer, SDL_Texture *texture , SDL_Rect * drect , int *w,int * h){
	SDL_QueryTexture(texture,NULL, NULL,w,h);
	SDL_RenderCopy(renderer, texture,NULL, drect);
}


/**
 * @brief La boucle principale du jeu.
 * 
 * @param renderer Le renderer SDL.
 * @param window La fenêtre SDL.
 * @return int Retourne 0 en cas de réussite.
 */
int jeu(SDL_Renderer *renderer,SDL_Window *window)
{
    //Le pointeur vers la fenetre
	//Le pointeur vers la surface incluse dans la fenetre
	SDL_Rect txtDestRect,imgDestRect,imgDestRect2,imgDestRectCase1,imgDestRectCase2,imgDestRectCase3,imgDestRectpause;
<<<<<<< HEAD
	SDL_Texture *background = NULL,*hud=NULL,*texte=NULL ,*case1=NULL,*case2=NULL,*case3=NULL,*pause=NULL,*textHero1=NULL,*textHero2=NULL,*textHero3=NULL,*textEnnemie;
=======
	SDL_Texture *background = NULL,*hud=NULL,*texte=NULL ,*case1=NULL,*case2=NULL,*case3=NULL,*pause=NULL,*textHero1=NULL,*textHero2=NULL,*textHero3=NULL,*textEnnemie=NULL;
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
	// Le pointeur vers notre police
  	int tab[ABS][ORD];
	int largeur,hauteur;
	int map=0;
  	chemin_t suite;
	char nb_argent[20];
	if(map==0){
		suite=creation_map(renderer,tab);
		map=1;
	}
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};
	tabCase_t * tabHero = malloc(sizeof(tabCase_t));
	for (int i = 0 ; i < MAXHERO ;i ++){
		tabHero->tab[i] = malloc(sizeof(hero_t));
	}

	heroText_t * lesHeros[MAXHERO];
	for(int tailleTab = 0 ; tailleTab < MAXHERO ; tailleTab++){
		lesHeros[tailleTab] = malloc(sizeof(heroText_t));
	}
	
	int indice = 0;

<<<<<<< HEAD
	int delay = 10;

	int nbCaseUse = 0;
=======
	int indice = 0;

	int delay = 10;

>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
	int * tailleCaseY = 0;
	int caseHero = 0;
	
	hero_t * hero1 = malloc(sizeof(hero_t));
	hero_t * hero2 = malloc(sizeof(hero_t));
	hero_t * hero3 = malloc(sizeof(hero_t));

	int etat = 1;

	player_t * joueur = malloc(sizeof(player_t));

	joueur = initialise_joueur();

	hero1 = initialise_hero(0);
	hero2 = initialise_hero(1);
	hero3 = initialise_hero(2);

<<<<<<< HEAD
	// load sample.png into image (FOND)
	background=loadImage("../img/map_v1.png",renderer);

=======
	int indiceChemin = 0;

	background=loadImage("../img/map_pixel_v2.png",renderer);
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
	hud=loadImage("../img/HUD.png",renderer);

// load sample.png into image (CASE 1)
	case1=loadImage("../img/1.png",renderer);

// load sample.png into image (CASE 2)
	case2=loadImage("../img/2.png",renderer);

// load sample.png into image (CASE 3)
	case3=loadImage("../img/3.png",renderer);

// load sample.png into image (pause)
	pause=loadImage("../img/pause.png",renderer);
// load lehero.png inti impage (HERO1)
	textHero1=loadImage("../img/sprite/Hero1.png",renderer);
// load lehero.png inti impage (HERO2)
	textHero2=loadImage("../img/sprite/Hero2.png",renderer);
// load lehero.png inti impage (HERO3)
	textHero3=loadImage("../img/lehero.png",renderer);

	textEnnemie = loadImage("../img/sprite/ennemie.png",renderer);

	int nbEnnemie = 10;

	ennemie_t * temp;

	ennemie_t * tabEnnemie[nbEnnemie];

		tabEnnemie[0] = malloc(sizeof(ennemie_t));
		tabEnnemie[0]->texture = textEnnemie;
		tabEnnemie[0]->imgDestRectEnnemie.x = 0;
		tabEnnemie[0]->imgDestRectEnnemie.y =200;
		tabEnnemie[0]->sensX = 0;
		tabEnnemie[0]->sensY = 0;

		for(int i = nbEnnemie - (nbEnnemie -1); i < nbEnnemie ; i++){
			tabEnnemie[i] = NULL;
		}

	int palierX = 0;
	
	textEnnemie = loadImage("../img/sprite/ennemie.png",renderer);
	int nbEnnemie = 1;

	ennemie_t * temp;

	ennemie_t * tabEnnemie[nbEnnemie];

	tabEnnemie[0] = malloc(sizeof(ennemie_t));
	tabEnnemie[0]->texture = textEnnemie;
	tabEnnemie[0]->imgDestRectEnnemie.x = (WIDTHSCREEN/ABS)*suite.chemin[0].x + (WIDTHSCREEN/ABS)/4;
	tabEnnemie[0]->imgDestRectEnnemie.y = ((HEIGHTSCREEN-200)/ORD)*suite.chemin[0].y + ((HEIGHTSCREEN-200)/ORD)/4;
	
	for(int i = nbEnnemie - (nbEnnemie -1); i < nbEnnemie ; i++){
		tabEnnemie[i] = NULL;
	}

	int palierX = 0;
	
	int running = 1; 
	while(running) { 
		SDL_Event e;
		SDL_GetWindowSize(window,&largeur,&hauteur);
		imgDestRect.x=0;
		imgDestRect.y=0;
		imgDestRect.h=hauteur-200;
		imgDestRect.w=largeur;
		SDL_RenderCopy(renderer, background,NULL, &imgDestRect);
<<<<<<< HEAD
		
		SDL_RenderClear(renderer);
		//image de fond
		imgDestRect.x = 0;
		imgDestRect.y = 0;
		SDL_QueryTexture(background, NULL, NULL,&(imgDestRect.w),&(imgDestRect.h));
		SDL_RenderCopy(renderer, background, NULL, NULL);
=======

		affiche_map_2(tab,renderer,window);
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
		//HUD tout moche
		imgDestRect2.x = 0;
		imgDestRect2.y = HEIGHTSCREEN-200;
		SDL_QueryTexture(hud, NULL, NULL,&(imgDestRect2.w),&(imgDestRect2.h));
		SDL_SetTextureBlendMode(hud,SDL_BLENDMODE_ADD);
		SDL_RenderCopy(renderer, hud,NULL, &imgDestRect2);
		//Case1
		imgDestRectCase1.x = 50;
		imgDestRectCase1.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case1,NULL, NULL,&(imgDestRectCase1.w),&(imgDestRectCase1.h));
		SDL_RenderCopy(renderer, case1,NULL, &imgDestRectCase1);
		//Case2
		imgDestRectCase2.x = 300;
		imgDestRectCase2.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case2,NULL, NULL,&(imgDestRectCase2.w),&(imgDestRectCase2.h));
		SDL_RenderCopy(renderer, case2,NULL, &imgDestRectCase2);
		//Case3
		imgDestRectCase3.x = 550;
		imgDestRectCase3.y = HEIGHTSCREEN-155;
		SDL_QueryTexture(case3,NULL, NULL,&(imgDestRectCase3.w),&(imgDestRectCase3.h));
		SDL_RenderCopy(renderer, case3,NULL, &imgDestRectCase3);
		//bouton pause
		imgDestRectpause.x = 5;
		imgDestRectpause.y = 5;
		imgDestRectpause.w = 30;
		imgDestRectpause.h = 30;
		SDL_RenderCopy(renderer, pause,NULL, &imgDestRectpause);

		if(nbCaseUse - 1 >= 0){
<<<<<<< HEAD
		SDL_QueryTexture(lesHeros[nbCaseUse-1]->texture,NULL, NULL,&(lesHeros[nbCaseUse-1]->rectHero.w),&(lesHeros[nbCaseUse-1]->rectHero.h));
				int parcoursTab = 0;
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
				if(nbCaseUse >= 2){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 3){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 4){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 5){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 6){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 7){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 8){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 9){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
				if(nbCaseUse >= 10){
					SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
					parcoursTab++;
				}
		}

		affiche_map_2(tab,renderer,window);
				
				for(indice = 0; indice < nbEnnemie ; indice++){
					if(tabEnnemie[indice] != NULL){	
						if(tabEnnemie[indice]->imgDestRectEnnemie.x < WIDTHSCREEN-tabEnnemie[indice]->imgDestRectEnnemie.w){
							tabEnnemie[indice] = avancerEnnemie(tabEnnemie,nbEnnemie,indice);
						}
						if(tabEnnemie[indice]->imgDestRectEnnemie.x > tabEnnemie[indice]->imgDestRectEnnemie.w){
							if(tabEnnemie[indice+1]== NULL && indice < nbEnnemie-1){
								tabEnnemie[indice+1] = malloc(sizeof(ennemie_t));
								tabEnnemie[indice+1]->texture = textEnnemie;
								tabEnnemie[indice+1]->imgDestRectEnnemie.x = 0;
								tabEnnemie[indice+1]->imgDestRectEnnemie.y = 200;
								tabEnnemie[indice+1]->sensX = 0;
								tabEnnemie[indice+1]->sensY = 0;
							}
						}
						if(tabEnnemie[indice]->imgDestRectEnnemie.x == WIDTHSCREEN-tabEnnemie[indice]->imgDestRectEnnemie.w){
							if(tabEnnemie[indice]!=NULL){					
							
								for(int j = 0 ; j < nbEnnemie-1 ; j++){
									tabEnnemie[j] = tabEnnemie[j+1];
								}
								nbEnnemie--;
								tabEnnemie[nbEnnemie]=NULL;
							}


						}
					}
					SDL_Delay(2);
					if(tabEnnemie[indice] != NULL){
					appelTextEnnemie(renderer,tabEnnemie[indice]->texture,&tabEnnemie[indice]->imgDestRectEnnemie,&tabEnnemie[indice]->imgDestRectEnnemie.w,&tabEnnemie[indice]->imgDestRectEnnemie.h,background,hud,texte,case1,case2,case3,pause,textHero1,textHero2,txtDestRect,imgDestRect,imgDestRect2,imgDestRectCase1,imgDestRectCase2,imgDestRectCase3,imgDestRectpause,lesHeros,nbCaseUse);
					}
			
				}
				SDL_RenderPresent(renderer);

		SDL_RenderPresent(renderer); //Taille fenetre 1847 / 1015
		while(SDL_PollEvent(&e)) { 
			switch(e.type) { 
				case SDL_QUIT: running = 0; 
				break; 
=======
			SDL_QueryTexture(lesHeros[nbCaseUse-1]->texture,NULL, NULL,&(lesHeros[nbCaseUse-1]->rectHero.w),&(lesHeros[nbCaseUse-1]->rectHero.h));
			int parcoursTab = 0;
			SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
			parcoursTab++;
			if(nbCaseUse >= 2){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 3){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 4){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 5){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 6){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 7){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 8){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 9){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
			if(nbCaseUse >= 10){
				SDL_RenderCopy(renderer, lesHeros[parcoursTab]->texture,NULL, &lesHeros[parcoursTab]->rectHero);
				parcoursTab++;
			}
				
		}

		SDL_itoa(joueur->argent,nb_argent,10);
		texte=load_text(renderer,nb_argent,30);
		affiche_argent(renderer,hauteur,largeur,texte);
		SDL_Log("ICI 1 ");
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
				
				for(indice = 0; indice < nbEnnemie ; indice++){
					SDL_Log(" %d ",indiceChemin);
					if(tabEnnemie[indice] != NULL){	
						if(suite.chemin[indiceChemin].x != suite.chemin[indiceChemin+1].x){
							if(tabEnnemie[indice]->imgDestRectEnnemie.x < WIDTHSCREEN-tabEnnemie[indice]->imgDestRectEnnemie.w){
								tabEnnemie[indice] = avancerHorizontal(tabEnnemie,nbEnnemie,indice,indiceChemin,suite.chemin);
							}
						}
						else if(suite.chemin[indiceChemin].y != suite.chemin[indiceChemin+1].y){
							if(tabEnnemie[indice]->imgDestRectEnnemie.y < WIDTHSCREEN-tabEnnemie[indice]->imgDestRectEnnemie.h){
								tabEnnemie[indice] = avancerVertical(tabEnnemie,nbEnnemie,indice,indiceChemin,suite.chemin);
							}
						}

						if((tabEnnemie[indice]->imgDestRectEnnemie.x == (WIDTHSCREEN/ABS)*suite.chemin[indiceChemin+1].x + (WIDTHSCREEN/ABS)/4) && (tabEnnemie[indice]->imgDestRectEnnemie.y == (((HEIGHTSCREEN-200)/ORD))*suite.chemin[indiceChemin+1].y + (((HEIGHTSCREEN-200)/ORD)/4))){
							indiceChemin++;
							if(tabEnnemie[indice]->imgDestRectEnnemie.x == (suite.chemin[indiceChemin+1].x != -1)  && tabEnnemie[indice]->imgDestRectEnnemie.y == (suite.chemin[indiceChemin+1].y != -1)){
								SDL_Log(" Ca devrait etre detruit la ");
							}			
						}
					}

					if(tabEnnemie[indice]->imgDestRectEnnemie.x > tabEnnemie[indice]->imgDestRectEnnemie.w || tabEnnemie[indice]->imgDestRectEnnemie.y > tabEnnemie[indice]->imgDestRectEnnemie.h){
						if(tabEnnemie[indice+1]== NULL && indice < nbEnnemie-1){
							tabEnnemie[indice+1] = malloc(sizeof(ennemie_t)); 
							tabEnnemie[indice+1]->texture = textEnnemie;
							tabEnnemie[indice+1]->imgDestRectEnnemie.x = (WIDTHSCREEN/ABS)*suite.chemin[0].x + (WIDTHSCREEN/ABS)/4;
							tabEnnemie[indice+1]->imgDestRectEnnemie.y = ((HEIGHTSCREEN-200)/ORD)*suite.chemin[0].y + (((HEIGHTSCREEN-200)/ORD)/4);
						}
					}
					
					
					SDL_Log("Le max en X et Y est : %d | %d ",suite.chemin[indiceChemin+1].x,suite.chemin[indiceChemin+1].y);
					if(suite.chemin[indiceChemin+1].x == -1 && suite.chemin[indiceChemin+1].y == -1){
						if(tabEnnemie[indice]!=NULL){					
						
							for(int j = 0 ; j < nbEnnemie-1 ; j++){
								tabEnnemie[j] = tabEnnemie[j+1];
							}
							nbEnnemie--;
							tabEnnemie[nbEnnemie]=NULL;
						}
					}
					SDL_Delay(5);
					if(tabEnnemie[indice] != NULL){
					appelTextEnnemie(renderer,tabEnnemie[indice]->texture,&tabEnnemie[indice]->imgDestRectEnnemie,&tabEnnemie[indice]->imgDestRectEnnemie.w,&tabEnnemie[indice]->imgDestRectEnnemie.h);
					}
			
				}

				SDL_Log("ICI 2 ");
		SDL_RenderPresent(renderer); //Taille fenetre 1847 / 1015
		while(SDL_PollEvent(&e)) { 
			switch(e.type) { 
				case SDL_QUIT: running = 0; 
				break; 
					
						
								
			if (e.window.event == SDL_WINDOWEVENT_CLOSE)
				running = SDL_FALSE;
				break;
				case SDL_KEYDOWN:
					SDL_Log("+key");
					break;
				case SDL_KEYUP: // Événement de relâchement d'une touche clavier
					if ( e.key.keysym.sym == SDLK_ESCAPE ) // C'est la touche Échap
					{
						SDL_Log("PAUSE");
						switch(param(renderer,window,largeur,hauteur,background)){
							case 0:running=SDL_FALSE;break;
							case 2:SDL_GetWindowSize(window,&largeur,&hauteur);break;
							case 1:
							largeur=WIDTHSCREEN;
							hauteur=HEIGHTSCREEN;
							break;
						}
					}
						break;
					SDL_Log("-key");
					break;
				case SDL_MOUSEMOTION: // Déplacement de souris
				//SDL_Log("Mouvement de souris (%d %d) (%d %d)", e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
					break;
				case SDL_MOUSEBUTTONDOWN: // Click de souris 
					if(e.button.y < imgDestRect2.y || e.button.y > imgDestRect2.y + imgDestRect2.h){
						etat =1;;
						switch(caseHero){
							case 1:
								lesHeros[nbCaseUse]->texture = textHero1;
								for(int indice = 0 ; indice < nbCaseUse ; indice++){
									if(((e.button.x > tabHero->tab[indice]->coordX - (lesHeros[indice]->rectHero.w))&&(e.button.x < tabHero->tab[indice]->coordX + (lesHeros[indice]->rectHero.w)))&&((e.button.y > tabHero->tab[indice]->coordY - (lesHeros[indice]->rectHero.h))&&(e.button.y < tabHero->tab[indice]->coordY + (lesHeros[indice]->rectHero.h)) )){
										etat = 0;
									}
								}
								if(nbCaseUse < MAXHERO && etat == 1){
									if(joueur->argent >= hero1->prix){		
										tabHero->tab[nbCaseUse]->coordX = e.button.x;
										tabHero->tab[nbCaseUse]->coordY = e.button.y;
										tabHero->tab[nbCaseUse]->Hero = hero1;
										joueur->argent -= hero1->prix;
										SDL_Log("Vous poser le héro %s en coordonnée %d , %d et il coute %d pièce il vous en reste donc %d ",tabHero->tab[nbCaseUse]->Hero->nom,e.button.x,e.button.y,hero1->prix,joueur->argent);
										caseHero = 0;


										lesHeros[nbCaseUse]->rectHero.x = e.button.x - 32;
										lesHeros[nbCaseUse]->rectHero.y = e.button.y - 30 ;





										nbCaseUse++;

										SDL_Log("Le nombre de case utilisé : %d !",nbCaseUse);
									}
									else{
										SDL_Log("Vous n'avez pas assez d'argent pour acheter ce héros");
									}
								}
								else if(etat == 0)SDL_Log("Vous ne pouvez pas placer un héros sur un héros déjà existant ! ");
								else if(nbCaseUse >= MAXHERO){
									SDL_Log("Nombre de heros maximum atteins !");
								}	
								break;
							case 2:
								lesHeros[nbCaseUse]->texture = textHero2;
								for(int indice = 0 ; indice < nbCaseUse ; indice++){
										if(((e.button.x > tabHero->tab[indice]->coordX - (lesHeros[indice]->rectHero.w))&&(e.button.x < tabHero->tab[indice]->coordX + (lesHeros[indice]->rectHero.w)))&&((e.button.y > tabHero->tab[indice]->coordY - (lesHeros[indice]->rectHero.h))&&(e.button.y < tabHero->tab[indice]->coordY + (lesHeros[indice]->rectHero.h)) )){
											etat = 0;
										}
									}
								if(nbCaseUse < MAXHERO && etat == 1){
									if(joueur->argent >= hero2->prix){		
										tabHero->tab[nbCaseUse]->coordX = e.button.x;
										tabHero->tab[nbCaseUse]->coordY = e.button.y;
										tabHero->tab[nbCaseUse]->Hero = hero2;
										joueur->argent -= hero1->prix;
										SDL_Log("Vous poser le héro %s en coordonnée %d , %d et il coute %d pièce il vous en reste donc %d ",tabHero->tab[nbCaseUse]->Hero->nom,e.button.x,e.button.y,hero1->prix,joueur->argent);
										caseHero = 0;


										lesHeros[nbCaseUse]->rectHero.x = e.button.x - 32;
										lesHeros[nbCaseUse]->rectHero.y = e.button.y - 30 ;





										nbCaseUse++;

										SDL_Log("Le nombre de case utilisé : %d !",nbCaseUse);
										}
									else{
									SDL_Log("Vous n'avez pas assez d'argent pour acheter ce héros");
									}
								}
								else if(etat == 0)SDL_Log("Vous ne pouvez pas placer un héros sur un héros déjà existant ! ");
								else if(nbCaseUse >= MAXHERO){
									SDL_Log("Nombre de heros maximum atteins !");
								}	
								break;
							case 3:
								lesHeros[nbCaseUse]->texture = textHero3;
								for(int indice = 0 ; indice < nbCaseUse ; indice++){
										if(((e.button.x > tabHero->tab[indice]->coordX - (lesHeros[indice]->rectHero.w))&&(e.button.x < tabHero->tab[indice]->coordX + (lesHeros[indice]->rectHero.w)))&&((e.button.y > tabHero->tab[indice]->coordY - (lesHeros[indice]->rectHero.h))&&(e.button.y < tabHero->tab[indice]->coordY + (lesHeros[indice]->rectHero.h)) )){
											etat = 0;
										}
									}
								if(nbCaseUse < MAXHERO && etat == 1){
									if(joueur->argent >= hero3->prix){		
										tabHero->tab[nbCaseUse]->coordX = e.button.x;
										tabHero->tab[nbCaseUse]->coordY = e.button.y;
										tabHero->tab[nbCaseUse]->Hero = hero3;
										joueur->argent -= hero3->prix;
										SDL_Log("Vous poser le héro %s en coordonnée %d , %d et il coute %d pièce il vous en reste donc %d ",tabHero->tab[nbCaseUse]->Hero->nom,e.button.x,e.button.y,hero1->prix,joueur->argent);
										caseHero = 0;


										lesHeros[nbCaseUse]->rectHero.x = e.button.x - 32;
										lesHeros[nbCaseUse]->rectHero.y = e.button.y - 30 ;





										nbCaseUse++;

										SDL_Log("Le nombre de case utilisé : %d !",nbCaseUse);
									}
									else{
										SDL_Log("Vous n'avez pas assez d'argent pour acheter ce héros");
									}
								}
								else if(etat == 0)SDL_Log("Vous ne pouvez pas placer un héros sur un héros déjà existant ! ");
								else if(nbCaseUse >= MAXHERO){
									SDL_Log("Nombre de heros maximum atteins !");
								}	
								break;
						}		
					}
					if((e.button.x >= imgDestRectCase1.x && e.button.x <= imgDestRectCase1.x + imgDestRectCase1.w) && (e.button.y >= imgDestRectCase1.y && e.button.y <= imgDestRectCase1.y + imgDestRectCase1.h)){
						SDL_Log("Réussite ca clique sur la case 1");
						SDL_Log("Hero 1 selectionner");
						caseHero = 1;
					}
					if((e.button.x >= imgDestRectCase2.x && e.button.x <= imgDestRectCase2.x + imgDestRectCase2.w) && (e.button.y >= imgDestRectCase2.y && e.button.y <= imgDestRectCase2.y + imgDestRectCase2.h)){
						SDL_Log("Réussite ca clique sur case 2");
						SDL_Log("Hero 2 selectionner");
						caseHero = 2;
					}
					if((e.button.x >= imgDestRectCase3.x && e.button.x <= imgDestRectCase3.x + imgDestRectCase3.w) && (e.button.y >= imgDestRectCase3.y && e.button.y <= imgDestRectCase3.y + imgDestRectCase3.h)){
						SDL_Log("Réussite ca clique sur case 3");
						SDL_Log("Hero 3 selectionner");
						caseHero = 3;
					}
					if((e.button.x >= imgDestRectpause.x && e.button.x <= imgDestRectpause.x + imgDestRectpause.w) && (e.button.y >= imgDestRectpause.y && e.button.y <= imgDestRectpause.y + imgDestRectpause.h)){
						SDL_Log("PAUSE");
						switch(param(renderer,window,largeur,hauteur,background)){
							case 0:running=SDL_FALSE;break;
							case 2:SDL_GetWindowSize(window,&largeur,&hauteur);break;
							case 1:
							largeur=WIDTHSCREEN;
							hauteur=HEIGHTSCREEN;
							break;
						}
						
					}
					
					SDL_Log("Click de la souris en (%d) (%d)", e.button.x, e.button.y);// 
					break;
				case SDL_MOUSEBUTTONUP: // Click de souris relâché
					SDL_Log("-clic");
					break;
				case SDL_MOUSEWHEEL: // Scroll de la molette
					SDL_Log("wheel");
					break;
								
				} 
		} 
	}
	
<<<<<<< HEAD

	SDL_DestroyTexture(background);
	SDL_DestroyTexture(hud);
	SDL_DestroyTexture(texte);
	SDL_DestroyTexture(case1);
	SDL_DestroyTexture(case2);
	SDL_DestroyTexture(case3);
=======
	SDL_DestroyTexture(case1);
	SDL_DestroyTexture(case2);
	SDL_DestroyTexture(case2);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(hud);
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f
	SDL_DestroyTexture(pause);
	SDL_DestroyTexture(textHero1);
	SDL_DestroyTexture(textHero2);
	SDL_DestroyTexture(textHero3);
<<<<<<< HEAD
	SDL_DestroyTexture(textEnnemie);
=======
	SDL_DestroyTexture(texte);
>>>>>>> bb4533840c98cd13ecf720c373290069aab3b84f

	detruireHero(&hero1);
	detruireHero(&hero2);
	detruireHero(&hero3);

	/*for(int j = 0 ; j < MAXHERO ; j++){
		detruireHero(&tabHero->tab[j]->Hero);
	}*/
	free(&tabHero->tab);

    return 0;
}

