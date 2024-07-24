#include "Etudiant.hpp"
#include <iostream>
#include <vector>

Etudiant::Etudiant(std::string nom, std::vector<double> notes, int nbNotes) : nom(nom), notes(notes), nbNotes(nbNotes){};

std::string Etudiant::getNom()
{
    return this->nom;
}
std::vector<double> Etudiant::getNotes()
{
    return this->notes;
}
int Etudiant::getNbNotes()
{
    return this->nbNotes;
}
double Etudiant::calculerMoyenne(std::vector<double> notes, int nbNotes)
{
    double result;
    double sum;
    for(auto i = 0; i < notes.size(); i++)
    {
        sum += notes[i];
    }
    result = sum / nbNotes;
    return result;
}
