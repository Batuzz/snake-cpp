# Projekt zaliczeniowy
|  | |
| ------ | ------ |
| Przedmiot | Jêzyki programowania|
| Autor | Bartosz Studnik |
| Jêzyk | C++ |
| Uczelnia | Wy¿sza Szko³a Technologii Informatycznych |
| Grupa | 2 AZI |
| Semestr | II |
| Rok | 2019 |


## Klasy

* ## Abstrakcyjne

| Nazwa | Opis | Zastosowanie |
| ------ | ------ | ------ |
| AbstractCollisionEngine | Abstrakcyjna klasa silnika kolizji. Dziedziczona w celu wymuszenia implementacji, stworzenia cia³a metody wirtualnej. | **ScoreCollisionEngine**<br> **SnakeCollisionEngine**<br>**WallCollisionEngine**|

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
| AbstractController | Abstrakcyjna klasa kontrolera odpowiedzialnego za ruch wê¿a. Dziedziczona w celu wymuszenia implementacji metod oraz zachowania dzia³ania niektórych z nich. Dziêki temu zabiegowi bêdzie mo¿na bezproblemowo zamieniæ zaimplementowany dalej `KeyboardController` np. na mechanizm sztucznej inteligencji rozwi¹zuj¹cy grê bez ingerencji u¿ytkownika. | **KeyboardController**|

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
Klasa reprezentuj¹ca punkt na planszy.
Posiada w³asny operator porównania pozycji dwóch punktów (dwóch instancji klasy Point).

| Pole klasy| Opis |
| ------ | ------ |
| `int x` | Umiejscowienie punktu na osi OX | 
| `int y` | Umiejscowienie punktu na osi OY | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Point(int x = 0, int y = 0)` | Konstruktor przyjmuj¹cy wartoœci x i y | 
| `int getX()` | Zwraca wartoœæ pola `x` instancji klasy `Point`. | 
| `int getY()` | Zwraca wartoœæ pola `y` instancji klasy `Point`. | 
| `int setX(int x)` | Ustawia wartoœæ pola `x` instancji klasy `Point`. | 
| `int setY(int y)` | Ustawia wartoœæ pola `y` instancji klasy `Point`. | 

<br>

| Operator | Opis |
| ------ | ------ |
| `bool operator==(Point& point)` | Porównuje umiejscowienie aktualnej instancji klasy `Point` z obiektem przekazanym w parametrze. Zwraca `true`, jeœli pozycje s¹ identyczne. | 

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
Klasa reprezentuj¹ca planszê gry.

| Pole klasy| Opis |
| ------ | ------ |
| `int width` | Szerokoœæ planszy | 
| `int height` | Wysokoœæ planszy | 
| `char wallCharacter` | Znak oznaczaj¹cy œcianê planszy | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Map(int width, int height, char wallCharacter)` | Konstruktor przyjmuj¹cy wszystkie wymagane wartoœci | 
| `int getWidth()` | Zwraca wartoœæ pola `width` instancji klasy `Map`. | 
| `int getHeight()` | Zwraca wartoœæ pola `height` instancji klasy `Map`. | 
| `char getWallCharacter()` | Zwraca wartoœæ pola `wallCharacter` instancji klasy `Map`. | 


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
Klasa reprezentuj¹ca punkt (wed³ug niektórych - "jedzenie" dla wê¿a), po którego zdobyciu d³ugoœæ wê¿a wyd³u¿a siê o wartoœæ (pole `int value`) podan¹ podczas tworzenia obiektu `Score`.

| Pole klasy| Opis |
| ------ | ------ |
| `Point* position` | Punkt oznaczaj¹cy miejsce pojawienia siê mo¿liwego do zdobycia "jedzenia"| 
| `char scoreCharacter` | Znak oznaczaj¹cy "jedzenie" na planszy | 
| `int value` | Wartoœæ o jak¹ zostanie zwiêkszony wynik (wyd³u¿ony w¹¿) po zdobyciu "jedzenia" | 

<br>

| Metoda | Opis |
| ------ | ------ |
| `Score(int value, char scoreCharacter)` | Konstruktor przyjmuj¹cy wszystkie wymagane wartoœci | 
| `void setRandomPosition(Map* map, Snake* snake)` | Ustawia wartoœæ `position` instancji klasy `Score`. Parametry `map` oraz `snake` s³u¿¹ do tego, aby punkt nie pojawi³ siê poza map¹ lub w ciele wê¿a. | 
| `Point* getPosition()` | Zwraca wartoœæ pola `position` instancji klasy `Score`. | 
| `char getCharacter()` | Zwraca wartoœæ pola `scoreCharacter` instancji klasy `Score`. | 


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