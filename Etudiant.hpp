#ifndef __ETUDIANT__
#define __ETUDIANT__
#include <iostream>
#include <array>
#include <vector>

class Etudiant
{
    public:
        Etudiant(std::string nom, std::vector<double> notes, int nbNotes);
        static double calculerMoyenne(std::vector<double> notes, int nbNotes);
        // static void ajouterEtudiant(std::string nom, std::vector<double> notes, int nbNotes);
        std::string getNom();
        std::vector<double> getNotes();
        int getNbNotes();
    

    private:
        std::string nom;
        std::vector<double> notes;
        int nbNotes;
};

#endif