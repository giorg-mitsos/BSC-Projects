/************************************************************//**
 * @file   main.c                                      		*
 * @author Nikolaos Batsaras <batsaras@csd.uoc.gr>  		*
 *                                                    		*
 * @brief Main function for the needs of cs-240b project 2017   *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "troy.h"

#define BUFFER_SIZE 1024  /**< Maximum length of a line in input file */

/* Uncomment the following line to enable debugging prints 
 * or comment to disable it */
#define DEBUG
#define N 7

#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else  /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */


/**
 * @brief Optional function to initialize data structures that 
 * need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
void inOrderTREE(struct TREE_soldier *root,struct TREE_soldier *guard);
void setArray(struct TREE_soldier *A[],struct TREE_soldier *root,struct TREE_soldier *guard);
struct TREE_soldier* toTree(struct TREE_soldier *guard,struct TREE_soldier *parent,int start,int end,struct TREE_soldier *a[]);
void addGuard(struct TREE_soldier *root,struct TREE_soldier *guard);
void printBattle(struct c_soldier *access);
void InmergeBattle(struct TREE_soldier *root,struct c_soldier *A[],int gid);
void PremergeBattle(struct TREE_soldier *root,struct c_soldier *B[],int gid);
void insertSold(struct c_soldier *temp,int gid);
void searchDead(struct c_soldier *temp);
void deleteDead(int sid);
 
int initialize() {
	registration_hashtable=malloc(sizeof(struct soldier)*N);
	int i = 0;
	while(i<N){
		registration_hashtable[i]=NULL;
		i++;
	}
	generals_list=NULL;
	my_combat = (struct combat*)malloc(sizeof(struct combat));
	my_combat->soldier_cnt=0;
	my_combat->combat_s=NULL;
    return 1;
}

/**
 * @brief Register soldier
 *
 * @param sid The soldier's id
 * @param gid The general's id who orders the soldier
 *
 * @return 1 on success
 *         0 on failure
 */
int register_soldier(int sid, int gid) {
	//h(k)=k mod N
	struct soldier *root=(struct soldier*)malloc(sizeof(struct soldier));
	root->gid=gid;
	root->sid=sid;
	root->next=NULL;
	int i=h(sid);
	if (registration_hashtable[i]==NULL){
		registration_hashtable[i]=root;
	}
	else {
		struct soldier *temp=registration_hashtable[i];
		while(root->sid>temp->sid && temp->next!=NULL){
			temp=temp->next;
		}
		if (temp==registration_hashtable[i]){
			root->next=registration_hashtable[i];
			registration_hashtable[i]=root;
		}
		else if(temp->next==NULL){
			temp->next=root;
		}
		else {
			struct soldier *temp2=registration_hashtable[i];
			while(temp2->next!=temp){
				temp2=temp2->next;
			}
			root->next=temp2->next;
			temp2->next=root;
			
		}
	}
	i=0;
	int j=0;
	printf ("	Soldiers Hash Table:\n\t");
	struct soldier *access;
	while(i<N){
		if (registration_hashtable[i]==NULL){
			i++;
			continue;
		}
		else{
			access=registration_hashtable[i];
			printf ("\b\b\b\b[%d] :",i);
			while (access!=NULL){
				printf ("<%d:%d>, ",access->sid,access->gid);
				j++;
				if (j%10==0){
					printf ("\n \t");
				}
				access=access->next;
			}		
			j=0;
			printf ("\b\b \n\t");
			i++;
		}
	}
    return 1;
}

int h(int k){
	
	return k % N;
}

/**
 * @brief General or King joins the battlefield
 *
 * @param gid The general's id
 *
 * @return 1 on success
 *         0 on failure
 */
int add_general(int gid) {
	struct general *root=(struct general*)malloc(sizeof(struct general));
	struct TREE_soldier *guard=(struct TREE_soldier*)malloc(sizeof(struct TREE_soldier));
	guard->sid=-1;
	guard->p=NULL;
	guard->rc=NULL;
	guard->lc=NULL;
	root->gid=gid;
	root->next=NULL;
	root->combats_no=0;
	root->soldiers_no=0;
	root->soldiers_R=NULL;
	root->soldiers_S=guard;
	if(generals_list==NULL){
		generals_list=root;
	}
	else{
		root->next=generals_list;
		generals_list=root;
	}
    return 1;
}


