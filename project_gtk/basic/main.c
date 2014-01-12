#include <stdlib.h>
#include <gtk/gtk.h> 
#include "fonctions.h"

int main(int argc,char **argv)
{ 
      /* Déclaration du widget */
      GtkWidget *pWindow, *pLabel, *pBoxV, *pBoxH, *pEntry;
      gtk_init(&argc,&argv);
              
      /* Création de la fenêtre */
      pWindow = make_window();

      pBoxH = make_box(HT);
      pBoxV = make_box(VT);

      /* Ajout des bouton et label à la box */
      add_button(pBoxV, EXEMPLE_1, "1", TF);

      pLabel = make_label(pBoxV, "Héjààààààààààà<b> heheh </b>");
      pEntry = make_entry(pBoxV, "Zone de texte");

      add_button(pBoxH, EXEMPLE_2, "_Nope", TT);
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

