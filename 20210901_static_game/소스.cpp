#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
//Game클래스 선언

class Game {
private:
	double energy = 100;
	static int life;

public:
	Game();
	double Damage();
	static void Die();
};
int Game::life = 10;

void Game::Die() {

	cout << "**생명이 부족하여 사망했습니다.\n" << endl;

}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0 && life > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			energy = 100;

			if (life > 0) {
				int a = rand() % 2 + 1;
				life -= a;
				cout << "생명이 " << a << " 감소하여 " << life << "이 되었습니다." << endl << endl;

				if (life <= 0) {
					return 0;
				}
			}

		}
	}
	return energy;
}
//Game클래스 멤버 함수의 정의
Game::Game()
{
	life = 10;

	cout << "에너지가 " << energy << " 이며, 생명이 " << life << "인 캐릭터가 만들어졌습니다.\n";

	while (life > 0) {

		Damage();
	}

}

int main()
{
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여
	Game c1;
	Game::Die();
	Game c2;
	c2.Damage();
	c2.Damage();
	c2.Damage();
	c2.Die();
	return 0;
}