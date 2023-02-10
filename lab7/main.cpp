#include <iostream>
#include <list>
using namespace std;

#define SIZE 8

class Figure {
private:

	char _Alp[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char _Nums[SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8' };

	string start_pos;
	string target_pos;

public:
	Figure() {
		this->start_pos = "";
		this->target_pos = "";
	}
	Figure(string start_pos) {
		this->start_pos = start_pos;
		this->target_pos = "";
	}
	
	char* _getAlp() { return this->_Alp; }
	char* _getNum() { return this->_Nums; }

	void setStart(string pos) { this->start_pos = pos; }
	string getStart() { return this->start_pos; }

	void getPos(string curPos, int* resPos) {

		char* alp = this->_getAlp();
		char* nums = this->_getNum();

		for (int i = 0; i < SIZE; i++) {
			if (curPos[0] == alp[i]) resPos[0] = i;
			if (curPos[1] == nums[i]) resPos[1] = i;
		}
	}

	virtual void makeMove(string target_pos) = 0;

};

class Horse : public Figure {
public:

	Horse(string start_pos) { this->setStart(start_pos); }

	list<string> getPossibleMoves(int* startPos) {

		list<string> res;

		char* alp = this->_getAlp();
		char* nums = this->_getNum();
		
		bool primaryPos = false;
		const int possibleForward = 2, possibleSide = 1;
		string possibleAlp, possibleNum;

		for (int i = 0; i < 8; i++) {
			if (i == 4) primaryPos = true;
			
			if ((i % 4) < 2) {
				if ((startPos[0] - (!primaryPos ? possibleForward : possibleSide)) < 0) continue;
				possibleAlp = alp[startPos[0] - (!primaryPos ? possibleForward : possibleSide)];
			}
			else {
				if ((startPos[0] + (!primaryPos ? possibleForward : possibleSide)) >= 8 || (startPos[0] + (!primaryPos ? possibleForward : possibleSide) < 0 )) continue;
				possibleAlp = alp[startPos[0] + (!primaryPos ? possibleForward : possibleSide)];
			}

			if ((i % 2) == 0) {
				if ((startPos[1] - (primaryPos ? possibleForward : possibleSide)) < 0) continue;
				possibleNum = nums[startPos[1] - (primaryPos ? possibleForward : possibleSide)];
			}
			else {
				if ((startPos[1] + (primaryPos ? possibleForward : possibleSide)) >= 8) continue;
				possibleNum = nums[startPos[1] + (primaryPos ? possibleForward : possibleSide)];
			}

			res.push_back(possibleAlp + possibleNum);

		}
		return res;

	}

	int checkMoveAvailable(string target, list<string> possibleMoves) {
		for(string i: possibleMoves)
			if (target == i) 
				return true;
		return false;
	}

	void makeMove(string target) {
		
		int startPos[2], targetPos[2];

		this->getPos(this->getStart(), startPos);
		this->getPos(target, targetPos);

		int status = checkMoveAvailable(target, this->getPossibleMoves(startPos));

		if (status) {
			this->setStart(target);
			cout << "You make your move succesfully" << endl;
		}
		else cout << "You can't make this move" << endl;

	}
};

class Bishop : public Figure {
public:
	Bishop(string startPos) { this->setStart(startPos); }

	void makeMove(string target) {
		int startPos[2], targetPos[2];

		this->getPos(this->getStart(), startPos);
		this->getPos(target, targetPos);

		if (targetPos[0] - startPos[0] == targetPos[1] - startPos[1]){
			this->setStart(target);
			cout << "You make your move succesfully" << endl;
		}
		
		else cout << "You can't make this move" << endl;
	}
};

class Castle : public Figure {
public:
	Castle(string startPos) { this->setStart(startPos); }

	void makeMove(string target) {
		int startPos[2], targetPos[2];

		this->getPos(this->getStart(), startPos);
		this->getPos(target, targetPos);

		if (targetPos[0] == startPos[0] || targetPos[1] == startPos[1]) {
			this->setStart(target);
			cout << "You make your move succesfully" << endl;
		}
		else cout << "You can't make this move" << endl;
	}
};

class Queen : public Figure {
public:
	Queen(string startPos) { this->setStart(startPos); }

	void makeMove(string target) {
		int startPos[2], targetPos[2];

		this->getPos(this->getStart(), startPos);
		this->getPos(target, targetPos);

		if (
			(targetPos[0] == startPos[0] || targetPos[1] == startPos[1]) || 
			(targetPos[0] - startPos[0] == targetPos[1] - startPos[1])
		) 
		{
			this->setStart(target);
			cout << "You make your move succesfully" << endl;
		}
		else cout << "You can't make this move" << endl;
	}
};

int main() {

	list<Figure*> arr;

	Horse a = Horse("D4");		arr.push_back(&a);
	Bishop b = Bishop("A1");	arr.push_back(&b);
	Castle c = Castle("A1");	arr.push_back(&c);
	Queen d = Queen("D5");		arr.push_back(&d);

	for (Figure* i : arr) {
		i->makeMove("A2");
	}
}