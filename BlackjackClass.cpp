// BlackjackClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BlackjackHeader.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <random>

// Maximum score before lossing
constexpr int maximumScore{ 21 };

// Minimum score that the dealer has to have
constexpr int mmimimumDealerScore{ 17 };

enum class CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
};

enum class CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
};

class Card
{
private:
    CardRank m_rank{};
    CardSuit m_suit{};

public:
    // Print the card value
    void print() const
    {
        switch (m_rank)
        {
        case CardRank::RANK_2:
            std::cout << '2';
            break;
        case CardRank::RANK_3:
            std::cout << '3';
            break;
        case CardRank::RANK_4:
            std::cout << '4';
            break;
        case CardRank::RANK_5:
            std::cout << '5';
            break;
        case CardRank::RANK_6:
            std::cout << '6';
            break;
        case CardRank::RANK_7:
            std::cout << '7';
            break;
        case CardRank::RANK_8:
            std::cout << '8';
            break;
        case CardRank::RANK_9:
            std::cout << '9';
            break;
        case CardRank::RANK_10:
            std::cout << 'T';
            break;
        case CardRank::RANK_JACK:
            std::cout << 'J';
            break;
        case CardRank::RANK_QUEEN:
            std::cout << 'Q';
            break;
        case CardRank::RANK_KING:
            std::cout << 'K';
            break;
        case CardRank::RANK_ACE:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case CardSuit::SUIT_CLUB:
            std::cout << 'C';
            break;
        case CardSuit::SUIT_DIAMOND:
            std::cout << 'D';
            break;
        case CardSuit::SUIT_HEART:
            std::cout << 'H';
            break;
        case CardSuit::SUIT_SPADE:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
        }
    }

    int value() const
    {
        if (m_rank <= CardRank::RANK_10)
        {
            return (static_cast<int>(m_rank) + 2);
        }

        switch (m_rank)
        {
        case CardRank::RANK_JACK:
        case CardRank::RANK_QUEEN:
        case CardRank::RANK_KING:
            return 10;
        case CardRank::RANK_ACE:
            return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }

    // Default constructor
    Card() = default;

    Card(CardRank rank, CardSuit suit)
        : m_rank{ rank }, m_suit{ suit }
    {
    }
};

class Deck
{
public:
    using array_type = std::array<Card, 52>;
    using index_type = array_type::size_type;

private:
    array_type m_deck{};
    index_type m_cardIndex{ 0 };

public:
    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    void shuffle()
    {
        static std::mt19937 
            mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);

        m_cardIndex = 0;
    }

};


int main()
{
    //Deck deck;
    //deck.print();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
