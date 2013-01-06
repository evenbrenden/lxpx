
/*
 * lxpx PD external
 *
 * 2012 Even Brenden
 */

#include "m_pd.h"
#include "lxpx_helpers.h"
#include <stdlib.h>

#define SYSEX_START			0xF0
#define LEXICON_ID 			0x06
#define LXP1_ID 			0x02
#define PPA_MIDI_CH_MASK 	0x20
#define SYSEX_END			0xF7

t_class *lxpx_class;

typedef struct lxpx
{
	t_object x_obj;
	t_float value; 		// only floats because of pd-api - converted to t_int before use
	t_float parameter;
	t_float midi_channel;
} t_lxpx;

void output_sysex_byte (t_lxpx *x, t_int byte)
{
	outlet_float (x->x_obj.ob_outlet, (t_float) byte);
}

void calc_and_output (t_lxpx *x)
{
	t_packed_value packed;
	unpacked_to_packed (&packed, (int) x->value);

	output_sysex_byte (x, SYSEX_START);
	output_sysex_byte (x, LEXICON_ID);
	output_sysex_byte (x, LXP1_ID);
	output_sysex_byte (x, PPA_MIDI_CH_MASK | (int) x->midi_channel);
	output_sysex_byte (x, x->parameter);
	output_sysex_byte (x, packed.byte_0);
	output_sysex_byte (x, packed.byte_1);
	output_sysex_byte (x, packed.byte_2);
	output_sysex_byte (x, SYSEX_END);
}

/*
void lxpx_bang (t_lxpx *x)
{
	calc_and_output (x);
}

void lxpx_send (t_lxpx *x)
{
  	calc_and_output (x);
}
*/

void lxpx_new_value (t_lxpx *x, t_floatarg f)
{
	x->value = f;
	calc_and_output (x);
}

void *lxpx_new (void)
{
    t_lxpx *x = (t_lxpx *) pd_new (lxpx_class);

//	floatinlet_new (&x->x_obj, &x->value);
	floatinlet_new (&x->x_obj, &x->parameter);
	floatinlet_new (&x->x_obj, &x->midi_channel);
	outlet_new (&x->x_obj, &s_list);

    return (void *) x;
}

void lxpx_setup (void)
{
    lxpx_class = class_new (gensym ("lxpx"),
							(t_newmethod) lxpx_new,
							0,
    						sizeof (t_lxpx),
							0,
							0);

	class_addfloat (lxpx_class, lxpx_new_value);

/*
	class_addbang (lxpx_class, lxpx_bang);

  	class_addmethod (	lxpx_class,
        				(t_method) lxpx_send,
						gensym ("send"),
						0);
*/

}