/**
 * @brief Distribute soldiers to the camps
 * 
 * @return 1 on success
 *         0 on failure
 */
int distribute() {
	int i=0;
	struct soldier *access;
	struct general *gaccess;
	while(i<N){
		access=registration_hashtable[i];
		while(access!=NULL){
			gaccess=generals_list;
			while(gaccess->gid!=access->gid){
				if(gaccess->next==NULL){
					printf ("General : %d Not Found",access->gid);
					return 0;
				}
				else{
					gaccess=gaccess->next;
				}
			}
			struct TREE_soldier *root=(struct TREE_soldier*)malloc(sizeof(struct TREE_soldier));
			root->lc=gaccess->soldiers_S;
			root->rc=gaccess->soldiers_S;
			root->sid=access->sid;
			if (gaccess->soldiers_R==NULL){
				root->p=NULL;
				gaccess->soldiers_R=root;
				gaccess->soldiers_no=1;
			}
			else{
				struct TREE_soldier *temp=gaccess->soldiers_R;
				int flag=0;
				while (flag==0){
					if (temp->sid<root->sid){
						if(temp->rc!=gaccess->soldiers_S){
							temp=temp->rc;		
						}
						else{
							root->p=temp;
							temp->rc=root;
							flag=1;
							gaccess->soldiers_no++;
						}
					}
					else if(temp->sid>root->sid){
						if(temp->lc!=gaccess->soldiers_S){
							temp=temp->lc;
						}
						else{
							root->p=temp;
							temp->lc=root;
							flag=1;
							gaccess->soldiers_no++;
						}
					}
				}
				
			}
			access=access->next;
		}	
		i++;
	}
	
    return 1;
}

/**
 * @brief General resigns from battlefield
 *
 * @param gid1 The id of general that resigns
 * @param gid2 The id of the general that will  
 * 
 * @return 1 on success
 *         0 on failure
 */
int general_resign(int gid1, int gid2) {
	struct general *gen1,*gen2;
	gen1=generals_list;
	gen2=generals_list;
	while(gen1->gid!=gid1){
		if (gen1->next!=NULL){
			gen1=gen1->next;
		}
		else{
			printf ("General : %d Not found\n",gid1);
			return 0;
		}
	}
	while(gen2->gid!=gid2){
		if(gen2->next!=NULL){
			gen2=gen2->next;
		}
		else{
			printf ("General : %d Not found\n",gid2);
			return 0;
		}
	}
	struct TREE_soldier *A[gen1->soldiers_no],*B[gen2->soldiers_no],*C[gen1->soldiers_no+gen2->soldiers_no];
	pos=0;  //GLOBAL ~>TROY.H
	setArray(A,gen1->soldiers_R,gen1->soldiers_S);
	pos=0;
	setArray(B,gen2->soldiers_R,gen2->soldiers_S);
	int i=0,j=0,k=0;
	
	while(i<gen1->soldiers_no && j<gen2->soldiers_no){
	
 		if (A[i]->sid<B[j]->sid){
 			C[k]=A[i];
 			k++;
 			i++;
 		}
 		else{
 			C[k]=B[j];
 			k++;
 			j++;
		 }
	}
	if(i==gen1->soldiers_no){
		while(j<gen2->soldiers_no && k<gen1->soldiers_no+gen2->soldiers_no){
			C[k]=B[j];
			j++;
			k++;
		}
	}
	else if(j==gen2->soldiers_no){
		while(i<gen1->soldiers_no && k<gen1->soldiers_no+gen2->soldiers_no){
			C[k]=A[i];
			i++;
			k++;
		}
	}
	gen2->soldiers_R=NULL;
	gen2->soldiers_R=toTree(gen2->soldiers_S,NULL,0,gen1->soldiers_no+gen2->soldiers_no-1,C);
	gen2->soldiers_no+=gen1->soldiers_no;
	struct TREE_soldier *guard=(struct TREE_soldier*)malloc(sizeof(struct TREE_soldier));
	guard->lc=NULL;
	guard->p=NULL;
	guard->rc=NULL;
	guard->sid=-1;
	gen2->soldiers_S=guard;
	addGuard(gen2->soldiers_R,gen2->soldiers_S);
	/*Antimetwpisa thema me to guard xanotane dld meta to neo dentro an kai pernaga ta guard den upirxan...
		me apotelesma na ftiaw tin addGuard kai ena neo guard
	*/
	struct soldier *accessor;
	int z=0;
	while(z<N){
		accessor=registration_hashtable[z];
		while(accessor->next!=NULL){
			if(accessor->gid==gid1){
				accessor->gid=gid2;
			}
			accessor=accessor->next;
		}
		z++;
	}
	
	struct general *temp=generals_list;
	 if(gen1==generals_list){
		generals_list=generals_list->next;
	}
	else{
		while(temp->next!=gen1){
			temp=temp->next;
		}
		temp->next=gen1->next;
	}
	
	
	
    return 1;
}

