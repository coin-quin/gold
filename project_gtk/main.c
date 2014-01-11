#include <stdlib.h>
#include <gtk/gtk.h>

void detruire_fenetre(GtkWidget *pF, gpointer data){
   gtk_main_quit();
}

void add_button(GtkWidget *pF){
   GtkWidget *pQuitBtn;
   pQuitBtn = gtk_button_new_with_label("Quitter !");
   gtk_window_set_default_size(GTK_WINDOW(pQuitBtn), 200, 200);

   g_signal_connect(G_OBJECT(pQuitBtn), "clicked",
                    G_CALLBACK(gtk_main_quit), NULL);
   
   gtk_container_add(GTK_CONTAINER(pF), pQuitBtn);
}

int main(int argc,char **argv)
{
   //variables
   GtkWidget *pFenetre;
   
   //Init de gtk+
   gtk_init(&argc, &argv);

   //Création de la fenêtre
   pFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pFenetre), "Titre->OK");
   gtk_window_set_default_size(GTK_WINDOW(pFenetre), 400, 400);

   add_button(pFenetre);

   //Affichage de la fenêtre
   gtk_widget_show_all(pFenetre);

   //Event
   g_signal_connect(G_OBJECT(pFenetre), "destroy",
                    G_CALLBACK(detruire_fenetre), NULL);

   //Quit
   gtk_main();

   return EXIT_SUCCESS;
}
