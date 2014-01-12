#include <stdlib.h>
#include <gtk/gtk.h> 
#include "fonctions.h"

int main(int argc,char **argv)
{ 
      /* Déclaration du widget */
      GtkWidget *pWindow, *pLabel, *pBoxV, *pBoxH;
      gtk_init(&argc,&argv);
              
      /* Création de la fenêtre */
      pWindow = make_window();
//    pLabel = make_label(pWindow, "Héjààààààààààà<b> heheh </b>");

      pBoxH = make_box(HT);
      pBoxV = make_box(HF);

      /* Ajout du bouton à la box */
      add_button(pBoxV, EXEMPLE_2, FT);
      add_button(pBoxV, EXEMPLE_2, TF);

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

