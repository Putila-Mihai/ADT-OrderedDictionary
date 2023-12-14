//
// Created by ultra on 03.06.2023.
//
#ifndef TADDICTIONARORDONAT_DO_H
#define TADDICTIONARORDONAT_DO_H

typedef int TCheie;
typedef int TValoare;

#define NULL_TVALOARE -1

#include <utility>
#include <limits.h>

typedef std::pair<TCheie, TValoare> TElem;

class Iterator;

typedef bool(*Relatie)(TCheie, TCheie);

class DO {
    friend class Iterator;

private:
    int cap;

    TElem *elements;
    int *left;
    int *right;
    int root;
    int firstFREE;
    int size;

    Relatie r;
    void resize();
    int add_rec(int p, TElem e, int& old_value);
    void first_free();
    int min(int node);

    int sterge_rec(int p, TCheie e, TValoare& found);
public:
    // constructorul implicit al dictionarului
    DO(Relatie r);


    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
    TValoare adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
    TValoare cauta(TCheie c) const;


    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
    TValoare sterge(TCheie c);

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    int dim() const;

    //verifica daca dictionarul e vid
    bool vid() const;

    // se returneaza iterator pe dictionar
    // iteratorul va returna perechile in ordine dupa relatia de ordine (pe cheie)
    Iterator iterator() const;


    // destructorul dictionarului
    ~DO();

};

#endif //TADDICTIONARORDONAT_DO_H