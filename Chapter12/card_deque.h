// card_deque.h

#include <cliext\deque>
#include <cliext\algorithm> // for random_shuffle and rotate
#include <stdlib.h> // for rand
#include <math.h>  // for floor

using namespace cliext;

using namespace System;
using namespace System::Text;
using namespace System::Collections;

enum class SuitEnum { Diamonds, Clubs, Hearts, Spades };

// represents a playing card
public value struct Card
{
   SuitEnum suit;
   unsigned int rank;
   literal int CHAR_HEART = 3; // ANSI heart character
   literal int CHAR_DIAMOND = 4; // ANSI diamond
   literal int CHAR_CLUB = 5; // ANSI club
   literal int CHAR_SPADE = 6;  // ANSI spade

   Card(SuitEnum s, int r) : suit(s), rank(r) {}

   // operator== is required for deque on a value type
   bool operator==(Card% c)
   { return c.rank == rank && c.suit == suit; }

   // Render the two-character card using ANSI card values.
   virtual String^ ToString() override
   {

      if (rank <= 0 || rank > 13)
         throw gcnew ArgumentOutOfRangeException();

      StringBuilder^ s = gcnew StringBuilder();
      if (rank > 1 && rank < 11)
      {
         s->Append(rank);
      }
      else
      {
         switch (rank)
         {
         case 1: // Ace
            s->Append("A");
         case 11: // Jack
            s->Append("J");
            break;
         case 12:  // Queen
            s->Append("Q");
            break;
         case 13:  // King
            s->Append("K");
            break;
         default:
            throw gcnew ArgumentOutOfRangeException();
         }
      }
      switch (suit)
      {
      case SuitEnum::Clubs:
         s->Append(CHAR_CLUB, 1);
         break;
      case SuitEnum::Hearts:
         s->Append(CHAR_HEART, 1);
         break;
      case SuitEnum::Diamonds:
         s->Append(CHAR_DIAMOND, 1);
         break;
      case SuitEnum::Spades:
         s->Append(CHAR_SPADE, 1);
         break;
      default:
         throw gcnew ArgumentOutOfRangeException();
      }
      return s->ToString();
   }
};

typedef deque<Card> deck_type;
typedef deck_type::iterator deck_iterator;

public ref class Deck
{
   deck_type m_deck;
   static int seed;
   static int m_random;

   public:

   Deck()
   {
      Reset();
   }

   // Get a card from the front of the deck.
   Card^ DrawFirst()
   {
      if ( m_deck.size() > 0)
      {
         Card^ pCard = m_deck.front();
         m_deck.pop_front();
         return pCard;
      }
      else
      {
         return nullptr;
      }
   }

   Card* Peek(int nCard)
   {
      return &m_deck[nCard];
   }

   // Shuffle the deck
   void Shuffle()
   {
       // Use the STL/CLR algorithm random_shuffle
       random_shuffle( m_deck.begin(), m_deck.end() );
   }

   // Reset to the original unshuffled order
   // in a standard deck
   void Reset()
   {
      int s;
      int rank;
      m_deck.clear();
      for (s = 0; s <= 3; ++s)
      {
         for (rank = 1; rank <= 13; ++rank)
         {
            m_deck.push_back(Card( safe_cast<SuitEnum>(s), rank));
         }
      }
   }

   // Cut the deck: put the bottom cards at the top of the deck.
   // This is equivalent to a rotate operation
   void Cut(int n)
   {
      rotate(m_deck.begin(), m_deck.begin() + n, m_deck.end());
   }

};
