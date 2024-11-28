#include<stdio.h>
#include<stdlib.h>

const char POUND = 156; // The char POUND is assigned the ASCII code of the pound sign

int getItemPrice(char choice, int applePrice, int orangePrice, int pearPrice)
{
	int price = 0;

	if (choice == 'a' || choice == 'A')
	{
		price = applePrice;
		return price;
	}

	else if (choice == 'o' || choice == 'O')
	{
		price = orangePrice;
		return price;
	}

	else if (choice == 'p' || choice == 'P')
	{
		price = pearPrice;
		return price;
	}

	else
	{
		return -1;
	}
}

void displayMenu(int applePrice, int orangePrice, int pearPrice)
{
	printf("\n***** Shop Menu *****\n");
	printf("Item:  Price\n");

	printf("A: %c%i\n",POUND, applePrice);
	printf("O: %c%i\n",POUND, orangePrice);
	printf("P: %c%i\n",POUND, pearPrice);
}

int withinBudget(int budget, char purchase, int applePrice, int orangePrice, int pearPrice)
{
	int price = 0;

	price = getItemPrice(purchase, applePrice, orangePrice, pearPrice);

	if (budget < price || price == -1)
	{
		return 0;
	}

	else
	{
		return 1;
	}
}

int purchaseItem(int budget, char purchase, int applePrice, int orangePrice, int pearPrice)
{
	int price = 0;
	price = getItemPrice(purchase, applePrice, orangePrice, pearPrice);

	if (withinBudget(budget, purchase, applePrice, orangePrice, pearPrice) == 1)
	{
		printf("\nPURCHASE SUCCESS!\n");

		printf("\nPurchase details\n");
		printf("-----------------\n");
		printf("Item: %c\n", purchase);
		printf("Price: %c%i\n",POUND, price);
		printf("Remaining budget: %c%i\n",POUND, budget - price);
	}
	else
	{
		printf("PURCHASE FAILED!\n");
		printf("Low budget or missing item.\n");
	}
	return 0;
}

int main()
{
	char fruitName[3][20] = { "Apple", "Orange", "Pear" };
	char fruitPre[3] = { 'A', 'O', 'P' };
	char cstmrc = 0;
	char cont = 'y'; // We assign the char cont the character 'y' so that the while loop begins automatically
	int price[3] = { 0, 0, 0 };
	int budget = 0;
	int applePrice = 0;
	int orangePrice = 0;
	int pearPrice = 0;

	printf("*** ItemPrefixes ***\n");

	for (int i = 0; i <= 2; i++)
	{
		printf("%c: %s\n", fruitPre[i], fruitName[i]);
	}

	printf("******************\n\n");

	printf("*** SHOPEKEEPER PANEL ***\n");

	for (int j = 0; j <= 2; j++)
	{
		printf("Please enter %s price:%c", fruitName[j],POUND);
		scanf_s("%i", &price[j]);
	}

	applePrice = price[0];
	orangePrice = price[1];
	pearPrice = price[2];

	displayMenu(applePrice, orangePrice, pearPrice);

	printf("\n\n*** CUSTOMER PANEL ***\n");
	printf("Please enter your budget: %c",POUND);
	scanf_s("%i", &budget);

	while (cont == 'y')
	{
		printf("\nPlease enter ItemPrefix from the Menu to purchase:");
		scanf_s(" %c", &cstmrc, 1);

		int fruitprice = getItemPrice(cstmrc, applePrice, orangePrice, pearPrice);

		withinBudget(budget, cstmrc, applePrice, orangePrice, pearPrice);
		purchaseItem(budget, cstmrc, applePrice, orangePrice, pearPrice);

		repeat: // If the user enter a character other than 'y' and 'n', they program loops back here 

		printf("\nWould you like to continue shopping (y/n)? ");
		scanf_s(" %c", &cont, 1);

		if (cont == 'y' || cont == 'Y')
		{
			if (fruitprice >= 0)
			{
				budget -= fruitprice;
			}
		}

		else if (cont == 'n' || cont == 'N')
		{
			printf("\n\nThanks for shopping with us!\n");
			exit(0);
		}

		else
		{
			printf("Non valid answer!\n");
			goto repeat; // The character entered was neither 'y' nor 'n' so the program loops back to repeat;
		}
	}
	return 0;
}