void addGuard(struct TREE_soldier *root,struct TREE_soldier *guard){
	if (root==guard)return;
	if(root->lc==NULL)root->lc=guard;
	if(root->rc==NULL)root->rc=guard;
	addGuard(root->lc,guard);
	addGuard(root->rc,guard);
}


struct TREE_soldier  *toTree(struct TREE_soldier *guard,struct TREE_soldier *parent,int start,int end,struct TREE_soldier *a[]){
	if(start>end)return NULL;
	int mid = (start+end)/2;
	struct TREE_soldier *root = (struct TREE_soldier*)malloc(sizeof(struct TREE_soldier));
	root->lc=NULL;
	root->rc=NULL;
	root->sid=a[mid]->sid;
	root->p=parent;
	
	root->lc=toTree(guard,root,start,mid-1,a);
	root->rc=toTree(guard,root,mid+1,end,a);
	
	return root;
}


void setArray(struct TREE_soldier *A[],struct TREE_soldier *root,struct TREE_soldier *guard){
	if (root==guard)return;
	setArray(A,root->lc,guard);
	A[pos]=root;
	pos++;
	setArray(A,root->rc,guard);
	
	
}

/**
 * @brief Prepare for battle
 * 
 * @param gid1 The id of the first general
 * @param gid2 The id of the second general
 * 
 * @return 1 on success
 *         0 on failure
 */
int prepare_battle(int gid1, int gid2) {
	struct general *gen1=generals_list;
	struct general *gen2=generals_list;
	while(gen1->gid!=gid1){
		if(gen1->next!=NULL){
			gen1=gen1->next;
		}
		else{
			printf("General : %d Not Found\n",gid1);
			return 0;
		}
	}
	while(gen2->gid!=gid2){
		if(gen2->next!=NULL){
			gen2=gen2->next;
		}
		else{
			printf("General : %d Not Found\n",gid2);
			return 0;
		}
	}
	gen1->combats_no++;
	gen2->combats_no++;
	my_combat->soldier_cnt=gen1->soldiers_no+gen2->soldiers_no;
	struct c_soldier *A[gen1->soldiers_no],*B[gen2->soldiers_no],*C[gen1->soldiers_no+gen2->soldiers_no];
	pos=0;
	InmergeBattle(gen1->soldiers_R,A,gen1->gid);
	pos=0;
	PremergeBattle(gen2->soldiers_R,B,gen2->gid);
	
	int i=0,j=0;
	int k=0;
	while(i<gen1->soldiers_no && j<gen2->soldiers_no){
		C[k]=A[i];
		i++;
		k++;
		C[k]=B[j];
		j++;
		k++;
		
	}
	if(i==gen1->soldiers_no){
		while(j<gen2->soldiers_no){
			C[k]=B[j];
			k++;
			j++;
		}
	}
	else if(j==gen2->soldiers_no){
		while(i<gen1->soldiers_no){
			C[k]=A[i];
			i++;
			k++;
		}
	}
	
	k=0;
	while(k<gen1->soldiers_no + gen2->soldiers_no){
		insertSold(C[k],C[k]->gid);
		k++;
	}
	dekades = 0;
	printf ("	Combat Soldiers (%d):",my_combat->soldier_cnt);
	printBattle(my_combat->combat_s);
	printf ("\b\b \n");
	
	
    return 1;
}
void insertSold(struct c_soldier *temp,int gid){
	if(my_combat->combat_s==NULL){
		my_combat->combat_s=temp;
	}
	else{
		int flag=0;
		struct c_soldier *search = my_combat->combat_s;
		while(flag==0){
			if(temp->sid<search->sid){
				if(search->lc!=NULL){
					search->left_cnt++;
					search=search->lc;
				}
				else{
					search->lc=temp;
				}
			}
			else if(search->sid<temp->sid){
				if(search->rc!=NULL){
					search=search->rc;
				}
				else{
					search->rc=temp;
				}
			}
			else{
				return;
			}
		}
	}
}

