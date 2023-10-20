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
* @return 1 on success
*         0 on failure
*/




void inorder(struct poi *root);
void userpoi(struct user_poi *root);
int add_location(int lid)
{
	struct location *root=(struct location*)malloc(sizeof(struct location));
	root->lid=lid;
	root->poi_tree=NULL;
	root->poi_sentinel=NULL;
	struct poi *guard=NULL;
	
	if (locations_array[0]==NULL){
		locations_array[0]=root;
		locations_array[0]->poi_sentinel=root->poi_sentinel;
		return 1;
	}
	
	else if (locations_array[1]==NULL){
		
		if (locations_array[0]->lid>lid){
			struct location *temp;
			temp=locations_array[0];
			locations_array[0]=root;
			locations_array[1]=temp;
			locations_array[0]->poi_sentinel=root->poi_sentinel;
			
		}
		else if(locations_array[0]->lid<lid){
			locations_array[1]=root;
			locations_array[1]->poi_sentinel=root->poi_sentinel;
		}
	}
	else{
		int i=0;
		while (locations_array[i]->lid<lid && locations_array[i+1]!=NULL){
			i++;
		}
		if (locations_array[i]->lid==lid)return 0;
		int j=0;
		while (locations_array[j]!=NULL){
			j++;
		}
		if (locations_array[j-1]->lid<lid){
			locations_array[j]=root;
			locations_array[j]->poi_sentinel=root->poi_sentinel;
			return 1;
		}
		else if (locations_array[j-1]->lid>lid && locations_array[j-2]->lid<lid){
			locations_array[j]=locations_array[j-1];
			locations_array[j-1]=root;
			locations_array[j-1]->poi_sentinel=root->poi_sentinel;
			return 1;
		}
		
		while (j>i){
			locations_array[j]=locations_array[j-1];
			j--;
		}
		
		locations_array[i]=root;
		locations_array[i]->poi_sentinel=root->poi_sentinel;
		
	}
	
	return 1;
}

/**
* @brief Add point-of-interest (POI) to a location
* 
* @param pid      POI's id
* @param type     The type of the POI
* @param distance The distance of POI from the locations reference point
* @param lid      The location of the POI
*
* @return 1 on success
*         0 on failure
*/
int add_poi_to_location(int pid, int type, int distance, int lid)
{
	struct poi *root=(struct poi*)malloc(sizeof(struct poi));
	root->distance=distance;
	root->type=type;
	root->pid=pid;
	
	int i=0;
	if (lid>2000)return 0;
	while (locations_array[i]->lid!=lid){
		if (locations_array[i]->lid>lid) return 0;
		i++;
	}
	root->lc=locations_array[i]->poi_sentinel;
	root->rc=locations_array[i]->poi_sentinel;
	if (locations_array[i]->poi_tree==NULL){
		locations_array[i]->poi_tree=root;
		root->lc=locations_array[i]->poi_sentinel;
		root->rc=locations_array[i]->poi_sentinel;
		root->p=NULL;
	}
	else{
		struct poi *temp;
		int flag=0;
		temp=locations_array[i]->poi_tree;
		while (flag==0){
			if (temp->pid>pid && temp->lc!=locations_array[i]->poi_sentinel){
				temp=temp->lc;
			}
			else if(temp->pid>pid && temp->lc==locations_array[i]->poi_sentinel){
				temp->lc=root;
				flag=1;
				root->p=temp;
			}
			if(temp->pid<pid && temp->rc!=locations_array[i]->poi_sentinel){
				temp=temp->rc;
			}
			else if(temp->pid<pid && temp->rc==locations_array[i]->poi_sentinel){
				temp->rc=root;
				flag=1;
				root->p=temp;
				
			}
			if (temp->pid==pid){
				return 0;
			}
		}
	}
  return 1;
}

