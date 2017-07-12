



#include"common.h"
#include<pwd.h>
//测试getpwuid

/*@getuserinfo start@*/
void Getuser_info(int uid){
   struct passwd *st_pw=NULL;
   st_pw=Getpwuid(uid);
   fprintf(stdout,"%s\n %s\n %d\n %d\n %s\n %s\n %s\n",st_pw->pw_name,st_pw->pw_passwd,
   st_pw->pw_uid,st_pw->pw_gid,st_pw->pw_gecos,st_pw->pw_dir,st_pw->pw_shell);
   return;    
}
/*@getuserinfo end@*/


/*@getuserinfo by getpwnam start@*/
void Getuser_infobyname(const char *name){
   struct passwd *st_pw=NULL;
   st_pw=Getpwnam(name);
   fprintf(stdout,"%s\n %s\n %d\n %d\n %s\n %s\n %s\n",st_pw->pw_name,st_pw->pw_passwd,
   st_pw->pw_uid,st_pw->pw_gid,st_pw->pw_gecos,st_pw->pw_dir,st_pw->pw_shell);
   return;    
}
/*@getuserinfobyname end@*/

/*Getalluser start*/

void Getalluser(){
   struct  passwd * st_pw=NULL;
    while((st_pw=Getpwent())!=NULL){
     
    printf("**********************************\n");
    fprintf(stdout,"%s\n %s\n %d\n %d\n %s\n %s\n %s\n",st_pw->pw_name,st_pw->pw_passwd,
    st_pw->pw_uid,st_pw->pw_gid,st_pw->pw_gecos,st_pw->pw_dir,st_pw->pw_shell); 
    printf("**********************************\n");
      
      }
return;
}

/*@getalluser end@*/





int main(){

   #if 0
   Getuser_info(0);
   Getuser_infobyname("wuyujie");
   #endif
   #if 1
   Getalluser();
   #endif
    return 0;
}