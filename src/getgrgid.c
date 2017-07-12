
/*@
  @吴玉杰
  @2017-7-6 xrs
  @*/

#include"common.h"


/*@getgrgid startt@*/
struct group *Getgrgid(int gid){
     struct group *st_gr=NULL;
      setgrent();
       while((st_gr=Getgrent())!=NULL){
            if(gid==st_gr->gr_gid){
                break;
            }
       }
      endgrent();
  return st_gr;
}

/*@getgrdid end@*/


/*@getgrnam start@*/
 struct group *Getgrnam(const char *name){
      struct group *st_gr=NULL;
      setgrent();
       while((st_gr=Getgrent())!=NULL){
            if(name==st_gr->gr_name){
                break;
            }
       }
      endgrent();
  return st_gr;
 }
/*@getgrnam end@*/


/*@getgrname_info start@*/
 /*
  *name：group number
  */
 static struct passwd *getgrname_info(const char *name){
   static struct passwd* st_pw=NULL;
   struct group *st_gr=NULL;  
    setgrent();
       while((st_gr=Getgrent())!=NULL){
            if(strcmp(name,st_gr->gr_name)==0){
                break;
            }
       }
    endgrent();
      
    setpwent();
    while((st_pw=Getpwent())!=NULL){
          if(st_pw->pw_gid==st_gr->gr_gid){
              break;
          }
    }
    endpwent();

    return st_pw;
 }
/*@getgrname_info end@*/

int main(int argc,char **argv){

    struct passwd *st_pw=NULL;
     while((st_pw=getgrname_info("wuyujie"))!=NULL){
             fprintf(stdout,"%s\n",st_pw->pw_name);
     }

    return 0;
}