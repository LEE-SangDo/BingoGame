#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 number
	for (int i = 0; i < 25; i++)
	{
		iNumber[i] = i + 1; // start nuber = 1
	}

	// mix
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		/* swap(iNumber[idx1] = iNumber[idx2]); */
	}

	while (true)
	{
		system("cls"); // clear

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;

		// 중복입력을 체크하기 위한 변수이다. 기본적으로 중복되었다라고 
		// 하기 위해 true로 잡아주었다.
		bool bAcc = true;

		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가
		// 있는지를 찾아낸다.
		for (int i = 0; i < 25; ++i)
		{
			// 같은 숫자가 있을 경우 
			if (iInput == iNumber[i])
			{
				// 숫자를 찾았을 경우 중복된 숫자가 아니므로
				// bAcc 변수를 false로 만들어준다.
				bAcc = false;

				// 숫자를 *로 변경하기 위해 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				// 더이상 다른 숫자를 찾아볼 필요가 없으므로
				// for문을 빠져나간다.
				break;
			}
		}

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 
		// 바꾸지 못했으므로 다시 입력받게 continue 해준다.
		if (bAcc)
			continue;
	}
}