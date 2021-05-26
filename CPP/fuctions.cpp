#include"New.h"

int bint(int &C,int M,int N) {             //用于获取从N到M之间的一个数字
	for (;;) {
		cin >> C;
		if (C>M||C<N) cout << "输入错误！请重新输入：";
		else break;
	}
		return C;
}    
void Register(player &C) {                 //注册
	C.score = 0;C.isvip = false;               //初始化个人数据
	C.max1 = 0;C.max2 = 0;
	C.color =0;
	int temp;
	for (;;) {                                      //注册
		cout << "注册中......\n";
		cout << "请输入你的游戏名（20个字符以内哦）：";
		cin >> C.name;
		system("cls");
		cout << "您的名字为：" <<C.name << endl;
		cout << "请问您确认吗？" << endl;
		cout << "确认请输入1；" << endl;
		cout << "修改请输入2。" << endl;
		if (bint(temp, 2, 1)== 1) {
			system("cls"); break; 
		}
		else system("cls");
	}
}

ifstream & operator >>(ifstream &in, player &C) {
	in >> C.name >> C.score >> C.isvip >> C.max1 >> C.max2>>C.color;
	return in;
}
ofstream & operator <<(ofstream &ou, const player C) {
	ou << C.name << '\t' << C.score << '\t' << C.isvip << '\t' << C.max1 << '\t' << C.max2
		<<'\t'<<C.color;
	return ou;
}

void game1(player & C) {
	int b = 0;
	cout << "亲爱的玩家：";
	if (!C.isvip) cout << C.name;
	else showname(C);
	cout << endl;
	cout << "即将进行猜大小游戏，若您不知道规则或不清楚，请输入0，" << endl;
	cout << "开始游戏请输入1," << endl;
	cout << "退出请输入2：" << endl;
	bint(b, 2);
	if (b == 2) { system("cls"); return; }
	system("cls");
	if (b == 2) { system("cls"); return; }
	if (b == 0) {                                                          //游戏规则
		cout << "游戏开始之前，您需要交100点积分（如果您有的话  卖萌脸），" << endl;
		cout << "系统会在奖金池中存放1点积分。" << endl;
		cout << "游戏中系统将随机从1到13中取一个整数，如：6。" << endl;
		cout << "然后系统再次随机取一个整数，记为*。" << endl;
		cout << "您需要判断*比6大，还是比6小。" << endl;
		cout << "如果您猜对了奖金池内的奖金翻倍；" << endl;
		cout << "如果您猜错了奖金池内的奖金清零，结束本局游戏；" << endl;
		cout << "如果*与6相等，系统则重新取一个数，您的积分加1。" << endl;
		cout << "当然，您可以在满足之后将奖金池内的奖金取走二分之一并结束本局游戏。" << endl;
		cout << "进行游戏请输入1" << endl;
		cout << "退出游戏请输入0" << endl;
		bint(b, 1);
		system("cls");
	}
	srand(time(0));
	int a1, a2, j;
	a1 = rand() % 13 + 1;
	for (;;) {          //游戏开始

		system("cls");int Temp1 = 1;
		if (C.score >= 100)   C.score -= 100;


		for (j = 1; j;) {                    //单次游戏
			a2 = rand() % 13 + 1;
			cout << "亲爱的玩家:";
			if (!C.isvip) cout << C.name;
			else showname(C);
			cout << '\t' << "您的积分为：" << C.score << endl
				<< "程序员祝您游戏愉快！" << endl;
			cout << "当前奖金池内的积分为：" << j << '\t' << "当前为：第" << Temp1 << "轮" << endl;
			cout << "*************************************" << endl;
			cout << "请猜测下一个数比" << a1 << "大，还是比" << a1 << "小。" << endl;
			cout << "比" << a1 << "大，输入1" << endl;
			cout << "比" << a1 << "小，输入2" << endl;
			bint(b, 2, 1);


			cout << "下一个数为" << a2 << endl;


			if (b == 1 && a2>a1 || b == 2 && a2<a1) {                    //正确
				j *= 2;
				cout << "恭喜您的猜测正确！" << endl;
				cout << "是否继续本局游戏？" << endl;
				cout << "继续请输入1，结束请输入0：" << endl;
				bint(b, 1);
				if (b == 1) {
					a1 = a2;
					Temp1++;
				}
				else b = 10086;
			}



			else if (a1 == a2) {                            //两数相等
				j += 1;
				cout << "两个数相等，您的积分加1。" << endl;
				cout << "请问是否本局继续？" << endl;
				cout << "继续请输入1，结束请输入0：" << endl;
				bint(b, 1);
				if (b)  Temp1++;
				if (b == 0)  b = 10086;
			}

			else {                                       //失败
				if (Temp1 - 1 > C.max1)  C.max1 = Temp1 - 1;
				if (C.max1 >= 20)  C.isvip = true;
				cout << "呀！您猜错了！" << endl;
				cout << "本局游戏结束！";
				cout << "输入0继续......";
				bint(b, 0);
				j = 0;
				break;
			}
			system("cls");
			if (b == 10086) {
				if (Temp1 > C.max1)  C.max1 = Temp1;
				if (C.max1 >= 20)  C.isvip = true;
				C.score += j;
				break;
			}


		}           //单循环结束

		system("cls");
		cout << "您的积分为" << C.score << endl;
		cout << "是否继续游戏？" << endl;
		cout << "继续请输入1，结束请输入0：" << endl;
		bint(b, 1);
		if (b == 0) break;


	}              //巨循环结束
	system("cls");
	return;
}

