#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
//GameŬ���� ����

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

	cout << "**������ �����Ͽ� ����߽��ϴ�.\n" << endl;

}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0 && life > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n";
		if (energy < 0) {
			energy = 100;

			if (life > 0) {
				int a = rand() % 2 + 1;
				life -= a;
				cout << "������ " << a << " �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

				if (life <= 0) {
					return 0;
				}
			}

		}
	}
	return energy;
}
//GameŬ���� ��� �Լ��� ����
Game::Game()
{
	life = 10;

	cout << "�������� " << energy << " �̸�, ������ " << life << "�� ĳ���Ͱ� ����������ϴ�.\n";

	while (life > 0) {

		Damage();
	}

}

int main()
{
	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�
	Game c1;
	Game::Die();
	Game c2;
	c2.Damage();
	c2.Damage();
	c2.Damage();
	c2.Die();
	return 0;
}