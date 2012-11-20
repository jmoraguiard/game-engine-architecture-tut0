#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum months_t { january=1, february, march, april,
                may, june, july, august,
                september, october, november, december} y2k;


struct movies_t {
  string title;
  int year;
} mine, yours;

void printmovie (movies_t movie);

int main ()
{
  string mystr;

	// WORKING WITH STRUCTURES DIRECTLY
  mine.title = "2001 A Space Odyssey";
  mine.year = 1968;

  cout << "Enter title: ";
  getline(cin, yours.title); // we can directly change member values
  cout << "Enter year: ";
  getline(cin, mystr);
  stringstream(mystr) >> yours.year;

  cout << "My favorite movie is:\n ";
  printmovie (mine);
  cout << "And yours is:\n ";
  printmovie (yours);

	getline(cin, mystr);

	// WORKING WITH STRUCTURES USING POINTERS
	movies_t amovie;
  movies_t * pmovie;
  pmovie = &amovie;

  cout << "Enter title: ";
  getline (cin, pmovie->title);
  cout << "Enter year: ";
  getline (cin, mystr);
  (stringstream) mystr >> (*pmovie).year; // The dereference is the same with -> than (* ).

  cout << "\nYou have entered:\n";
  cout << pmovie->title;
  cout << " (" << (*pmovie).year << ")\n";

	getline(cin, mystr);

  return 0;
}

void printmovie (movies_t movie) //functions can get structures
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}