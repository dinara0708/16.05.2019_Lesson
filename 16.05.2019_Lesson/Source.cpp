﻿#include"Pupil.h"
#include"Student.h"
#include<vector>
#include<fstream>;

int main() {

	ifstream in_file("in.txt");
	Learner *ls;
	vector<Learner*> v;

	string str;
	while (!in_file.eof()) {
		in_file >> str;
		if (str == "pupil") {
			Pupil *tmp = new Pupil;//динамически создаем объект - т.е. указатель на временный объект, выделяя память на него динамически
			//иначе если будет статичный объект, то каждый раз считанная инфа будет пытаться записывать в одну и ту же область памяти, что приведет к ошибке и повтору
			in_file >> (*tmp);
			tmp->setType(str);
			ls = tmp;
			//ls->show();
		}
		else if (str == "student") {
			Student*tmp = new Student;
			in_file >> (*tmp);
			tmp->setType(str);
			ls = tmp;
			//ls->show();
		}
		v.push_back(ls);
		in_file.get();
	}
	cout << "PUPILS:" << endl;
	for (int i = 0; i < v.size(); i++)
		if(v[i]->getType()=="pupil")
			v[i]->show();
	cout << endl << endl;
	cout << "STUDENTS:" << endl;
	for (int i = 0; i < v.size(); i++)
		if (v[i]->getType() == "student")
			v[i]->show();

	in_file.close();

	system("pause");
	return 0;
}