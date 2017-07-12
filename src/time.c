

#include<time.h>


int main(int argc,char **argv){
     
    //  time_t timer;
    //  struct tm *t_time;
    //  timer=time(NULL);
    //  t_time=localtime(&timer);
    //  printf("%d %d %d",t_time->tm_year,t_time->tm_mon,t_time->tm_mday);
  
    struct tm tm;   
    char buf[255];  
    printf("asctime:%s\n",asctime(&tm));
    memset(buf,0,sizeof(buf));  
    strftime(buf, sizeof(buf), "%d %b %Y %H:%M", &tm);  
    puts(buf);  

    return 0;
}