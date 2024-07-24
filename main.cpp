#include "Etudiant.hpp"
#include <iostream>
#include <vector>

Etudiant ajouterEtudiant(std::string nom, std::vector<double> notes, int nbNotes)
{
    Etudiant etudiant (nom, notes, nbNotes);
    std::cout << "Etudiant créé !" << std::endl;
    std::cout << "Nom : " << etudiant.getNom() << std::endl;
    return etudiant;
}
void afficherEtudiants(std::vector<Etudiant> liste)
{
    for(auto i = 0; i < liste.size(); i++)
    {
        std::cout <<  "Nom : " << liste[i].getNom();
        std::vector<double> notes = liste[i].getNotes();
        std::cout << " Notes : ";
        for(auto note : notes)
        {
            std::cout << note << " ";
        }
        std::cout << "Nombre de notes : " << liste[i].getNbNotes() << std::endl;
    }
}
Etudiant trouverMeilleurEtudiant(std::vector<Etudiant> liste)
{
    if(liste.empty())
    {
        std::cout << "La liste est vide" << std::endl;
    }
    Etudiant meilleur = liste[0];
    double meilleureMoyenne = meilleur.calculerMoyenne(meilleur.getNotes(), meilleur.getNbNotes());

    for(auto etu : liste)
    {
        double moyenne = etu.calculerMoyenne(etu.getNotes(), etu.getNbNotes());
        if(moyenne > meilleureMoyenne)
        {
            meilleur = etu;
            meilleureMoyenne = moyenne;
        }
    }
    std::cout << "Le meilleur élève est : " << meilleur.getNom() << " avec une moyenne de : " << meilleur.calculerMoyenne(meilleur.getNotes(), meilleur.getNbNotes());

    return meilleur;
    
    // for(auto i = 0; i < liste.size(); i++)
    // {
    //     if(liste[i].calculerMoyenne(liste[i].getNotes(), liste[i].getNbNotes()) > liste[i+1].calculerMoyenne(liste[i+1].getNotes(), liste[i+1].getNbNotes()))
    //     {
    //         std::cout << "Le meilleur élève est : " << liste[i].getNom() << std::endl;
    //         return liste[i];
    //     }else{
    //         std::cout << "Le meilleur élève est : " << liste[i+1].getNom() << std::endl;
    //         return liste[i+1];
    //     }
    // }

    
}
int main()
{
    std::vector<Etudiant> liste;
    Etudiant newEtudiant = ajouterEtudiant("Gabriel", {12.0, 10.5, 17.1}, 3);
    liste.push_back(newEtudiant);
    Etudiant nikita = ajouterEtudiant("Nikita", {15.5, 18.0, 9.5}, 3);
    liste.push_back(nikita);
    afficherEtudiants(liste);
    double moyenne = Etudiant::calculerMoyenne(newEtudiant.getNotes(), newEtudiant.getNbNotes());
    std::cout << "Moyenne des notes de " << newEtudiant.getNom() << " : " << std::endl;
    std::cout << moyenne << std::endl;
    trouverMeilleurEtudiant(liste);

    



    return 0;
}