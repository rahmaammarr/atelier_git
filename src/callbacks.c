#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.c"
int s=1;
int testM=1;
int tn=0;
int tt=0;
int ts=0;
int tr=0;
int tu=0;
int tp=0;
void on_button_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *Login,*psw,*windowESadmin,*fen;
char user[20];
char pw[20];
Login=lookup_widget(button,"entry1_login");
psw =lookup_widget(button,"entry2_login");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(Login)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(psw)));
if (verif(user,pw)==1)
{
	fen=lookup_widget(button,"LOGIN");
	gtk_widget_destroy(fen);
	windowESadmin=create_ADMIN();
	gtk_widget_show(windowESadmin);
}
}


void on_button_gosupp_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_SUPP();
gtk_widget_show(fen_nv);
}


void on_button_gomodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_MODIF();
gtk_widget_show(fen_nv);
}


void on_button_gorech_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_RECHERCHE();
gtk_widget_show(fen_nv);
}


void on_button_goajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_AJOUT();
gtk_widget_show(fen_nv);
}


void on_button_affich_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *tv;
 tv=lookup_widget(button,"treeview1");
 afficher_user(tv);
}


void on_Home_ajout_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"AJOUT");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *login,*pw,*nom,*id,*Role,*type;
user u;
int role ;

nom=lookup_widget (button, "entry1_ajout");
id = lookup_widget (button, "entry2_ajout");
login = lookup_widget (button, "entry3_ajout");
pw = lookup_widget (button, "entry4_ajout");
type=lookup_widget(button,"combobox1_ajout");
Role=lookup_widget (button,"spinbutton1_ajout");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Role));
sprintf(u.role,"%d",role);
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
if (s==1)
	strcpy(u.sexe,"Homme");
else if (s==2) 
	strcpy(u.sexe,"Femme");
ajouter_USER(u);
}


void on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=1;
}


void on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=2;
}


void on_button_homesupp_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"SUPP");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *idd;
char U[20];
idd=lookup_widget(button,"entry1_supp");
strcpy(U,gtk_entry_get_text(GTK_ENTRY(idd)));
supprimer_user(U);
}


void on_button_homerech_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*outputr;
GtkWidget *output1,*output2,*output3,*output4,*output5,*output6;
GtkWidget *output11,*output22,*output33,*output44,*output55,*output66;
int test;
char p[20];
char nom[20];
char t[20];
char sx[20];
char log[20];
char pw[20];
char r[20];
id=lookup_widget(button,"entry_rech");
strcpy(p,gtk_entry_get_text(GTK_ENTRY(id)));
test=cherche_user(p,nom,t,sx,log,pw,r);
if (test==1)
{
output1=lookup_widget(button,"aa1");
 gtk_label_set_text(GTK_LABEL(output1),"nom-->");
output2=lookup_widget(button,"aa2");
 gtk_label_set_text(GTK_LABEL(output2),"type-->");
output3=lookup_widget(button,"aa3");
 gtk_label_set_text(GTK_LABEL(output3),"sexe-->");
output4=lookup_widget(button,"aa4");
 gtk_label_set_text(GTK_LABEL(output4),"role-->");
output5=lookup_widget(button,"aa5");
 gtk_label_set_text(GTK_LABEL(output5),"user_name-->");
output6=lookup_widget(button,"aa6");
 gtk_label_set_text(GTK_LABEL(output6),"pw -->");
output11=lookup_widget(button,"nom");
 gtk_label_set_text(GTK_LABEL(output11),nom);
output22=lookup_widget(button,"type");
 gtk_label_set_text(GTK_LABEL(output22),t);
output33=lookup_widget(button,"sexe");
 gtk_label_set_text(GTK_LABEL(output33),sx);
output44=lookup_widget(button,"role");
 gtk_label_set_text(GTK_LABEL(output44),r);
output55=lookup_widget(button,"username");
 gtk_label_set_text(GTK_LABEL(output55),log);
output66=lookup_widget(button,"pw");
 gtk_label_set_text(GTK_LABEL(output66),pw);
}
else
{
 outputr=lookup_widget(button,"notrecherche");
 gtk_label_set_text(GTK_LABEL(outputr),"n existe pas");

}
}


void on_button_homemodif_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_modif_clicked                (GtkWidget       *button,
                                             gpointer         user_data)
{
user x;
GtkWidget *idd,*nom,*type,*sexe,*role,*user,*pw ;
int Ri;
idd=lookup_widget(button,"entry_modif");
nom=lookup_widget(button,"entry1");
type=lookup_widget(button,"combobox_modif");
role=lookup_widget(button,"spinbutton_modif");
user=lookup_widget(button,"entry5");
pw=lookup_widget(button,"entry6");
strcpy(x.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(x.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.login,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
Ri=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(role));
sprintf(x.role,"%d",Ri);
if (testM==1)
	strcpy(x.sexe,"Homme");
else if (testM==2) 
	strcpy(x.sexe,"Femme");

modifier_user(x,tn,tt,ts,tr,tu,tp);

}


void on_checkbutton_n_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tn=1;
}


void on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tt=1;
}


void on_checkbutton_s_toggled               (GtkToggleButton *togglebutton,
                                      	     gpointer         user_data)
{
ts=1;
}


void on_checkbutton_r_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tr=1;
}


void on_checkbutton_u_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tu=1;
}


void on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tp=1;
}


void on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=1;
}


void on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=2;
}

