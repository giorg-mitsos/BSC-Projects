#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "geo.h"

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
* @brief Add a new location to the system
*
* @param lid The location's id
*
* @return true on success
*         false on failure
*/

int add_location(int lid) {
	int flag=0;
	struct location *root=(struct location*)malloc(sizeof(struct location));
	root->poi_list=NULL;
	if (locations_list==NULL){
		locations_list = root;
		root->lid=lid;
		root->next=NULL;
		flag=1;
	}
	else if( lid<locations_list->lid){
		root->lid=lid;
		root->next=locations_list;
		locations_list=root;
		flag=1;
	}
	else if(locations_list->next==NULL && locations_list->lid<lid){
		root->lid=lid;
		locations_list->next=root;
		root->next=NULL;
		flag=1;	
	}
	else{
		struct location *temp,*temp2;
		temp2=locations_list->next;
		temp=locations_list;
		if (temp2->next==NULL && temp->lid<lid && temp2->lid>lid){
			root->next=temp2;
			root->lid=lid;
			temp->next=root;
			flag=1;
		}
		while (temp2->next!=NULL){
			if (temp->lid<lid && temp2->lid>lid){
				root->next=temp2;
				root->lid=lid;
				temp->next=root;
				flag=1;
				break;
			}
			else{
				temp2=temp2->next;
				temp=temp->next;
			}
		}
		if (temp2->next==NULL && temp2->lid>lid && temp->lid<lid)
		{
			root->next=temp2;
			root->lid=lid;
			temp->next=root;
			flag=1;
		}
	}
	if (flag==0){
		struct location *temp=locations_list;
		root->lid=lid;
		root->next=NULL;
		while (temp->next!=NULL ){
			temp=temp->next;		
		}
		if (locations_list!=root){
			temp->next=root;
		}
	}	
	return 1;
}

/**
* @brief Add point-of-interest (POI) to a location
* 
* @param pid POI's id
* @param type The type of the POI
* @param distance The distance of POI from the locations reference point
* @param lid The location of the POI
*
* @return true on success
*         false on failure
*/
int add_poi_to_location(int pid, int type, int distance, int lid) {
	struct poi *root=(struct poi*)malloc(sizeof(struct poi));
	struct location *temp=locations_list;
	struct poi *search;
	int sum=0,flag=0;
	while (temp->lid!=lid){
		temp=temp->next;	
	}
	/*first poi_interest */
	if (temp->poi_list==NULL){
		temp->poi_list=root;
		root->distance=distance;
		root->next=NULL;
		root->pid=pid;
		root->prev=NULL;
		root->type=type;
		flag=1;
	}
	else if(temp->poi_list!=NULL && distance < temp->poi_list->distance){
		root->distance=distance;
		root->next=temp->poi_list;
		root->pid=pid;
		root->prev=NULL;
		root->type=type;
		flag=1;
		search=temp->poi_list;
		search->prev=root;
		search->distance=search->distance-distance;
		temp->poi_list=root;
	}
	/*second poi_of_interest*/
	else if(temp->poi_list!=NULL && temp->poi_list->next==NULL){
		search=temp->poi_list;
		if (distance< search->distance){
			root->pid=pid;
			root->prev=NULL;
			root->next=temp->poi_list;
			root->distance=distance;
			search->prev=root;
			search->distance=search->distance-distance;
			root->type=type;
			temp->poi_list=root;
			flag=1;
		}
		else if(distance>search->distance){
			search->next=root;
			root->distance=distance-search->distance;
			root->pid=pid;
			root->next=NULL;
			root->prev=search;
			root->type=type;
			flag=1;
		}
		
	}
	else{
		int flag2=0;
		sum=0;
		search=temp->poi_list;
		struct poi *search2=search->next;
		while (sum+search->distance<distance){
			sum=sum+search->distance;
			if (search2->next==NULL){
				flag2=1;
				break;
			}
			search=search->next;
			search2=search2->next;
		}
		if (flag2==0){
			search2=search;
			search=search->prev;
			root->distance=distance-sum;
			root->next=search2;
			root->prev=search;
			search->next=root;
			search2->prev=root;
			root->pid=pid;
			root->type=type;
			flag=1;
			search2->distance=search2->distance-root->distance;
		}
		else if (flag2==1 && distance<sum+search2->distance){
			root->distance=distance-sum;
			root->next=search2;
			root->prev=search;
			search->next=root;
			search2->prev=root;
			root->pid=pid;
			root->type=type;
			flag=1;
			search2->distance=search2->distance-root->distance;
			
		}
		
		
	}
	if (flag==0){
		sum=0;
		search=temp->poi_list;
		while(search->next!=NULL){
			sum=sum+search->distance;
			search=search->next;
		}
		sum=sum+search->distance;
		search->next=root;
		root->prev=search;
		root->type=type;
		root->distance=distance-sum;
		root->next=NULL;
		root->pid=pid;
		
		
	}
	
	return 1;
}

