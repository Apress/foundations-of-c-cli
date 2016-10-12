// cards_main.cpp
#include "card_deque.h"
int main()
{
   Deck deck;
   deck.Shuffle();
   // cut the deck at card 40
   deck.Cut(40);

   Card c1 = *deck.DrawFirst();
   //cout << "Your draw is " << c1 << endl;
   Console::WriteLine("Your draw is {0}", c1);

 }
