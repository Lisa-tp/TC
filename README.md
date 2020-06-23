# TC
Techniki programowania projekt4.

URUCHAMIANIE:
1. Pobierz ze strony Enauczanie na kursie Techniki Programowania folder z przykładowym programem Draw2
2. Podmień pliki w folderze draw 
3. Uruchom Draw2.sln
4. Otwórz w konsoli VisualStudio podmieniony plik draw2.cpp
5. W razie wyskakującego komunikatu kliknij ok
6. Uruchom debugowanie


INFORMACJE DLA UŻYTKOWNIKA

Program ten jest symulatorem dźwiga, zaprogramowanego tak, aby układał wieżę o wysokości 3 figur wyłącznie z trójkątów.
Po prawej stronie okna znajduje się pulpit sterujący.
Na dole są przyciski, zmieniające kształt figury na platformie.
Po prawej stronie jest platforma, na której dozwolone jest układanie wieży.

INFORMACJE DLA PROGRAMISTY:

Program działa poprzez rysowanie w dwóch oddzielnych funkcjach- dźwigu i figurach. Podczas gdy ta pierwsza ma dość prostą strukturę, druga zawiera w sobie zarówno "worki" z figurami, które można zamieniać na inne, poruszającą się z ramieniem figurę oraz te, które już tworzą wieżę, z koordynatami zapisanymi w tablicy. 

Poruszanie figurami opiera się na timerach (i przyciskach im odpowiadających) i prostych ograniczeniach.
Teoretycznie możemy tworzyć i ustawiać tyle trójkątów, ile jest miejsc w tablicy (50), ale ze względu na ograniczenia zadania nie ma to sensu.
