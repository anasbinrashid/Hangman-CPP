#include<iostream> 
using namespace std;

int main() 
{
	const int totalsize = 100;
	const int guesssize = 30;
	const int wordsize = totalsize / 2 + 1;
	char words[totalsize] = {};
	char guess[guesssize] = {};
	char word[wordsize] = {};
	char guess_t[totalsize] = {};
	char letter;
	int numberofwords = 0;
	int wrongguess = 0;
	int correctguess = 0;
	int currentwordsize = 0;
	int iteration = 0;
	int location = 0;
	bool correct = false;
	bool wordfound = false;
	bool cguess = false;

	cout << "\n~~~ WELCOME TO HANGMAN ~~~" << endl;

	cout << "\nEnter a list of words seperated by commas (All Lowercase): ";
	cin >> words;

	for (int i = 0; i < totalsize; i++) 
	{
		if (words[i] == '\0')
		{
			numberofwords += 1;
			break;
		}

		if (words[i] == ',')
		{
			numberofwords += 1;
		}
	}

	cout << "\nStarting the Game!\n";

	for (int loop = 0; loop < numberofwords; loop++)
	{
		if (loop > 0)
		{
			cout << "\nYOU WON!\n";
		}

		cout << "\nRound " << loop + 1 << " starting!\n";

		currentwordsize = 0;
		correctguess = 0;
		wrongguess = 0;

		for (int i = location; i < totalsize; i++)
		{
			if (words[i] == ',' || words[i] == '\0')
			{
				break;
			}
			else
			{
				word[currentwordsize] = words[i];
				currentwordsize++;
			}
		}

		word[currentwordsize] = '\0';

		for (int j = 0; j < guesssize; j++)
		{
			guess[j] = '_';
			guess_t[j] = '_';
		}

		guess[currentwordsize] = '\0';
		guess_t[currentwordsize] = '\0';

		location += currentwordsize + 1;

		iteration = 0;

		while (correctguess < currentwordsize)
		{
			do 
			{ 
				correct = false;
				wordfound = false;
				cout << "\nEnter a letter: ";
				cin >> letter;

				for (int m = 0; m < guesssize; m++)
				{
					if (letter == guess_t[m])
					{
						cout << "\nLetter already entered!\n";
						correct = true;
						break;
					}
				}
			} 
			while (correct);

			for (int i = 0; i < currentwordsize; i++)
			{
				if (word[i] == letter)
				{
					correctguess++;
					guess[i] = letter;
					guess_t[iteration] = letter;
					iteration++;
					wordfound = true;
				}
			}

			if (!wordfound)
			{
				guess_t[iteration] = letter;
				iteration++;
			}

			cout << "\nCorrect Guesses: " << guess;
			cout << "\nIncorrect Guesses: ";

			for (int v = 0; v < iteration; v++)
			{
				cguess = 0;

				for (int w = 0; w < currentwordsize; w++)
				{
					if (guess_t[v] == guess[w])
					{
						cguess = true;
					}
				}

				if (!cguess)
				{
					cout << guess_t[v] << " ";
				}
			}

			cout << endl;

			if (!wordfound)
			{
				wrongguess++;
			}

			if (wrongguess == 1) 
			{
				cout << "\n    +---+\n    |   |\n\t|\n\t|\n\t|\n\t|\n  =========" << endl;
			}
			else if (wrongguess == 2)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n\t|\n\t|\n\t|\n  =========" << endl;
			}
			else if (wrongguess == 3)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n    |   |\n\t|\n\t|\n  =========" << endl;
			}
			else if (wrongguess == 4)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n   /|   |\n\t|\n\t|\n  =========" << endl;
			}
			else if (wrongguess == 5)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n   /|\\  |\n\t|\n\t|\n  =========" << endl;
			}
			else if (wrongguess == 6)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n   /|\\  |\n   /    |\n\t|\n  =========" << endl;
			}

			if (wrongguess == 7)
			{
				cout << "\n    +---+\n    |   |\n    0   |\n   /|\\  |\n   / \\  |\n\t|\n  =========" << endl;
				cout << "\nNo more lives left! The word was: " << word << endl;

				return 0;
			}
		}
	}

	return 0;
}
