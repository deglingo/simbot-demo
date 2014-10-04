/* sbdmain.c -
 */

#include <clog.h>
#include <altk.h>
#include <simbot.h>



#define SIM_FPS ((gdouble) 10.0)



struct timer_data
{
  SbSim *sim;
  GTimer *timer;
  guint frame;
  gdouble next_frame;
};



/* _timer:
 */
static gboolean _timer ( struct timer_data *data )
{
  while (g_timer_elapsed(data->timer, NULL) >= data->next_frame)
    {
      sb_sim_update(data->sim);
      data->frame++;
      CL_DEBUG("frame: %d", data->frame);
      data->next_frame = ((gdouble)(data->frame + 1)) / SIM_FPS;
    }
  return G_SOURCE_CONTINUE;
}



/* main:
 */
int main ( int argc,
           char **argv )
{
  AltkDisplay *display;
  AltkWidget *dlg;
  GMainLoop *loop;
  SbSim *sim;
  SbBot *bot;
  GTimer *timer;
  struct timer_data timer_data;
  CL_DEBUG("hello!");
  altk_init();
  sim = sb_sim_new();
  bot = sb_bot_new(sim);
  display = altk_display_new();
  dlg = altk_dialog_new(display);
  altk_widget_show_all(dlg);
  altk_display_open(display);
  loop = g_main_loop_new(NULL, FALSE);
  timer = g_timer_new();
  timer_data.sim = sim;
  timer_data.timer = timer;
  timer_data.frame = 0;
  timer_data.next_frame = 1.0 / SIM_FPS;
  g_timeout_add_full(0 /* [fixme] priority */,
                     1,
                     (GSourceFunc) _timer,
                     &timer_data,
                     NULL);
  g_main_loop_run(loop);
  return 0;
}