/**
* @brief A POI is unavailable to vistors
*
* @param pid The POI's id
* @param lid The location's id
* 
* @return true on success
*         false on failure
*/
int unavailable_poi(int pid, int lid) {
	struct location *search=locations_list;
	struct poi *search2;
	while (search->lid!=lid){
		search=search->next;	
	}
	search2=search->poi_list;
	while (pid!=search2->pid){
		search2=search2->next;
	}
	if (search2->next==NULL){
		struct poi *prev=search2->prev;
		prev->next=NULL;
	}
	else if(search2->prev==NULL){
		struct poi* flag=search2->next;
		int left=search2->distance;
		flag->distance=flag->distance+left;
		search->poi_list=flag;
	}
	else{
	
	struct poi *next=search2->next;
	struct poi *prev=search2->prev;
	int left=search2->distance;
	next->distance=next->distance+left;
	next->prev=prev;
	prev->next=next;
	}
	
	return 1;
}
        
/**
* @brief Register user
*
* @param uid The user's id
* 
* @return true on success
*         false on failure
*/
int register_user(int uid) {
	struct user *root=(struct user*)malloc(sizeof(struct user));
	root->interesting_poi=NULL;
	if (users_list==NULL){
		users_list=root;
		root->uid=uid;
		root->next=NULL;
	}
	else{
		root->uid=uid;
		root->next=NULL;
		struct user *temp=users_list;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=root;
	}
	
	return 1;
}
        
/**
* @brief User is interested in POI
* 
* @param uid The user's id
* @param pid The POI's id
*
* @return true on success
*         false on failure
*/
int interesting_poi(int uid, int upid) {
	struct user_poi *root=(struct user_poi*)malloc(sizeof(struct user_poi));
	struct user *search=users_list;
	struct user_poi *temp,*temp2;
	int flag=0;
	while(search->uid!=uid){
		search=search->next;
	}
	root->upid=upid;
	if (search->interesting_poi==NULL){
		search->interesting_poi=root;
		root->next=NULL;
		return 1;
	}
	temp=search->interesting_poi;
	if (temp->next==NULL && temp->upid<upid){
		temp->next=root;
		root->next=NULL;
		return 1;
	}
	else if (temp->upid>upid){
		root->next=temp;
		search->interesting_poi=root;
		return 1;
	}
	else{
		temp=search->interesting_poi;
		temp2=temp->next;
		if (temp2->next==NULL && temp->upid<upid && temp2->upid>upid){
			root->next=temp2;
			temp->next=root;
			flag=1;
		}
		while (temp2->next!=NULL){
			if (temp2->upid>upid && temp->upid<upid){
				root->next=temp2;
				temp->next=root;
				flag=1;
				break;
			}
			else{
				temp2=temp2->next;
				temp=temp->next;
			}
		}
		if(temp2->next==NULL && temp2->upid>upid && temp->upid<upid){
			root->next=temp2;
			temp->next=root;
			flag=1;
		}
		if (flag==0){
			temp=search->interesting_poi;
			root->next=NULL;
			while (temp->next!=NULL){
				temp=temp->next;
				
			}
			if (search->interesting_poi!=root){
				temp->next=root;
			}
		}
	}
	
	
	
	
	
	return 1;
}
        
