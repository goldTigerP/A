#include"New.h"

int bint(int &C,int M,int N) {             //���ڻ�ȡ��N��M֮���һ������
	for (;;) {
		cin >> C;
		if (C>M||C<N) cout << "����������������룺";
		else break;
	}
		return C;
}    
void Register(player &C) {                 //ע��
	C.score = 0;C.isvip = false;               //��ʼ����������
	C.max1 = 0;C.max2 = 0;
	C.color =0;
	int temp;
	for (;;) {                                      //ע��
		cout << "ע����......\n";
		cout << "�����������Ϸ����20���ַ�����Ŷ����";
		cin >> C.name;
		system("cls");
		cout << "��������Ϊ��" <<C.name << endl;
		cout << "������ȷ����" << endl;
		cout << "ȷ��������1��" << endl;
		cout << "�޸�������2��" << endl;
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
	cout << "�װ�����ң�";
	if (!C.isvip) cout << C.name;
	else showname(C);
	cout << endl;
	cout << "�������в´�С��Ϸ��������֪������������������0��" << endl;
	cout << "��ʼ��Ϸ������1," << endl;
	cout << "�˳�������2��" << endl;
	bint(b, 2);
	if (b == 2) { system("cls"); return; }
	system("cls");
	if (b == 2) { system("cls"); return; }
	if (b == 0) {                                                          //��Ϸ����
		cout << "��Ϸ��ʼ֮ǰ������Ҫ��100����֣�������еĻ�  ����������" << endl;
		cout << "ϵͳ���ڽ�����д��1����֡�" << endl;
		cout << "��Ϸ��ϵͳ�������1��13��ȡһ���������磺6��" << endl;
		cout << "Ȼ��ϵͳ�ٴ����ȡһ����������Ϊ*��" << endl;
		cout << "����Ҫ�ж�*��6�󣬻��Ǳ�6С��" << endl;
		cout << "������¶��˽�����ڵĽ��𷭱���" << endl;
		cout << "������´��˽�����ڵĽ������㣬����������Ϸ��" << endl;
		cout << "���*��6��ȣ�ϵͳ������ȡһ���������Ļ��ּ�1��" << endl;
		cout << "��Ȼ��������������֮�󽫽�����ڵĽ���ȡ�߶���֮һ������������Ϸ��" << endl;
		cout << "������Ϸ������1" << endl;
		cout << "�˳���Ϸ������0" << endl;
		bint(b, 1);
		system("cls");
	}
	srand(time(0));
	int a1, a2, j;
	a1 = rand() % 13 + 1;
	for (;;) {          //��Ϸ��ʼ

		system("cls");int Temp1 = 1;
		if (C.score >= 100)   C.score -= 100;


		for (j = 1; j;) {                    //������Ϸ
			a2 = rand() % 13 + 1;
			cout << "�װ������:";
			if (!C.isvip) cout << C.name;
			else showname(C);
			cout << '\t' << "���Ļ���Ϊ��" << C.score << endl
				<< "����Աף����Ϸ��죡" << endl;
			cout << "��ǰ������ڵĻ���Ϊ��" << j << '\t' << "��ǰΪ����" << Temp1 << "��" << endl;
			cout << "*************************************" << endl;
			cout << "��²���һ������" << a1 << "�󣬻��Ǳ�" << a1 << "С��" << endl;
			cout << "��" << a1 << "������1" << endl;
			cout << "��" << a1 << "С������2" << endl;
			bint(b, 2, 1);


			cout << "��һ����Ϊ" << a2 << endl;


			if (b == 1 && a2>a1 || b == 2 && a2<a1) {                    //��ȷ
				j *= 2;
				cout << "��ϲ���Ĳ²���ȷ��" << endl;
				cout << "�Ƿ����������Ϸ��" << endl;
				cout << "����������1������������0��" << endl;
				bint(b, 1);
				if (b == 1) {
					a1 = a2;
					Temp1++;
				}
				else b = 10086;
			}



			else if (a1 == a2) {                            //�������
				j += 1;
				cout << "��������ȣ����Ļ��ּ�1��" << endl;
				cout << "�����Ƿ񱾾ּ�����" << endl;
				cout << "����������1������������0��" << endl;
				bint(b, 1);
				if (b)  Temp1++;
				if (b == 0)  b = 10086;
			}

			else {                                       //ʧ��
				if (Temp1 - 1 > C.max1)  C.max1 = Temp1 - 1;
				if (C.max1 >= 20)  C.isvip = true;
				cout << "ѽ�����´��ˣ�" << endl;
				cout << "������Ϸ������";
				cout << "����0����......";
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


		}           //��ѭ������

		system("cls");
		cout << "���Ļ���Ϊ" << C.score << endl;
		cout << "�Ƿ������Ϸ��" << endl;
		cout << "����������1������������0��" << endl;
		bint(b, 1);
		if (b == 0) break;


	}              //��ѭ������
	system("cls");
	return;
}

void  showbombs(bomb *b, int M,bool B) {                         //��ʾ�����׽���
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
			if (b[i].s == 0)           cout << "�� ";
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
	if (i + 1 > M) {                      //��
		b[i - M].s = 1;
		if (b[i - M].t == 0 && !b[i - M].z) open(b, i - M, M);
	}
	if (i > M&&i%M) {                   //����
		b[i - M - 1].s = 1;
		if (b[i - M - 1].t == 0 && !b[i - M - 1].z)  open(b, i - M - 1, M);
	}
	if (i + 1 > M && (i + 1) % M) {                     //����
		b[i - M + 1].s = 1;
		if (b[i - M + 1].t == 0 && !b[i - M + 1].z)	  open(b, i - M + 1, M);
	}
	if (i%M) {                     //��
		b[i - 1].s = 1;
		if (b[i - 1].t == 0 && !b[i - 1].z)	open(b, i - 1, M);
	}
	if ((i + 1) % M) {                     //��
		b[i + 1].s = 1;
		if (b[i + 1].t == 0 && !b[i + 1].z)	open(b, i + 1, M);
	}
	if ((i + M) < M*M) {                     //��
		b[i + M].s = 1;
		if (b[i + M].t == 0 && !b[i + M].z)	open(b, i + M, M);
	}
	if (i%M&&(i+M-1)<M*M) {                   //����
		b[i + M - 1].s = 1;
		if (b[i + M - 1].t == 0 && !b[i + M - 1].z)	open(b, i + M - 1, M);
	}
	if ((i + 1) % M && (i + M + 1)<M*M) {                     //����
		b[i + M + 1].s = 1;
		if (b[i + M + 1].t == 0 && !b[i + M + 1].z)	 open(b, i + 1 + M, M);
	}
}
void fail(bomb*b, int M,bool B) {
	if (!B) {
		int i, m = M*M;
		cout << "ʧ�ܣ�" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  cout << "*  ";
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "����������Ϸ������0:";
		bint(i, 0);   return;
	}
	else {
		int i, m = M*M;
		cout << "ʧ�ܣ�" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  show("*  ",12);
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "����������Ϸ������0:";
		bint(i, 0);   return;
	}
}
void victory(bomb*b, int M, bool B) {
	if (!B) {
		int i, m = M*M;
		cout << "ʤ����" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  cout << "*  ";
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "����������Ϸ������0:";
		bint(i, 0);   return;
	}
	else {
		int i, m = M*M;
		cout << "ʤ����" << endl;
		for (i = 0; i < m; i++) {
			if (b[i].f)                  show("*  ", 12);
			else                         cout << b[i].t << "  ";
			if ((i + 1) % M == 0)        cout << "  " << (i + 1) / M << endl;
		}
		cout << endl;
		for (i = 1; i <= 9; i++)  cout << i << "  ";
		for (i = 10; i < M; i++)  cout << i << " ";
		cout << "����������Ϸ������0:";
		bint(i, 0);   return;
	}
}
void game2(player &C) {
	int f;
	cout << "�װ�����ң�";
	if (!C.isvip)cout << C.name;
	else showname(C);
	cout << "����������ɨ����Ϸ," << endl;
	cout << "�鿴����������1��" << endl;
	cout << "��ʼ��Ϸ������2��" << endl;
	cout << "�˳�������3." << endl;
	bint(f,3,1);
	if (f == 1) {
		system("cls");
		cout << "ÿ��ɨ����Ϸ��Ҫ�ȿ۳�1000���֣�" << endl;
		cout << "����ѡ�����Ҳ��۳�1000����Ŷ��" << endl;
		cout << "������ֲ��㣬�����ܽ�����Ϸ��" << endl;
		cout << "���ʤ��������9999���֣����ʧ�ܣ����������֡�" << endl;
		cout << "ע�⣺�Ӻš�+����ʾ��Χû�е��ס�" << endl;
		cout << "��ʼ��Ϸ������1��" << endl;
		cout << "�˳�������2." << endl;
		bint(f,2,1);
		if (f == 2) { system("cls"); return; };
	}
	else if (f == 3) { system("cls"); return; }
	system("cls");
	int x, y, i, j = 0, M, N, m; bomb *B;
	srand(time(0));
	for (;;) {                                                  //��ѭ����ʼ
		if (C.score < 1000) {
			cout << "���Ļ��ֲ��㣡��������´�С��Ϸ׬���֣�" << endl;
			cout << "����������0��\n";
			bint(j,0);
			system("cls");
			return;
		}
		else {
			C.score -= 1000;
			cout << "�װ�����ң�";
			if (!C.isvip)cout << C.name;
			else showname(C);
			cout<< "������Աף����Ϸ��죡" << endl;
			cout << "��ѡ���Ѷ�(�������)" << endl;
			cout << "1.    �򵥣�9*9    10����" << endl
				    << "2.    ���ѣ�16*16  40����" << endl
				    << "3.    ���ѣ�20*20  70����" << endl
			        << "0.    ��ѡ�����2333" << endl;
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

			for (i = 0; i < N;) {                            //���ɵ���
				j = rand() % m;
				if (!B[j].f) {
					B[j].f = true;
					B[j].t = -1;
					i++;
				}
			}

			for (i = 0; i < m; i++) {                                                 //ͳ����Χ���׸���
				if (!B[i].f) {
					if (i + 1 > M&&B[i - M].f)                                                  B[i].t++;       //��
					if (i > M&&B[i - M - 1].f&&i%M)												B[i].t++;       //����
					if (i +1> M && (i + 1) % M&&B[i - M + 1].f)									B[i].t++;       //����
					if (i%M&&B[i - 1].f)                                                        B[i].t++;       //��
					if ((i + 1) % M&&B[i + 1].f)                                                B[i].t++;       //��
					if ((i + M) < m&&B[i + M].f)                                                B[i].t++;       //��
					if (i%M&&((i+M-1)<m)&&B[i + M - 1].f)										B[i].t++;       //����
					if ((i + 1) % M && ((i + M - 1)<m) &&B[i + M + 1].f)						B[i].t++;       //����
				} 
			}



			for (;;) {                //��ѭ��


				showbombs(B, M, C.isvip);                 //��ɨ�׽�����ʾ����

				cout << "��������Ҫ�����Ķ����������������";                    //��λ
				for (;;) {
					cin >> x >> y;
					if (x <= M&&y <= M&&x > 0 && y > 0)  break;
					else cout << "����������������룺";
				}

				i = (x - 1)*M + y - 1;

				cout << "������������еĲ�������ţ�" << endl;               //����
				cout << "1.�㿪��" << endl;
				cout << "2.���Ϊ���ס�" << endl;
				cout << "3.����������Ϸ��" << endl;
				bint(j,3,1);

				if (j == 3) break;

				B[i].s = j;
				system("cls");
				if (j == 1 && B[i].t == 0)    open(B, i, M);               //�Ѹ�����Χ���׸���Ϊ0�Ŀ�չ��
				if (j == 1 && B[i].f) {                                               //ʧ��
					fail(B, M,C.isvip); break;
				}

				for (i = 0, j = 0; i < m; i++)
					if (B[i].f&&B[i].s == 2) j++;

				if (j == N) {
					C.score += 9999;
					victory(B,M,C.isvip);
					system("cls");
					cout << "����ǰ����Ϊ��" << C.score << endl;
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
					cout << "����������0��" << endl;
					bint(j,0); break;
				}
			}                                                              //��ѭ������

			system("cls");

			cout << "�Ƿ����ɨ����Ϸ��" << endl;
			cout << "����������1" << endl;
			cout << "����������2" << endl;
			bint(f,2,1);
			system("cls");
			if (f == 2)  return; 

		}
	}                                                                      //��ѭ������
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
		cout << "�װ������:";
		if (!C.isvip)  cout << C.name;
		else showname(C);
		cout << ",��ӭ�ص�mathworld��\n";
		cout << "����������1 " << endl;
		cout << "�˳�������0" << endl;
	}
	else {
		cout << "��ӭ����mathworld��" << endl;
		cout << "����������1 " << endl;
		cout << "�˳�������0" << endl;
	}
	in.close();
}
void mainshow(player &C) {
	for (;;) {
		int temp=-1;
		cout << "�װ�����ң�";
		if (!C.isvip) cout << C.name; 
		else showname(C);
		cout<< ",���Ļ���Ϊ��" << C.score << endl;
		cout << "������������е���Ϸ��" << endl;
		cout << "1.�´�С��Ϸ��" << endl;
		cout << "2.ɨ�ף�" << endl;
		cout << "3.������Ϣ��" << endl;
		cout << "0.�˳�" << endl;
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
			cout << "�Ƿ���Ҫ�浵��\n";
			cout << "����1�����д浵������0ֱ���˳���\n";
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
		cout << "��Ϸ����";
		if (!C.isvip) cout << C.name;
		else showname(C);
		cout << endl;
		cout << "������" << C.score << endl;
		switch (C.isvip) {
		case true:cout << "����VIP\n";break;
		case false:cout << "��������VIP\n";break;
		}
		cout << "�´�С��Ϸ�����Ӯ����" << C.max1 << endl;
		cout << "ɨ����߳ɾ�:";
		switch (C.max2) {
		case 0:cout << "��δͨ���κ��Ѷȣ�\n";break;
		case 1:cout << "��ͨ�ؼ�ģʽ��\n";break;
		case 2:cout << "��ͨ������ģʽ��\n";break;
		case 3:cout << "��ͨ�س���ģʽ��\n";break;
		default:cout << "�����쳣��\n";
		}
		cout << "**********************************************\n";
		cout << "1���޸���Ϸ�������ƺ���ɫ��\n";
		cout << "2����ͨVIP\n";
		cout << "3�����¿�ʼ\n";
		cout << "0���˳�\n";
		bint(temp, 3);
		if (temp == 1) {
			system("cls");
			cout << "1������������ɫ������VIPʹ�ã���" << endl;
			cout << "2���޸����ƣ�" << endl;
			cout << "0���˳�" << endl;
			int tEmp = -1;
			bint(tEmp,2);
			if(tEmp==2)
			for (;;) {
				int t = -1;char name[20];
				system("cls");
				cout << "������Ϸ����......\n";
				cout << "�����������Ϸ����20���ַ�����Ŷ����";
				cin >> name;
				system("cls");
				cout << "��������Ϊ��" << name << endl;
				cout << "����ԭ��Ϊ��" << C.name << endl;
				cout << "������ȷ���޸���" << endl;
				cout << "ȷ���޸�������1��" << endl;
				cout << "�����޸�������2��" << endl;
				cout << "�����޸�������0��" << endl;
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
					cout << "1���Ų����ƣ�";showname1("������Altman12138");cout << endl;
					cout << "2����ɫ��";show("������Altman12138",10);cout << endl;
					cout << "3������ɫ��";show("������Altman12138", 11);cout << endl;
					cout << "4����ɫ��";show("������Altman12138", 12);cout << endl;
					cout << "5����ɫ��";show("������Altman12138", 13);cout << endl;
					cout << "6����ɫ��";show("������Altman12138", 14);cout << endl;
					cout << "0������\n";
						int teMp = -1;
						bint(teMp,6);
						if (teMp) {
							C.color = teMp - 1;
							system("cls");
							cout << "�޸ĳɹ���"<<endl;
							cout << "��ǰ��Ϸ��Ч��Ϊ��";
							if (C.color) showname2(C);
							else showname1(C.name);
							cout<<endl << "������0���أ�";
							int temP = -1;
							bint(temP,0);
							system("cls");
						}
				}
				else {
					cout << "��Ǹ����������VIP������ʹ�ò�ɫ��Ϸ����\n";
					cout << "������0���أ�";
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
			cout << "1��VIP����Щ��Ȩ��" << endl
				<< "2����γ�ΪVIP��" << endl
				<< "3��ǿ�г�ΪVIP;" << endl
				<< "0���˳�" << endl;
			int Temp;
			bint(Temp, 3);
			if (Temp == 0) break;
			if (Temp == 1) {
				int tEmp;
				system("cls");
				cout << "1������ʹ���Ų���Ϸ����" << endl
					<< "2����Ϸ������ӷḻ����𵥵��ķǺڼ��ף�" << endl
					<< "3��������Ҫ�ġ���������Խ�а�23333" << endl;
				cout << "***********************************\n";
				cout << "��֪���ˣ�������0���أ���";
				bint(tEmp,0);
			}
			if (Temp == 2) {
				system("cls");
				cout << "����Ϸ�ж��ַ�ʽ��ΪVIP:" << endl
					<< "1���´�С��Ϸ��߳ɾͳ���20���Զ���ΪVIP��" << endl
					<< "2��ͨ�������Ѷ�ɨ����Ϸ���Զ���ΪVIP��" << endl
					<< "3��ǿ�л���9999���ֳ�ΪVIP������ѡ3����" << endl
					<< "4���򿪱���Ϸ�����ļ��У��ҵ�data.txt�ļ����ѵڶ������ָ�Ϊ1���ɡ�" << endl;
				cout << "****************************************" << endl;
				cout << "��֪���ˣ�����0���أ�:";
				int tEmp = -1;
				bint(tEmp,0);
			}
			if (Temp == 3) {
				if (!C.isvip) {
					system("cls");
					if (C.score < 9999) {
						cout << "���ֲ��㣡" << endl;
						int tEmp = -1;
						cout << "������0���أ�";
						bint(tEmp, 0);
					}
					else {
						cout << "��ϲ����ΪVIP!" << endl;
						cout << "��֪���ˣ�����0���أ���";
						int tEmp=-1;
						bint(tEmp,0);
						C.score -= 9999;
						C.isvip = true;
					}
				}
				else {
					system("cls");
					cout << "���Ѿ���VIP!" << endl;
					cout << "������0���أ�";
					int tEmp = -1;
					bint(tEmp,0);
				}
			}
		}
			system("cls");
		}
		if (temp == 3) {
			system("cls");
			cout << "���¿�ʼ�����Ļ��ֽ������㣬VIP��ȨҲ����ʧ��\nȷ�����¿�ʼ������1������������0��";
			int Temp = -1;bint(Temp);
			system("cls");
			if (Temp) {
				C.isvip = false;
				C.max1 = 0;
				C.max2 = 0;
				C.score = 0;
				C.color = 0;
				for (;;) {                                      //ע��
					cout << "ע����......\n";
					cout << "�����������Ϸ����20���ַ�����Ŷ����";
					cin >> C.name;
					system("cls");
					cout << "��������Ϊ��" << C.name << endl;
					cout << "������ȷ����" << endl;
					cout << "ȷ��������1��" << endl;
					cout << "�޸�������2��" << endl;
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