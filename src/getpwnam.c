
#include"common.h"
#include<pwd.h>



// /*@getpwent start @*/
// struct passwd *Getpwent(){
//      struct passwd *pw_st=NULL;
//     if((pw_st=getpwent())==NULL){
//         err_exit("getpwent");
//     } 
//     return pw_st;
// }

// /*@getpwent end@*/

/*Getpwnam start*/

struct passwd * __Getpwnam(const char *name){
   struct  passwd * st_pw=NULL;
    while((st_pw=Getpwent())!=NULL){ 
         if(strcmp(name,st_pw->pw_name)==0){
            break;
         }
      }
return st_pw;
}

/*@Getpwnam end@*/


int main(int argc,char **argv){

    struct passwd *pwn=NULL;
    pwn=__Getpwnam("wuyujie");
    fprintf(stdout,"%s\n",pwn->pw_name);
    return 0;
}