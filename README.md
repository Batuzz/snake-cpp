# Projekt zaliczeniowy
|  | |
| ------ | ------ |
| Przedmiot | J�zyki programowania|
| Autor | Bartosz Studnik |
| J�zyk | C++ |
| Uczelnia | Wy�sza Szko�a Technologii Informatycznych |
| Grupa | 2 AZI |
| Semestr | II |
| Rok | 2019 |


## Klasy

* ## Abstrakcyjne

| Nazwa | Opis | Zastosowanie |
| ------ | ------ | ------ |
| AbstractCollisionEngine | Abstrakcyjna klasa silnika kolizji. Dziedziczona w celu wymuszenia implementacji, stworzenia cia�a metody wirtualnej. | **ScoreCollisionEngine**<br> **SnakeCollisionEngine**<br>**WallCollisionEngine**|

```cpp
#pragma once
#include "Point.h"

class AbstractCollisionEngine {

protected:
	Point* currentPosition;

public:
	virtual bool hasCollided() = 0;
	void setCurrentPosition(Point* point);
};
```
<br><br><br>

| Nazwa | Opis | Zastosowanie |
| ------ | ------ | ------ |
| AbstractController | Abstrakcyjna klasa kontrolera odpowiedzialnego za ruch w�a. Dziedziczona w celu wymuszenia implementacji metod oraz zachowania dzia�ania niekt�rych z nich. Dzi�ki temu zabiegowi b�dzie mo�na bezproblemowo zamieni� zaimplementowany dalej `KeyboardController` np. na mechanizm sztucznej inteligencji rozwi�zuj�cy gr� bez ingerencji u�ytkownika. | **KeyboardController**|

```cpp
#pragma once
#include "Point.h"

class AbstractController
{
protected:
	Point* displacement;

public:
	AbstractController();
	Point getMove();
	virtual void prepareMove() = 0;
};
```
* ## Klasy nieabstrakcyjne (ang. concrete classes)

*  ### Point
Klasa reprezentuj�ca punkt na planszy.
Posiada w�asny operator por�wnania pozycji dw�ch punkt�w (dw�ch instancji klasy Point).

| Pole klasy| Opis |
| ------ | ------ |
| `int x` | Umiejscowienie punktu na osi OX | 
| `int y` | Umiejscowienie punktu na osi OY | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Point(int x = 0, int y = 0)` | Konstruktor przyjmuj�cy warto�ci x i y | 
| `int getX()` | Zwraca warto�� pola `x` instancji klasy `Point`. | 
| `int getY()` | Zwraca warto�� pola `y` instancji klasy `Point`. | 
| `int setX(int x)` | Ustawia warto�� pola `x` instancji klasy `Point`. | 
| `int setY(int y)` | Ustawia warto�� pola `y` instancji klasy `Point`. | 

<br>

| Operator | Opis |
| ------ | ------ |
| `bool operator==(Point& point)` | Por�wnuje umiejscowienie aktualnej instancji klasy `Point` z obiektem przekazanym w parametrze. Zwraca `true`, je�li pozycje s� identyczne. | 

```cpp
#pragma once

class Point {

private:
	int x;
	int y;

public:
	Point(int x = 0, int y = 0);
	bool operator==(Point& point);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};
```
<br><br>
*  ### Map
Klasa reprezentuj�ca plansz� gry.

| Pole klasy| Opis |
| ------ | ------ |
| `int width` | Szeroko�� planszy | 
| `int height` | Wysoko�� planszy | 
| `char wallCharacter` | Znak oznaczaj�cy �cian� planszy | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Map(int width, int height, char wallCharacter)` | Konstruktor przyjmuj�cy wszystkie wymagane warto�ci | 
| `int getWidth()` | Zwraca warto�� pola `width` instancji klasy `Map`. | 
| `int getHeight()` | Zwraca warto�� pola `height` instancji klasy `Map`. | 
| `char getWallCharacter()` | Zwraca warto�� pola `wallCharacter` instancji klasy `Map`. | 


```cpp
#pragma once

class Map {

private:
	int width;
	int height;
	char wallCharacter;

public: 
	Map(int width, int height, char wallCharacter);
	int getWidth();
	int getHeight();
	char getWallCharacter();
};
```
<br><br>
*  ### Score
Klasa reprezentuj�ca punkt (wed�ug niekt�rych - "jedzenie" dla w�a), po kt�rego zdobyciu d�ugo�� w�a wyd�u�a si� o warto�� (pole `int value`) podan� podczas tworzenia obiektu `Score`.

| Pole klasy| Opis |
| ------ | ------ |
| `Point* position` | Punkt oznaczaj�cy miejsce pojawienia si� mo�liwego do zdobycia "jedzenia"| 
| `char scoreCharacter` | Znak oznaczaj�cy "jedzenie" na planszy | 
| `int value` | Warto�� o jak� zostanie zwi�kszony wynik (wyd�u�ony w��) po zdobyciu "jedzenia" | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Score(int value, char scoreCharacter)` | Konstruktor przyjmuj�cy wszystkie wymagane warto�ci | 
| `void setRandomPosition(Map* map, Snake* snake)` | Ustawia warto�� `position` instancji klasy `Score`. Parametry `map` oraz `snake` s�u�� do tego, aby punkt nie pojawi� si� poza map� lub w ciele w�a. | 
| `Point* getPosition()` | Zwraca warto�� pola `position` instancji klasy `Score`. | 
| `char getCharacter()` | Zwraca warto�� pola `scoreCharacter` instancji klasy `Score`. | 


```cpp
#pragma once
#include "Point.h"
#include "Snake.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>

class Score
{
private:
	Point* position;
	char scoreCharacter;
	int value;

public:
	Score(int value, char scoreCharacter);
	void setRandomPosition(Map* map, Snake* snake);
	Point* getPosition();
	char getCharacter();
};
```
<br><br>