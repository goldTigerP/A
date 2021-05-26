#ifndef Mygame
#define Mygame
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
#include <Windows.h>  
#include <stdio.h>  
#include <stdarg.h>  
using namespace std;
struct player {
	char name[20];                            //��Ϸ��
	int score;                                     //����
	bool isvip;                                   //�Ƿ�ΪVIP
	int max1;                                     //�´�С��Ϸ�����ʤ��
	int max2;                                     //ɨ�������ʤ��
	int color;                                     //VIP��Ϸ����Ч����
};
ifstream & operator >>(ifstream &, player &);
ofstream & operator <<(ofstream &, const player );
struct bomb {
	bool f;             //�Ƿ��ǵ���
	int t;                //��Χ���׸���
	int s;               //չʾ״̬
	bool z;            //��ʾ�Ƿ������ݹ麯��
};
int bint(int&,int=1,int=0);                  //��ȡ�޶����ַ�
void game1(player &);                         //�´�С��Ϸ
void game2(player &);                        //ɨ��
void Register(player &);                     //ע��
void showbombs(bomb*, int,bool);   //��ɨ�׽�����ʾ����
void open(bomb*, int, int);                   //չ��
void fail(bomb*, int,bool);                    //ʧ��

void firstshow(player &);                       //��ʼ����
void mainshow(player &);                     //������
void show(char* str, WORD color, ...);                        //���֮Դ����ӡ����ɫ����
void showname(player);                          //���ϳ��Ĵ�ӡ����
void showname1(char *);                         //��ϴ�ӡ���Ųʣ�
void showname2(player);                         //��ɫ��ӡ
void I(player &);                                        //�û��޸ĸ��˵���
#endif;