void InmergeBattle(struct TREE_soldier *root,struct c_soldier *A[],int gid){
	if(root==NULL || root->sid==-1)return;
	InmergeBattle(root->lc,A,gid);
	struct c_soldier *temp=(struct c_soldier*)malloc(sizeof(struct c_soldier));
	temp->alive=1;
	temp->gid=gid;
	temp->lc=NULL;
	temp->left_cnt=0;
	temp->rc=NULL;
	temp->sid=root->sid;
	A[pos]=temp;
	pos++;
	InmergeBattle(root->rc,A,gid);
}

void PremergeBattle(struct TREE_soldier *root,struct c_soldier *B[],int gid){
	if(root->sid==-1 || root==NULL)return;
	PremergeBattle(root->rc,B,gid);
	struct c_soldier *temp=(struct c_soldier*)malloc(sizeof(struct c_soldier));
	temp->alive=1;
	temp->gid=gid;
	temp->lc=NULL;
	temp->left_cnt=0;
	temp->rc=NULL;
	temp->sid=root->sid;
	B[pos]=temp;
	pos++;
	PremergeBattle(root->lc,B,gid);
	
}

void printBattle(struct c_soldier *access){
	if(access==NULL)return;
	printBattle(access->lc);
	printf("<%d:%d>, ",access->sid,access->gid);
	dekades++;
	if (dekades % 11 == 0){
		printf ("\n\t\t\t     ");
	}
	printBattle(access->rc);
}
/**
 * @brief Battle
 * 
 * @param god_favor
 * @param bit_stream A sequence of bits
 * @param bitsno The number of bits in the sequence
 *
 * @return 1 on success
 *         0 on failure
 */
int dead;
void death(int deaths,struct c_soldier *root){
	if(root==NULL)return;
	death(deaths,root->lc);
	if(deaths>dead){
		dead++;
		root->left_cnt--;
		root->alive=0;
	}
	death(deaths,root->rc);
	
	
} 

int battle(int god_favor, char *bit_stream, int bitsno) {
	if(my_combat->combat_s==NULL){
		printf("No Battle in battle record\n");
		return 0;
	}
	if (god_favor==0){
		dead=0;
		int deaths=my_combat->soldier_cnt*0.4;
		death(deaths,my_combat->combat_s);
	}
	else{
		struct c_soldier *root=my_combat->combat_s;
		int k=0;
		while(k<bitsno){
			if(bit_stream[k]==1){
				if(root->rc!=NULL){
					root=root->rc;
					root->alive=0;
				}
				else{
					return 1;
				}
				
			}
			else{
				if(root->lc!=NULL){
					root->left_cnt--;
					root=root->lc;
					root->alive=0;
					
				}
				
			}	
			k++;
			if(bitsno<k){
				k=0;
			}
		}
		
	}
    return 1;
}
void Printdeath(struct c_soldier *root){
	if (root==NULL)return;
	Printdeath(root->lc);
	printf("<%d:%d>, ",root->sid,root->alive);
	dekades++;
	if(dekades % 11 == 0){
		printf("\n\t\t\t");
	}
	Printdeath(root->rc);
}
/**
 * @brief Cease fire
 * 
 * @return 1 on success
 *         0 on failure
 */
int cease_fire() {
	searchDead(my_combat->combat_s);
    return 1;
}

