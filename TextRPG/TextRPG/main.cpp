#include <iostream>
#include <time.h> //랜덤값을 이용하기 위한 헤더
#include <process.h>
#include <stdlib.h> // 콘솔창에 이전 결과 덮어 씌우기

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};


enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};


enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SIZE 32

struct _taginventory
{
	int iGold;

};



struct _tagPlayer // 플레이어
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE]; //정수로만 비교하자
	JOB eJOB; // 직업
	int iAttackMin; //최소 공격력
	int iAttackMax; //최대 공격력
	int iArmorMin; // 최소 방어력
	int iArmorMax; // 최대 방어력
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel; //레벨
	_taginventory tinventory;
};

struct _tagMonster // 몬스터
{
	char strName[NAME_SIZE];
	int iAttackMin; //최소 공격력
	int iAttackMax; //최대 공격력
	int iArmorMin; // 최소 방어력
	int iArmorMax; // 최대 방어력
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel; //레벨
	int iExp; //잡았을때 얻을 경험치
	int iGoldMin; //잡았을때 떨어뜨리는 최소 돈
	int iGoldMax; // 최대 돈
};

int main()
{

	srand((unsigned int)time(0));

	//게임을 시작할때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {}; //0으로 초기화

	//플레이어 이름을 입력받는다.
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1); //문자열 끝은 NULL 이여야 한다.
	// 마지막 NULL넣을 공간 비워두기.

	int iJob = JOB_NONE;

	while (iJob == JOB_NONE) {

		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail()) // 입력에 실패할 경우
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;

		}


	}

	// 플레이어 셋팅
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJOB = (JOB)iJob;
	tPlayer.tinventory.iGold = 10000;

	switch (tPlayer.eJOB)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	default:
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 10;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	//세로 블록 : alt누르고
	//트롤 생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	//세로 블록 : alt누르고
	//드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;


	//메인 로비 화면 만들어주기
	while (true)
	{
		system("cls");
		cout << "****************************** 로비 ******************************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) // 입력에 실패할 경우
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;		 
		}

		if (iMenu == MM_EXIT) //종료인 경우
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "****************************** 맵 ******************************" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) // 입력에 실패할 경우
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}


				if(iMenu == MT_BACK)
					
				// 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while문에 속해있으므로
				// 이 while문을 빠져 나간다.
				if (iMenu == MT_BACK) // 뒤로가기 기능
					break;

				// 선택한 메뉴에 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					system("cls");

					switch (iMenu)
					{
					case MT_EASY :
						cout << "****************************** 쉬움 ******************************" << endl;
						break;
					case MT_NORMAL:
						cout << "****************************** 보통 ******************************" << endl;
						break;
					case MT_HARD:
						cout << "****************************** 어려움 ******************************" << endl;
						break;
					default:
						break;
					}

					// 플레이어 정보를 출력한다.
					cout << "***************************** 플레이어 *****************************" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " <<
						tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " <<
						tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << " ~ " << tPlayer.iAttackMax
						<< "\t방어력 : " << tPlayer.iArmorMin << " ~ " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						 "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유 골드 : " << tPlayer.tinventory.iGold << "Gold " << endl;

					// 몬스터 정보 출력
					cout << "****************************** 몬스터 ******************************" << endl;
					cout << "이름 : " << tMonster.strName << endl;
					cout << "레벨 : " << tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " ~ " << tMonster.iAttackMax
						<< "\t방어력 : " << tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "획득경험치 : " << tMonster.iExp <<
						"\t 획득골드 : " << tMonster.iGoldMin << " ~ " << tMonster.iGoldMax << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : ";
					cin >> iMenu;


					if (cin.fail()) // 입력에 실패할 경우
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
						/* 예를 들어 min 5, max 15라고 가정할 경우
						15 - 5 + 1 을 하면 11이 된다. 11로 나눈 나머지는 0 ~ 10이 나오게 되고
						여기에 min 값인 5를 더하게 되면 5 ~ 15 사이로 값이 나오게 된다.
						*/
					case BATTLE_ATTACK:
					{
						srand((unsigned int)time(0));
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1)
							+ tPlayer.iAttackMin; // 최소 ~ 최대 사이 공격력이 랜덤으로 지정
						srand((unsigned int)time(0));
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1)
							+ tMonster.iArmorMin; // 최소 ~ 최대 사이 공격력이 랜덤으로 지정

						int iDamage = iAttack - iArmor;
						// 삼항연산자 : 조건식 ? true일때 값 : false일때 값
						iDamage = iDamage < 1 ? 1 : iDamage;
						// if(iDagae < 1) iDamage = 1;
						// iDamage = max(1,iDamage); // 헤더 선언 필요

						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << "가 " << tMonster.strName <<
							"에게 " << iDamage << " 피해를 입혔습니다." << endl;

						// 몬스터가 죽었을 경우를 처리한다.
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin)
								+ tMonster.iGoldMin);

							tPlayer.tinventory.iGold += iGold;

							cout << tMonster.iExp << " 경험치를 획득하였습니다." << endl;
							cout << iGold << " Gold를 획득하였습니다." << endl;
							system("pause");
							break;
						}



						srand((unsigned int)time(0));
						//몬스터가 살아있다면 플레이어를 공격한다.

						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1)
							+ tMonster.iAttackMin; // 최소 ~ 최대 사이 공격력이 랜덤으로 지정
						srand((unsigned int)time(0));
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1)
							+ tPlayer.iArmorMin; // 최소 ~ 최대 사이 공격력이 랜덤으로 지정

						iDamage = iAttack - iArmor;
						// 삼항연산자 : 조건식 ? true일때 값 : false일때 값
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer.strJobName <<
							"에게 " << iDamage << " 피해를 입혔습니다." << endl;



						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " 플레이어가 사망하였습니다. " << endl;

							int iExp = tPlayer.iExp * 0.11;
							int iGold = tPlayer.tinventory.iGold * 0.11;

							tPlayer.iExp -= iExp;
							tPlayer.tinventory.iGold -= iGold;

							cout << iExp << " 경험치를 잃었습니다. " << endl;
							cout << iGold  << " Gold를 잃었습니다. " << endl;

							// 플레이어의 HP와 MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
							
						}
						system("pause");
					}
						break;
					default:
						break;
					}


				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}
	}


	return 0;
}