void  showbombs(bomb *b, int M,bool B) {                         //显示出地雷界面
	int i;
	if (B) {
		for (i = 0; i < M*M; i++) {     
			if (b[i].s == 0)           show("?  ",13);
			else if (b[i].s == 1)     if (b[i].t) cout << b[i].t << "  "; else show("+  ",10);
			else if (b[i].s == 2)      show("*  ",12);
			if ((i + 1) % M == 0)cout << " " << (1 + i) / M << endl;
		}
		cout << endl;
		for (i = 0; i < M; i++) if (i < 9) cout << i + 1 << "  "; else cout << i + 1 << " ";
		cout << endl;
	}
	else {
		for (i = 0; i < M*M; i++) {                 
			if (b[i].s == 0)           cout << "？ ";
			else if (b[i].s == 1)     if (b[i].t) cout << b[i].t << "  "; else cout << "+  ";
			else if (b[i].s == 2)      cout << "*  ";
			if ((i + 1) % M == 0)cout << " " << (1 + i) / M << endl;
		}
		cout << endl;
		for (i = 0; i < M; i++) if (i < 9) cout << i + 1 << "  "; else cout << i + 1 << " ";
		cout << endl;
	}
}
void open(bomb*b, int i, int M) {
	b[i].z = 1;
	if (i + 1 > M) {                      //上
		b[i - M].s = 1;
		if (b[i - M].t == 0 && !b[i - M].z) open(b, i - M, M);
	}
	if (i > M&&i%M) {                   //左上
		b[i - M - 1].s = 1;
		if (b[i - M - 1].t == 0 && !b[i - M - 1].z)  open(b, i - M - 1, M);
	}
	if (i + 1 > M && (i + 1) % M) {                     //右上
		b[i - M + 1].s = 1;
		if (b[i - M + 1].t == 0 && !b[i - M + 1].z)	  open(b, i - M + 1, M);
	}
	if (i%M) {                     //左
		b[i - 1].s = 1;
		if (b[i - 1].t == 0 && !b[i - 1].z)	open(b, i - 1, M);
	}
	if ((i + 1) % M) {                     //右
		b[i + 1].s = 1;
		if (b[i + 1].t == 0 && !b[i + 1].z)	open(b, i + 1, M);
	}
	if ((i + M) < M*M) {                     //下
		b[i + M].s = 1;
		if (b[i + M].t == 0 && !b[i + M].z)	open(b, i + M, M);
	}
	if (i%M&&(i+M-1)<M*M) {                   //左下
		b[i + M - 1].s = 1;
		if (b[i + M - 1].t == 0 && !b[i + M - 1].z)	open(b, i + M - 1, M);
	}
	if ((i + 1) % M && (i + M + 1)<M*M) {                     //右下
		b[i + M + 1].s = 1;
		if (b[i + M + 1].t == 0 && !b[i + M + 1].z)	 open(b, i + 1 + M, M);
	}
}
void fail(bomb*b, int M,bool B) {
	if (!B) {
		int i, m = M*M;
		cout << "失败！" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  cout << "*  ";
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "结束本次游戏请输入0:";
		bint(i, 0);   return;
	}
	else {
		int i, m = M*M;
		cout << "失败！" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  show("*  ",12);
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "结束本次游戏请输入0:";
		bint(i, 0);   return;
	}
}
void victory(bomb*b, int M, bool B) {
	if (!B) {
		int i, m = M*M;
		cout << "胜利！" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  cout << "*  ";
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "结束本次游戏请输入0:";
		bint(i, 0);   return;
	}
	else {
		int i, m = M*M;
		cout << "胜利！" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  show("*  ", 12);
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "结束本次游戏请输入0:";
		bint(i, 0);   return;
	}
}
void game2(player &C) {
	int f;
	cout << "亲爱的玩家：";
	if (!C.isvip)cout << C.name;
	else showname(C);
	cout << "，即将进行扫雷游戏," << endl;
	cout << "查看规则请输入1，" << endl;
	cout << "开始游戏请输入2，" << endl;
	cout << "退出请输入3." << endl;
	bint(f,3,1);
	if (f == 1) {
		system("cls");
		cout << "每局扫雷游戏需要先扣除1000积分，" << endl;
		cout << "即便选择放弃也会扣除1000积分哦，" << endl;
		cout << "如果积分不足，将不能进行游戏，" << endl;
		cout << "如果胜利，奖励9999积分，如果失败，不返还积分。" << endl;
		cout << "注意：加号“+”表示周围没有地雷。" << endl;
		cout << "开始游戏请输入1，" << endl;
		cout << "退出请输入2." << endl;
		bint(f,2,1);
		if (f == 2) { system("cls"); return; };
	}
	else if (f == 3) { system("cls"); return; }
	system("cls");
	int x, y, i, j = 0, M, N, m; bomb *B;
	srand(time(0));
	for (;;) {                                                  //局循环开始
		if (C.score < 1000) {
			cout << "您的积分不足！请您多玩猜大小游戏赚积分！" << endl;
			cout << "结束请输入0：\n";
			bint(j,0);
			system("cls");
			return;
		}
		else {
			C.score -= 1000;
			cout << "亲爱的玩家：";
			if (!C.isvip)cout << C.name;
			else showname(C);
			cout<< "，程序员祝您游戏愉快！" << endl;
			cout << "请选择难度(输入序号)" << endl;
			cout << "1.    简单：9*9    10个雷" << endl
				    << "2.    困难：16*16  40个雷" << endl
				    << "3.    超难：20*20  70个雷" << endl
			        << "0.    我选择放弃2333" << endl;
			bint(j,3);
			if (!j)  break;
			if (j == 1) { M = 9, N = 10; }
			else if (j == 2) { M = 16, N = 40; }
			else { M = 20, N = 70; }
			m = M*M;

			B = new bomb[m];

			system("cls");

			for (i = 0; i < m; i++) {
				B[i].f = false; B[i].s = 0; B[i].t = 0; B[i].z = 0;
			}

			for (i = 0; i < N;) {                            //生成地雷
				j = rand() % m;
				if (!B[j].f) {
					B[j].f = true;
					B[j].t = -1;
					i++;
				}
			}

			for (i = 0; i < m; i++) {                                                 //统计周围地雷个数
				if (!B[i].f) {
					if (i + 1 > M&&B[i - M].f)                                                  B[i].t++;       //上
					if (i > M&&B[i - M - 1].f&&i%M)												B[i].t++;       //左上
					if (i +1> M && (i + 1) % M&&B[i - M + 1].f)									B[i].t++;       //右上
					if (i%M&&B[i - 1].f)                                                        B[i].t++;       //左
					if ((i + 1) % M&&B[i + 1].f)                                                B[i].t++;       //右
					if ((i + M) < m&&B[i + M].f)                                                B[i].t++;       //下
					if (i%M&&((i+M-1)<m)&&B[i + M - 1].f)										B[i].t++;       //左下
					if ((i + 1) % M && ((i + M - 1)<m) &&B[i + M + 1].f)						B[i].t++;       //右下
				} 
			}



			for (;;) {                //单循环


				showbombs(B, M, C.isvip);                 //将扫雷界面显示出来

				cout << "请输入您要操作的对象的行数和列数：";                    //定位
				for (;;) {
					cin >> x >> y;
					if (x <= M&&y <= M&&x > 0 && y > 0)  break;
					else cout << "输入错误，请重新输入：";
				}

				i = (x - 1)*M + y - 1;

				cout << "请输入您想进行的操作的序号：" << endl;               //操作
				cout << "1.点开。" << endl;
				cout << "2.标记为地雷。" << endl;
				cout << "3.放弃本局游戏。" << endl;
				bint(j,3,1);

				if (j == 3) break;

				B[i].s = j;
				system("cls");
				if (j == 1 && B[i].t == 0)    open(B, i, M);               //把附近周围地雷个数为0的块展开
				if (j == 1 && B[i].f) {                                               //失败
					fail(B, M,C.isvip); break;
				}

				for (i = 0, j = 0; i < m; i++)
					if (B[i].f&&B[i].s == 2) j++;

				if (j == N) {
					C.score += 9999;
					victory(B,M,C.isvip);
					system("cls");
					cout << "您当前积分为：" << C.score << endl;
					C.isvip = true;
					if (M == 9) {
						if (C.max2 <= 1)  C.max2 = 1;
					}
					else if (M == 16) {
						if (C.max2 <= 2)  C.max2 = 2;
					}
					else {
						if (C.max2 <= 3)  C.max2 = 3;
					}
					cout << "继续请输入0：" << endl;
					bint(j,0); break;
				}
			}                                                              //单循环结束

			system("cls");

			cout << "是否继续扫雷游戏？" << endl;
			cout << "继续请输入1" << endl;
			cout << "结束请输入2" << endl;
			bint(f,2,1);
			system("cls");
			if (f == 2)  return; 

		}
	}                                                                      //局循环结束
	 system("cls");
	 return; 
}

