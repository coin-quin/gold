#include <gtk/gtk.h>
#include "fonctions.h"

/* FONCTIONS DE BASE DE CRÉATION / DESTRUCTION ETC */

//Création d'une fenêtre
GtkWidget* make_window()
{
   GtkWidget *pF;
   pF = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pF), "TITRE");
   gtk_window_set_position(GTK_WINDOW(pF), GTK_WIN_POS_CENTER);
   gtk_window_set_deletable(GTK_WINDOW(pF), TRUE);
   gtk_window_set_default_size(GTK_WINDOW(pF), 320, 200);
   gtk_window_set_resizable(GTK_WINDOW(pF), TRUE);
   
   return pF;
}//Fin make_window

//Création d'une barre de menu
GtkWidget* make_menu(GtkWidget *pF)
{
   GtkWidget *pMenuBar, *pMenuBase, *pMenuItem;
   pMenuBar = gtk_menu_bar_new();
   pMenuBase = gtk_menu_new();
   pMenuItem = gtk_menu_item_new_with_label("New");  
   gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBase), pMenuItem);
   pMenuItem = gtk_menu_item_new_with_label("Open");  
   gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBase), pMenuItem);
   pMenuItem = gtk_menu_item_new_with_label("Save");  
   gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBase), pMenuItem);
   pMenuItem = gtk_menu_item_new_with_label("Quit");  
   g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(end_all), pF);
   gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBase), pMenuItem);
   
   pMenuItem = gtk_menu_item_new_with_label("Fichier");
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenuBase);
   gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
   return pMenuBar;
}

//Création d'une boite
GtkWidget* make_box(int dir)
{
   GtkWidget *pBox;
   switch(dir)
   {
      default:
      case 0:
         pBox = gtk_hbox_new(FALSE, 0);
         break;
      case 1:
         pBox = gtk_hbox_new(TRUE, 0);
         break;        
      case 2:
         pBox = gtk_vbox_new(FALSE, 0);
         break;
      case 3:
         pBox = gtk_vbox_new(TRUE, 0);
         break;
   }

   return pBox;
}//Fin make_box

//Création d'une ligne de saisie
GtkWidget* make_entry(char *base)
{
   GtkWidget *pEntry;
   gchar* text = convert(base);
   pEntry = gtk_entry_new();
   gtk_entry_set_text(GTK_ENTRY(pEntry), text);

   return pEntry;
}//Fin make_entry

//Création d'un label
GtkWidget* make_label(char* base)
{
   GtkWidget *pLabel;
   gchar* text = convert(base);
   pLabel = gtk_label_new(text);
   gtk_label_set_use_markup(GTK_LABEL(pLabel), TRUE);
   gtk_label_set_justify(GTK_LABEL(pLabel), GTK_JUSTIFY_FILL);

   return pLabel;
}//Fin make_label

//Création d'un bouton
void add_button(GtkWidget* pBox, gint iExemple, char* base, int dir)
{
   GtkWidget* pButton;
   gchar* text = convert(base);
   switch(iExemple)
   {
      default:
      case 0:
         pButton = gtk_button_new_with_label(text);
         break;
      case 1:
         pButton = gtk_button_new_with_mnemonic(text);
         break;
      case 2:
         pButton = gtk_button_new_from_stock(GTK_STOCK_QUIT);
         break;
   }
   
   gtk_button_set_relief(GTK_BUTTON(pButton), GTK_RELIEF_HALF);
   g_signal_connect( G_OBJECT(pButton), "clicked", G_CALLBACK(end_all), NULL);
   
   switch(dir)
   {  
      default:
      case 0:
         gtk_box_pack_start(GTK_BOX(pBox), pButton, TRUE, TRUE, 1);
         break;
      case 1:
         gtk_box_pack_start(GTK_BOX(pBox), pButton, TRUE, FALSE, 1);
         break;
      case 2:
         gtk_box_pack_start(GTK_BOX(pBox), pButton, FALSE, TRUE, 1);
         break;
      case 3:
         gtk_box_pack_start(GTK_BOX(pBox), pButton, FALSE, FALSE, 1);
         break;
   }
}

//Convertion texte
gchar* convert(char* base)
{
   return g_locale_to_utf8(base, -1, NULL, NULL, NULL);
}//Fin convert

//Quitte gtk
void end_all(GtkWidget *pWidget, gpointer pData)
{
   gtk_main_quit();
}//Fin end_all


