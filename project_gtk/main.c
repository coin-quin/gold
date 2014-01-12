#include <stdlib.h>
#include <stdio.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "gtk.h"

int main(int argc,char **argv)
{
   //variables
   GtkWidget *pFenetre, *vBox, *pBarreMenu;

   //Init de gtk+
   gtk_init(&argc, &argv);

   //Création de la fenêtre et des objets
   pFenetre = make_window();
   pBarreMenu = make_menu(pFenetre);

   vBox = gtk_vbox_new(FALSE, 0);
  
   gtk_container_add(GTK_CONTAINER(pFenetre), vBox);
   gtk_box_pack_start(GTK_BOX(vBox), pBarreMenu, FALSE, FALSE, 3);

   //Affichage de la fenêtre
   gtk_widget_show_all(pFenetre);

   //Quit
   gtk_main();

   return EXIT_SUCCESS;
}
