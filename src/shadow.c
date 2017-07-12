
#include"shw.h"

#include<stdio.h>

#define BUFSIZ 1024


static char SHADOW[]	= "/etc/shadow";
static char EMPTY[] = "";
static FILE *shwf = NULL;
static char line[BUFSIZ+1];
static struct shadow shw;

void setshwent(){
  if(shwf==NULL){
      shwf=fopen(SHADOW,"r");

  }else{
      rewind(shwf);
  }
}
void endshwent(){
    if(shwf!=NULL){
        fclose(shwf);
        shwf=NULL;
    }
}

/*@skip start@*/
static char *skip(register char *p){
 
while( *p && *p != ':' )
		++p;
	if( *p ) *p++ = 0;
	return(p);


}
/*@skip end@*/

struct shadow *getshwent(){
     register char *p;
     if(shwf==NULL){
         if((shwf=fopen(SHADOW,"r"))==NULL){
             return 0;
         }
     }
     p=fgets(line,BUFSIZE,shwf);
     if(p==NULL){
         return 0;
     }
    shadow.shw_name=p;
    skip(p);
    shadow.shw_passwd=p;
     skip(p);
    shadow.shw_unmod_day=p;
    skip(p);
    shadow.shw_time_mod_limit=p;
    skip(p);
    shadow.shw_pre_mod_time=p;
    skip(p);
    shadow.shw_outday=p;
    skip(p);
     shadow.shw_invalidday=p;
     return &shadow;
}    