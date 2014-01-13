#include <stdlib.h>
#include <gtk/gtk.h> 
#include "fonctions.h"

int main(int argc,char **argv)
{
   /* Constantes */
   const int EXEMPLE_1 = 0, EXEMPLE_2 = 1, EXEMPLE_3 = 2;
   const int HF = 0, HT = 1, VF = 2, VT = 3;
   const int TT = 0, TF = 1, FT = 2, FF = 3;

   /* Déclaration du widget */
   GtkWidget *pWindow, *pBoxV, *pBoxH, *pMenu;
   GtkWidget *pLabel;
   GtkWidget *pEntry;
   gtk_init(&argc,&argv);
           
   /* Création de la fenêtre */
   pWindow = make_window();
   pBoxH = make_box(HT);
   pBoxV = make_box(VT);
   pMenu = make_menu(pWindow);

   /* Ajout des bouton et label à la box */
   gtk_box_pack_start(GTK_BOX(pBoxV), pMenu, FALSE, FALSE, 0);

   add_button(pBoxV, EXEMPLE_1, "1", TF);

   pLabel = make_label("<b> Jaloux Davy ? </b>");
   gtk_box_pack_start(GTK_BOX(pBoxV), pLabel, TRUE, TRUE, 1);

   pEntry = make_entry("Zone de texte");
   gtk_box_pack_start(GTK_BOX(pBoxV), pEntry, TRUE, TRUE, 1);
    
   add_button(pBoxH, EXEMPLE_2, "No_pe", TT);
   add_button(pBoxH, EXEMPLE_1, "3", TF);
   gtk_box_pack_start(GTK_BOX(pBoxV), pBoxH, TRUE, TRUE, 1);

   add_button(pBoxV, EXEMPLE_3, "4",TT);

   /*Ajout de la box à la fenêtre */
   gtk_container_add(GTK_CONTAINER(pWindow), pBoxV);

   /* Affichage de la fenêtre */
   gtk_widget_show_all(pWindow);

   /* Connexion du signal "destroy" */
   g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(end_all), NULL);

   /* Demarrage de la boucle evenementielle */
   gtk_main();
                               
   return EXIT_SUCCESS;
}

