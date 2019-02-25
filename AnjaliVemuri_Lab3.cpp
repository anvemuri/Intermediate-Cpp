#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int showMenu();

enum Status { CHECKED_OUT, ON_SHELF };

struct Book
{
	string title;
	string author;
	string isbn;
	int copies;
	Status status;
};

// PROTOTYPES
int showMenu();
void sortBooks(string[], int);

int main()
{
	// ARRAY DEFINITIONS
	const int SIZE = 20;
	Book bookList[SIZE];
	string bookTitleSort[SIZE];
	string bookAuthorSort[SIZE];

	// DEFINITIONS
	int choice, numChoice, arrayCounter, position, contents;
	int counter = 0;
	int  value = 0;
	string temp;
	char charChoice;

	//Set all copies to 0
	for (int i = 0; i < SIZE; i++)
	{
		bookList[i].copies = 0;
	}

	// info is a Book structure
	Book info;
	Book tempInfo;

	// ARRAY INITIALIZATIONS
	bookList[0] = { "The American Promise", "Roark", "20262628", 1 };
	bookList[1] = { "PreCalculus Limits", "Larson", "59874154", 0 };
	bookList[2] = { "American History", "Michael", "54897869", 1 };

	choice = showMenu(); // Display the menu and prompt the user to enter a choice

						 // Repeat getting the choice until the user types in a number less than 1, and more than 5.
	while (choice > 0 && choice <= 5)
	{
		switch (choice)
		{
			//Add or save a new book record
		case 1:	for (int i = 0; i < SIZE; i++) // Get the first
		{
			if (bookList[i].copies == 0 && (bookList[i].title).length() == 0)
			{
				arrayCounter = i;
				break;
			}
		}

				cin.ignore();
				cout << "Enter the title of the book: ";
				getline(cin, bookList[arrayCounter].title);
				cout << "Enter the author of the book: ";
				getline(cin, bookList[arrayCounter].author);
				cout << "Enter the 8 digit isbn: ";
				cin >> bookList[arrayCounter].isbn;
				cout << "How many copies of the book? ";
				cin >> bookList[arrayCounter].copies;
				cout << endl;
				cout << "The book is now saved!\n\n";
				choice = showMenu(); // show the menu again and get a choice from the user
				break;

				// 	Search a book
		case 2: cout << "1. Search by title" << endl;
			cout << "2. Search by author" << endl;
			cout << "3. Search by ISBN" << endl << endl;
			cout << "Enter your choice: ";
			cin >> numChoice;
			cout << endl;
			switch (numChoice)
			{
			case 1:	cin.ignore();
				cout << "Enter the title of the book you want to search: ";
				getline(cin, temp);
				cout << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (temp == bookList[i].title)
					{
						position = i;
						value = 1;
					}
				}

				if (value == 1)
				{
					cout << "Book information found (title): " << temp << endl << endl;
					cout << "Title: " << bookList[position].title << endl;
					cout << "Author: " << bookList[position].author << endl;
					cout << "ISBN: " << bookList[position].isbn << endl << endl;
					cout << "Do you want to borrow it(Y or N)? ";
					cin >> charChoice;
					switch (charChoice)
					{
					case 'Y':
					case 'y': if (bookList[position].copies == CHECKED_OUT)
					{
						cout << "\nSorry, the book you are trying to borrow is out of stock" << endl;
					}
							  else
							  {
								  bookList[position].copies--;
								  cout << "\nThe book is now borrowed!" << endl;
							  }
							  break;
					case 'N':
					case 'n': break;
					}
				}
				else if (value == 0)
				{
					cout << "There is no book found with the title of: " << temp << endl;
				}
				break;

			case 2: cin.ignore();
				cout << "Enter the author of the book you want to search: ";
				getline(cin, temp);
				cout << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (temp == bookList[i].author)
					{
						position = i;
						value = 1;
					}
				}

				if (value == 1)
				{
					cout << "Book information found with author: " << temp << endl << endl;
					cout << "Title: " << bookList[position].title << endl;
					cout << "Author: " << bookList[position].author << endl;
					cout << "ISBN: " << bookList[position].isbn << endl << endl;
					cout << "Do you want to borrow it(Y or N)? ";
					cin >> charChoice;
					switch (charChoice)
					{
					case 'Y':
					case 'y': if (bookList[position].copies == CHECKED_OUT)
					{
						cout << "\nSorry, the book is out of stock" << endl;
					}
							  else
							  {
								  bookList[position].copies--;
								  cout << "\nThe book is now borrowed!" << endl;
							  }
							  break;
					case 'N':
					case 'n': break;
					}
				}
				else if (value == 0)
				{
					cout << "There is no book found with the author: " << temp << endl;
				}

				break;

			default: cin.ignore();
				cout << "Enter the ISBN of the book you want to search: ";
				getline(cin, temp);
				cout << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (temp == bookList[i].isbn)
					{
						position = i;
						value = 1;
					}
				}
				if (value == 1)
				{
					cout << "Book information found with ISBN: " << temp << endl << endl;
					cout << "Title: " << bookList[position].title << endl;
					cout << "Author: " << bookList[position].author << endl;
					cout << "ISBN: " << bookList[position].isbn << endl << endl;
					cout << "Do you want to borrow it(Y or N)? ";
					cin >> charChoice;
					switch (charChoice)
					{
					case 'Y':
					case 'y': if (bookList[position].copies == CHECKED_OUT)
					{
						cout << "\nSorry, the book you are trying to borrow is out of stock" << endl;
					}
							  else
							  {
								  bookList[position].copies--;
								  cout << "\nThe book is now borrowed!" << endl;
							  }
							  break;
					case 'N':
					case 'n': break;
					}
				}
				else if (value == 0)
				{
					cout << "There is no book found with the ISBN of: " << temp << endl;
				}
			}
			choice = showMenu(); // show the menu again and get a choice from the user
			break;

			// Return or borrow book
		case 3:	cout << "1. Return" << endl;
			cout << "2. Borrow" << endl;
			cout << "\nEnter your choice: ";
			cin >> numChoice;
			cout << endl;
			switch (numChoice)
			{
			case 1: cin.ignore();
				cout << "Enter the title of the book: ";
				getline(cin, tempInfo.title);
				cout << "Enter the author of the book: ";
				getline(cin, tempInfo.author);
				cout << "Enter the 8 digit isbn: ";
				cin >> tempInfo.isbn;
				for (int i = 0; i < SIZE; i++)
				{
					if (tempInfo.title == bookList[i].title && tempInfo.author == bookList[i].author && tempInfo.isbn == bookList[i].isbn)
					{
						position = i;
						value = 1;
					}
				}
				if (value == 1)
				{
					bookList[position].copies++;
					cout << "\nThe book is now returned!" << endl;
				}
				else if (value == 0)
				{
					cout << "\nThe book you are trying to return is not on our library" << endl;
				}
				break;
			default: cin.ignore();
				cout << "Enter the title of the book: ";
				getline(cin, tempInfo.title);
				cout << "Enter the author of the book: ";
				getline(cin, tempInfo.author);
				cout << "Enter the 8 digit isbn: ";
				cin >> tempInfo.isbn;
				for (int i = 0; i < SIZE; i++)
				{
					if (tempInfo.title == bookList[i].title && tempInfo.author == bookList[i].author && tempInfo.isbn == bookList[i].isbn)
					{
						position = i;
						value = 1;
					}
				}
				if (value == 1)
				{
					bookList[position].copies--;
					cout << "\nThe book is now borrowed!" << endl;
				}
				else if (value == 0)
				{
					cout << "\nThe book you are trying to borrow is not on our library" << endl;
				}
			}
			choice = showMenu(); // show the menu again and get a choice from the user
			break;

			// List books by status
		case 4:	for (int i = 0; i < SIZE; i++)
		{
			switch (bookList[i].copies)
			{
			case 0: bookList[i].status = static_cast<Status>(0);
				break;
			default: bookList[i].status = static_cast<Status>(1);
			}
		}
				cout << "\tTITLE" << "\t\t\tAUTHOR" << "\t\tISBN" << "\t\tSTATUS" << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (bookList[i].copies >= 0 && (bookList[i].title).length() >= 1)
					{
						if (bookList[i].status == CHECKED_OUT)
						{
							cout << i + 1 << ". " <<
								bookList[i].title << "\t\t" << bookList[i].author << "\t\t" << bookList[i].isbn << "\t" << "Checked out" << endl;
						}
						else if (bookList[i].status == ON_SHELF)
						{
							cout << i + 1 << ". " << bookList[i].title << "\t\t" << bookList[i].author << "\t\t" << bookList[i].isbn << "\t" << "On shelf" << endl;
						}
					}
				}
				choice = showMenu(); // show the menu again and get a choice from the user
				break;

				// Display books
		default: cout << "1. Display library" << endl;
			cout << "2. Sort by title" << endl;
			cout << "3. Sort by author" << endl << endl;
			cout << "Enter your choice: ";
			cin >> numChoice;
			cout << endl;

			switch (numChoice)
			{
			case 1: cout << "\tTITLE" << "\t\t\tAUTHOR" << "\t\tISBN" << "\t\tCOPIES" << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (bookList[i].copies >= 0 && (bookList[i].title).length() >= 1)
					{
						cout << i + 1 << ". " << bookList[i].title << "\t\t" << bookList[i].author << "\t\t" << bookList[i].isbn << "\t   " << bookList[i].copies << endl;
					}
				}
				break;

			case 2:	for (int i = 0; i < SIZE; i++) // Get the first
			{
				if (bookList[i].copies == 0 && (bookList[i].title).length() == 0)
				{
					arrayCounter = i;
					break;
				}
			}
					contents = arrayCounter;
					for (int i = 0; i < contents; i++) // Copy contents of bookList array to bookSort
					{
						bookTitleSort[i] = bookList[i].title;
					}

					sortBooks(bookTitleSort, contents); // sort the contents of the array

					cout << "TITLE (SORTED)" << endl << endl;
					for (int i = 0; i < SIZE; i++) // Display the contents of the sorted array
					{
						if (bookTitleSort[i].length() > 0)
						{
							cout << (i + 1) << ". " << bookTitleSort[i] << endl;
						}
					}
					cout << "\nEnter your choice to see details: ";
					cin >> numChoice;
					cout << endl;
					for (int i = 0; i < SIZE; i++) // Find the title of the book chosen in the original unsorted array bookList.
					{
						if (bookTitleSort[numChoice - 1] == bookList[i].title)
						{
							position = i;
							break;
						}
					}
					cout << "Title: " << bookList[position].title << endl;
					cout << "Author: " << bookList[position].author << endl;
					cout << "ISBN: " << bookList[position].isbn << endl << endl;
					cout << "Do you want to borrow it(Y or N)? ";
					cin >> charChoice;
					switch (charChoice)
					{
					case 'Y':
					case 'y': if (bookList[position].copies == CHECKED_OUT)
					{
						cout << "\nSorry, the book you are trying to borrow is out of stock" << endl;
					}
							  else
							  {
								  bookList[position].copies--;
								  cout << "\nThe book is now borrowed!" << endl;
							  }
							  break;
					case 'N':
					case 'n': break;
					}
					break;

			default: for (int i = 0; i < SIZE; i++) // Get the first
			{
				if (bookList[i].copies == 0 && (bookList[i].title).length() == 0)
				{
					arrayCounter = i;
					break;
				}
			}contents = arrayCounter;
				for (int i = 0; i < SIZE; i++)
				{
					bookAuthorSort[i] = bookList[i].author;
				}
				sortBooks(bookAuthorSort, contents); // Sort the contents of the array alphabetically

				cout << "AUTHOR (SORTED)" << endl << endl;
				for (int i = 0; i < SIZE; i++)
				{
					if (bookAuthorSort[i].length() > 0)
					{
						cout << (i + 1) << ". " << bookAuthorSort[i] << endl;
					}
				}
				cout << "Enter the your choice to see more details: ";
				cin >> numChoice;
				cout << endl;
				for (int i = 0; i < SIZE; i++) // Find the author of the book chosen in the original unsorted array bookList.
				{
					if (bookAuthorSort[numChoice - 1] == bookList[i].author)
					{
						position = i;
						break;
					}
				}
				cout << "Title: " << bookList[position].title << endl;
				cout << "Author: " << bookList[position].author << endl;
				cout << "ISBN: " << bookList[position].isbn << endl << endl;
				cout << "Do you want to borrow it(Y or N)? ";
				cin >> charChoice;
				cout << endl;
				switch (charChoice)
				{
				case 'Y':
				case 'y': if (bookList[position].copies == CHECKED_OUT)
				{
					cout << "\nSorry, the book you are trying to borrow is out of stock" << endl;
				}
						  else
						  {
							  bookList[position].copies--;
							  cout << "\nThe book is now borrowed!" << endl;
						  }
						  break;
				case 'N':
				case 'n': break;
				}

			}

			choice = showMenu(); // show the menu again and get a choice from the user

		}
	}
}


int showMenu()
{
	int choice;

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\tLIBRARY SERVICES" << endl << endl;
	cout << "1. Add or save a new book record" << endl;
	cout << "2. Search for a book" << endl;
	cout << "3. Return or Borrow a book" << endl;
	cout << "4. List book by status" << endl;
	cout << "5. Display library collection" << endl << endl;
	cout << "Enter your choice(0 to stop): ";
	cin >> choice;
	cout << "\n-------------------------------------------------------------------------------" << endl;

	return choice;
}


void sortBooks(string books[], int length)
{
	int i, j;
	string value;
	for (i = 1; i < length; i++)
	{
		value = books[i];
		for (j = i - 1; j >= 0 && books[j] > value; j--)
		{
			books[j + 1] = books[j];
		}
		books[j + 1] = value;
	}
}







