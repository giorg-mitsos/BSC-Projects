/************************************************************//**
 * @file   main.c                                      			*
 * @author Antonis Papaioannou <papaioan@csd.uoc.gr>  			*
 *                                                    			*
 * @brief Header function for the needs of cs-240a project 2017 *
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
	int initialize() {
		general_sentinel= (struct general*)malloc(sizeof(struct general));
		registration_sentinel=(struct soldier*)malloc(sizeof(struct soldier));
		registration_sentinel->gid=-1;
		registration_sentinel->next=NULL;
		registration_sentinel->sid=-1;
		general_sentinel->combats_no=-1;
		general_sentinel->soldiers_head=NULL;
		general_sentinel->soldiers_tail=NULL;
		general_sentinel->next=NULL;
		general_sentinel->gid=-1;
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
	int register_soldier (int sid, int gid) {
		struct soldier *root=(struct soldier*)malloc(sizeof(struct soldier));
		root->sid=sid;
		root->gid=gid;
		root->next=NULL;
		if (registration_list == NULL){
			registration_list = root;
			root->next= registration_sentinel;
		}
		else {
			root->next= registration_list;
			registration_list = root;
		}
		
		return 1;
	}

	/**
	 * @brief General or King joins the battlefield
	 *
     * @param gid The general's id
	 * @return 1 on success
	 *         0 on failure
	 */
	 int add_general(int gid) {
	 	struct general *root = (struct general*)malloc(sizeof(struct general));
	 	root->combats_no=0;
	 	root->gid=gid;
	 	root->next=NULL;
	 	root->soldiers_head=NULL;
	 	root->soldiers_tail=NULL;
	 	if (generals_list == NULL){
	 		generals_list = root;
	 		root->next=general_sentinel;
		 }
		else{
			root->next = generals_list;
			generals_list = root;
		 	
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
		struct soldier *sol=registration_list;
		struct general *gen;
		struct DDL_soldier *root;
		if (sol!=NULL){
		
			while (sol->sid!=-1){
				gen = generals_list;
				while (gen->gid!=sol->gid){
					gen = gen->next;
				}
				root=(struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
				root->sid = sol->sid;
				root->next=NULL;
				root->prev=NULL;
				if (gen->gid==sol->gid){
					if (gen->soldiers_head==NULL){						//prwtos komvos
						gen->soldiers_head=root;
						gen->soldiers_tail=root;
					}
					else if((gen->soldiers_head!=NULL) && (gen->soldiers_head->sid > root->sid) && (gen->soldiers_head->next == NULL)){  //deuteros komvos mikroteros apo ton prwto
						gen->soldiers_head->prev=root;
						root->next=gen->soldiers_head;
						gen->soldiers_head=root;
					}
					else if ((gen->soldiers_head!=NULL) && (gen->soldiers_head->sid < root->sid) && (gen->soldiers_head->next==NULL)){ //deuteros komvos megaliteros apo ton prwto
						root->prev=gen->soldiers_head;
						gen->soldiers_head->next=root;
						gen->soldiers_tail=root;
					}
					else if(gen->soldiers_head->sid > root->sid){
						root->next = gen->soldiers_head;
						gen->soldiers_head->prev=root;
						gen->soldiers_head=root;
						
					}
					else {
						struct DDL_soldier *temp;
						temp = gen->soldiers_head;
						while (temp->sid < root->sid){
							if (temp->next!=NULL){
								temp=temp->next;
								continue;
							}
							break;
						}
						if (temp->next == NULL && temp->sid < root->sid){
							temp->next=root;
							root->prev=temp;
							gen->soldiers_tail = root;		
						}
						else{
							struct DDL_soldier *temp2=temp;
							temp=temp->prev;
							temp->next=root;
							temp2->prev=root;
							root->next=temp2;
							root->prev=temp;
						}			
					}		
				}
				sol=sol->next;
			}
		}
		else{
			printf ("No soldiers registered!!!\n");
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
		if (gid1==gid2)return 0;
		struct general *gen1,*gen2;
		gen1=generals_list;
		gen2=generals_list;
		while (gen1->gid!=gid1){
			if (gen1->gid!=-1){
				gen1=gen1->next;
			}
			else{
				return 0;
			}
		}
		while (gen2->gid!=gid2){
			if(gen2->gid!=-1){
				gen2=gen2->next;
			}
			else{
				return 0;
			}
			
		}
		struct DDL_soldier *list1,*list2;
		list1=gen1->soldiers_head;
		list2=gen2->soldiers_head;
		if (list1==NULL){				
			struct general *temp=generals_list;
			if (temp==gen1){
				generals_list=generals_list->next;
			}
			else{
				while(temp->next!=gen1){
					temp=temp->next;
				}
				if (temp->next->gid==gen1->gid){
					temp->next=temp->next->next;
				}
				
			}
		}
		else if(list2==NULL){
			while(list1!=gen1->soldiers_tail){
				struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
				root->sid=list1->sid;
				root->next=NULL;
				if (gen2->soldiers_head==NULL){
					gen2->soldiers_head = root;
					root->prev=NULL;
					list1=list1->next;
					gen2->soldiers_tail=root;
					list2= gen2->soldiers_head;
				}
				else{
					root->prev = list2;
					list2->next=root;
					list2=list2->next;
					list1=list1->next;
					gen2->soldiers_tail=root;
				}
				
			}
			struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
			root->sid=list1->sid;
			root->next=NULL;
			root->prev=list2;
			list2->next=root;
			gen2->soldiers_tail=root;
		}
		else{
			while(list1!=gen1->soldiers_tail && list2!=gen2->soldiers_tail){
				if (list1->sid<list2->sid){
					struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
					root->sid=list1->sid;
					root->next=list2;
					if (gen2->soldiers_head==list2){
						gen2->soldiers_head=root;
						list2->prev = root;
						root->prev=NULL;
						
					}
					else{
						struct DDL_soldier* temp;
						temp = list2->prev;
						temp->next=root;
						root->prev = list2->prev;
						list2->prev=root;
						
					}
					list1=list1->next;
				}
				else{
					list2=list2->next;
				}
				
			}
			if (list1==gen1->soldiers_tail){
				while(list2->sid<list1->sid && list2!=gen2->soldiers_tail){
					list2=list2->next;
				}
				if (list1->sid<list2->sid){
					struct DDL_soldier* temp = list2->prev;
					struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
					root->sid=list1->sid;
					root->next=list2;
					root->prev=temp;
					temp->next=root;
					list2->prev=root;
				}
				else{
					struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
					root->sid=list1->sid;
					root->next = NULL;
					root->prev=list2;
					list2->next=root;
					gen2->soldiers_tail=root;
				}
				
			}
			else if(list2==gen2->soldiers_tail){
				if(list1->sid<list2->sid){
					while(list1->sid<list2->sid && list1!=gen1->soldiers_tail){
						struct DDL_soldier* root=(struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
						root->sid=list1->sid;
						if (list2==gen2->soldiers_head && list2==gen2->soldiers_tail){
							gen2->soldiers_head=root;
							root->next=list2;
							root->prev= NULL;
							list2->prev=root;
							list1=list1->next;
						}
						else{
							struct DDL_soldier* temp = list2->prev;
							temp->next=root;
							root->prev=temp;
							root->next=list2;
							list2->prev=root;
							list1=list1->next;
						}
					}			
				}
				while(list1!=gen1->soldiers_tail){
					struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
					root->sid=list1->sid;
					root->prev=list2;
					root->next= NULL;
					list2->next = root;
					list2=list2->next;
					list1=list1->next;
				}
				struct DDL_soldier* root = (struct DDL_soldier*)malloc(sizeof(struct DDL_soldier));
				root->sid=list1->sid;
				if (list1->sid > list2->sid){
					root->prev=list2;
					root->next= NULL;
					list2->next = root;
					gen2->soldiers_tail = root;
				}
				else{
					root->prev=list2->prev;
					struct DDL_soldier* temp = list2->prev;
					temp->next=root;
					list2->prev=root;
					root->next=list2;
				}
				
			}
			
		}
		struct general *temp=generals_list;
		if (temp==gen1){
			generals_list=generals_list->next;
		}
		else{
			while(temp->next!=gen1){
				temp=temp->next;
			}
			if (temp->next->gid==gen1->gid){
				temp->next=temp->next->next;
			}
		}
		struct soldier* change = registration_list;
		while (change->sid!=-1){
			if (change->gid==gen1->gid){
				change->gid=gen2->gid;
			}
			change=change->next;
		}
		return 1;
	}
        
	/**
	 * @brief Prepare for battle
     * 
	 * @param gid1 The id of the first general
     * @param gid2 The id of the second general
     * @param gid3 The id of the third general
      * 
	 * @return 1 on success
	 *         0 on failure
	 */
	int prepare_battle(int gid1, int gid2, int gid3) {
		struct general *gen1=NULL,*gen2=NULL,*gen3=NULL;
		if(gid1==gid2 || gid2==gid3 || gid3==gid1){
			printf ("Duplicate General Spotted...\n");
			return 0;
		}
		else{
			struct general* temp=generals_list;
			while(temp!=general_sentinel){
				if (gid1==temp->gid){
					gen1=temp;
					break;
				}
				else{
					temp=temp->next;
				}
			}
			temp=generals_list;
			while(temp!=general_sentinel){
				if(gid2==temp->gid){
					gen2=temp;
					break;
				
				}
				else{
					temp=temp->next;
				}
			}
			temp=generals_list;
			while(temp!=general_sentinel){
				if(gid3==temp->gid){
					gen3=temp;
					break;
				}
				else{
					temp=temp->next;
				}
			}
			
			if (gen1==NULL || gen2==NULL || gen3 == NULL){
				printf ("General not Found\n");
				return 0;
			}
		}
		
		/*have ----gen1, gen2, gen3, my_combat----*/
		gen1->combats_no++;
		gen2->combats_no++;
		gen3->combats_no++;
		int s1=0,s2=0,s3=0;
		int change1=0,change2=0,change3=0;
		struct c_soldier *temp;
		/*s1,s2,s3 defines meet of two pointers in soldier list true if the meet (1) */
		/*change1.2.3 defines from where soldiers are putted ex. when change2 = 0 soldier get from left (0=left,1=right)*/
		struct DDL_soldier *r1,*l1,*r2,*l2,*r3,*l3;
		r1=gen1->soldiers_tail;
		l1=gen1->soldiers_head;
		r2=gen2->soldiers_tail;
		l2=gen2->soldiers_head;
		r3=gen3->soldiers_tail;
		l3=gen3->soldiers_head;
		while(s1!=1 || s2!=1 || s3!=1){
			
			if (s1==0){
				if (change1==0){
					
					if(my_combat->combat_s==NULL){
						
						struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
						root->alive=1;
						root->gid=gid1;
						root->sid=l1->sid;
						root->next=NULL;
						my_combat->combat_s=root;
						my_combat->soldier_cnt=1;
						temp=root;
						if(l1==r1){
							s1=1;
						}
						else if(l1->next!=NULL){
							l1=l1->next;
						}
					}
					else{
						
						struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
						root->alive=1;
						root->gid=gid1;
						root->next=NULL;
						root->sid=l1->sid;
						temp->next=root;
						temp=temp->next;
						my_combat->soldier_cnt++;
						if(l1==r1){
							s1=1;
						}
						else if (l1->next!=NULL){
							l1=l1->next;
						}
						
					}
					change1 = 1;	
				}
				else{
					
					struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
					root->gid=gid1;
					root->sid=r1->sid;
					root->next=NULL;
					root->alive=1;
					temp->next = root;
					temp=temp->next;
					my_combat->soldier_cnt++;
					if(l1==r1){
						s1=1;
					}
					else if(r1->prev!=NULL){
						r1=r1->prev;
					}
					change1 = 0;	
				}
				
			}
			if(s2==0){
				if(change2==0){
					
					struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
					root->alive=1;
					root->gid=gid2;
					root->next=NULL;
					root->sid=l2->sid;
					temp->next=root;
					temp=temp->next;
					my_combat->soldier_cnt++;
					if(r2==l2){
						s2=1;
					}
					else if(l2->next!=NULL){
						
						l2=l2->next;
					}	
					change2=1;
				}
				else{
					
					struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
					root->alive=1;
					root->gid=gid2;
					root->next=NULL;
					
					root->sid=r2->sid;
					
					my_combat->soldier_cnt++;
					temp->next=root;
					temp=temp->next;
					if(r2==l2){
						s2=1;
						
					}
					else if(r2->prev!=NULL){
						
						r2=r2->prev;
					}
					change2=0;
					
				}
				
			}
			if(s3==0){
				if(change3==0){
					struct c_soldier *root=(struct c_soldier*)malloc(sizeof(struct c_soldier));
					root->alive=1;
					root->gid=gid3;
					root->sid=l3->sid;
					root->next=NULL;
					temp->next=root;
					temp=temp->next;
					my_combat->soldier_cnt++;
					if(l3==r3){
						s3=1;
					}
					else if(l3->next!=NULL){
						l3=l3->next;
					}
					change3=1;
				}
				else{
					
					struct c_soldier *root = (struct c_soldier*)malloc(sizeof(struct c_soldier));
					root->alive=1;
					my_combat->soldier_cnt++;
					root->gid=gid3;
					root->sid=r3->sid;
					root->next=NULL;
					temp->next=root;
					temp=temp->next;
					if(r3==l3){
						s3=1;
					}
					else if(r3->prev!=NULL){
						r3=r3->prev;
					}
					
					change3=0;
				}	
			}
		
		}
		
		struct c_soldier *temp2=my_combat->combat_s;
		printf ("	Combat soldiers(%d) : ",my_combat->soldier_cnt);
		while(temp2!=NULL){
			printf ("<%d>, ",temp2->sid);
			temp2=temp2->next;
		}
		printf ("\b\b \n");
		
		
		return 1;
	}
        
	/**
	 * @brief Battle
     * 
     * @param god_favor 
     *
	 * @return 1 on success
	 *         0 on failure
	 */
	int battle(int god_favor) {
		if (god_favor == 1){
			int i=0;
			struct c_soldier *temp = my_combat->combat_s;
			printf ("God power help you with this battle only a few died!!!\n");
			printf ("Combat soldiers: ");
			while(temp!=NULL){
				if ((i % 10) == 0){
					temp->alive=0;
				}
				printf ("<%d:%d>, ",temp->sid,temp->alive);
				temp=temp->next;
				i++;
			}
			printf ("\b\b \n");
			
		}
		else{
			struct c_soldier *temp = my_combat->combat_s;
			int s = my_combat->soldier_cnt*(0.4);
			int i=0;
			printf ("Unfortunately Gods did not help you %d soldiers died!!!\n",s);
			printf ("Combat soldiers: ");
			while (i<s){
				i++;
				temp->alive=0;
				printf ("<%d:%d>, ",temp->sid,temp->alive);
				temp=temp->next;
			}
			while(temp!=NULL){
				printf ("<%d:%d>, ",temp->sid,temp->alive);
				temp=temp->next;
			}
			printf ("\b\b \n");
			
		}
		return 1;
	}
        
	/**
	 * @brief Cease fire
     * 
	 * @return 1 on success
	 *         0 on failure
	 */
	int cease_fire() {
		/*
			skeftika na valw kateuthian ta list1,2,3 kai gen1,2,3 efoson oi prwtoi 3 stratiwtes einai apo tous 3 diaforetikous generals wste na min 
			elenxw kathe fora ta if list(x)==NULL alla i diasxisi tis listas prepei na ginei mia fora kai den to riskara
			Erwthsh : pia skepsi simferei perisotero? (pithani apantisi: i deuteri se plithos megalitero apo n)
		*/
		struct c_soldier *runner = my_combat->combat_s;
		struct DDL_soldier *list1h=NULL,*list1t=NULL,*list2h=NULL,*list2t=NULL,*list3h=NULL,*list3t=NULL;
		struct general *genlist=generals_list;
		struct general *gen1=NULL,*gen2=NULL,*gen3=NULL;
		while(runner!=NULL){
			if(gen1==NULL){
				while(genlist!=general_sentinel){	
					if (genlist->gid==runner->gid){
						gen1=genlist;
						genlist=generals_list;
						list1h=gen1->soldiers_head;
						list1t=gen1->soldiers_tail;
						break;
					}
					genlist=genlist->next;
				}
			}
			else if(gen2==NULL){
				while(genlist!=general_sentinel){
					if(genlist->gid==runner->gid){
						gen2=genlist;
						genlist=generals_list;
						list2h=gen2->soldiers_head;
						list2t=gen2->soldiers_tail;
						break;
					}
					genlist=genlist->next;
				}
			}
			else if(gen3==NULL){
				while(genlist!=general_sentinel){
					if(genlist->gid==runner->gid){
						gen3=genlist;
						genlist=generals_list;
						list3h=gen3->soldiers_head;
						list3t=gen3->soldiers_tail;
						break;
					}
					genlist=genlist->next;
				}
			}	
			if(runner->alive==0){ //if not alive	
				//we have list1,list2,list3 pointers to each general soldiers and gen1,gen2,gen3 pointers to the three soldiers	
				if (runner->gid==gen1->gid){
					if (runner->sid==gen1->soldiers_head->sid && runner->sid==list1h->sid){
						if(runner->sid==gen1->soldiers_tail->sid && runner->sid==list1t->sid){
							gen1->soldiers_head=NULL;
							gen1->soldiers_tail=NULL;
							list1h=NULL;
							list1t=NULL;
						}
						else{
							gen1->soldiers_head=gen1->soldiers_head->next;
							gen1->soldiers_head->prev=NULL;
							list1h=gen1->soldiers_head;
						}
					}
					else if(runner->sid==gen1->soldiers_tail->sid && list1t->sid==runner->sid){
						gen1->soldiers_tail=gen1->soldiers_tail->prev;
						gen1->soldiers_tail->next=NULL;
						list1t=gen1->soldiers_tail;
					}
					else{
						struct DDL_soldier *left,*right;
						if(list1h->sid==runner->sid){
							left=list1h->prev;
							right=list1h->next;
							left->next=right;
							right->prev=left;
							list1h=right;
						}
						else if(list1t->sid==runner->sid){
							left=list1t->prev;
							right=list1t->next;
							left->next=right;
							right->prev=left;
							list1t=left;
						}
						
					}
					
				}
				else if(runner->gid==gen2->gid){
					if (runner->sid==gen2->soldiers_head->sid && runner->sid==list2h->sid){
						if(runner->sid==gen2->soldiers_tail->sid && runner->sid==list2t->sid){
							gen2->soldiers_head=NULL;
							gen2->soldiers_tail=NULL;
							list2h=NULL;
							list2t=NULL;
						}
						else{
							gen2->soldiers_head=gen2->soldiers_head->next;
							gen2->soldiers_head->prev=NULL;
							list2h=gen2->soldiers_head;
						}
					}
					else if(runner->sid==gen2->soldiers_tail->sid && list2t->sid==runner->sid){
						gen2->soldiers_tail=gen2->soldiers_tail->prev;
						gen2->soldiers_tail->next=NULL;
						list2t=gen2->soldiers_tail;
					}
					else{
						struct DDL_soldier *left,*right;
						if(list2h->sid==runner->sid){
							left=list2h->prev;
							right=list2h->next;
							left->next=right;
							right->prev=left;
							list2h=right;
						}
						else if(list2t->sid==runner->sid){
							left=list2t->prev;
							right=list2t->next;
							left->next=right;
							right->prev=left;
							list2t=left;
						}
						
					}
				
				}
				else if(runner->gid==gen3->gid){
					if (runner->sid==gen3->soldiers_head->sid && runner->sid==list3h->sid){
						if(runner->sid==gen3->soldiers_tail->sid && runner->sid==list3t->sid){
							gen3->soldiers_head=NULL;
							gen3->soldiers_tail=NULL;
							list3h=NULL;
							list3t=NULL;
						}
						else{
							gen3->soldiers_head=gen3->soldiers_head->next;
							gen3->soldiers_head->prev=NULL;
							list3h=gen3->soldiers_head;
						}
					}
					else if(runner->sid==gen3->soldiers_tail->sid && list3t->sid==runner->sid){
						gen3->soldiers_tail=gen3->soldiers_tail->prev;
						gen3->soldiers_tail->next=NULL;
						list3t=gen3->soldiers_tail;
					}
					else{
						struct DDL_soldier *left,*right;
						if(list3h->sid==runner->sid){
							left=list3h->prev;
							right=list3h->next;
							left->next=right;
							right->prev=left;
							list3h=right;
						}
						else if(list3t->sid==runner->sid){
							left=list3t->prev;
							right=list3t->next;
							left->next=right;
							right->prev=left;
							list3t=left;
						}
						
					}
					
				}
				else{
					printf ("Something gone wrong...\nIgnoring : Sid:%d Gid:%d  \n",runner->sid,runner->gid);
					runner=runner->next;
					continue;
				}
				
				//delete from registration list
				struct soldier *access = registration_list;
				struct soldier *temp = access;
				while(access!=registration_sentinel){
					if(runner->sid==registration_list->sid){
						registration_list=registration_list->next;
					}
					else if(runner->sid==access->sid){
						while(temp->next!=access){
							temp=temp->next;
						}
						temp->next=access->next;
					}
					access=access->next;
				}
				
				
								
			}
			else{  //if alive
				if (runner->gid==gen1->gid){
					if(runner->sid==list1h->sid){
						list1h=list1h->next;
					}
					else if(runner->sid==list1t->sid){
						list1t=list1t->prev;
					}
				}
				else if(runner->gid==gen2->gid){
					if(runner->sid==list2h->sid){
						list2h=list2h->next;
					}
					else if(runner->sid==list2t->sid){
						list2t=list2t->prev;
					}
				}
				else if(runner->gid==gen3->gid){
					if(runner->sid==list3h->sid){
						list3h=list3h->next;
					}
					else if(runner->sid==list3t->sid){
						list3t=list3t->prev;
					}
				}
			}
			
			
			
			
			
			runner=runner->next;
		}
		my_combat->combat_s=NULL;
		my_combat->soldier_cnt=0;
		return 1;
	}
        
	/**
	 * @brief Trojan Horse
	 *
	 * @return 1 on success
	 *         0 on failure
	 */
	int trojan_horse() {
		
		struct general *A[5];
		struct general *gen=generals_list;
		int i=0;
		while (i<5){
			if(gen!=general_sentinel){
				A[i]=gen;
				gen=gen->next;
			}
			else{
				printf ("General number %d is missing\n",i+1);
				A[i]=NULL;
				return 0;
			}
			i++;
		}
		while(gen!=general_sentinel){
			int i = min(A[0]->combats_no,A[1]->combats_no,A[2]->combats_no,A[3]->combats_no,A[4]->combats_no);
			if(gen->combats_no>A[i]->combats_no){
				A[i]=gen;
			}
			gen=gen->next;
		}
		printf ("General = ");
		int a=0;
		while (a<5){
			printf("<%d:%d>, ",A[a]->gid,A[a]->combats_no);
			a++;
		}
		printf ("\b\b \n");
		
		
		return 1;
	}
	
	int min(int a,int b,int c,int d, int e){
		int i=0;
		int min=a;
		if(min>b){
			min=b;
			i=1;
		}
		if(min>c){
			min=c;
			i=2;
		}
		if(min>d){
			min=d;
			i=3;
		}
		if(min>e){
			min=e;
			i=4;
		}
		return i;
	}
	  
	/**
	 * @brief Print generals
	 *
	 * @return 1 on success
	 *         0 on failure
	 */
	int print_generals() {
		printf ("GENERALS:\n");
				struct general *gen=generals_list;
				struct DDL_soldier *sol;
				while (gen->gid!=-1){
					printf ("	<%d>: ",gen->gid);
					sol=gen->soldiers_head;
					if (sol!=NULL){
						do{
							printf ("<%d>, ",sol->sid);
							if (sol->next!=NULL){
								sol=sol->next;
							}
						}while (sol!=gen->soldiers_tail);
						if (gen->soldiers_head!=gen->soldiers_tail){
						
							printf ("<%d>, ",sol->sid);
							
						}
						printf ("\b\b \n");
					}
					else{
						printf ("\b\b \n");
					}
					gen=gen->next;
				}
				printf ("DONE\n");
		return 1;
	}
        
	/**
	 * @brief Print registration list
	 *
	 * @return 1 on success
	 *         0 on failure
	 */
	int print_registration_list() {
		printf("	Registration list = ");
		struct soldier *temp = registration_list;
		if (temp==NULL){
			printf("No registrations");
			printf("\nDONE\n");
		}
		else{
			while (temp->sid!=-1){
				printf ("<%d:%d>, ",temp->sid,temp->gid);
				temp=temp->next;
			}
			printf ("\b\b ");
			printf ("\nDONE\n");
		}
		return 1;
	}



	int free_world() {
		return 1;
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

	initialize();

	/* Read input file buff-by-buff and handle the events */
	while ( fgets(buff, BUFFER_SIZE, fin) ) {

		DPRINT("\n>>> Event: %s", buff);

		switch(buff[0]) {

		/* Comment */
		case '#':
			break;

		/* Register soldier
		 * R <sid> <gid> */
		case 'R':
		{
			int sid, gid;
			sscanf(buff, "%c %d %d", &event, &sid, &gid);
			DPRINT("%c %d %d\n", event, sid, gid);


			if ( register_soldier(sid, gid) ) {
				DPRINT("R %d %d succeeded\n", sid, gid);
				printf ("R <sid> <gid>\n	Registration list = ");
				struct soldier *temp = registration_list;
				while (temp->sid!=-1){
					printf ("<%d:%d>, ",temp->sid,temp->gid);
					temp=temp->next;
				}
				printf ("\b\b ");
				printf ("\nDONE\n");
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
				struct general *temp = generals_list;
				
				printf ("G <gid> \n 	Generals = ");
				while (temp->gid!=-1){
					printf ("<%d>, ",temp->gid);
					temp = temp->next;
				}
				printf ("\b\b ");
				printf ("\nDONE \n");
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
				print_generals();
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
				print_generals();
			} else {
				fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
			}

			break;
		}

		/* Prepare for battle
		 * P <gid1> <gid2> <gid3> */
		case 'P':
		{
			int gid1, gid2, gid3;
			sscanf(buff, "%c %d %d %d", &event, &gid1, &gid2, &gid3);
			DPRINT("%c %d %d %d\n", event, gid1, gid2, gid3);

			if ( prepare_battle(gid1, gid2, gid3) ) {
				DPRINT("%c %d %d %d succeeded\n", event, gid1, gid2, gid3);
			} else {
				fprintf(stderr, "%c %d %d %d failed\n", event, gid1, gid2, gid3);
			}

			break;
		}

		/* Battle
		 * B <god_favor> */
		case 'B':
		{
			int god_favor;
			sscanf(buff, "%c %d\n", &event, &god_favor);
			DPRINT("%c %d\n", event, god_favor);

			if ( battle(god_favor) ) {
				DPRINT("%c %d succeeded\n", event, god_favor);
			} else {
				fprintf(stderr, "%c %d failed\n", event, god_favor);
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

		/* Trojan Horse
		 * T */
		case 'T':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if ( trojan_horse() ) {
				DPRINT("%c succeeded\n", event);
			} else {
				fprintf(stderr, "%c failed\n", event);
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

		/* Print registration list
		 * Y */
		case 'Y':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if ( print_registration_list() ) {
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