void searchDead(struct c_soldier *temp){
	if (temp==NULL){
		return;
	}
	searchDead(temp->lc);
	if(temp->alive==0){
		deleteDead(temp->sid);
	}
	searchDead(temp->rc);
}

void deleteDead(int sid){
	int i=0;
	struct soldier *temp;
	temp=registration_hashtable[i];
	while(i<N){
		if(temp==NULL){
			i++;
			temp=registration_hashtable[i];
			continue;
		}
		else{
			while(temp!=NULL){
				if(temp->sid==sid){
					if(registration_hashtable[i]->sid==temp->sid){
						registration_hashtable[i]=registration_hashtable[i]->next;
					}
					else{
						struct soldier *temp2=registration_hashtable[i];
						while(temp2->next!=temp){
							temp2=temp2->next;
						}
						temp2->next=temp->next;
					}
				
				} 
				temp=temp->next;
			}
		}
	} 
}

/**
 * @brief Print general's soldiers
 *
 * @param gid The id of the general
 *
 * @return 1 on success
 *         0 on failure
 */
int print_generals_soldiers(int gid) {
	
	struct general *gen=generals_list;
	while(gen->gid!=gid){
		if(gen->next!=NULL){
			gen=gen->next;
		}
		else{
			printf ("General : %d Not found",gid);
			return 0;
		}
	}
	printf ("	Soldier Tree : ");
	if(gen->soldiers_R!=NULL){
		inOrderTREE(gen->soldiers_R,gen->soldiers_S);
	}
	printf ("\b\b \n");
    return 1;
}

/**
 * @brief Print generals
 *
 * @return 1 on success
 *         0 on failure
 */
int print_generals() {
	printf("	GENERALS(Number of Soldiers):\n");
	struct general *gen=generals_list;
	while(gen!=NULL){
		printf("	<%d>(%d): ",gen->gid,gen->soldiers_no);
		dekades=0;
		if (gen->soldiers_R!=NULL){
			inOrderTREE(gen->soldiers_R,gen->soldiers_S);	
		}
		printf("\b\b \n");
		gen=gen->next;
	}
	
    return 1;
}

/**
 * @brief Print registration hashtable
 *
 * @return 1 on success
 *         0 on failure
 */
