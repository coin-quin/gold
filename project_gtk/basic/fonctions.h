#define EXEMPLE_1 0
#define EXEMPLE_2 1
#define EXEMPLE_3 2
#define VT 0
#define VF 1
#define HT 2
#define HF 3
#define TT 0
#define TF 1
#define FT 2
#define FF 3

GtkWidget* make_window();
GtkWidget* make_label(GtkWidget* pF, char* base);
void add_button(GtkWidget *pF, gint iExemple, char* base, int dir);
gchar* convert(char* base);
GtkWidget* make_box(int dir);
void end_all(GtkWidget *pWidget, gpointer pData);
