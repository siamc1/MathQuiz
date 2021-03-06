// MathQuiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Problem {
	int Ans;
	int Diff;
	int *Args;
	int *Ops;
	string *OpChars;
	public:
		void set_prob(int[], int[], int, int);
		string get_prob(void);
		bool is_correct(int ans);
};

void Problem::set_prob(int args[], int op[], int ans, int d) {
	Args = args;
	Ops = op;
	Ans = ans;
	Diff = d;
	OpChars = new string[Diff];
	for (int i = 0; i < Diff; i++) {
		switch (Ops[i]) {
		case 0:
			OpChars[i] = "+";
			break;
		case 1:
			OpChars[i] = "-";
			break;
		case 2:
			OpChars[i] = "*";
			break;
		case 3:
			OpChars[i] = "/";
			break;
		}
	}
	
}
string Problem::get_prob() {
	int count = 0;
	string output = "";
	stringstream ss;
	ss << "";
	switch (Diff) {
	case 1:
		ss << Args[0] << ' ' << OpChars[0] << ' ' << Args[1] << " = ";
		output = ss.str();
		break;
	case 2:
		ss << Args[0] << ' ' << OpChars[0] << ' ' << Args[1] << ' ' << OpChars[1] << ' ' << Args[2] << " = ";
		output = ss.str();
		break;
	case 3:
		ss << Args[0] << ' ' << OpChars[0] << ' ' << Args[1] << ' ' << OpChars[1] << ' ' << Args[2] << ' ' << OpChars[2] << ' ' << Args[3] << " = ";
		output = ss.str();
	}
	
	

	return output;
}
bool Problem::is_correct(int ans) {
	return ans == this->Ans;
}

