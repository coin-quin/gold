//Make
GtkWidget* make_window();
GtkWidget* make_entry(char *base);
GtkWidget* make_label(char* base);
GtkWidget* make_box(int dir);
GtkWidget* make_menu(GtkWidget *pF);

//Add button
void add_button(GtkWidget *pF, gint iExemple, char* base, int dir);

//Divers
void end_all(GtkWidget *pWidget, gpointer pData);
gchar* convert(char* base);

