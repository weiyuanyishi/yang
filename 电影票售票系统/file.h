#ifndef _FILE
#define _FILE

#include "mainControl.h"
#include "user.h"
#include "administrator.h"
#include "menu.h"
#include "movie.h"

int read_user_file(information1 *user);//���û�
void read_administrator_file(information2 *administrator);//������Ա
int read_movie_file(Movie *movie);//����Ӱ
void read_seat_file(Seat *seat);//����λ
void save_user_file(information1 *user, int num_user);//���û�
void save_administrator_file(information2 *administrator, int num_administrator);//�����Ա
void save_movie_file(Movie *movie, int num_movie);//���Ӱ
void save_seat_file();//����λ
void add_user_register_file(information1 *user);//׷��ע���û�
#endif