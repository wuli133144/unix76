

struct shadow{
  char *shw_name;
  char *shw_passwd;
  int shw_unmod_day;//密码不可修改时间

  int shw_time_mod_limit;//密码需要修改的时间
  int shw_pre_mod_time;//修改前几天几天发出警告
  int shw_outday;//密码过期的宽限
  int shw_invalidday;//账号失效的日期

  char*free; 保留
};