/**
* @brief A POI is unavailable to visitors
*
* @param pid The POI's id
* @param lid The location's id
* 
* @return 1 on success
*         0 on failure
*/
int unavailable_poi(int pid, int lid)
{	
	int i;
	i=0;
	/* lid found*/
	if (lid>2000)return 0;
	while (locations_array[i]->lid!=lid){
		if (locations_array[i]->lid>lid){
			return 0;
		}
		i++;
		
	}
	/*an den iparxei pid return 0;*/
	struct poi *temp,*temp2,*change;
	temp=locations_array[i]->poi_tree;
	if (temp==locations_array[i]->poi_sentinel){
		return 0;
	}
	/*an uparxei kai einai monadiko*/
	if (temp!=locations_array[i]->poi_sentinel){
		if (temp->pid==pid && temp->lc==locations_array[i]->poi_sentinel && temp->rc==locations_array[i]->poi_sentinel){
			locations_array[i]->poi_tree=locations_array[i]->poi_sentinel;
			free(temp);
		}
	}
	
	
	/* an einai to root me ena paidi*/
	if (temp->pid==pid && temp->p==NULL){
		if (temp->lc==locations_array[i]->poi_sentinel && temp->rc!=locations_array[i]->poi_sentinel){
			locations_array[i]->poi_tree=temp->rc;
			free(temp);
			return 1;
		}
		else if(temp->lc!=locations_array[i]->poi_sentinel && temp->rc==locations_array[i]->poi_sentinel){
			locations_array[i]->poi_tree=temp->lc;
			return 1;
		}
		
	}
	
	/*an einai to root me dyo paidia*/
	if (temp->pid==pid && temp->p==NULL && temp->lc!=locations_array[i]->poi_sentinel && temp->rc!=locations_array[i]->poi_sentinel){
		change=temp;
		temp=temp->rc;
		while (temp->lc!=locations_array[i]->poi_sentinel){
			temp=temp->lc;
		}
		temp->lc=change->lc;
		temp->rc=change->rc;
		temp2=temp->p;
		if (temp2!=locations_array[i]->poi_tree){
			temp2->lc=locations_array[i]->poi_sentinel;
		}
		temp->p=NULL;
		locations_array[i]->poi_tree=temp;
		return 1;
		
	}
		
	int flag=0;
	/*anazitisi komvou*/
	while (flag==0){
		if (pid>temp->pid && temp->rc!=locations_array[i]->poi_sentinel){
			temp=temp->rc;
			flag=1;
		}
		else if (pid<temp->pid && temp->lc!=locations_array[i]->poi_sentinel){
			temp=temp->lc;
			flag=1;
		}
		if (flag==1){
			flag=0;
		}
		else if (flag==0 && temp->pid!=pid){
			return 0;
		}
		if (temp->pid==pid){
			break;
		}
		
	}
	/*an einai "fulo" */
	if (temp->lc==locations_array[i]->poi_sentinel && temp->rc==locations_array[i]->poi_sentinel){
		temp2=temp->p;
		if (temp2->lc==temp){
			temp2->lc=locations_array[i]->poi_sentinel;
			free(temp);
		}
		else if(temp2->rc==temp){
			temp2->rc=locations_array[i]->poi_sentinel;
			free(temp);
		}
		return 1;
	}
	
	/*an exei ena paidi*/
	if ((temp->lc==locations_array[i]->poi_sentinel && temp->rc!=locations_array[i]->poi_sentinel) || (temp->lc!=locations_array[i]->poi_sentinel && temp->rc==locations_array[i]->poi_sentinel)){
		if (temp->lc==locations_array[i]->poi_sentinel){
			change=temp;
			temp2=temp->rc;
			temp=temp->p;
			temp2->p=temp;
			if (temp->rc==change){
				temp->rc=temp2;
				
			}
			else if (temp->lc==change){
				temp->lc=temp2;
			}
			free(change);
		}
		else if(temp->rc==locations_array[i]->poi_sentinel){
			change=temp;
			temp2=temp->lc;
			temp=temp->p;
			temp2->p=temp;
			if(temp->rc==change){
				temp->rc=temp2;
			}
			else if(temp->lc==change){
				temp->lc=temp2;
			}
			free(change);
		}
		return 1;	
		
	}
	
	/*an exei duo paidia*/
	if (temp->lc!=locations_array[i]->poi_sentinel && temp->rc!=locations_array[i]->poi_sentinel && temp->pid==pid){
		change=temp;
		temp=temp->rc;
		while (temp->lc!=locations_array[i]->poi_sentinel){
			temp=temp->lc;
		}
		temp2=temp->p;
		if (temp2->lc==temp){
			temp2->lc=locations_array[i]->poi_sentinel;
		}
		else if (temp2->rc==temp){
			temp2->rc=locations_array[i]->poi_sentinel;
		}
		temp->lc=change->lc;
		temp->rc=change->rc;
		temp->p=change->p;
		temp2=change->p;
		if (temp2->lc==change){
			temp2->lc=temp;
		}
		else if(temp2->rc==change){
			temp2->rc=temp;
		}
		
		
	}
	
		
		
		

  return 1;
}

