//ajouter un candidat
candidat  ajout (){
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
	printf ("introduisez son numero de dosier \n");
	scanf ("%d",&cand.num_doss);
	printf ("introduisez son age \n");
	scanf ("%d",&cand.age);
	printf ("introduisez le montant paye \n");
	scanf ("%f",&cand.mont_p);
	
	cand.mont_r= (18000-cand.mont_p);
	printf (" le montant restant est : %.2f  \n",cand.mont_r);
	
	printf ("introduisez son nombre de seances \n");
	scanf ("%d",&cand.nb_seances);
	
	strcpy(cand.tab[0].nom,"code");
	strcpy(cand.tab[1].nom,"creneau");
	strcpy(cand.tab[2].nom,"conduite");
	
	
	printf ("donnez les frais de lexamen de code  \n");
	scanf ("%f",&cand.tab[0].frais);
	printf ("donnez les frais de lexamen du creneau \n");
	scanf ("%f",&cand.tab[1].frais);
	printf ("donnez les frais de lexamen de conduite \n");
	scanf ("%f",&cand.tab[2].frais);
	for (i=0;i<3;i++){
		cand.tab[i].statut=0;
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
		
	return cand;
}


//procedure suppression
void suppression (){
	candidat cand;
	int num_doss,i;
	FILE *F,*INTER;
	bool jjj=false,kkk=false,iii=false;
	
	printf ("donnez le numero de dossier du candidat que vous voulez supprimer \n");
	scanf ("%d",&num_doss);
	
	F=fopen("candidats.txt","r");
	INTER=fopen("candidats_inetr.txt","w");
	
	while (fread (&cand,sizeof(candidat),1,F)){
		if (cand.num_doss==num_doss){
		
			if (cand.mont_r==0){
				jjj=true;
			} 
			
			for (i=0;i<3;i++){
				if(cand.tab[i].statut==1){
					kkk=true;
				}
			}
		}
	}
	fclose (F);
	
	F=fopen("candidats.txt","r");
	while (fread (&cand,sizeof(candidat),1,F)){
		
			if( jjj==true && kkk==true)
			iii==true; 
	
	
			else fwrite(&cand,sizeof(candidat),1,INTER);
	}	
	
	fclose(F);
	fclose(INTER);
	
	F=fopen ("candidats.txt","w");
	INTER=fopen("candidats_inter.txt","r");
	
	while (fread(&cand,sizeof(candidat),1,INTER))
			fwrite(&cand,sizeof(candidat),1,F);
			
	fclose(F);
	fclose(INTER);
	
	if (iii==true)
				printf ("le candidat a ete supprime avec reussite \n");
	else 
				printf ("la suppression a echouee \n");
	
}
		
//foction modification du montant restant d'un candidat
void modification_montant(int num_doss, float somme){
	candidat cand,nv_cand;
	FILE *F,*INTER;
	bool jjj=false;
	int i;
	
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F) && jjj==false){
		if (cand.num_doss==num_doss)
				jjj=true;
	}
	strcpy(nv_cand.nom,cand.nom);
	nv_cand.age=cand.age;
	nv_cand.mont_p=((cand.mont_p)+somme);
	nv_cand.mont_r=(18000-(nv_cand.mont_p));
	nv_cand.nb_seances=cand.nb_seances;
	
	for (i=0;i<3;i++){
	strcpy(nv_cand.tab[i].nom,cand.tab[i].nom);
	nv_cand.tab[i].frais=cand.tab[i].frais;
	nv_cand.tab[i].statut=cand.tab[i].statut;
	}
	fclose(F);
	
	printf ("\n");
	printf ("le nouveau montant restant de ce candidat est :  %.2f \n",nv_cand.mont_r);
	
	F=fopen("candidats.txt","r");
	INTER=fopen("cand_INTER_mont.txt","w");
	
	while (fread(&cand,sizeof(candidat),1,F)){
		if ((cand.num_doss) != (nv_cand.num_doss))
			fwrite(&cand,sizeof(candidat),1,INTER);
		else 
			fwrite(&nv_cand,sizeof(candidat),1,INTER);
	}
	fclose(F);
	fclose(INTER);
	
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
	bool jjj=false;
	
	printf ("donnez le nom de lexamen dont vous voulez changer le statut \n");
	scanf (" %s",exam);
	printf ("donnez le statut de lexamen sachant que 1 signifie la reussite du condidat et 0 son echec \n");
	scanf ("%d",&val);
	
	F=fopen ("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F) && jjj==false){
		if (cand.num_doss==num_doss)
			jjj=true;
	}
	strcpy(nv_cand.nom,cand.nom);
	nv_cand.age=cand.age;
	nv_cand.mont_p=cand.mont_p;
	nv_cand.mont_r=cand.mont_r;
	nv_cand.nb_seances=cand.nb_seances;
	
	for (i=0;i<3;i++){
		nv_cand.tab[i].frais=cand.tab[i].frais;
		strcpy(nv_cand.tab[i].nom,cand.tab[i].nom);
		
		if (strcmp(nv_cand.tab[i].nom, exam)==0)
			nv_cand.tab[i].statut=val;
		else 
			nv_cand.tab[i].statut=cand.tab[i].statut;
	}
	fclose (F);
	
	F=fopen("candidats.txt","r");
	INTER=fopen("inter_statut.txt","w");
	
	while (fread(&cand,sizeof(candidat),1,F)){
		if (cand.num_doss !=num_doss)
			fwrite(&cand,sizeof(candidat),1,INTER);
		else 
			fwrite(&nv_cand,sizeof(candidat),1,INTER);
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
	bool jjj=false,iii=false,nnn=false;
	
	F=fopen("candidats.txt","r");
	while (fread(&cand,sizeof(candidat),1,F) && jjj==false){
		if(cand.num_doss==num_doss)
			jjj=true;
	}
	
	if(cand.nb_seances>=5)
		iii=true;
		
	for (i=0;i<3;i++){
		if(strcmp(cand.tab[i].nom,exam))
			if (cand.tab[i].frais==1000)
				nnn=true;
	}
	
	if(iii==true && nnn==true)
		printf ("le candidat a le droit de passer cet examen \n");
	else 
		printf ("le candidat na pas le droit de passer cet examen \n");
	
	fclose (F); 
}