/**
* @brief Group users
* 
* @param uid1 The id of the 1st user
* @param uid2 The id of the 2nd user
* @param uid3 The id of the 3rd user
*
* @return true on success
*         false on failure
*/
int group_users(int uid1, int uid2, int uid3) {
	
	struct user *user1,*user2,*user3,*temp;
	temp=users_list;
	struct user_poi *inpoi1;
	user1=NULL;
	user2=NULL;
	user3=NULL;
	while (temp->next!=NULL){
		if (temp->uid==uid1){
			user1=temp;
		}
		if(temp->uid==uid2){
			user2=temp;
		}
		if(temp->uid==uid3){
			user3=temp;
		}
		temp=temp->next;
	}
	if (user1==NULL || user2==NULL || user3==NULL){
		if (temp->uid==uid1){
			user1=temp;
		}
		if (temp->uid==uid2){
			user2=temp;
		}
		if(temp->uid==uid3){
			user3=temp;
		}
	}
	printf("G <%d> <%d> <%d>\n",user1->uid,user2->uid,user3->uid);
	inpoi1=user1->interesting_poi;
	printf("User1 = ");
	while (inpoi1->next!=NULL){
		printf ("<%d>, ",inpoi1->upid);
		inpoi1=inpoi1->next;
	}
	printf("<%d>\n",inpoi1->upid);
	inpoi1=user2->interesting_poi;
	printf("User2 = ");
	while (inpoi1->next!=NULL){
		printf ("<%d>, ",inpoi1->upid);
		inpoi1=inpoi1->next;
	}
	printf("<%d>\n",inpoi1->upid);
	inpoi1=user3->interesting_poi;
	printf("User3 = ");
	while (inpoi1->next!=NULL){
		printf ("<%d>, ",inpoi1->upid);
		inpoi1=inpoi1->next;
	}
	printf("<%d>\n",inpoi1->upid);
	printf("COMMON : ");
	inpoi1=user1->interesting_poi;
	struct user_poi *inpoi2,*inpoi3;
	inpoi1=user1->interesting_poi;
	inpoi2=user2->interesting_poi;
	inpoi3=user3->interesting_poi;
	int flag1=0,flag2=0,flag3=0;
	while (inpoi1->next!=NULL){
		if(inpoi2->upid<inpoi1->upid && inpoi2->next!=NULL){
			inpoi2=inpoi2->next;
			continue;
			if (inpoi2->next==NULL){
				printf("flag 2!!!!!!!");
				flag2=1;
			}
		}
		if(inpoi3->upid<inpoi1->upid && inpoi3->next!=NULL){
			inpoi3=inpoi3->next;
			continue;
			if (inpoi3->next==NULL){
				printf("flag 3!!!!!!!!!!");
				flag3=1;
			}
		}
		if (inpoi1->upid==inpoi2->upid && inpoi2->upid==inpoi3->upid){
			printf ("<%d>, ",inpoi1->upid);
		}
		inpoi1=inpoi1->next;	
	}
	if (flag2==1){
		while(inpoi3->next!=NULL){
			if (inpoi3->upid==inpoi2->upid && inpoi1->upid==inpoi3->upid){
				printf ("<%d> ",inpoi1->upid);
			}
			else {
				inpoi3=inpoi3->next;
			}
			
		}
	}
	else if(flag3==1){
		while (inpoi2->next!=NULL){
			if (inpoi2->upid==inpoi1->upid && inpoi3->upid==inpoi1->upid){
				printf ("<%d> ",inpoi1->upid);
			}
			else{
				inpoi2=inpoi2->next;
			}
		}
	}
	if (flag2==0 && flag3==0){
		while (inpoi2->next!=NULL){
			if (inpoi3->upid<inpoi2->upid && inpoi3->next!=NULL){
				inpoi3=inpoi3->next;
				continue;
			}
			else{
				inpoi2=inpoi2->next;
			}
			if (inpoi2->upid==inpoi3->upid && inpoi3->upid==inpoi1->upid){
				printf ("<%d>",inpoi1->upid);
			}
		}
		if (inpoi3->next!=NULL){
			inpoi3=inpoi3->next;
		}
	}
	if (inpoi1->upid==inpoi2->upid && inpoi2->upid==inpoi3->upid){
		printf ("<%d>",inpoi1->upid);
	}
	printf("\nDONE\n");
	return 1;
}
        