/**
* @brief Register user
*
* @param uid The user's id
* 
* @return 1 on success
*         0 on failure
*/
int register_user(int uid)
{
	struct user *root=(struct user*)malloc(sizeof(struct user));
	root->uid=uid;
	root->interesting_poi=NULL;
	root->upoi_count=0;
	int i;
	i=0;
	if (users_hashtable[0]==NULL){
		users_hashtable[0]=root;
	}
	while (users_hashtable[i]!=NULL){
		if (i+1>100){
			return 0;
		}
		if (users_hashtable[i]->uid==uid){
			return 0;
		}
		i++;
	}
	users_hashtable[i]=root;
  return 1;
}

/**
* @brief User is interested in POI
* 
* @param uid The user's id
* @param pid The POI's id
*
* @return 1 on success
*         0 on failure
*/
int interesting_poi(int uid, int pid)
{	
	struct user_poi *root=(struct user_poi*)malloc(sizeof(struct user_poi));
	root->lc=NULL;
	root->rc=NULL;
	root->upid=pid;
	int i;
	i=0;
	
	while (users_hashtable[i]->uid!=uid){
		if (users_hashtable[i]->uid==uid){
			break;
		}
		if (users_hashtable[i+1]==NULL){
			return 0;
		}
		i++;
	}
	
	if (users_hashtable[i]->interesting_poi==NULL){
		users_hashtable[i]->interesting_poi=root;
		users_hashtable[i]->upoi_count++;
	}
	else{
		struct user_poi *temp;
		temp=users_hashtable[i]->interesting_poi;
		int flag=0;
		while (flag==0){
			if (temp->upid>pid){
				if (temp->lc==NULL){
					temp->lc=root;
					flag=1;
					users_hashtable[i]->upoi_count++;
				}
				else{
					temp=temp->lc;
				}
			}
			else if(temp->upid<pid){
				if (temp->rc==NULL){
					temp->rc=root;
					flag=1;
					users_hashtable[i]->upoi_count++;
				}
				else{
					temp=temp->rc;
				}
			}
			if (temp->upid==pid){
				return 0;
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
*
* @return 1 on success
*         0 on failure
*/





int group_users(int uid1, int uid2)
{	printf ("G <%d><%d>\n",uid1,uid2);
	int group(int uid){

		int i;
		i=0;
		while (users_hashtable[i]!=NULL){
			if (users_hashtable[i]->uid==uid){
				break;
			}
			i++;
		}
		if (users_hashtable[i]->uid!=uid){
			return 0;
		}
		struct user_poi *temp;
		temp=users_hashtable[i]->interesting_poi;
		userpoi(temp);
		return 1;
}
	printf("	USER 1= ");
	if(!group(uid1)){
		return 0;
	}
	printf ("\b\b \n");
	printf("	USER 2= ");
	if(!group(uid2)){
		return 0;
	}
	printf("\b\b \nDONE\n");
  return 1;
}

/**
* @brief Find the inorder successors from one pid the other
* 
* @param lid  The location's id
* @param pid1 A point of interest
* @param pid2 A point of interest
*
* @return 1 on success
*         0 on failure
*/

 
 
int inorder_successors(int lid, int pid1, int pid2)
{	
	int i;
	i=0;
	if (lid>1000)return 0;
	while (locations_array[i]->lid!=lid){
		i++;
	}
	
	struct poi *temp;
	temp=locations_array[i]->poi_tree;
	printf ("\nB <%d> <%d> <%d>\n",lid,pid1,pid2);
	printf ("	Locations : <%d>",lid);
	printf ("\n	Inorder traversal: ");
	
	void recurse(struct poi *temp,int pid1,int pid2){
		if(temp==NULL){
			return;
		}
		
		
		recurse(temp->lc,pid1,pid2);
		if (temp->pid>=pid1 && temp->pid<=pid2){
			printf ("<%d:%d:%d>, ",temp->pid,temp->type,temp->distance);
		}
		recurse(temp->rc,pid1,pid2);
	}
	recurse (temp,pid1,pid2);
	printf ("\b\b \nDONE\n");
  return 1;
}

/**
* @brief Print all locations
*
* @return 1 on success
*         0 on failure
*/
int print_locations()
{
	printf("LOCATIONS:\n");
	int i=0;
	while(locations_array[i]!=NULL){
		printf ("	Location: <%d>: ",locations_array[i]->lid);
		inorder(locations_array[i]->poi_tree);
		i++;
		printf("\b\b ");
		printf("\n");
		
	}
	printf("\nDONE\n");
  return 1;
}

/**
* @brief Print all users
*
* @return 1 on success
*         0 on failure
*/
int print_users()
{
	
	int i;
	i=0;
	printf("USERS:\n");
	while (users_hashtable[i]!=NULL){
		printf("	User:<%d> = ",users_hashtable[i]->uid);
		if(users_hashtable[i]->uid<100 && users_hashtable[i]->uid>10){
			printf ("\b\b = ");
		}
		else if(users_hashtable[i]->uid<10){
			printf ("\b\b  = ");
		}
		userpoi(users_hashtable[i]->interesting_poi);
		printf ("\b\b \n");
		i++;
	}
	printf ("DONE\n");
  return 1;
}

/**
* @brief Search for user
* 
* @param uid The id of the user we are looking for
*
* @return 1 on success
*         0 on failure
*/
int search_user(int uid)
{
	
	int i;
	i=0;
	while (users_hashtable[i]!=NULL){
		if (users_hashtable[i]->uid==uid){
			break;
		}
		i++;
	}
	printf ("Z <%d>\n",users_hashtable[i]->uid);
	printf ("	Interesting_poi:");
	userpoi(users_hashtable[i]->interesting_poi);
	printf ("\b\b \nDONE\n");
  return 1;
}

/**
* @brief Cleanup resources
* 
* @return 1 on success
*         0 on failure
*/
int free_world()
{
  return 1;
}


/**
* @brief Initialize hash parameters
* 
* @return null
*/
void initialize()
{

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
 void userpoi(struct user_poi *root){
 	if (root==NULL){
 		return;
	 }
	 userpoi(root->lc);
	 printf ("<%d>, ",root->upid);
	 userpoi(root->rc);
 }
 void inorder(struct poi *root){
 	if (root==NULL){
 		return;
	 }
	 inorder(root->lc);
	 printf ("<%d:%d:%d>, ",root->pid,root->type,root->distance);
	 inorder(root->rc);
 }

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

      /* Maximum users */
    case '0':
      {
	sscanf(buff, "%c %u", &event, &max_users_g);
	DPRINT("%c %u\n", event, max_users_g);
	break;
      }

      /* Maximum user id */
    case '1':
      {
	sscanf(buff, "%c %u", &event, &max_uid_g);
	DPRINT("%c %u\n", event, max_uid_g);
	initialize();
	break;
      }

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
	  break;
	}
	

	
	printf ("L <%d>\n",lid);
	printf ("	Locations = ");
	int i=0;
	while (locations_array[i]!=NULL){
		printf ("<%d>, ",locations_array[i]->lid);
		i++;
	}
	printf ("\b\b ");
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
	  fprintf(stderr,
		  "%c %d %d %d %d failed\n", event, pid, type, distance, lid);
		  break;
	}
	printf ("P <%d> <%d> <%d> <%d>\n",pid,type,distance,lid);
	printf ("	Location= ");
	int i=0;
	while (locations_array[i]->lid!=lid){
		i++;
	}
	if (locations_array[i]->poi_tree!=NULL){
	
	inorder(locations_array[i]->poi_tree);
	printf ("\b\b \n");
	printf("DONE\n");}

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
	  break;
	}
	printf ("A <%d> <%d>\n",pid,lid);
	printf ("	Location= ");
	int i=0;
	while (locations_array[i]->lid!=lid){
		i++;
	}
	inorder(locations_array[i]->poi_tree);
	printf ("\b\b \n");
	printf("DONE\n");
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
	  break;
	}
	printf ("R <%d>\n",uid);
	printf ("	Users = ");
	int i;
	i=0;
	while (users_hashtable[i]!=NULL ){
		printf ("<%d>, ",users_hashtable[i]->uid);
		i++;
	}
	printf ("\b\b \nDONE\n");

	break;
      }

      /* User interested in poi
       * I <uid> <pid> */
    case 'I':
      {
	int uid, pid;
	sscanf(buff, "%c %d %d", &event, &uid, &pid);
	DPRINT("%c %d %d\n", event, uid, pid);

	if ( interesting_poi(uid, pid) ) {
	  DPRINT("%c %d %d succeeded\n", event, uid, pid);
	} else {
	  fprintf(stderr, "%c %d %d failed\n", event, uid, pid);
	  break;
	}
	int i;
	i=0;
	while (users_hashtable[i]->uid!=uid){
		if (users_hashtable[i]->uid==uid){
			break;
		}
		i++;
	}
	struct user_poi *temp;
	temp=users_hashtable[i]->interesting_poi;
	printf ("I <%d> <%d>\n",uid,pid);
	printf("	Users POI = ");
	userpoi(temp);
	printf ("\b\b \nDONE\n");

	break;
      }

      /* Group users
       * G <uid1> <uid2> */
    case 'G':
      {
	int uid1, uid2;
	sscanf(buff, "%c %d %d", &event, &uid1, &uid2);
	DPRINT("%c %d %d\n", event, uid1, uid2);

	if ( group_users(uid1, uid2) ) {
	  DPRINT("%c %d %d succeeded\n", event, uid1, uid2);
	} else {
	  fprintf(stderr, "%c %d %d failed\n", event, uid1, uid2);
	  break;
	}

	break;
      }

      /* Find inorder successors
       * B <lid> <pid1> <pid2> */
    case 'B':
      {
	int lid, pid1, pid2;
	sscanf(buff, "%c %d %d %d\n", &event, &lid, &pid1, &pid2);
	DPRINT("%c %d %d %d\n", event, lid, pid1, pid2);
	if (pid1>pid2){
		int a;
		a=pid1;
		pid1=pid2;
		pid2=a;
	}

	if ( inorder_successors(lid, pid1, pid2) ) {
	  DPRINT("%c %d %d %d succeeded\n", event, lid, pid1, pid2);
	} else {
	  fprintf(stderr, "%c %d %d %d failed\n", event, lid, pid1, pid2);
	  break;
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
	  break;
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
	  break;
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
	  break;
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