Problem generate_problem(int diff) {
	int ans = 0;
	int *args = nullptr;
	int *op = nullptr;
	switch (diff) {
	case 1:
		op = new int[1];
		op[0] = rand() % 4;
		args = new int[2];
		if (op[0] == 3) {
			args[1] = rand() % 9 + 1;
			ans = rand() % 9 + 1;
			args[0] = ans * args[1];
		}
		else {
			args[0] = rand() % 9 + 1;
			args[1] = rand() % 9 + 1;
			switch (op[0]) {
			case 0:
				ans = args[0] + args[1];
				break;
			case 1:
				ans = args[0] - args[1];
				break;
			case 2:
				ans = args[0] * args[1];
				break;
			}
		}
		break;
	case 2:
		op = new int[2];
		op[0] = rand() % 4;
		op[1] = rand() % 4;
		args = new int[3];
		if (op[0] == 3) {
			int sudoans;
			if (op[1] == 3) {
				ans = rand() % 9 + 1;
				args[2] = rand() % 9 + 1;
				sudoans = ans * args[2];
				args[1] = rand() % 9 + 1;
				args[0] = sudoans * args[1];
			}
			else if (op[1] == 2) {
				args[1] = rand() % 9 + 1;
				args[2] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				args[0] = args[1] * args[2] * ans;
			}
			else if (op[1] == 1) {
				args[1] = rand() % 9 + 1;
				args[2] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				args[0] = (ans + args[2]) * args[1];
			}
			else {
				args[1] = rand() % 9 + 1;
				args[2] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				args[0] = (ans - args[2]) * args[1];
			}
		}
		else if (op[1] == 3) {
			int sudoans;
			if (op[0] == 2) {
				args[2] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				sudoans = ans * args[2];
				args[1] = rand() % 9 + 1;
				args[0] = sudoans / args[1];
			}
			else if (op[0] == 1) {
				args[0] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				sudoans = ans - args[0];
				args[2] = rand() % 9 + 1;
				args[1] = -sudoans * args[2];
			}
			else {
				args[0] = rand() % 9 + 1;
				ans = rand() % 9 + 1;
				sudoans = ans - args[0];
				args[2] = rand() % 9 + 1;
				args[1] = sudoans * args[2];
			}
		}
		else if (op[0] == 2) {
			args[0] = rand() % 9 + 1;
			args[1] = rand() % 9 + 1;
			args[2] = rand() % 9 + 1;
			if (op[1] == 2) {
				ans = args[0] * args[1] * args[2];
			}
			else if (op[1] == 1) {
				ans = args[0] * args[1] - args[2];
			}
			else {
				ans = args[0] * args[1] + args[2];
			}
		}
		else if (op[1] == 2) {
			args[0] = rand() % 9 + 1;
			args[1] = rand() % 9 + 1;
			args[2] = rand() % 9 + 1;
			if (op[0] == 1) {
				ans = args[0] - args[1] * args[2];
			}
			else {
				ans = args[0] + args[1] * args[2];
			}
		}
		else {
			args[0] = rand() % 9 + 1;
			args[1] = rand() % 9 + 1;
			args[2] = rand() % 9 + 1;
			if (op[0] == 0) {
				if (op[1] == 0) {
					ans = args[0] + args[1] + args[2];
				}
				else {
					ans = args[0] + args[1] - args[2];
				}
			}
			else {
				if (op[1] == 0) {
					ans = args[0] - args[1] + args[2];
				}
				else {
					ans = args[0] - args[1] - args[2];
				}
			}
		}
		break;
	case 3:
		op = new int[3];
		op[0] = rand() % 4;
		op[1] = rand() % 4;
		op[2] = rand() % 4;
		args = new int[4];
		if (op[0] == 3) {
			int sudoans;
			if (op[1] == 3) {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1) * args[2] * args[3];
					args[0] = (rand() % 9 + 1) * args[2] * args[3] * args[1];
					ans = args[0] / args[1] / args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = (rand() % 9 + 1) * args[2] * args[1];
					ans = args[0] / args[1] / args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = (rand() % 9 + 1) * args[2] * args[1];
					ans = args[0] / args[1] / args[2] - args[3];
				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = (rand() % 9 + 1) * args[2] * args[1];
					ans = args[0] / args[1] / args[2] + args[3];
				}
			}
			else if (op[1] == 2) {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] * args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] * args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] * args[2] - args[3];
				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] * args[2] + args[3];
				}
			}
			else if (op[1] == 1) {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] - args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] - args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] - args[2] - args[3];
				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] - args[2] + args[3];
				}
			}
			else {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] + args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] + args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] + args[2] - args[3];
				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1);
					args[0] = (rand() % 9 + 1) * args[1];
					ans = args[0] / args[1] + args[2] + args[3];
				}
			}
		}
		else if (op[1] == 3) {
			int sudoans;
			if (op[0] == 2) {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1) * args[2] * args[3];
					args[0] = (rand() % 9 + 1);
					ans = args[0] * args[1] / args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] * args[1] / args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] * args[1] / args[2] - args[3];
					
				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] * args[1] / args[2] - args[3];
				}
			}
			else if (op[0] == 1) {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1) * args[2] * args[3];
					args[0] = (rand() % 9 + 1);
					ans = args[0] - args[1] / args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] - args[1] / args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] - args[1] / args[2] - args[3];

				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] - args[1] / args[2] + args[3];
				}
			}
			else {
				if (op[2] == 3) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[3];
					args[1] = (rand() % 9 + 1) * args[2] * args[3];
					args[0] = (rand() % 9 + 1);
					ans = args[0] + args[1] / args[2] / args[3];
				}
				else if (op[2] == 2) {
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1);
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] + args[1] / args[2] * args[3];
				}
				else if (op[2] == 1) {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] + args[1] / args[2] - args[3];

				}
				else {
					args[3] = rand() % 9 + 1;
					args[2] = rand() % 9 + 1;
					args[1] = (rand() % 9 + 1) * args[2];
					args[0] = rand() % 9 + 1;
					ans = args[0] + args[1] / args[2] + args[3];
				}
			}
		}
		else if (op[2] == 3) {
			if (op[0] == 2) {
				if (op[1] == 2) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] * args[1] * args[2] / args[3];
				}
				else if (op[1] == 1) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] * args[1] - args[2] / args[3];
				}
				else {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] * args[1] + args[2] / args[3];
				}
			}
			else if (op[0] == 1) {
				if (op[1] == 2) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] - args[1] * args[2] / args[3];
				}
				else if (op[1] == 1) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] - args[1] - args[2] / args[3];
				}
				else {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] - args[1] + args[2] / args[3];
				}
			}
			else {
				if (op[1] == 2) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] + args[1] * args[2] / args[3];
				}
				else if (op[1] == 1) {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] + args[1] - args[2] / args[3];
				}
				else {
					args[0] = rand() % 9 + 1;
					args[3] = rand() % 9 + 1;
					args[2] = (rand() % 9 + 1) * args[2];
					args[1] = rand() % 9 + 1;
					ans = args[0] + args[1] + args[2] / args[3];
				}
			}
		}
		else {
			args[0] = rand() % 9 + 1;
			args[1] = rand() % 9 + 1;
			args[2] = rand() % 9 + 1;
			args[3] = rand() % 9 + 1;
			if (op[0] == 0) {
				if (op[1] == 0) {
					if (op[2] == 0) {
						ans = args[0] + args[1] + args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] + args[1] + args[2] - args[3];
					}
					else {
						ans = args[0] + args[1] + args[2] * args[3];
					}
				}
				else if (op[1] == 1) {
					if (op[2] == 0) {
						ans = args[0] + args[1] - args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] + args[1] - args[2] - args[3];
					}
					else {
						ans = args[0] + args[1] - args[2] * args[3];
					}
				}
				else {
					if (op[2] == 0) {
						ans = args[0] + args[1] * args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] + args[1] * args[2] - args[3];
					}
					else {
						ans = args[0] + args[1] * args[2] * args[3];
					}
				}
			}
			else if (op[0] == 1) {
				if (op[1] == 0) {
					if (op[2] == 0) {
						ans = args[0] - args[1] + args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] - args[1] + args[2] - args[3];
					}
					else {
						ans = args[0] - args[1] + args[2] * args[3];
					}
				}
				else if (op[1] == 1) {
					if (op[2] == 0) {
						ans = args[0] - args[1] - args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] - args[1] - args[2] - args[3];
					}
					else {
						ans = args[0] - args[1] - args[2] * args[3];
					}
				}
				else {
					if (op[2] == 0) {
						ans = args[0] - args[1] * args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] - args[1] * args[2] - args[3];
					}
					else {
						ans = args[0] - args[1] * args[2] * args[3];
					}
				}
			}
			else {
				if (op[1] == 0) {
					if (op[2] == 0) {
						ans = args[0] * args[1] + args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] * args[1] + args[2] - args[3];
					}
					else {
						ans = args[0] * args[1] + args[2] * args[3];
					}
				}
				else if (op[1] == 1) {
					if (op[2] == 0) {
						ans = args[0] * args[1] - args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] * args[1] - args[2] - args[3];
					}
					else {
						ans = args[0] * args[1] - args[2] * args[3];
					}
				}
				else {
					if (op[2] == 0) {
						ans = args[0] * args[1] * args[2] + args[3];
					}
					else if (op[2] == 1) {
						ans = args[0] * args[1] * args[2] - args[3];
					}
					else {
						ans = args[0] * args[1] * args[2] * args[3];
					}
				}
			}
		}
	}
	Problem p;
	p.set_prob(args, op, ans, diff);
	return p;
}

int main()
{	
	char input = 'y';
	cout << "Welcome to the math quiz!" << endl;
	cout << "You will be given 10 basic math questions that you must solve, and you will be given a score at the end!" << endl;
	while (input == 'y') {
		int score = 0;
		cout << endl << "Select your difficulty:\n1) Masy\n2) Medium\n3) Hard" << endl;
		int diff;
		cin >> diff;
		Problem prob;
		int ans;
		for (int i = 1; i <= 10; i++) {
			cout << endl << "Problem " + to_string(i) << endl;
			prob = generate_problem(diff);
			cout << endl << prob.get_prob();
			cin >> ans;
			if (prob.is_correct(ans)) {
				score++;
				cout << "Great! That's Right!" << endl;
			}
			else {
				cout << "Sorry, Wrong Answer... Better Luck Next Time!" << endl;
			}
		}
		cout << endl << "Your final score is " << score << " / 10" << endl;
		cout << "Would you like to try again? (y/n) ";
		cin >> input;
	}
    return 0;
}