/**
* @brief Calculate the distance between locations
* 
* @param lid The location's id
* @param pid1 The id of the 1st POI
* @param pid1 The id of the 2nd POI
* @param pid1 The id of the 3rd POI
*
* @return true on success
*         false on failure
*/
int sightseeing_distance(int lid, int pid1, int pid2, int pid3) {
	struct poi *place[3],*temp;
	struct location *search;
	int distance,flag=0,i;
	search=locations_list;
	while (search->lid!=lid){
		search=search->next;
	}
	temp=search->poi_list;
	while(flag!=3){
		if (temp->pid==pid1){
			place[flag]=temp;
			flag++;
		}
		else if(temp->pid==pid2){
			place[flag]=temp;
			flag++;
		}
		else if(temp->pid==pid3){
			place[flag]=temp;
			flag++;
		}
		temp=temp->next;
	}
	distance=0;
	i=0;
 	while (place[i]->pid!=pid1){
 		i++;
	 }
	 temp=place[i];
	 int j=0;
	 while (place[j]->pid!=pid2){
	 	j++;
	 }
	 if (i>j){
	 	while(place[i]->pid!=place[j]->pid){
	 		distance=distance + place[i]->distance;
	 		place[i]=place[i]->prev;
		 }
	 }
	 else{
	 	while (place[i]->pid!=place[j]->pid){
	 		place[i]=place[i]->next;
	 		distance=distance+place[i]->distance;
		 }
	 }
	 i=j;
	 j=0;
	 while(place[j]->pid!=pid3){
	 	j++;
	 }
	 if(i>j){
	 	while(place[i]->pid!=place[j]->pid){
	 		distance=distance+place[i]->distance;
	 		place[i]=place[i]->prev;
		 }
	 }
	 else{
	 	while (place[i]->pid!=place[j]->pid){
	 		place[i]=place[i]->next;
	 		distance=distance+place[i]->distance;
		 }
	 }
	 printf ("B <%d> <%d> <%d> <%d>",lid,pid1,pid2,pid3);
	 printf("\n	Total distance: <%d>",distance);
	 printf("\nDONE\n");
		 
	
	
	return 1;
}
        
/**
* @brief Print all locations
*
* @return true on success
*         false on failure
*/
int print_locations() {
	struct location *temp;
	struct poi *temp2;
	temp=locations_list;
	printf ("LOCATIONS:\n");
	while (temp->next!=NULL){
		printf ("Location <%d> = ",temp->lid);
		temp2=temp->poi_list;
		while (temp2->next!=NULL){
			printf ("<%d:%d:%d>, ",temp2->pid,temp2->type,temp2->distance);
			temp2=temp2->next;
		}
		printf ("<%d:%d:%d>\n",temp2->pid,temp2->type,temp2->distance);
		temp=temp->next;
		
	}
	printf("Location <%d> = ",temp->lid);
	temp2=temp->poi_list;
	while (temp2->next!=NULL){
		printf ("<%d:%d:%d>, ",temp2->pid,temp2->type,temp2->distance);
		temp2=temp2->next;
	}
	printf ("<%d:%d:%d>\n",temp2->pid,temp2->type,temp2->distance);
	
	
	
	
	return 1;
}
        
