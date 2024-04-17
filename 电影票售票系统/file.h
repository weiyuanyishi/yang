#ifndef _FILE
#define _FILE

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "movie.h"

int read_user_file(information1 *user);//读用户
void read_administrator_file(information2 *administrator);//读管理员
int read_movie_file(Movie *movie);//读电影
void read_seat_file(Seat *seat);//读座位
void save_user_file(information1 *user, int num_user);//存用户
void save_administrator_file(information2 *administrator, int num_administrator);//存管理员
void save_movie_file(Movie *movie, int num_movie);//存电影
void save_seat_file();//存座位
void add_user_register_file(information1 *user);//追加注册用户
#endif