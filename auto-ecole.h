
//fonction recherche
bool exist (int num_doss){
	FILE *F;
	candidat cand;
	bool trouv=false;
	
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F) && trouv==false){
		if (cand.num_doss==num_doss)
			trouv=true;
	}
	fclose(F);
	return trouv;
}

//ajouter un candidat
void ajout (){
	FILE *F;
	candidat cand;
	int i,val;
	
	F=fopen ("candidats.txt","a");
	if (F==NULL){
			printf ("le fichier na pas ete cree correctement \n");
			exit (1);
	}
	//demander les infos du candidat
	printf ("introduisez le nom du candidat \n");
	scanf (" %s",cand.nom);
	do{
	printf ("introduisez son numero de dosier \n");
	scanf ("%d",&cand.num_doss);
	}while (exist(cand.num_doss)==true);
	
	printf ("introduisez son age \n");
	scanf ("%d",&cand.age);
	printf ("introduisez le montant paye \n");
	scanf ("%f",&cand.mont_p);
	
	if (cand.mont_p>18000){
		printf ("la somme payee depasse les frais du permis, vous devez lui rendre : %.2f \n",cand.mont_p-18000);
	}
	
	cand.mont_r= (18000-cand.mont_p);
	printf (" le montant restant est : %.2f  \n",cand.mont_r);
	
	printf ("introduisez son nombre de seances \n");
	scanf ("%d",&cand.nb_seances);
	
	strcpy(cand.tab[0].nom,"code");
	strcpy(cand.tab[1].nom,"creneau");
	strcpy(cand.tab[2].nom,"conduite");
	
	
	for (i=0;i<3;i++){
		cand.tab[i].statut=0;
		cand.tab[i].frais=0;
		}
	
	printf ("\n");
	printf ("\n");
	//l'ajout du candidat au fichier
	if (cand.mont_p>=5000){
		printf ("candidature acceptee \n");
		printf ("\n");
	fwrite (&cand,sizeof(candidat),1,F);
	
	//verification
	if (fwrite==0)
		printf ("le candidat na pas ete ajoute \n");
	else 
		printf ("le candidat a ete ajoute avec succes \n");
	
	}
	else 
		printf ("candidature non acceptee \n");
	fclose (F);
		
}


//procedure suppression
void suppression (){
	candidat cand;
	int num_doss,i;
	FILE *F,*INTER;
	bool jjj=false,kkk=true,iii=false;
	
	printf ("donnez le numero de dossier du candidat que vous voulez supprimer \n");
	scanf ("%d",&num_doss);
	
	F=fopen("candidats.txt","r");
	INTER=fopen("candidats_inetr.txt","w");
	
	while (fread (&cand,sizeof(candidat),1,F)){
		if (cand.num_doss==num_doss){
			iii=true;
			if (cand.mont_r==0){
				jjj=true;
			}
		 
			
			i=0;
			while (i<3 && kkk==true){
				if(cand.tab[i].statut==0){
					kkk=false;
				}
			}
		}else fwrite(&cand,sizeof(candidat),1,INTER);
	}
	fclose (F);
	fclose(INTER);
	if (jjj==true && kkk==true){
		printf ("la suppression a ete effectuee avec reussite  \n");
		
		F=fopen ("candidats.txt","w");
		INTER=fopen("candidats_inter.txt","r");
	
		while (fread(&cand,sizeof(candidat),1,INTER))
				fwrite(&cand,sizeof(candidat),1,F);
			
		fclose(F);
		fclose(INTER);
	}else  
		printf ("la suppression a echouee \n");
	
}
		
//foction modification du montant restant d'un candidat
void modification_montant(int num_doss, float somme){
	candidat cand,nv_cand;
	FILE *F,*INTER;
	int i;
	
	INTER=fopen("cand_INTER_mont.txt","w");
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F)){
		if (cand.num_doss==num_doss){
			cand.mont_p=((cand.mont_p)+somme);
			cand.mont_r=(18000-(nv_cand.mont_p));
			
			fwrite(&cand,sizeof(candidat),1,INTER);
			
	}else fwrite(&cand,sizeof(candidat),1,INTER);
	}
	
	fclose(F);
	fclose(INTER);
	printf ("\n");
	
	
	F=fopen("candidats.txt","w");
	INTER=fopen("cand_INTER_mont.txt","r");
	
	while(fread(&cand,sizeof(candidat),1,INTER)) {
		fwrite(&cand,sizeof(candidat),1,F);
	}
	fclose (F);
	fclose(INTER);
} 


//modification du statut d'un examen
void modification_statut(int num_doss){
	candidat cand,nv_cand;
	int i,val;
	FILE *F,*INTER;
	char exam[10];
	
	
	printf ("donnez le nom de lexamen dont vous voulez changer le statut \n");
	scanf (" %s",exam);
	printf ("donnez le statut de lexamen sachant que 1 signifie la reussite du condidat et 0 son echec \n");
	scanf ("%d",&val);
	
	F=fopen ("candidats.txt","r");
	INTER=fopen("inter_statut.txt","w");
	
	while (fread(&cand,sizeof(candidat),1,F) ){
		if (cand.num_doss==num_doss)
			for (i=0;i<3;i++){
				if (strcmp(nv_cand.tab[i].nom, exam)==0)
					nv_cand.tab[i].statut=val;
			fwrite(&cand,sizeof(candidat),1,INTER);	
				
		}else fwrite(&cand,sizeof(candidat),1,INTER);
	
	}
	fclose (F);
	fclose(INTER);
	
		
	F=fopen("candidats.txt","w");
	INTER=fopen("inter_statut.txt","r");
	
	while (fread(&cand,sizeof(candidat),1,INTER)){
		fwrite(&cand,sizeof(candidat),1,F);
	}
	fclose (F);
	fclose (INTER);
	printf ("le resultat de lexmen de  %s est : %d \n",exam,val);
}