void firstshow(player &C) {
	showname1("Holle!World!");
	cout << endl;
	ifstream in;
	in.open("data.txt");
	if (in) {
		in >> C;
		cout << "亲爱的玩家:";
		if (!C.isvip)  cout << C.name;
		else showname(C);
		cout << ",欢迎回到mathworld！\n";
		cout << "进入请输入1 " << endl;
		cout << "退出请输入0" << endl;
	}
	else {
		cout << "欢迎来到mathworld！" << endl;
		cout << "进入请输入1 " << endl;
		cout << "退出请输入0" << endl;
	}
	in.close();
}
void mainshow(player &C) {
	for (;;) {
		int temp=-1;
		cout << "亲爱的玩家：";
		if (!C.isvip) cout << C.name; 
		else showname(C);
		cout<< ",您的积分为：" << C.score << endl;
		cout << "请输入您想进行的游戏：" << endl;
		cout << "1.猜大小游戏；" << endl;
		cout << "2.扫雷；" << endl;
		cout << "3.个人信息；" << endl;
		cout << "0.退出" << endl;
		bint(temp,3);
		if (temp == 1) {
			system("cls");
			game1(C);
		}
		else if (temp == 2) {
			system("cls");
			game2(C);
		}
		else if (temp == 3) {
			system("cls");
			 I(C);
		}
		else {
			system("cls");
			cout << "是否需要存档？\n";
			cout << "输入1，进行存档；输入0直接退出：\n";
			bint(temp);
			if (temp) {
				ofstream os;
				os.open("data.txt");
				os << C;
				os.close();
				system("cls");
			}
			break;
		}
	}
}
void show(char* str, WORD color, ...) {
	WORD colorOld;
	HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	colorOld = csbi.wAttributes;
	SetConsoleTextAttribute(handle, color);
	cout << str;
	SetConsoleTextAttribute(handle, colorOld);
}
void showname(player C) {
	if (C.color) showname2(C);
	else showname1(C.name);
}
void showname1(char *name){
int Len, i;
char **p;
for (Len = 0, i = 0;name[i];++Len, ++i);
p = new char*[Len];
for (i = 0;i<Len;++i) {
	p[i] = new char[2];
	p[i][0] = name[i];
	p[i][1] = '\0';
}
for (i = 0;i<Len;++i) {
	show(p[i], 11 + i % 5);
}
}
void showname2( player C) {
	show(C.name,9+C.color);
}