/**
* @brief Print all users
*
* @return true on success
*         false on failure
*/
int print_users() {
	
	struct user *search;
	struct user_poi *temp;
	search=users_list;
	if (users_list==NULL){
		printf ("No users...\n");
		return 1;
	}
	while (search->next!=NULL){
		printf ("User <%d> :",search->uid);
		temp=search->interesting_poi;
		while (temp->next!=NULL){
			printf ("<%d>, ",temp->upid);
			temp=temp->next;
		}
		printf ("<%d>\n",temp->upid);
		search=search->next;
		
	
	}
	temp=search->interesting_poi;
	printf ("User <%d> :",search->uid);
	while (temp->next!=NULL){
		printf ("<%d>, ",temp->upid);
		temp=temp->next;
	}
	printf ("<%d>\n",temp->upid);
	
	
	

	return 1;
}
        
/**
* @brief Search for user
* 
* @param uid The id of the user we are looking for
*
* @return true on success
*         false on failure
*/
int search_user(int uid) {
	struct user *search=users_list;
	struct user_poi *temp;
	if (search==NULL){
		printf ("number 1");
		return 0;
	}
	while (search->next!=NULL && search->uid!=uid){
		search=search->next;
	}
	if (search->uid!=uid){
		printf ("<%d> <%d>",uid, search->uid);
		printf("number 2");
		return 0;
	}
	temp=search->interesting_poi;
	printf ("Interesting_poi : ");
	while (temp->next!=NULL){
		printf ("<%d>, ",temp->upid);
		temp=temp->next;
	}
	printf ("<%d>\n",temp->upid);
	
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
	locations_list = NULL;
	users_list = NULL;
	users_sentinel = NULL;


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

		/* Add location
		 * L <lid> */
		case 'L':
		{
			int lid;
			sscanf(buff, "%c %d", &event, &lid);
			DPRINT("%c %d\n", event, lid);


			if ( add_location(lid) ) {
				DPRINT("L %d succeeded\n", lid);
			} else {
				fprintf(stderr, "L %d failed\n", lid);
			}
			struct location *po=locations_list;
			printf ("L <%d>\n",lid);
			printf ("	Locations = ");
			while (po!=NULL)
			{
				printf ("<%d> ",po->lid);
				po=po->next;
			}
			printf ("\nDONE\n");

			break;
		}

		/* Add POI to location
		 * P <pid> <type> <distance> <lid> */
		case 'P':
		{
			int pid, type, distance, lid;

			sscanf(buff, "%c %d %d %d %d", &event, &pid, &type, &distance, &lid);
			DPRINT("%c\n", event);

			if ( add_poi_to_location(pid, type, distance, lid) ) {
				DPRINT("%c %d %d %d %d succeeded\n", event, pid, type, distance, lid);
			} else {
				fprintf(stderr, "%c %d %d %d %d failed\n", event, pid, type, distance, lid);
			}
			struct location *temp=locations_list;
			struct poi *temp2;
			while (temp->lid!=lid)
			{
				temp=temp->next;
			}
			temp2=temp->poi_list;
			printf ("P <%d> <%d> <%d>\n",pid,lid,distance);
			printf ("	Location: ");
			while(temp2->next!=NULL){
				printf ("<%d:%d:%d>, ",temp2->pid,temp2->type,temp2->distance);
				temp2=temp2->next;
			}
			printf ("<%d:%d:%d>",temp2->pid,temp2->type,temp2->distance);
			printf ("\nDONE");
			break;
			
		}

		/* POI is not available
		 * A <pid> <lid> */
		case 'A':
		{
			int pid;
			int lid;
			sscanf(buff, "%c %d %d", &event, &pid, &lid);
			DPRINT("%c %d %d\n", event, pid, lid);

			if ( unavailable_poi(pid, lid) ) {
				DPRINT("%c %d %d succeeded\n", event, pid, lid);
			} else {
				fprintf(stderr, "%c %d %d failed\n", event, pid, lid);
			}
			struct location *temp=locations_list;
			struct poi *temp2;
			while (lid!=temp->lid){
				temp=temp->next;
			}
			temp2=temp->poi_list;
			printf("A <%d> <%d>\n",pid,lid);
			printf("	Location: ");
			while (temp2->next!=NULL){
				printf ("<%d:%d:%d>, ",temp2->pid,temp2->type,temp2->distance);
				temp2=temp2->next;
			}
			printf ("<%d:%d:%d> ",temp2->pid,temp2->type,temp2->distance);
			printf ("\nDONE");
			

			break;
		}

		/* Register user
		 * R <uid> <hotel-id> */
		case 'R':
		{
			int uid;
			sscanf(buff, "%c %d", &event, &uid);
			DPRINT("%c %d\n", event, uid);

			if ( register_user(uid) ) {
				DPRINT("%c %d succeeded\n", event, uid);
			} else {
				fprintf(stderr, "%c %d failed\n", event, uid);
			}
			printf ("R <%d>\n",uid);
			printf ("	Users = ");
			struct user *temp=users_list;
			while (temp->next!=NULL){
				printf("<%d>, ",temp->uid);
				temp=temp->next;
			}
			printf("<%d>",temp->uid);
			printf ("\nDONE");

			break;
		}

		/* User interested in poi
		 * I <uid> <pid> */
		case 'I':
		{
			int uid, upid;
			sscanf(buff, "%c %d %d", &event, &uid, &upid);
			DPRINT("%c %d %d\n", event, uid, upid);

			if ( interesting_poi(uid, upid) ) {
				DPRINT("%c %d %d succeeded\n", event, uid, upid);
			} else {
				fprintf(stderr, "%c %d %d failed\n", event, uid, upid);
			}
			printf("I <%d> <%d>\n",uid,upid);
			printf("	POI = ");
			struct user *search=users_list;
			struct user_poi *temp;
			while (search->uid!=uid){
				search=search->next;
			}
			temp=search->interesting_poi;
			while (temp->next!=NULL){
				printf("<%d>, ",temp->upid);
				temp=temp->next;
			}
			printf ("<%d>",temp->upid);
			printf ("\nDONE");
			

			break;
		}

		/* Group users
		 * G <uid1> <uid2> <uid3> */
		case 'G':
		{
			int uid1, uid2, uid3;
			sscanf(buff, "%c %d %d %d", &event, &uid1, &uid2, &uid3);
			DPRINT("%c %d %d %d\n", event, uid1, uid2, uid3);

			if ( group_users(uid1, uid2, uid3) ) {
				DPRINT("%c %d %d %d succeeded\n", event, uid1, uid2, uid3);
			} else {
				fprintf(stderr, "%c %d %d %dfailed\n", event, uid1, uid2, uid3);
			}

			break;
		}

		/* Sightseeing distance
		 * B <lid> <pid1> <pid2> <pid3> */
		case 'B':
		{
			int lid;
			int pid1, pid2, pid3;
			sscanf(buff, "%c %d %d %d %d\n", &event, &lid, &pid1, &pid2, &pid3);
			DPRINT("%c %d %d %d %d\n", event, lid, pid1, pid2, pid3);

			if ( sightseeing_distance(lid, pid1, pid2, pid3) ) {
				DPRINT("%c %d %d %d %d succeeded\n", event, lid, pid1, pid2, pid3);
			} else {
				fprintf(stderr, "%c %d %d %d %d failed\n", event, lid, pid1, pid2, pid3);
			}

			break;
		}

		/* Print locations
         * X */
		case 'X':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if ( print_locations() ) {
				DPRINT("%c succeeded\n", event);
			} else {
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print users
		 * Y */
		case 'Y':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if ( print_users() ) {
				DPRINT("%c succeeded\n", event);
			} else {
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Search user
		 * Z */
		case 'Z':
		{
			int uid;
			sscanf(buff, "%c %d", &event, &uid);
			DPRINT("%c\n", event);

			if ( search_user(uid) ) {
				DPRINT("%c %d succeeded\n", event, uid);
			} else {
				fprintf(stderr, "%c %d failed\n", event, uid);
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