//procedure passer un examen
void pass_exam (int num_doss , char exam[10]){
	candidat cand;
	int i;
	FILE *F;
	bool jjj=false,iii=false,nnn=true;
	
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F) && jjj==false){
		if(cand.num_doss==num_doss){
			jjj=true;
	
	
			if(cand.nb_seances>=5)
				iii=true;
		
			while(i<3 && nnn==true){
				if(strcmp(cand.tab[i].nom,exam)==0)
					if (cand.tab[i].frais!=1000)
						nnn=false;
			}
		}
	}
	if(iii==true && nnn==true)
		printf ("le candidat a le droit de passer cet examen \n");
	else 
		printf ("le candidat na pas le droit de passer cet examen \n");
	
	fclose (F); 
}

void affichage (){
	FILE *F;
	candidat cand;
	
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F))
		printf (" %s \n",cand.nom );
		printf ("numero du dossir : %d \n",cand.num_doss);
		printf ("age: %d \n",cand.age);
		printf ("le montant payant : %.2f \n",cand.mont_p);
		printf ("le montnt restant : %.2f \n",cand.mont_r);
		printf ("le nombre de seances : %d \n",cand.nb_seances);
		printf ("les frais de lexamen de code : %.2f \n",cand.tab[1].frais);
		printf ("le statut de lexamen de code : %d \n",cand.tab[1].statut);
		printf ("les frais de lexamen de creneau : %.2f \n",cand.tab[2].frais);
		printf ("le statut de lexamen de creneau : %d \n",cand.tab[2].statut);
		printf ("les frais de lexamen de conduite : %.2f \n",cand.tab[3].frais);
		printf("le statut de  lexamen de conduite : %d \n",cand.tab[3].statut);
		
	
	fclose (F);
}

//procedure qui modifie les frais dun examen

void mod_frais ( int num_doss){
	FILE *F,*INTER;
	char exam[10];
	float somme;
	int i;
	candidat cand;
	
	F=fopen("candidats.txt","r");
	INTER= fopen("inter_frais","w");
	
	printf ("donnez le nom de lexamen auquel vous voulez modifier les frais \n");
	scanf(" %s",exam);
	printf ("donnez la somme rajouteepar le candidat \n");
	scanf ("%f",&somme);
	
	while (fread(&cand,sizeof(candidat),1,F)){
		if (cand.num_doss==num_doss){
			for (i=0;i<3;i++)
				if (strcmp(cand.tab[i].nom, exam)==0){
					cand.tab[i].frais=cand.tab[i].frais+somme;
					if(cand.tab[i].frais>1000){
						printf("la somme payee depasse les frais de lexamen, vous devez lui rendre : %.2f \n",cand.tab[i].frais-1000);
					}
				}
			fwrite(&cand,sizeof(candidat),1,INTER);
		}else fwrite(&cand,sizeof(candidat),1,INTER);
	}
	fclose(F);
	fclose(INTER);
	
	
	F=fopen("candidats.txt","w");
	INTER= fopen("inter_frais","r");
	
	while (fread(&cand,sizeof(candidat),1,INTER)){
		fwrite(&cand,sizeof(candidat),1,F);
	}
	fclose (F);
	fclose (INTER);
	
}

//procedure qui modifie le montant payee dun candidat 

void mod_mont (int num_doss){
	FILE *F,*INTER;
	candidat cand,nv_cand;
	float somme;
	
	
	F=fopen("canidats.txt","r");
	INTER=fopen("inter_mont","w");
	
	printf ("donnez la somme rajoutee par le candidat \n");
	scanf ("%f",&somme);
	
	while (fread(&cand,sizeof(candidat),1,F)){
		if (cand.num_doss==num_doss){
			cand.mont_p=cand.mont_p+somme;
			cand.mont_r=18000-(cand.mont_p);
			
			if (cand.mont_p>18000){
				printf ("la somme depasse les frais du permis, vous devez lui rendre : %.2f \n",cand.mont_p-18000);
			}
			
			nv_cand=cand;
			fwrite(&cand,sizeof(candidat),1,INTER);
		}else fwrite(&cand,sizeof(candidat),1,F);
	}
	fclose (F);
	fclose (INTER);
	
	
	F=fopen("canidats.txt","w");
	INTER=fopen("inter_mont","r");
	
	while (fread(&cand,sizeof(candidat),1,INTER))
		fwrite(&cand,sizeof(candidat),1,F);
	
	
		
	fclose(F);
	fclose(INTER);
	printf ("le nouveau montant restant est de : %.2f \n",nv_cand.mont_r);
}