void I(player &C) {
	int temp=-1;
	do {
		cout << "游戏名：";
		if (!C.isvip) cout << C.name;
		else showname(C);
		cout << endl;
		cout << "分数：" << C.score << endl;
		switch (C.isvip) {
		case true:cout << "您是VIP\n";break;
		case false:cout << "您还不是VIP\n";break;
		}
		cout << "猜大小游戏最多连赢数：" << C.max1 << endl;
		cout << "扫雷最高成就:";
		switch (C.max2) {
		case 0:cout << "尚未通关任何难度！\n";break;
		case 1:cout << "已通关简单模式！\n";break;
		case 2:cout << "已通关困难模式！\n";break;
		case 3:cout << "已通关超难模式！\n";break;
		default:cout << "数据异常！\n";
		}
		cout << "**********************************************\n";
		cout << "1、修改游戏名（名称和颜色）\n";
		cout << "2、开通VIP\n";
		cout << "3、重新开始\n";
		cout << "0、退出\n";
		bint(temp, 3);
		if (temp == 1) {
			system("cls");
			cout << "1、更改名字颜色（仅限VIP使用）；" << endl;
			cout << "2、修改名称；" << endl;
			cout << "0、退出" << endl;
			int tEmp = -1;
			bint(tEmp,2);
			if(tEmp==2)
			for (;;) {
				int t = -1;char name[20];
				system("cls");
				cout << "更改游戏名中......\n";
				cout << "请输入你的游戏名（20个字符以内哦）：";
				cin >> name;
				system("cls");
				cout << "您的名字为：" << name << endl;
				cout << "您的原名为：" << C.name << endl;
				cout << "请问您确认修改吗？" << endl;
				cout << "确认修改请输入1；" << endl;
				cout << "继续修改请输入2；" << endl;
				cout << "放弃修改请输入0。" << endl;
				bint(t, 2);
				if (t == 1) {
					strcpy(C.name, name);
					system("cls"); break;
				}
				else if (t == 0) {
					system("cls");break;
				}
			}
			if (tEmp == 1) {
				system("cls");
				if (C.isvip) {
					system("cls");
					cout << "1、炫彩名称：";showname1("奥特曼Altman12138");cout << endl;
					cout << "2、绿色：";show("奥特曼Altman12138",10);cout << endl;
					cout << "3、天蓝色：";show("奥特曼Altman12138", 11);cout << endl;
					cout << "4、红色：";show("奥特曼Altman12138", 12);cout << endl;
					cout << "5、紫色：";show("奥特曼Altman12138", 13);cout << endl;
					cout << "6、黄色：";show("奥特曼Altman12138", 14);cout << endl;
					cout << "0、返回\n";
						int teMp = -1;
						bint(teMp,6);
						if (teMp) {
							C.color = teMp - 1;
							system("cls");
							cout << "修改成功！"<<endl;
							cout << "当前游戏名效果为：";
							if (C.color) showname2(C);
							else showname1(C.name);
							cout<<endl << "请输入0返回：";
							int temP = -1;
							bint(temP,0);
							system("cls");
						}
				}
				else {
					cout << "抱歉！您还不是VIP，不能使用彩色游戏名！\n";
					cout << "请输入0返回：";
					int teMp = -1;
					bint(teMp,0);
					system("cls");
				}
			
			}
			if (tEmp == 0) system("cls");
		}
		if (temp == 2) {
			for (;;) {
				system("cls");
			cout << "1、VIP有哪些特权？" << endl
				<< "2、如何成为VIP？" << endl
				<< "3、强行成为VIP;" << endl
				<< "0、退出" << endl;
			int Temp;
			bint(Temp, 3);
			if (Temp == 0) break;
			if (Temp == 1) {
				int tEmp;
				system("cls");
				cout << "1、可以使用炫彩游戏名；" << endl
					<< "2、游戏界面更加丰富，告别单调的非黑即白；" << endl
					<< "3、最最重要的、可以秀优越感啊23333" << endl;
				cout << "***********************************\n";
				cout << "我知道了（请输入0返回）：";
				bint(tEmp,0);
			}
			if (Temp == 2) {
				system("cls");
				cout << "本游戏有多种方式成为VIP:" << endl
					<< "1、猜大小游戏最高成就超过20，自动成为VIP；" << endl
					<< "2、通关任意难度扫雷游戏，自动成为VIP；" << endl
					<< "3、强行花费9999积分成为VIP（出门选3）；" << endl
					<< "4、打开本游戏所在文件夹，找到data.txt文件，把第二个数字改为1即可。" << endl;
				cout << "****************************************" << endl;
				cout << "我知道了（输入0返回）:";
				int tEmp = -1;
				bint(tEmp,0);
			}
			if (Temp == 3) {
				if (!C.isvip) {
					system("cls");
					if (C.score < 9999) {
						cout << "积分不足！" << endl;
						int tEmp = -1;
						cout << "请输入0返回：";
						bint(tEmp, 0);
					}
					else {
						cout << "恭喜您成为VIP!" << endl;
						cout << "朕知道了（输入0返回）：";
						int tEmp=-1;
						bint(tEmp,0);
						C.score -= 9999;
						C.isvip = true;
					}
				}
				else {
					system("cls");
					cout << "您已经是VIP!" << endl;
					cout << "请输入0返回：";
					int tEmp = -1;
					bint(tEmp,0);
				}
			}
		}
			system("cls");
		}
		if (temp == 3) {
			system("cls");
			cout << "重新开始，您的积分将被清零，VIP特权也将消失。\n确定重新开始请输入1，返回请输入0：";
			int Temp = -1;bint(Temp);
			system("cls");
			if (Temp) {
				C.isvip = false;
				C.max1 = 0;
				C.max2 = 0;
				C.score = 0;
				C.color = 0;
				for (;;) {                                      //注册
					cout << "注册中......\n";
					cout << "请输入你的游戏名（20个字符以内哦）：";
					cin >> C.name;
					system("cls");
					cout << "您的名字为：" << C.name << endl;
					cout << "请问您确认吗？" << endl;
					cout << "确认请输入1；" << endl;
					cout << "修改请输入2。" << endl;
					if (bint(temp, 2, 1) == 1) {
						system("cls"); break;
					}
					else system("cls");
				}
			}
		}
		if (temp == 0) system("cls");
		} while (temp);
	}