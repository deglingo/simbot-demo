/* sbdmain.c -
 */

#include <clog.h>
#include <altk.h>



/* main:
 */
int main ( int argc,
           char **argv )
{
  AltkDisplay *display;
  AltkWidget *dlg;
  GMainLoop *loop;
  CL_DEBUG("hello!");
  altk_init();
  display = altk_display_new();
  dlg = altk_dialog_new(display);
  altk_widget_show_all(dlg);
  altk_display_open(display);
  loop = g_main_loop_new(NULL, FALSE);
  g_main_loop_run(loop);
  return 0;
}