int print_registration_hashtable() {
	dekades=0;
	int i=0;
	struct soldier *access;
	printf ("	Registration list = ");
	while (i<N){
		access=registration_hashtable[i];
		if(access==NULL){
			i++;
			continue;
		}
		else{
			while(access!=NULL){
				printf ("<%d:%d>, ",access->sid,access->gid);
				dekades++;
				if(dekades%15==0){
					printf("\n\t\t\t    ");
				}
				access=access->next;
			}
		}
		
		
		i++;
	}
	printf ("\b\b \n");
	
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */
int free_world() {
    return 1;
}


void inOrderTREE(struct TREE_soldier *root,struct TREE_soldier *guard){
	if (root==guard || root==NULL)return;
	inOrderTREE(root->lc,guard);
	printf("<%d>, ",root->sid);
	dekades++;
	if(dekades % 22 ==0)printf("\n\t\t  ");
	inOrderTREE(root->rc,guard);
	
}


/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char** argv)
{
    FILE *fin = NULL;
    char buff[BUFFER_SIZE], event;

    /* Check command buff arguments */
    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s <input_file> \n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open input file */
    if (( fin = fopen(argv[1], "r") ) == NULL ) {
        fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
        perror("Opening test file\n");
        return EXIT_FAILURE;
    }

    /* Read input file buff-by-buff and handle the events */
    while ( fgets(buff, BUFFER_SIZE, fin) ) {

        DPRINT("\n>>> Event: %s", buff);

        switch(buff[0]) {

            /* Comment */
            case '#':
                break;

                /* Maximum soldiers */
            case '0':
                {
                    sscanf(buff, "%c %d", &event, &max_soldiers_g);
                    DPRINT("%c %d\n", event, max_soldiers_g);

                    initialize();

                    break;
                }

                /* Register soldier
                 * R <sid> <gid> */
            case 'R':
                {
                    int sid, gid;

                    sscanf(buff, "%c %d %d", &event, &sid, &gid);
                    DPRINT("%c %d %d\n", event, sid, gid);

                    if ( register_soldier(sid, gid) ) {
                        DPRINT("R %d %d succeeded\n", sid, gid);
                    } else {
                        fprintf(stderr, "R %d %d failed\n", sid, gid);
                    }

                    break;
                }

                /* General or king joins the battlefield
                 * G <gid> */
            case 'G':
                {
                    int gid;

                    sscanf(buff, "%c %d", &event, &gid);
                    DPRINT("%c %d\n", event, gid);

                    if ( add_general(gid) ) {
                        DPRINT("%c %d succeeded\n", event, gid);
                    } else {
                        fprintf(stderr, "%c %d failed\n", event, gid);
                    }

                    break;
                }

                /* Distribute soldier
                 * D */
            case 'D':
                {
                    sscanf(buff, "%c", &event);
                    DPRINT("%c\n", event);

                    if ( distribute() ) {
                        DPRINT("%c succeeded\n", event);
                    } else {
                        fprintf(stderr, "%c failed\n", event);
                    }

                    break;
                }

                /* General resigns from battle
                 * M <gid1> <gid2> */
            case 'M':
                {
                    int gid1, gid2;

                    sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                    DPRINT("%c %d %d\n", event, gid1, gid2);

                    if ( general_resign(gid1, gid2) ) {
                        DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                    } else {
                        fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                    }

                    break;
                }

                /* Prepare for battle
                 * P <gid1> <gid2> */
            case 'P':
                {
                    int gid1, gid2;
                    sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                    DPRINT("%c %d %d\n", event, gid1, gid2);

                    if ( prepare_battle(gid1, gid2) ) {
                        DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                    } else {
                        fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                    }

                    break;
                }

                /* Battle
                 * B <god_favor> <bit_stream> */
            case 'B':
                {
                    int god_favor;
                    char bit_stream[9];

                    sscanf(buff, "%c %d %s\n", &event, &god_favor, bit_stream);
                    DPRINT("%c %d %s\n", event, god_favor, bit_stream);

                    if ( battle(god_favor, bit_stream, 8) ) {
                    	dekades=0;
                    	printf("	Combat soldiers : ");
                    	Printdeath(my_combat->combat_s);
                    	printf("\n");
                        DPRINT("%c %d %s succeeded\n", event, god_favor, bit_stream);
                    } else {
                        fprintf(stderr, "%c %d %s failed\n", event, god_favor, bit_stream);
                    }

                    break;
                }

                /* Cease fire
                 * U */
            case 'U':
                {
                    sscanf(buff, "%c", &event);
                    DPRINT("%c\n", event);

                    if ( cease_fire() ) {
                        DPRINT("%c succeeded\n", event);
                    } else {
                        fprintf(stderr, "%c failed\n", event);
                    }

                    break;
                }

                /* Print general's soldiers
                 * W <gid> */
            case 'W':
                {
                    int gid;

                    sscanf(buff, "%c %d", &event, &gid);
                    DPRINT("%c %d\n", event, gid);

                    if ( print_generals_soldiers(gid) ) {
                        DPRINT("%c %d succeeded\n", event, gid);
                    } else {
                        fprintf(stderr, "%c %d failed\n", event, gid);
                    }

                    break;
                }

                /* Print generals
                 * X */
            case 'X':
                {
                    sscanf(buff, "%c", &event);
                    DPRINT("%c\n", event);

                    if ( print_generals() ) {
                        DPRINT("%c succeeded\n", event);
                    } else {
                        fprintf(stderr, "%c failed\n", event);
                    }

                    break;
                }

                /* Print registration hashtable
                 * Y */
            case 'Y':
                {
                    sscanf(buff, "%c", &event);
                    DPRINT("%c\n", event);

                    if ( print_registration_hashtable() ) {
                        DPRINT("%c succeeded\n", event);
                    } else {
                        fprintf(stderr, "%c failed\n", event);
                    }

                    break;
                }

                /* Empty line */
            case '\n':
                break;

                /* Ignore everything else */
            default:
                DPRINT("Ignoring buff: %s \n", buff);

                break;
        }
    }

    free_world();
    return (EXIT_SUCCESS);
}
