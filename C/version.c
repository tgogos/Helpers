#include <my_global.h>
#include <mysql.h>

// gcc version.c -o version  `mysql_config --cflags --libs`

int main(int argc, char **argv)
{
  printf("MySQL client version: %s\n", mysql_get_client_info());

  exit(0);
}
